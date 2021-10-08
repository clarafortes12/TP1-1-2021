
#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"


//--------------------------------------------------------------------------------------------
// Declara��es de classes controladoras da camada de servi�os.
//
// Falta implementar c�digos.

class CntrServicoAutenticacao:public IServicoAutenticacao{

};

//--------------------------------------------------------------------------------------------


class CntrServicoParticipante:public IServicoParticipante{
    public:
        bool consultarParticipante(Participante*);
        bool executarParticipante(Participante*);
        bool cadastrarParticipante(Participante);
        bool editarParticipante(Participante*);
        bool descadastrarParticipante(Participante*); //trocar o parametro para matricula
};


//--------------------------------------------------------------------------------------------

class CntrServicoPeca:public IServicoPeca{
    public:
        bool listarPeca();
        bool visualizarPeca(Codigo);
        bool incluirPeca(Peca);
        bool editarPeca(Peca);
        bool excluirPeca(Codigo);
};


//--------------------------------------------------------------------------------------------

class CntrServicoSala:public IServicoSala{
    public:
        bool listarSala();
        bool visualizarSala(Codigo);
        bool incluirSala(Sala);
        bool editarSala(Sala);
        bool excluirSala(Codigo);
};

//--------------------------------------------------------------------------------------------

class CntrServicoSessao:public IServicoSessao{
    public:
        bool listarSessao();
        bool visualizarSessao(Codigo);
        bool incluirSessao(Sessao);
        bool editarSessao(Sessao);
        bool excluirSessao(Codigo);
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
