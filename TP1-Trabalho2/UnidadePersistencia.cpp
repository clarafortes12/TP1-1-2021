#include "UnidadePersistencia.h"

// Atributo est�tico.

list<ElementoResultado> ComandoSQL::listaResultado;

EErroPersistencia::EErroPersistencia(string mensagem)
{
    this->mensagem = mensagem;
}

string EErroPersistencia::what()
{
    return mensagem;
}

void ElementoResultado::setNomeColuna(const string& nomeColuna)
{
    this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna)
{
    this->valorColuna = valorColuna;
}

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
        sqlite3_free(mensagem);
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

ComandoLerSenha::ComandoLerSenha(Matricula matricula)
{
    comandoSQL = "SELECT senha FROM participante WHERE matricula = ";
    comandoSQL += "'" + matricula.getValor() + "'";
}

string ComandoLerSenha::getResultado()
{
    ElementoResultado resultado;
    string senha;

    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia. Aqui senha");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha = resultado.getValorColuna();

    return senha;
}

ComandoCadastrarSessao::ComandoCadastrarSessao(Sessao sessao)
{
    comandoSQL = "INSERT INTO sessao VALUES (";
    comandoSQL += "'" + sessao.getCodigo().getValor() + "', ";
    comandoSQL += "'" + sessao.getData().getValor() + "', ";
    comandoSQL += "'" + sessao.getHorario().getValor() + "',";
    comandoSQL += "NULL,";
    comandoSQL += "NULL)";
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

    // Remover codigo_sala;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    if(resultado.getValorColuna() != "NULL"){
        sessao.setCodigoSala(Codigo(resultado.getValorColuna()));
    }

    // Remover codigo_peca;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    if(resultado.getValorColuna()!= "NULL"){
        sessao.setCodigoPeca(Codigo(resultado.getValorColuna()));
    }

    return sessao;

}

ComandoAtualizarSessao::ComandoAtualizarSessao(Sessao sessao)
{
    comandoSQL = "UPDATE sessao ";
    comandoSQL += "SET data = '" + sessao.getData().getValor();
    comandoSQL += "', horario = '" + sessao.getHorario().getValor();
    comandoSQL += "' WHERE codigo = '" + sessao.getCodigo().getValor()+"'";
}

ComandoCadastrarSessaoPeca::ComandoCadastrarSessaoPeca(Sessao sessao)
{
    comandoSQL = "UPDATE sessao ";
    comandoSQL += "SET codigo_peca = '" + sessao.getCodigoPeca().getValor();
    comandoSQL += "' WHERE codigo = '" + sessao.getCodigo().getValor()+"'";
}

ComandoCadastrarSessaoSala::ComandoCadastrarSessaoSala(Sessao sessao)
{
    comandoSQL = "UPDATE sessao ";
    comandoSQL += "SET codigo_sala = '" + sessao.getCodigoSala().getValor();
    comandoSQL += "' WHERE codigo = '" + sessao.getCodigo().getValor()+"'";
}

ComandoRemoverSessao::ComandoRemoverSessao(Codigo codigo)
{
    comandoSQL = "DELETE FROM sessao WHERE codigo = '";
    comandoSQL += codigo.getValor()+"'";
}

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

        // Remover horario;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        resultado_sessao.setHorario(Horario(resultado.getValorColuna()));

        // Remover codigo_sala;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        if(resultado.getValorColuna()!= "NULL"){
            resultado_sessao.setCodigoSala(Codigo(resultado.getValorColuna()));
        }

        // Remover codigo_peca;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        if(resultado.getValorColuna()!= "NULL"){
            resultado_sessao.setCodigoPeca(Codigo(resultado.getValorColuna()));
        }

        sessoes.push_back(resultado_sessao);
    }

    return sessoes;
}

ComandoPesquisarSessaoPeca::ComandoPesquisarSessaoPeca(Codigo codigo)
{
    comandoSQL = "SELECT * FROM sessao WHERE codigo_peca = '";
    comandoSQL += codigo.getValor()+"'";
}

int ComandoPesquisarSessaoPeca::getResultado()
{
    ElementoResultado resultado;
    int pecas = 0;

    while(!listaResultado.empty()){

    // Remover codigo;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();

    // Remover Data;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();

    // Remover Horario;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();

    // Remover codigo_peca;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();

    // Remover codigo_sala;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();

    pecas = pecas + 1;

    }
    return pecas;
}

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
    comandoSQL = "SELECT * FROM peca WHERE codigo = '";
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

