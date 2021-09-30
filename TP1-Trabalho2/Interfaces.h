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
class IServicoPessoal;
class IServicoPeca;
class IServicoProdutosFinanceiros;

//--------------------------------------------------------------------------------------------
// Declara��es das interfaces da camada de apresenta��o.

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(CPF*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoPessoal{
    public:
        virtual void executar(CPF) = 0;
        virtual void cadastrar() = 0;
        virtual void setCntrServicoPessoal(IServicoPessoal*) = 0;
        virtual void setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros*) = 0;
        virtual ~IApresentacaoPessoal(){}
};

class IApresentacaoPeca {
public:
    virtual void executar(const Matricula&) = 0;                 // M�todo por meio do qual � solicitado o servi�o.
    virtual void executar() = 0;
    virtual void setCntrServicoPeca(IServicoPeca *) = 0;         // M�todo para estabelecer liga��o (link) com a controladora de servi�o.
    virtual ~IApresentacaoPeca(){}                                          // M�todo destrutor virtual.
};

class IApresentacaoSala {
public:
    virtual void executar(const Matricula&) = 0;                 // M�todo por meio do qual � solicitado o servi�o.
    virtual void executar() = 0;
    virtual void setCntrServicoSala(IServicoSala *) = 0;         // M�todo para estabelecer liga��o (link) com a controladora de servi�o.
    virtual ~IApresentacaoSala(){}                                          // M�todo destrutor virtual.
};

class IApresentacaoProdutosFinanceiros{
    public:
        virtual void executar() = 0;
        virtual void executar(CPF) = 0;
        virtual void setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros*) = 0;
        virtual ~IApresentacaoProdutosFinanceiros(){}
};

//--------------------------------------------------------------------------------------------
// Declara��es das interfaces da camada de servi�o.

class IServicoAutenticacao {
    public:
        virtual bool autenticar(CPF, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoPessoal{
public:
        virtual bool cadastrarUsuario(Usuario) = 0;
        virtual ~IServicoPessoal(){}
};

class IServicoPeca{
public:

    // M�todos por meio dos quais s�o solicitados os servi�os.

    virtual bool cadastrar(const Peca&) = 0;
    virtual bool descadastrar(const Matricula&) = 0;
    virtual bool listar(Peca&) = 0;
    virtual bool alterar(const Peca&) = 0;
    virtual ~IServicoPeca(){}                                         // M�todo destrutor virtual.
};

class IServicoSala{
public:

    // M�todos por meio dos quais s�o solicitados os servi�os.

    virtual bool listar() = 0;
    virtual bool incluir(Sala) = 0;
    virtual bool excluir(Sala*) = 0;
    virtual bool editar(Sala*) = 0; // O prof costuma colocar o objeto Sala, como se passasse todo um novo objeto ao alterar, mas acho melhor ser pelo endere�o, n?
    virtual bool visualizar(Sala*) = 0;
    virtual ~IServicoSala(){}                                         // M�todo destrutor virtual.
};

class IServicoProdutosFinanceiros{
public:
        virtual bool cadastrarConta(Conta) = 0;
        virtual bool consultarConta(Conta*) = 0;
        virtual bool cadastrarProdutoInvestimento(Produto) = 0;
        virtual bool descadastrarProdutoInvestimento(Codigo) = 0;
        virtual bool realizarAplicacao(Aplicacao) = 0;
        virtual bool recuperarAplicacao(Aplicacao*) = 0;                        // Adaptar aos requisitos.
        virtual ~IServicoProdutosFinanceiros(){}
};

#endif // INTERFACES_H_INCLUDED
