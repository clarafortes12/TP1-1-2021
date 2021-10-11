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
    rc = sqlite3_open(nomeBancoDados, &bd);
    if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar()
{
    rc =  sqlite3_close(bd);
    if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

void ComandoSQL::executar()
{
    conectar();

    rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
    if(rc != SQLITE_OK)
    {
        sqlite3_free(mensagem); // so para esvaziar a memoria mensagem
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
        throw EErroPersistencia("Lista de resultados vazia. Aqui senha");
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

ComandoPesquisarSessao::ComandoPesquisarSessao(Codigo codigo)
{
    comandoSQL = "SELECT * FROM sessao WHERE codigo = '";
    comandoSQL += codigo.getValor()+"'";
}

Sessao ComandoPesquisarSessao::getResultado()
{
    ElementoResultado resultado;
    Sessao sessao;

    // Remover codigo;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sessao.setCodigo(Codigo(resultado.getValorColuna()));

    // Remover Data;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sessao.setData(Data(resultado.getValorColuna()));

    // Remover Horario;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sessao.setHorario(Horario(resultado.getValorColuna()));

    return sessao;

}
//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe AtualizarSessao.

ComandoAtualizarSessao::ComandoAtualizarSessao(Sessao sessao)
{
    comandoSQL = "UPDATE sessao ";
    comandoSQL += "SET data = '" + sessao.getData().getValor();
    comandoSQL += "', horario = '" + sessao.getHorario().getValor();
    comandoSQL += "' WHERE codigo = '" + sessao.getCodigo().getValor()+"'";
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoRemoverSessao.

ComandoRemoverSessao::ComandoRemoverSessao(Codigo codigo)
{
    comandoSQL = "DELETE FROM sessao WHERE codigo = '";
    comandoSQL += codigo.getValor()+"'";
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoListarSessao.

ComandoListarSessao::ComandoListarSessao()
{
    comandoSQL = "SELECT * FROM sessao";
}

list<Sessao> ComandoListarSessao::getResultado()
{
    ElementoResultado resultado;
    Sessao resultado_sessao;
    list<Sessao> sessoes;

    while(!listaResultado.empty()){
        // Remover codigo;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        resultado_sessao.setCodigo(Codigo(resultado.getValorColuna()));

        // Remover nome;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        resultado_sessao.setData(Data(resultado.getValorColuna()));

        // Remover capacidade;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        resultado_sessao.setHorario(Horario(resultado.getValorColuna()));

        sessoes.push_back(resultado_sessao);
    }

    return sessoes;
}


//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoPesquisarPeca.
ComandoCadastrarPeca::ComandoCadastrarPeca(Peca peca)
{
    comandoSQL = "INSERT INTO peca VALUES (";
    comandoSQL += "'" + peca.getCodigo().getValor() + "', ";
    comandoSQL += "'" + peca.getNome().getValor() + "', ";
    comandoSQL += "'" + peca.getTipo().getValor() + "', ";
    comandoSQL += "'" + peca.getClassificacao().getValor() + "')";
}

ComandoPesquisarPeca::ComandoPesquisarPeca(Codigo codigo)
{
    comandoSQL = "SELECT * FROM Peca WHERE codigo = '";
    comandoSQL += codigo.getValor()+"'";
}

Peca ComandoPesquisarPeca::getResultado()
{
    ElementoResultado resultado;
    Peca peca;

    // Remover codigo;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    peca.setCodigo(Codigo(resultado.getValorColuna()));

    // Remover nome;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    peca.setNome(Nome(resultado.getValorColuna()));

    // Remover tipo;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    peca.setTipo(Tipo(resultado.getValorColuna()));

    // Remover classificacao;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    peca.setClassificacao(Classificacao(resultado.getValorColuna()));

    return peca;

}
//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe AtualizarPeca.

ComandoAtualizarPeca::ComandoAtualizarPeca(Peca peca)
{
    comandoSQL = "UPDATE Peca ";
    comandoSQL += "SET nome = '" + peca.getNome().getValor();
    comandoSQL += "', tipo = '" + peca.getTipo().getValor();
    comandoSQL += "', classificacao = '" + peca.getClassificacao().getValor();
    comandoSQL += "' WHERE codigo = '" + peca.getCodigo().getValor()+"'";
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoRemoverPeca.

ComandoRemoverPeca::ComandoRemoverPeca(Codigo codigo)
{
    comandoSQL = "DELETE FROM Peca WHERE codigo = '";
    comandoSQL += codigo.getValor()+"'";
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoListarPeca.

ComandoListarPeca::ComandoListarPeca()
{
    comandoSQL = "SELECT * FROM Peca";
}

list<Peca> ComandoListarPeca::getResultado()
{
    ElementoResultado resultado;
    Peca resultado_peca;
    list<Peca> pecas;

    while(!listaResultado.empty()){
        // Remover codigo;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        resultado_peca.setCodigo(Codigo(resultado.getValorColuna()));

        // Remover nome;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        resultado_peca.setNome(Nome(resultado.getValorColuna()));

        // Remover tipo;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        resultado_peca.setTipo(Tipo(resultado.getValorColuna()));

        // Remover classificacao;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        resultado_peca.setClassificacao(Classificacao(resultado.getValorColuna()));

        pecas.push_back(resultado_peca);
    }

    return pecas;
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
    comandoSQL = "SELECT * FROM sala WHERE codigo = '";
    comandoSQL += codigo.getValor()+"'";
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
    comandoSQL += "' WHERE codigo = '" + sala.getCodigo().getValor()+"'";
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoRemoverSala.

ComandoRemoverSala::ComandoRemoverSala(Codigo codigo)
{
    comandoSQL = "DELETE FROM sala WHERE codigo = '";
    comandoSQL += codigo.getValor()+"'";
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoListarSala.

ComandoListarSala::ComandoListarSala()
{
    //comandoSQL = "SELECT codigo, nome FROM sala ";
    comandoSQL = "SELECT * FROM sala";
}

list<Sala> ComandoListarSala::getResultado()
{
    ElementoResultado resultado;
    Sala resultado_sala;
    // por ora vai voltar as salas com todos os campos msm, pq n sei como retornaria so codigo e nome, teria de criar uma nova entidade
    list<Sala> salas;

    while(!listaResultado.empty()){
        // Remover codigo;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        resultado_sala.setCodigo(Codigo(resultado.getValorColuna()));

        // Remover nome;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        resultado_sala.setNome(Nome(resultado.getValorColuna()));

        // Remover capacidade;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        resultado_sala.setCapacidade(Capacidade(resultado.getValorColuna()));

        salas.push_back(resultado_sala);
    }

    return salas;
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoPesquisarParticipante.

ComandoPesquisarParticipante::ComandoPesquisarParticipante(Matricula matricula)
{
    comandoSQL = "SELECT * FROM participante WHERE matricula = '";
    comandoSQL += matricula.getValor()+"'";
}

Participante ComandoPesquisarParticipante::getResultado()
{
    ElementoResultado resultado;
    Participante participante;

    // Remover matricula;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    participante.setMatricula(Matricula(resultado.getValorColuna()));

    // Remover nome;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    participante.setNome(Nome(resultado.getValorColuna()));

    // Remover sobrenome;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    participante.setSobrenome(Nome(resultado.getValorColuna()));

    // Remover email;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    participante.setEmail(Email(resultado.getValorColuna()));

    // Remover telefone;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    participante.setTelefone(Telefone(resultado.getValorColuna()));

    // Remover senha;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    participante.setSenha(Senha(resultado.getValorColuna()));

    // Remover cargo;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    participante.setCargo(Cargo(resultado.getValorColuna()));

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
    comandoSQL = "DELETE FROM participante WHERE matricula = '";
    comandoSQL += matricula.getValor()+"'";
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
    comandoSQL += "' WHERE matricula = '" + participante.getMatricula().getValor()+"'";
}

