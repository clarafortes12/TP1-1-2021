#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "Interfaces.h"
#include <stdexcept>
#include <iostream>

using namespace std;

//----------------------------------------------------------------------------
// Declaração de stub que implementa interface da camada de serviço.

class StubISAutenticacao:public ISAutenticacao{
public:

    // Definições de valores a serem usados como gatilhos para notificações de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    // Declaração de método relacionado na interface.

    bool autenticar(const Matricula&, const Senha&) ;
};

//----------------------------------------------------------------------------
// Declaração de stub que implementa interface da camada de serviço.

class StubISGerente:public ISGerente{
public:

    // Definições de valores a serem usados como gatilhos para notificações de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    // Declarações de métodos relacionados na interface.

    bool incluir(const Gerente&);
    bool remover(const Matricula&);
    bool pesquisar(Gerente&);
    bool editar(const Gerente&);
};

class StubISPeca:public ISPeca{
public:

    // Definições de valores a serem usados como gatilhos para notificações de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    // Declarações de métodos relacionados na interface.

    bool incluir(const Peca&);
    bool remover(const Matricula&);
    bool pesquisar(Peca&);
    bool editar(const Peca&);
};

#endif // STUBS_H_INCLUDED
