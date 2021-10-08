
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
        bool descadastrarParticipante(Participante*);
};


//--------------------------------------------------------------------------------------------

class CntrServicoPeca:public IServicoPeca{
    public:
        bool listarPeca(Peca*);
        bool visualizarPeca(Peca*);
        bool incluirPeca(Peca);
        bool editarPeca(Peca*);
        bool excluirPeca(Peca*);
};


//--------------------------------------------------------------------------------------------

class CntrServicoSala:public IServicoSala{
    public:
        bool listarSala(Sala*);
        bool visualizarSala(Sala*);
        bool incluirSala(Sala);
        bool editarSala(Sala*);
        bool excluirSala(Sala*);
};

//--------------------------------------------------------------------------------------------

class CntrServicoSessao:public IServicoSessao{
    public:
        bool listarSessao(Sessao*);
        bool visualizarSessao(Sessao*);
        bool incluirSessao(Sessao);
        bool editarSessao(Sessao*);
        bool excluirSessao(Sessao*);
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
