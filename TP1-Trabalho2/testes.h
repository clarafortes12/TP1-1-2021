#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "dominios.h"

using namespace std;

// EXEMPLO
// --------------------------------------------------------

// Teste de unidade de classe que representa um domínio.

class TUCodigo {
private:

    // Definições de constantes com o intuito de evitar numeros mágicos.

    const static int VALOR_VALIDO   = 20;
    const static int VALOR_INVALIDO = 30;

    Codigo *codigo;         // Referência para o objeto a ser testado.

    int estado;             // Estado do teste.

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
public:

    // Definições de constantes para reportar resultado do teste.

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

    int run();
};


#endif // TESTES_H_INCLUDED
