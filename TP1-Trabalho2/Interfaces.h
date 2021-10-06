#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
// Adequar as declara��es das interfaces de acordo com as necessidades.
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

// Forward declarations.

class IServicoAutenticacao;
class IServicoParticipante;
class IServicoPeca;
class IServicoSessao;
class IServicoSala;

//--------------------------------------------------------------------------------------------
// Declara��es das interfaces da camada de apresenta��o.

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Matricula*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoParticipante{
    public:
        virtual void executar(Matricula) = 0;
        virtual void cadastrar() = 0;
        virtual void setCntrServicoParticipantes(IServicoParticipantes*) = 0;
        virtual ~IApresentacaoParticipantes(){}
};

class IApresentacaoPeca {
public:
    virtual void executar(const Matricula&) = 0;
    virtual void executar() = 0;
    virtual void setCntrServicoPeca(IServicoPeca *) = 0;
    virtual ~IApresentacaoPeca(){}
};

class IApresentacaoSala {
public:
    virtual void executar(const Matricula&) = 0;
    virtual void executar() = 0;
    virtual void setCntrServicoSala(IServicoSala *) = 0;
    virtual ~IApresentacaoSala(){}
};

class IApresentacaoSessao {
public:
    virtual void executar(const Matricula&) = 0;
    virtual void executar() = 0;
    virtual void setCntrServicoSessao(IServicoPeca *) = 0;
    virtual ~IApresentacaoSessao(){}
};

//--------------------------------------------------------------------------------------------
// Declara��es das interfaces da camada de servi�o.

class IServicoAutenticacao {
    public:
        virtual bool autenticar(Matricula, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoParticipante{
public:
        virtual bool cadastrar(Participante) = 0;
        virtual bool editar(Participante*) = 0;
        virtual bool excluir(Participante*) = 0;
        virtual ~IServicoParticipante(){}
};

class IServicoPeca{
public:
    virtual bool incluir(Peca) = 0;
    virtual bool excluir(Peca*) = 0;
    virtual bool listar() = 0;
    virtual bool editar(Peca*) = 0;
    virtual bool visualizar(Peca*) = 0;
    virtual ~IServicoPeca(){}
};

class IServicoSessao{
public:
    virtual bool incluir(Sessao) = 0;
    virtual bool excluir(Sessao*) = 0;
    virtual bool listar() = 0;
    virtual bool editar(Sessao*) = 0;
    virtual bool visualizar(Sessao*) = 0;
    virtual ~IServicoSessao(){}
};

class IServicoSala{
public:
    virtual bool listar() = 0;
    virtual bool incluir(Sala) = 0;
    virtual bool excluir(Sala*) = 0;
    virtual bool editar(Sala*) = 0; // O prof costuma colocar o objeto Sala, como se passasse todo um novo objeto ao alterar, mas acho melhor ser pelo endere�o, n?
    virtual bool visualizar(Sala*) = 0;
    virtual ~IServicoSala(){}
};

#endif // INTERFACES_H_INCLUDED
