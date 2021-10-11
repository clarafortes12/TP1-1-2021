
#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED


#include <conio.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"
#include "UnidadePersistencia.h"


//---------------------------------------------------------------------------
//Classe CntrInteracao.

class CntrInteracao {
     virtual void apresentarOpcoes() = 0;
public:
     void notificarErroAcesso();
     void notificarErroDigitacao();
     void notificarSucessoOperacao();
     virtual void executar() = 0;
};

//--------------------------------------------------------------------------------------------
// Declara��es de classes controladoras da camada de servi�os.
//
// Falta implementar c�digos.

class CntrServicoAutenticacao:public IServicoAutenticacao{
    bool autenticar(Matricula, Senha);
};

//--------------------------------------------------------------------------------------------


class CntrServicoParticipante:public IServicoParticipante{
    public:
        bool consultarParticipante(Matricula);
        bool cadastrarParticipante(Participante);
        bool editarParticipante(Participante);
        bool descadastrarParticipante(Matricula);
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
