
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
};

class CntrServicoParticipante:public IServicoParticipante{
    public:
        void consultarParticipante(Participante*);
        void executarParticipante(Participante*);
        void cadastrarParticipante(Participante);
        void editarParticipante(Participante*);
        void descadastrarParticipante(Participante*);
};

inline void CntrApresentacaoParticipante::setCntrServicoParticipante(IServicoParticipante *cntr){
    cntrServicoParticipante = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrServicoPeca:public IServicoPeca{
};

//--------------------------------------------------------------------------------------------

class CntrServicoSala:public IServicoSala{
};

//--------------------------------------------------------------------------------------------

class CntrServicoSessao:public IServicoSessao{
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
