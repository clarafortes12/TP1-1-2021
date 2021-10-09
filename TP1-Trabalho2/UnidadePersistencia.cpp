//---------------------------------------------------------------------------
// Incluir cabe�alhos.

#include "UnidadePersistencia.h"

// Atributo est�tico.

list<ElementoResultado> ComandoSQL::listaResultado;

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ErroPersistencia.

EErroPersistencia::EErroPersistencia(string mensagem)
{
    this->mensagem = mensagem;
}

string EErroPersistencia::what()
{
    return mensagem;
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ElementoResultado.

void ElementoResultado::setNomeColuna(const string& nomeColuna)
{
    this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna)
{
    this->valorColuna = valorColuna;
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoSQL.

void ComandoSQL::conectar()
{
    rc = sqlite3_open(nomeBancoDados, &bd); // possivel funcai definida pelo prof
    if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar()
{
    rc =  sqlite3_close(bd); // possivel funcai definida pelo prof
    if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

void ComandoSQL::executar()
{
    conectar();
    rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem); // possivel funcai definida pelo prof
    if(rc != SQLITE_OK)
    {
        sqlite3_free(mensagem); // possivel funcai definida pelo prof
        desconectar();
        throw EErroPersistencia("Erro na execucao do comando SQL");
    }
    desconectar();
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna)
{
    NotUsed=0;
    ElementoResultado elemento;
    int i;
    for(i=0; i<argc; i++)
    {
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
    }
    return 0;
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoLerSenha.

ComandoLerSenha::ComandoLerSenha(Matricula matricula)
{
    comandoSQL = "SELECT senha FROM participante WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

string ComandoLerSenha::getResultado()
{
    ElementoResultado resultado;
    string senha;

    //Remover senha;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha = resultado.getValorColuna();

    return senha;
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoPesquisarSala.
ComandoCadastrarSessao::ComandoCadastrarSessao(Sessao sessao)
{
    comandoSQL = "INSERT INTO sessao VALUES (";
    comandoSQL += "'" + sessao.getCodigo().getValor() + "', ";
    comandoSQL += "'" + sessao.getHorario().getValor() + "', ";
    comandoSQL += "'" + sessao.getData().getValor() + "')";
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoPesquisarSala.
ComandoCadastrarPeca::ComandoCadastrarPeca(Peca peca)
{
    comandoSQL = "INSERT INTO peca VALUES (";
    comandoSQL += "'" + peca.getCodigo().getValor() + "', ";
    comandoSQL += "'" + peca.getNome().getValor() + "', ";
    comandoSQL += "'" + peca.getTipo().getValor() + "', ";
    comandoSQL += "'" + peca.getClassificacao().getValor() + "')";
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoPesquisarSala.
ComandoCadastrarSala::ComandoCadastrarSala(Sala sala)
{
    comandoSQL = "INSERT INTO sala VALUES (";
    comandoSQL += "'" + sala.getCodigo().getValor() + "', ";
    comandoSQL += "'" + sala.getNome().getValor() + "', ";
    comandoSQL += "'" + sala.getCapacidade().getValor() + "')";
}

ComandoPesquisarSala::ComandoPesquisarSala(Codigo codigo)
{
    comandoSQL = "SELECT * FROM sala WHERE codigo = ";
    comandoSQL += codigo.getValor();
}

Sala ComandoPesquisarSala::getResultado()
{
    ElementoResultado resultado;
    Sala sala;

    // Remover codigo;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sala.setCodigo(Codigo(resultado.getValorColuna()));

    // Remover nome;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sala.setNome(Nome(resultado.getValorColuna()));

    // Remover capacidade;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sala.setCapacidade(Capacidade(resultado.getValorColuna()));

    return sala;

}
//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe AtualizarSala.

ComandoAtualizarSala::ComandoAtualizarSala(Sala sala)
{
    comandoSQL = "UPDATE sala ";
    comandoSQL += "SET nome = '" + sala.getNome().getValor();
    comandoSQL += "', capacidade = '" + sala.getCapacidade().getValor();
    comandoSQL += "' WHERE codigo = " + sala.getCodigo().getValor();
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoRemoverSala.

ComandoRemoverSala::ComandoRemoverSala(Codigo codigo)
{
    comandoSQL = "DELETE FROM sala WHERE codigo = ";
    comandoSQL += codigo.getValor();
}


//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoPesquisarParticipante.

ComandoPesquisarParticipante::ComandoPesquisarParticipante(Matricula matricula)
{
    comandoSQL = "SELECT * FROM participante WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

Participante ComandoPesquisarParticipante::getResultado()
{
    ElementoResultado resultado;
    Participante participante;

    // Remover nome;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    participante.setNome(Nome(resultado.getValorColuna()));

    // Remover matricula;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    participante.setMatricula(Matricula(resultado.getValorColuna()));

    // Remover senha;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    participante.setSenha(Senha(resultado.getValorColuna()));

    // Remover telefone;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    participante.setTelefone(Telefone(resultado.getValorColuna()));

    // Remover matr�cula do orientador;
    /*if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    participante.setMatriculaOrientador(Matricula(resultado.getValorColuna()));*/

    return participante;

}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoCadastrarAluno.

ComandoCadastrarParticipante::ComandoCadastrarParticipante(Participante participante)
{
    comandoSQL = "INSERT INTO participante VALUES (";
    comandoSQL += "'" + participante.getMatricula().getValor() + "', ";
    comandoSQL += "'" + participante.getNome().getValor() + "', ";
    comandoSQL += "'" + participante.getSobrenome().getValor() + "', ";
    comandoSQL += "'" + participante.getEmail().getValor() + "', ";
    comandoSQL += "'" + participante.getTelefone().getValor() + "', ";
    comandoSQL += "'" + participante.getSenha().getValor() + "', ";
    comandoSQL += "'" + participante.getCargo().getValor() + "')";
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoRemoverAluno.

ComandoRemoverParticipante::ComandoRemoverParticipante(Matricula matricula)
{
    comandoSQL = "DELETE FROM participante WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoEditarAluno.

ComandoAtualizarParticipante::ComandoAtualizarParticipante(Participante participante)
{
    comandoSQL = "UPDATE participante ";
    comandoSQL += "SET nome = '" + participante.getNome().getValor();
    comandoSQL += "', sobrenome = '" + participante.getSobrenome().getValor();
    comandoSQL += "', email = '" + participante.getEmail().getValor();
    comandoSQL += "', telefone = '" + participante.getTelefone().getValor();
    comandoSQL += "', senha = '" + participante.getSenha().getValor();
    comandoSQL += "', cargo = '" + participante.getCargo().getValor();
    comandoSQL += "' WHERE matricula = " + participante.getMatricula().getValor();
}

