#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED
#include <iostream>
#include <string.h>


#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");


//--------------------------------------------------------------------------------------------
// Declara��es de classes controladoras e implementa��es de m�todos.

class CntrApresentacaoControle
{
private:
    Matricula matricula;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoParticipante *cntrApresentacaoParticipante;
    IApresentacaoPeca *cntrApresentacaoPeca;
    IApresentacaoSala *cntrApresentacaoSala;
    IApresentacaoSessao *cntrApresentacaoSessao;
public:
    void executar();
    void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
    void setCntrApresentacaoParticipante(IApresentacaoParticipante*);
    void setCntrApresentacaoPeca(IApresentacaoPeca*);
    void setCntrApresentacaoSala(IApresentacaoSala*);
    void setCntrApresentacaoSessao(IApresentacaoSessao*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr)
{
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoParticipante(IApresentacaoParticipante *cntr)
{
    cntrApresentacaoParticipante = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPeca(IApresentacaoPeca *cntr)
{
    cntrApresentacaoPeca = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoSala(IApresentacaoSala *cntr)
{
    cntrApresentacaoSala = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoSessao(IApresentacaoSessao *cntr)
{
    cntrApresentacaoSessao = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao
{
private:
    IServicoAutenticacao *cntrServicoAutenticacao;
public:
    bool autenticar(Matricula*);
    void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr)
{
    cntrServicoAutenticacao = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoParticipante:public IApresentacaoParticipante
{
private:
    IServicoParticipante *cntrServicoParticipante;
    void cadastrarParticipante();
    void consultarParticipante();
    void editarParticipante();
    void descadastrarParticipante();
public:
    void executar(Matricula);
    void executar();
    void setCntrServicoParticipante(IServicoParticipante*);
};

inline void CntrApresentacaoParticipante::setCntrServicoParticipante(IServicoParticipante *cntr)
{
    cntrServicoParticipante = cntr;
}
//--------------------------------------------------------------------------------------------

class CntrApresentacaoSala:public IApresentacaoSala
{
private:
    IServicoSala *cntrServicoSala;
    void listarSala();
    void incluirSala();
    void excluirSala();
    void editarSala();
    void visualizarSala();
public:
    void executar(Matricula);
    void executar();
    void setCntrServicoSala(IServicoSala*);
};

inline void CntrApresentacaoSala::setCntrServicoSala(IServicoSala *cntr)
{
    cntrServicoSala = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoPeca:public IApresentacaoPeca
{
private:
    IServicoPeca *cntrServicoPeca;
    void listarPeca();
    void incluirPeca();
    void excluirPeca();
    void editarPeca();
    void visualizarPeca();
public:
    void executar(Matricula);
    void executar();
    void setCntrServicoPeca(IServicoPeca*);
};

inline void CntrApresentacaoPeca::setCntrServicoPeca(IServicoPeca *cntr)
{
    cntrServicoPeca = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoSessao:public IApresentacaoSessao
{
private:
    IServicoSessao *cntrServicoSessao;
    void listarSessao();
    void incluirSessao();
    void excluirSessao();
    void editarSessao();
    void visualizarSessao();
public:
    void executar(Matricula);
    void executar();
    void setCntrServicoSessao(IServicoSessao*);
};

inline void CntrApresentacaoSessao::setCntrServicoSessao(IServicoSessao *cntr)
{
    cntrServicoSessao = cntr;
}


#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
