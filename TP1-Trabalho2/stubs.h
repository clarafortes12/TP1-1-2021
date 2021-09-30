#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "Interfaces.h"
#include <stdexcept>
#include <iostream>

using namespace std;

//----------------------------------------------------------------------------
// Declara��o de stub que implementa interface da camada de servi�o.

class StubISAutenticacao:public ISAutenticacao{
public:

    // Defini��es de valores a serem usados como gatilhos para notifica��es de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    // Declara��o de m�todo relacionado na interface.

    bool autenticar(const Matricula&, const Senha&) ;
};

//----------------------------------------------------------------------------
// Declara��o de stub que implementa interface da camada de servi�o.

class StubISGerente:public ISGerente{
public:

    // Defini��es de valores a serem usados como gatilhos para notifica��es de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    // Declara��es de m�todos relacionados na interface.

    bool incluir(const Gerente&);
    bool remover(const Matricula&);
    bool pesquisar(Gerente&);
    bool editar(const Gerente&);
};

class StubISPeca:public ISPeca{
public:

    // Defini��es de valores a serem usados como gatilhos para notifica��es de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    // Declara��es de m�todos relacionados na interface.

    bool incluir(const Peca&);
    bool remover(const Matricula&);
    bool pesquisar(Peca&);
    bool editar(const Peca&);
};

#endif // STUBS_H_INCLUDED
