
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

class CntrServicoPeca:public IServicoPeca{
    public:
        void listarPeca(Peca*);
        void visualizarPeca(Peca*);
        void incluirPeca(Peca);
        void editarPeca(Peca*);
        void excluirPeca(Peca*);
};

inline void CntrApresentacaoPeca::setCntrServicoPeca(IServicoPeca *cntr){
    cntrServicoPeca = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrServicoSala:public IServicoSala{
};

//--------------------------------------------------------------------------------------------

class CntrServicoSessao:public IServicoSessao{
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
