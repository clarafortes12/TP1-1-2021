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
        nomeBancoDados = "testedb.db";                             // Nome do banco de dados.
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
// Declara��o da classe ComandoCadastrarAluno.

class ComandoCadastrarSessao:public ComandoSQL
{
public:
    ComandoCadastrarSessao(Sessao);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoCadastrarAluno.

class ComandoCadastrarPeca:public ComandoSQL
{
public:
    ComandoCadastrarPeca(Peca);
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
