
#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

//-----------------------------------------------------------------------------------
// Declara��es adiantadas (forward declaration).

class ISAutenticacao;
class ISGerente;

//-----------------------------------------------------------------------------------
// Declara��o de interface da camada de apresenta��o.

class IAAutenticacao {
public:
    virtual bool autenticar(Matricula*) = 0;                        // M�todo por meio do qual � solicitado o servi�o.
    virtual void setCntrISAutenticacao(ISAutenticacao *) = 0;       // M�todo para estabelecer liga��o (link) com a controladora na camada de servi�o.
    virtual ~IAAutenticacao(){}                                     // M�todo destrutor virtual.
};

//-----------------------------------------------------------------------------------
// Declara��o de interface da camada de servi�o.

class ISAutenticacao {
public:
    virtual bool autenticar(const Matricula&, const Senha&) = 0;    // M�todo por meio do qual � solicitado o servi�o.
    virtual ~ISAutenticacao(){}                                     // M�todo destrutor virtual.
};

//-----------------------------------------------------------------------------------
// Declara��o de interface da camada de apresenta��o.

class IAGerente {
public:
    virtual void executar(const Matricula&) = 0;                    // M�todo por meio do qual � solicitado o servi�o.
    virtual void setCntrISGerente(ISGerente *) = 0;                 // M�todo para estabelecer liga��o (link) com a controladora de servi�o.
    virtual ~IAGerente(){}                                          // M�todo destrutor virtual.
};

//-----------------------------------------------------------------------------------
// Declara��o de interface da camada de servi�o

class ISGerente {
public:

    // M�todos por meio dos quais s�o solicitados os servi�os.

    virtual bool incluir(const Gerente&) = 0;
    virtual bool remover(const Matricula&) = 0;
    virtual bool pesquisar(Gerente&) = 0;
    virtual bool editar(const Gerente&) = 0;

    virtual ~ISGerente(){}                                         // M�todo destrutor virtual.
};


class IAPeca {
public:
    virtual void executar(const Matricula&) = 0;                    // M�todo por meio do qual � solicitado o servi�o.
    virtual void setCntrISPeca(ISPeca *) = 0;                 // M�todo para estabelecer liga��o (link) com a controladora de servi�o.
    virtual ~IAPeca(){}                                          // M�todo destrutor virtual.
};

class ISPeca {
public:

    // M�todos por meio dos quais s�o solicitados os servi�os.

    virtual bool cadastrar(const Peca&) = 0;
    virtual bool descadastrar(const Matricula&) = 0;
    virtual bool listar(Peca&) = 0;
    virtual bool alterar(const Peca&) = 0;

    virtual ~ISPeca(){}                                         // M�todo destrutor virtual.
};

class IASala {
public:
    virtual void executar(const Matricula&) = 0;                    // M�todo por meio do qual � solicitado o servi�o.
    virtual void setCntrISSala(ISSala *) = 0;                 // M�todo para estabelecer liga��o (link) com a controladora de servi�o.
    virtual ~IAPeca(){}                                          // M�todo destrutor virtual.
};

class ISSala {
public:

    // M�todos por meio dos quais s�o solicitados os servi�os.

    virtual bool cadastrar(const Sala&) = 0;
    virtual bool descadastrar(const Matricula&) = 0;
    virtual bool listar(Sala&) = 0;
    virtual bool alterar(const Sala&) = 0;

    virtual ~ISSala(){}                                         // M�todo destrutor virtual.
};

#endif // INTERFACES_H_INCLUDED
