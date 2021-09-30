#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "dominios.h"

using namespace std;

// EXEMPLO
// --------------------------------------------------------

// Teste de unidade de classe que representa um dom�nio.

class TUCodigo {
private:

    // Defini��es de constantes com o intuito de evitar numeros m�gicos.

    const static int VALOR_VALIDO   = 20;
    const static int VALOR_INVALIDO = 30;

    Codigo *codigo;         // Refer�ncia para o objeto a ser testado.

    int estado;             // Estado do teste.

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
public:

    // Defini��es de constantes para reportar resultado do teste.

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

    int run();
};


#endif // TESTES_H_INCLUDED
