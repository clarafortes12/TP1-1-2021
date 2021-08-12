#ifndef TESTE_ENTIDADES_H_INCLUDED
#define TESTE_ENTIDADES_H_INCLUDED

#include <string>
#include "Dominios.h"
#include "Entidades.h"

// -------------------------------------------------------
// Testes do Leandro - 180145169
//teste Peca
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

//sessao
class TUSessao {
private:
    const string VALOR_VALIDO1   = "AB1234";   // Definição de constante para evitar número mágico.
    const string VALOR_VALIDO2   = "03:45";   // Definição de constante para evitar número mágico.
    const int VALOR_VALIDO3   = 11;   // Definição de constante para evitar número mágico.
    const int VALOR_VALIDO4   = 8;   // Definição de constante para evitar número mágico.
    const int VALOR_VALIDO5   = 2021;   // Definição de constante para evitar número mágico.
    const string VALOR_VALIDO6   = "11/08/2021";   // Definição de constante para evitar número mágico.

    Sessao *sessao;                       // Referência para unidade em teste.
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
// Teste da Liz - 180022261

//sala
class TUSala {
private:
    const string VALOR_VALIDO_CODIGO   = "AC4321";   // Definição de constante para evitar número mágico.
    const string VALOR_VALIDO_NOME   = "Liz.Costato";   // Definição de constante para evitar número mágico.
    const int VALOR_VALIDO_CAPACIDADE   = 100;   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO_CODIGO   = "1C4321";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO_NOME   = "Liz  Costato";   // Definição de constante para evitar número mágico.
    const int VALOR_INVALIDO_CAPACIDADE   = 150;   // Definição de constante para evitar número mágico.

    Sala *sala;                             // Referência para unidade em teste.
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
// Testes da Clara - 190017503


#endif // TESTE_ENTIDADES_H_INCLUDED
