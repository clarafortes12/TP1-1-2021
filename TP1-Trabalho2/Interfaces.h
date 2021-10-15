#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "Dominios.h"
#include "Entidades.h"

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
// Adequar as declarações das interfaces de acordo com as necessidades.
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

// Forward declarations.

class IServicoAutenticacao;
class IServicoParticipante;
class IServicoPeca;
class IServicoSala;
class IServicoSessao;

//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de apresentação.

class IApresentacaoAutenticacao
{
public:
    virtual bool autenticar(Matricula*) = 0;
    virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
    virtual ~IApresentacaoAutenticacao() {}
};

class IApresentacaoParticipante
{
public:
    virtual bool executar(Matricula) = 0;
    virtual void executar() = 0;
    virtual void setCntrServicoParticipante(IServicoParticipante*) = 0;
    virtual ~IApresentacaoParticipante() {}
};

class IApresentacaoPeca
{
public:
    virtual void executar(Matricula) = 0;
    virtual void executar() = 0;
    virtual void setCntrServicoPeca(IServicoPeca *) = 0;
    virtual ~IApresentacaoPeca() {}
};

class IApresentacaoSala
{
public:
    virtual void executar(Matricula) = 0;
    virtual void executar() = 0;
    virtual void setCntrServicoSala(IServicoSala *) = 0;
    virtual ~IApresentacaoSala() {}
};

class IApresentacaoSessao
{
public:
    virtual void executar(Matricula) = 0;
    virtual void executar() = 0;
    virtual void setCntrServicoSessao(IServicoSessao *) = 0;
    virtual ~IApresentacaoSessao() {}
};

//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de serviço.

class IServicoAutenticacao
{
public:
    virtual bool autenticar(Matricula, Senha) = 0;
    virtual ~IServicoAutenticacao() {}
};

class IServicoParticipante{
public:
    virtual bool cadastrarParticipante(Participante) = 0;
    virtual bool consultarParticipante(Matricula) = 0;
    virtual bool editarParticipante(Participante) = 0;
    virtual bool descadastrarParticipante(Matricula) = 0;
    virtual bool cadastrarParticipantePeca(Participante) = 0;
    virtual int pesquisarParticipantePeca(Codigo) = 0;
    virtual ~IServicoParticipante() {}
};

class IServicoPeca
{
public:
    virtual bool incluirPeca(Peca) = 0;
    virtual bool excluirPeca(Codigo) = 0;
    virtual bool listarPeca() = 0;
    virtual bool editarPeca(Peca) = 0;
    virtual bool visualizarPeca(Codigo) = 0;
    virtual ~IServicoPeca() {}
};

class IServicoSessao
{
public:
    virtual bool incluirSessao(Sessao) = 0;
    virtual bool excluirSessao(Codigo) = 0;
    virtual bool listarSessao() = 0;
    virtual bool editarSessao(Sessao) = 0;
    virtual bool visualizarSessao(Codigo) = 0;
    virtual bool cadastrarSessaoPeca(Sessao) = 0;
    virtual bool cadastrarSessaoSala(Sessao) = 0;
    //virtual int pesquisarSessaoPeca(Codigo) = 0;
    //virtual int pesquisarSessaoSala(Codigo) = 0;
    virtual ~IServicoSessao() {}
};

class IServicoSala
{
public:
    virtual bool incluirSala(Sala) = 0;
    virtual bool excluirSala(Codigo) = 0;
    virtual bool listarSala() = 0;
    virtual bool editarSala(Sala) = 0;
    virtual bool visualizarSala(Codigo) = 0;
    virtual ~IServicoSala() {}
};

#endif // INTERFACES_H_INCLUDED
