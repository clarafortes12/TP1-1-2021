#ifndef UnidadePersistenciaH
#define UnidadePersistenciaH

//---------------------------------------------------------------------------
// Incluir cabeçalhos.

#include "Dominios.h"
#include "Entidades.h"

#include <list>

//#include <iostream>
//#include <conio.h>
#include <string>
//#include <stdio.h>

#include "sqlite3.h"            // Incluir cabeçalho da biblioteca SQLite.

using namespace std;

//---------------------------------------------------------------------------
// Declaração da classe EErroPersistencia.

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};

//---------------------------------------------------------------------------
// Declaração da classe ElementoResultado.

class ElementoResultado {
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
// Declaração da classe ComandoSQL.

class ComandoSQL {
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
        ComandoSQL() {
             nomeBancoDados = "testedb.db";                             // Nome do banco de dados.
        }
        void executar();
};

//---------------------------------------------------------------------------
// Declaração da classe ComandoLerSenha.

class ComandoLerSenha:public ComandoSQL {
public:
        ComandoLerSenha(Matricula);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarSala.

class ComandoPesquisarSala:public ComandoSQL {
public:
        ComandoPesquisarSala(Codigo);
        Sala getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarSala.

class ComandoAtualizarSala:public ComandoSQL {
public:
        ComandoAtualizarSala(Sala);
};

//---------------------------------------------------------------------------
// Declaração da classe ComandoCadastrarSala.

class ComandoCadastrarSala:public ComandoSQL {
public:
        ComandoCadastrarSala(Sala);
};

//---------------------------------------------------------------------------
// Declaração da classe ComandoRemoverSala.

class ComandoRemoverSala:public ComandoSQL {
public:
        ComandoRemoverSala(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarAluno.

class ComandoPesquisarParticipante:public ComandoSQL {
public:
        ComandoPesquisarParticipante(Matricula);
        Participante getResultado();
};

//---------------------------------------------------------------------------
// Declaração da classe ComandoCadastrarAluno.

class ComandoCadastrarParticipante:public ComandoSQL {
public:
        ComandoCadastrarParticipante(Participante);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarAluno.

class ComandoAtualizarParticipante:public ComandoSQL {
public:
        ComandoAtualizarParticipante(Participante);
};

//---------------------------------------------------------------------------
// Declaração da classe ComandoRemoverAluno.

class ComandoRemoverParticipante:public ComandoSQL {
public:
        ComandoRemoverParticipante(Matricula);
};

//---------------------------------------------------------------------------
// Implementações de métodos.

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}

#endif

