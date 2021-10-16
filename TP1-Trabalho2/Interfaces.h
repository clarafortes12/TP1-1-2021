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

// Estudante responsável: Liz Costato - 180022261
class IApresentacaoAutenticacao
{
public:
    virtual bool autenticar(Matricula*) = 0;
    virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
    virtual ~IApresentacaoAutenticacao() {}
};

// Estudante responsável: Clara Fortes - 190017503
class IApresentacaoParticipante
{
public:
    virtual bool executar(Matricula) = 0;
    virtual void executar() = 0;
    virtual void setCntrServicoParticipante(IServicoParticipante*) = 0;
    virtual ~IApresentacaoParticipante() {}
};

// Estudante responsável: Leandro Bottecchia - 180145169
class IApresentacaoPeca
{
public:
    virtual void executar(Matricula) = 0;
    virtual void executar() = 0;
    virtual void setCntrServicoPeca(IServicoPeca *) = 0;
    virtual ~IApresentacaoPeca() {}
};

// Estudante responsável: Leandro Bottecchia - 180145169
class IApresentacaoSessao
{
public:
    virtual void executar(Matricula) = 0;
    virtual void executar() = 0;
    virtual void setCntrServicoSessao(IServicoSessao *) = 0;
    virtual ~IApresentacaoSessao() {}
};

// Estudante responsável: Liz Costato - 180022261
class IApresentacaoSala
{
public:
    virtual void executar(Matricula) = 0;
    virtual void executar() = 0;
    virtual void setCntrServicoSala(IServicoSala *) = 0;
    virtual ~IApresentacaoSala() {}
};


//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de serviço.

// Estudante responsável: Liz Costato - 180022261
class IServicoAutenticacao
{
public:
    virtual bool autenticar(Matricula, Senha) = 0;
    virtual ~IServicoAutenticacao() {}
};

// Estudante responsável: Clara Fortes - 190017503
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

// Estudante responsável: Leandro Bottecchia - 180145169
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

// Estudante responsável: Leandro Bottecchia - 180145169
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

// Estudante responsável: Liz Costato - 180022261
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
