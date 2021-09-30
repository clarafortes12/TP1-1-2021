
#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

//-----------------------------------------------------------------------------------
// Declarações adiantadas (forward declaration).

class ISAutenticacao;
class ISGerente;

//-----------------------------------------------------------------------------------
// Declaração de interface da camada de apresentação.

class IAAutenticacao {
public:
    virtual bool autenticar(Matricula*) = 0;                        // Método por meio do qual é solicitado o serviço.
    virtual void setCntrISAutenticacao(ISAutenticacao *) = 0;       // Método para estabelecer ligação (link) com a controladora na camada de serviço.
    virtual ~IAAutenticacao(){}                                     // Método destrutor virtual.
};

//-----------------------------------------------------------------------------------
// Declaração de interface da camada de serviço.

class ISAutenticacao {
public:
    virtual bool autenticar(const Matricula&, const Senha&) = 0;    // Método por meio do qual é solicitado o serviço.
    virtual ~ISAutenticacao(){}                                     // Método destrutor virtual.
};

//-----------------------------------------------------------------------------------
// Declaração de interface da camada de apresentação.

class IAGerente {
public:
    virtual void executar(const Matricula&) = 0;                    // Método por meio do qual é solicitado o serviço.
    virtual void setCntrISGerente(ISGerente *) = 0;                 // Método para estabelecer ligação (link) com a controladora de serviço.
    virtual ~IAGerente(){}                                          // Método destrutor virtual.
};

//-----------------------------------------------------------------------------------
// Declaração de interface da camada de serviço

class ISGerente {
public:

    // Métodos por meio dos quais são solicitados os serviços.

    virtual bool incluir(const Gerente&) = 0;
    virtual bool remover(const Matricula&) = 0;
    virtual bool pesquisar(Gerente&) = 0;
    virtual bool editar(const Gerente&) = 0;

    virtual ~ISGerente(){}                                         // Método destrutor virtual.
};


class IAPeca {
public:
    virtual void executar(const Matricula&) = 0;                    // Método por meio do qual é solicitado o serviço.
    virtual void setCntrISPeca(ISPeca *) = 0;                 // Método para estabelecer ligação (link) com a controladora de serviço.
    virtual ~IAPeca(){}                                          // Método destrutor virtual.
};

class ISPeca {
public:

    // Métodos por meio dos quais são solicitados os serviços.

    virtual bool cadastrar(const Peca&) = 0;
    virtual bool descadastrar(const Matricula&) = 0;
    virtual bool listar(Peca&) = 0;
    virtual bool alterar(const Peca&) = 0;

    virtual ~ISPeca(){}                                         // Método destrutor virtual.
};

class IASala {
public:
    virtual void executar(const Matricula&) = 0;                    // Método por meio do qual é solicitado o serviço.
    virtual void setCntrISSala(ISSala *) = 0;                 // Método para estabelecer ligação (link) com a controladora de serviço.
    virtual ~IAPeca(){}                                          // Método destrutor virtual.
};

class ISSala {
public:

    // Métodos por meio dos quais são solicitados os serviços.

    virtual bool cadastrar(const Sala&) = 0;
    virtual bool descadastrar(const Matricula&) = 0;
    virtual bool listar(Sala&) = 0;
    virtual bool alterar(const Sala&) = 0;

    virtual ~ISSala(){}                                         // Método destrutor virtual.
};

#endif // INTERFACES_H_INCLUDED
