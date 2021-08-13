#ifndef TESTE_DOMINIOS_H_INCLUDED
#define TESTE_DOMINIOS_H_INCLUDED

#include <string>
#include "Dominios.h"

// -------------------------------------------------------
// Testes do Leandro - 180145169

//Capacidade
class TUCapacidade {
private:
    const static int VALOR_VALIDO   = 200;   // Definição de constante para evitar número mágico.
    const static int VALOR_INVALIDO = 350;   // Definição de constante para evitar número mágico.
    Capacidade *capacidade;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

//Horario
class TUHorario {
private:
    const string VALOR_VALIDO   = "12:15";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "48:32";   // Definição de constante para evitar número mágico.
    Horario *horario;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

//Senha
class TUSenha {
private:
    const string VALOR_VALIDO   = "Abc1Df$2";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "AAAA1BBB";   // Definição de constante para evitar número mágico.
    Senha *senha;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

//Telefone
class TUTelefone {
private:
    const string VALOR_VALIDO   = "(61)-982277718";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "(09)-000000000";   // Definição de constante para evitar número mágico.
    Telefone *telefone;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

// -------------------------------------------------------
// Testes da Liz - 180022261

//Cargo
class TUCargo {
private:
    const string VALOR_VALIDO   = "ator";    // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "atoor";   // Definição de constante para evitar número mágico.
    Cargo *cargo;                                // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

//Horario
class TUMatricula {
private:
    const string VALOR_VALIDO   = "12345";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "12245";   // Definição de constante para evitar número mágico.
    Matricula *matricula;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

//Nome
class TUNome {
private:
    const string VALOR_VALIDO   = "Liz Costato";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = ".Liz  Costato";   // Definição de constante para evitar número mágico.
    Nome *nome;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

//Data
class TUData {
private:
    const string VALOR_VALIDO   = "02/09/2005";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "03/08/1900";   // Definição de constante para evitar número mágico.
    Data *data;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

// -------------------------------------------------------
// Testes da Clara - 190017503


#endif // TESTE_DOMINIOS_H_INCLUDED
