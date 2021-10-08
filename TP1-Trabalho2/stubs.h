#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Classe stub do servi�o autentica��o.

class StubServicoAutenticacao:public IServicoAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(Matricula, Senha);
};

//--------------------------------------------------------------------------------------------
// Classe stub do servi�o participante.

class StubServicoParticipante:public IServicoParticipante {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarParticipante(Participante);
        bool consultarParticipante(Matricula);
        bool editarParticipante(Participante);
        bool descadastrarParticipante(Matricula);
};

//--------------------------------------------------------------------------------------------
// Classe stub do servi�o pe�a.

class StubServicoPeca:public IServicoPeca {
    private:
        static const string INVALIDO;
    public:
        bool incluirPeca(Peca);
        bool visualizarPeca(Codigo);
        bool editarPeca(Peca);
        bool excluirPeca(Codigo);
        bool listarPeca();
};

//--------------------------------------------------------------------------------------------
// Classe stub do servi�o sala.

class StubServicoSala:public IServicoSala {
    private:
        static const string INVALIDO;
    public:
        bool incluirSala(Sala);
        bool visualizarSala(Codigo);
        bool editarSala(Sala);
        bool excluirSala(Codigo);
        bool listarSala();
};

//--------------------------------------------------------------------------------------------
// Classe stub do servi�o sess�o.

class StubServicoSessao:public IServicoSessao {
    private:
        static const string INVALIDO;
    public:
        bool incluirSessao(Sessao);
        bool visualizarSessao(Codigo);
        bool editarSessao(Sessao);
        bool excluirSessao(Codigo);
        bool listarSessao();
};

#endif // STUBS_H_INCLUDED