ComandoAtualizarPeca::ComandoAtualizarPeca(Peca peca)
{
    comandoSQL = "UPDATE peca ";
    comandoSQL += "SET nome = '" + peca.getNome().getValor();
    comandoSQL += "', tipo = '" + peca.getTipo().getValor();
    comandoSQL += "', classificacao = '" + peca.getClassificacao().getValor();
    comandoSQL += "' WHERE codigo = '" + peca.getCodigo().getValor()+"'";
}

ComandoRemoverPeca::ComandoRemoverPeca(Codigo codigo)
{
    comandoSQL = "DELETE FROM peca WHERE codigo = '";
    comandoSQL += codigo.getValor()+"'";
}

ComandoListarPeca::ComandoListarPeca()
{
    comandoSQL = "SELECT * FROM peca";
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

ComandoAtualizarSala::ComandoAtualizarSala(Sala sala)
{
    comandoSQL = "UPDATE sala ";
    comandoSQL += "SET nome = '" + sala.getNome().getValor();
    comandoSQL += "', capacidade = '" + sala.getCapacidade().getValor();
    comandoSQL += "' WHERE codigo = '" + sala.getCodigo().getValor()+"'";
}

ComandoRemoverSala::ComandoRemoverSala(Codigo codigo)
{
    comandoSQL = "DELETE FROM sala WHERE codigo = '";
    comandoSQL += codigo.getValor()+"'";
}

ComandoListarSala::ComandoListarSala()
{
    comandoSQL = "SELECT * FROM sala";
}

list<Sala> ComandoListarSala::getResultado()
{
    ElementoResultado resultado;
    Sala resultado_sala;
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

ComandoPesquisarParticipante::ComandoPesquisarParticipante(Matricula matricula)
{
    comandoSQL = "SELECT * FROM participante WHERE matricula = '";
    comandoSQL += matricula.getValor()+"'";
}

Participante ComandoPesquisarParticipante::getResultado(){
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

    // Remover codigo_peca;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    if(resultado.getValorColuna() != "NULL"){
        participante.setCodigoPeca(Codigo(resultado.getValorColuna()));
    }
    else{
        participante.setCodigoPeca(Codigo());
    }

    return participante;

}

ComandoCadastrarParticipante::ComandoCadastrarParticipante(Participante participante)
{
    cout << "Comando executar cadastro" << endl;
    comandoSQL = "INSERT INTO participante VALUES (";
    comandoSQL += "'" + participante.getMatricula().getValor() + "', ";
    comandoSQL += "'" + participante.getNome().getValor() + "', ";
    comandoSQL += "'" + participante.getSobrenome().getValor() + "', ";
    comandoSQL += "'" + participante.getEmail().getValor() + "', ";
    comandoSQL += "'" + participante.getTelefone().getValor() + "', ";
    comandoSQL += "'" + participante.getSenha().getValor() + "', ";
    comandoSQL += "'" + participante.getCargo().getValor() + "',";
    comandoSQL += "NULL)";
    cout << "Fim Comando executar cadastro" << endl;
}

ComandoRemoverParticipante::ComandoRemoverParticipante(Matricula matricula)
{
    comandoSQL = "DELETE FROM participante WHERE matricula = '";
    comandoSQL += matricula.getValor()+"'";
}

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

ComandoCadastrarParticipantePeca::ComandoCadastrarParticipantePeca(Participante participante)
{
    comandoSQL = "UPDATE participante ";
    comandoSQL += "SET codigo_peca = '" + participante.getCodigoPeca().getValor();
    comandoSQL += "' WHERE matricula = '" + participante.getMatricula().getValor()+"'";
}

ComandoPesquisarParticipantePeca::ComandoPesquisarParticipantePeca(Codigo codigo)
{
    comandoSQL = "SELECT * FROM participante WHERE codigo_peca = '";
    comandoSQL += codigo.getValor()+"'";
}

int ComandoPesquisarParticipantePeca::getResultado()
{
    ElementoResultado resultado;
    int pecas = 0;

    while(!listaResultado.empty()){

        // Remover matricula;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();

        // Remover nome;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();

        // Remover sobrenome;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();

        // Remover email;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();

        // Remover telefone;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();

        // Remover senha;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();

        // Remover cargo;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();

        // Remover codigo_peca;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();

        pecas = pecas + 1;
    }
    return pecas;
}
