#ifndef UNIDADEPERSISTENCIA_H_INCLUDED
#define UNIDADEPERSISTENCIA_H_INCLUDED

//---------------------------------------------------------------------------
// Incluir cabe�alhos.

#include "Dominios.h"
#include "Entidades.h"

#include <list>

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>

#include "sqlite3.h" // Incluir cabe�alho da biblioteca SQLite.

    using namespace std;

//---------------------------------------------------------------------------
// Declara��o da classe EErroPersistencia.

class EErroPersistencia
{
private:
    string mensagem;
public:
    EErroPersistencia(string);
    string what();
};

//---------------------------------------------------------------------------
// Declara��o da classe ElementoResultado.

class ElementoResultado
{
private:
    string nomeColuna;
    string valorColuna;
public:
    void setNomeColuna(const string&);
    string getNomeColuna() const;
    void setValorColuna(const string&);
    string getValorColuna() const;
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoSQL.

class ComandoSQL
{
private:
    const char *nomeBancoDados;
    sqlite3 *bd;
    char *mensagem;
    int rc;
    void conectar();
    void desconectar();
    static int callback(void *, int, char **, char **);

protected:
    static list<ElementoResultado> listaResultado;
    string comandoSQL;
public:
    ComandoSQL()
    {
        nomeBancoDados = "BancoTrabalho.db";                             // Nome do banco de dados.
    }
    void executar();
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoLerSenha.

class ComandoLerSenha:public ComandoSQL
{
public:
    ComandoLerSenha(Matricula);
    string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarSala.

class ComandoPesquisarSala:public ComandoSQL
{
public:
    ComandoPesquisarSala(Codigo);
    Sala getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarSala.

class ComandoAtualizarSala:public ComandoSQL
{
public:
    ComandoAtualizarSala(Sala);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoCadastrarSala.

class ComandoCadastrarSala:public ComandoSQL
{
public:
    ComandoCadastrarSala(Sala);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoRemoverSala.

class ComandoRemoverSala:public ComandoSQL
{
public:
    ComandoRemoverSala(Codigo);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoListarSala.

class ComandoListarSala:public ComandoSQL
{
public:
    ComandoListarSala();
    list<Sala> getResultado();
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoPesquisarSessao.


class ComandoPesquisarSessao:public ComandoSQL
{
public:
    ComandoPesquisarSessao(Codigo);
    Sessao getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarSessao.

class ComandoAtualizarSessao:public ComandoSQL
{
public:
    ComandoAtualizarSessao(Sessao);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoCadastrarSessao.

class ComandoCadastrarSessao:public ComandoSQL
{
public:
    ComandoCadastrarSessao(Sessao);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoRemoverSessao.

class ComandoRemoverSessao:public ComandoSQL
{
public:
    ComandoRemoverSessao(Codigo);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoListarSessao.

class ComandoListarSessao:public ComandoSQL
{
public:
    ComandoListarSessao();
    list<Sessao> getResultado();
};

class ComandoPesquisarSessaoPeca:public ComandoSQL
{
public:
    ComandoPesquisarSessaoPeca(Codigo);
    int getResultado();
};

class ComandoPesquisarSessaoSala:public ComandoSQL
{
public:
    ComandoPesquisarSessaoSala(Codigo);
    int getResultado();
};

class ComandoCadastrarSessaoPeca:public ComandoSQL
{
public:
    ComandoCadastrarSessaoPeca(Sessao);
};

class ComandoCadastrarSessaoSala:public ComandoSQL
{
public:
    ComandoCadastrarSessaoSala(Sessao);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarPeca.

class ComandoPesquisarPeca:public ComandoSQL
{
public:
    ComandoPesquisarPeca(Codigo);
    Peca getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarPeca.

class ComandoAtualizarPeca:public ComandoSQL
{
public:
    ComandoAtualizarPeca(Peca);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoCadastrarPeca.

class ComandoCadastrarPeca:public ComandoSQL
{
public:
    ComandoCadastrarPeca(Peca);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoRemoverPeca.

class ComandoRemoverPeca:public ComandoSQL
{
public:
    ComandoRemoverPeca(Codigo);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoListarPeca.

class ComandoListarPeca:public ComandoSQL
{
public:
    ComandoListarPeca();
    list<Peca> getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarAluno.

class ComandoPesquisarParticipante:public ComandoSQL
{
public:
    ComandoPesquisarParticipante(Matricula);
    Participante getResultado();
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoCadastrarAluno.

class ComandoCadastrarParticipante:public ComandoSQL
{
public:
    ComandoCadastrarParticipante(Participante);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarAluno.

class ComandoAtualizarParticipante:public ComandoSQL
{
public:
    ComandoAtualizarParticipante(Participante);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoRemoverAluno.

class ComandoRemoverParticipante:public ComandoSQL
{
public:
    ComandoRemoverParticipante(Matricula);
};

class ComandoCadastrarParticipantePeca:public ComandoSQL
{
public:
    ComandoCadastrarParticipantePeca(Participante);
};

class ComandoPesquisarParticipantePeca:public ComandoSQL
{
public:
    ComandoPesquisarParticipantePeca(Codigo);
    int getResultado();
};

//---------------------------------------------------------------------------
// Implementa��es de m�todos.

inline string ElementoResultado::getNomeColuna() const
{
    return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const
{
    return valorColuna;
}

#endif // UNIDADEPERSISTENCIA_H_INCLUDED
