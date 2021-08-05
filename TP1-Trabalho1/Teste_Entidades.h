#ifndef TESTE_ENTIDADES_H_INCLUDED
#define TESTE_ENTIDADES_H_INCLUDED

#include <string>
#include "Dominios.h"
#include "Entidades.h"

// -------------------------------------------------------
// Testes do Leandro - 180145169
class TUPeca {
private:
    const string VALOR_VALIDO1   = "AB1234";   // Definição de constante para evitar número mágico.
    const string VALOR_VALIDO2   = "O Fantasma Da Opera";   // Definição de constante para evitar número mágico.
    const string VALOR_VALIDO3   = "musical";   // Definição de constante para evitar número mágico.
    const string VALOR_VALIDO4   = "12";   // Definição de constante para evitar número mágico.

    Peca *peca;                       // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

// -------------------------------------------------------
// Testes da Liz - 180022261

// -------------------------------------------------------
// Testes da Clara - 190017503


#endif // TESTE_ENTIDADES_H_INCLUDED
