#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"
#include "entidades.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

//----------------------------------------------------------------------------
// Declara��es de comandos.

class ComandoIAGerente {
public:
    virtual void executar(ISGerente*) = 0;             // M�todo por meio do qual � solicitada a execu��o do comando.
    virtual ~ComandoIAGerente(){}                       // M�todo destrutor virtual.
};

//----------------------------------------------------------------------------

class ComandoIAGerenteIncluir:public ComandoIAGerente {
public:
    void executar(ISGerente*);
};

//----------------------------------------------------------------------------

class ComandoIAGerenteRemover:public ComandoIAGerente {
    void executar(ISGerente*);
};

//----------------------------------------------------------------------------

class ComandoIAGerentePesquisar:public ComandoIAGerente {
    void executar(ISGerente*);
};

//----------------------------------------------------------------------------

class ComandoIAGerenteEditar:public ComandoIAGerente {
    void executar(ISGerente*);
};


class ComandoIAPeca {
public:
    virtual void executar(ISPeca*) = 0;             // M�todo por meio do qual � solicitada a execu��o do comando.
    virtual ~ComandoIAPeca(){}                       // M�todo destrutor virtual.
};

//----------------------------------------------------------------------------

class ComandoIAPecaIncluir:public ComandoIAPeca {
public:
    void executar(ISPeca*);
};

//----------------------------------------------------------------------------

class ComandoIAPecaRemover:public ComandoIAPeca {
    void executar(ISPeca*);
};

//----------------------------------------------------------------------------

class ComandoIAPecaPesquisar:public ComandoIAPeca {
    void executar(ISPeca*);
};

//----------------------------------------------------------------------------

class ComandoIAGerenteEditar:public ComandoIAPeca {
    void executar(ISPeca*);
};


#endif // COMANDOS_H_INCLUDED

