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
    const string VALOR_VALIDO1   = "AB1234";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_VALIDO2   = "O Fantasma Da Opera";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_VALIDO3   = "musical";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_VALIDO4   = "12";   // Defini��o de constante para evitar n�mero m�gico.

    Peca *peca;                       // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};

//sessao
class TUSessao {
private:
    const string VALOR_VALIDO1   = "AB1234";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_VALIDO2   = "03:45";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_VALIDO3   = "11/08/2021";   // Defini��o de constante para evitar n�mero m�gico.

    Sessao *sessao;                       // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};

// -------------------------------------------------------
// Teste da Liz - 180022261

//sala
class TUSala {
private:
    const string VALOR_VALIDO_CODIGO   = "AC4321";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_VALIDO_NOME   = "Liz.Costato";   // Defini��o de constante para evitar n�mero m�gico.
    const int VALOR_VALIDO_CAPACIDADE   = 100;   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO_CODIGO   = "1C4321";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO_NOME   = "Liz  Costato";   // Defini��o de constante para evitar n�mero m�gico.
    const int VALOR_INVALIDO_CAPACIDADE   = 150;   // Defini��o de constante para evitar n�mero m�gico.

    Sala *sala;                             // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};

// -------------------------------------------------------
// Testes da Clara - 190017503

//------------ Participante
class TUParticipante {
    private:
        const string VALOR_VALIDO_MATRICULA = "12345";
        const string VALOR_INVALIDO_MATRICULA = "12245";
        const string VALOR_VALIDO_NOME   = "Maria";
        const string VALOR_INVALIDO_NOME   = "Liz";
        const string VALOR_VALIDO_SOBRENOME   = "Fortes";
        const string VALOR_INVALIDO_SOBRENOME   = ".Fortes";
        const string VALOR_VALIDO_EMAIL   = "pessoa@hotmail.com";
        const string VALOR_INVALIDO_EMAIL   = "pessoahotmail.com";
        const string VALOR_VALIDO_TELEFONE   = "(61)-982277718";
        const string VALOR_INVALIDO_TELEFONE   = "(09)-000000000";
        const string VALOR_VALIDO_SENHA   = "Abc1Df$2";
        const string VALOR_INVALIDO_SENHA   = "AAAA1BBB";
        const string VALOR_VALIDO_CARGO  = "ator";
        const string VALOR_INVALIDO_CARGO   = "atoor";

        Participante *participante;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO =  0;
        const static int FALHA   = -1;
        int run();
};

#endif // TESTE_ENTIDADES_H_INCLUDED
