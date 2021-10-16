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

#include "sqlite3.h"

    using namespace std;

// Classe obtida dos exemplos disponibilizados pelo professor
class EErroPersistencia
{
private:
    string mensagem;
public:
    EErroPersistencia(string);
    string what();
};

// Classe obtida dos exemplos disponibilizados pelo professor
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

inline string ElementoResultado::getNomeColuna() const
{
    return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const
{
    return valorColuna;
}

// Classe obtida dos exemplos disponibilizados pelo professor
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

// Estudante responsável: Liz Costato - 180022261
class ComandoLerSenha:public ComandoSQL
{
public:
    ComandoLerSenha(Matricula);
    string getResultado();
};

// Estudante responsável: Clara Fortes - 190017503
class ComandoPesquisarParticipante:public ComandoSQL
{
public:
    ComandoPesquisarParticipante(Matricula);
    Participante getResultado();
};

// Estudante responsável: Clara Fortes - 190017503
class ComandoCadastrarParticipante:public ComandoSQL
{
public:
    ComandoCadastrarParticipante(Participante);
};

// Estudante responsável: Clara Fortes - 190017503
class ComandoAtualizarParticipante:public ComandoSQL
{
public:
    ComandoAtualizarParticipante(Participante);
};

// Estudante responsável: Clara Fortes - 190017503
class ComandoRemoverParticipante:public ComandoSQL
{
public:
    ComandoRemoverParticipante(Matricula);
};

// Estudante responsável: Clara Fortes - 190017503
class ComandoCadastrarParticipantePeca:public ComandoSQL
{
public:
    ComandoCadastrarParticipantePeca(Participante);
};

// Estudante responsável: Clara Fortes - 190017503
class ComandoPesquisarParticipantePeca:public ComandoSQL
{
public:
    ComandoPesquisarParticipantePeca(Codigo);
    int getResultado();
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoPesquisarPeca:public ComandoSQL
{
public:
    ComandoPesquisarPeca(Codigo);
    Peca getResultado();
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoAtualizarPeca:public ComandoSQL
{
public:
    ComandoAtualizarPeca(Peca);
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoCadastrarPeca:public ComandoSQL
{
public:
    ComandoCadastrarPeca(Peca);
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoRemoverPeca:public ComandoSQL
{
public:
    ComandoRemoverPeca(Codigo);
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoListarPeca:public ComandoSQL
{
public:
    ComandoListarPeca();
    list<Peca> getResultado();
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoPesquisarSessao:public ComandoSQL
{
public:
    ComandoPesquisarSessao(Codigo);
    Sessao getResultado();
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoAtualizarSessao:public ComandoSQL
{
public:
    ComandoAtualizarSessao(Sessao);
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoCadastrarSessao:public ComandoSQL
{
public:
    ComandoCadastrarSessao(Sessao);
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoRemoverSessao:public ComandoSQL
{
public:
    ComandoRemoverSessao(Codigo);
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoListarSessao:public ComandoSQL
{
public:
    ComandoListarSessao();
    list<Sessao> getResultado();
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoPesquisarSessaoPeca:public ComandoSQL
{
public:
    ComandoPesquisarSessaoPeca(Codigo);
    int getResultado();
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoCadastrarSessaoPeca:public ComandoSQL
{
public:
    ComandoCadastrarSessaoPeca(Sessao);
};

// Estudante responsável: Leandro Bottecchia - 180145169
class ComandoCadastrarSessaoSala:public ComandoSQL
{
public:
    ComandoCadastrarSessaoSala(Sessao);
};

// Estudante responsável: Liz Costato - 180022261
class ComandoPesquisarSala:public ComandoSQL
{
public:
    ComandoPesquisarSala(Codigo);
    Sala getResultado();
};

// Estudante responsável: Liz Costato - 180022261
class ComandoAtualizarSala:public ComandoSQL
{
public:
    ComandoAtualizarSala(Sala);
};

// Estudante responsável: Liz Costato - 180022261
class ComandoCadastrarSala:public ComandoSQL
{
public:
    ComandoCadastrarSala(Sala);
};

// Estudante responsável: Liz Costato - 180022261
class ComandoRemoverSala:public ComandoSQL
{
public:
    ComandoRemoverSala(Codigo);
};

// Estudante responsável: Liz Costato - 180022261
class ComandoListarSala:public ComandoSQL
{
public:
    ComandoListarSala();
    list<Sala> getResultado();
};

#endif // UNIDADEPERSISTENCIA_H_INCLUDED
