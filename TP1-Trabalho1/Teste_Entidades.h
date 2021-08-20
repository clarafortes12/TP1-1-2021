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
    const string VALOR_VALIDO_CODIGO   = "AB1234";   
    const string VALOR_VALIDO_HORARIO   = "O Fantasma Da Opera";   
    const string VALOR_VALIDO_TIPO   = "musical";   
    const string VALOR_VALIDO_CLASSIFICACAO   = "12";   

    Peca *peca;                       
    int estado;                             
    void setUp();                           
    void tearDown();                        
    void testarCenarioSucesso();            
public:
    const static int SUCESSO =  0;          
    const static int FALHA   = -1;          
    int run();                              
};

// Testes do Leandro - 180145169
//sessao
class TUSessao {
private:
    const string VALOR_VALIDO_CODIGO   = "AB1234";   
    const string VALOR_VALIDO_HORARIO   = "03:45";   
    const string VALOR_VALIDO_DATA   = "11/08/2021";   

    Sessao *sessao;                       
    int estado;                             
    void setUp();                           
    void tearDown();                        
    void testarCenarioSucesso();            
public:
    const static int SUCESSO =  0;          
    const static int FALHA   = -1;          
    int run();                              
};

// -------------------------------------------------------
// Teste da Liz - 180022261

//sala
class TUSala {
private:
    const string VALOR_VALIDO_CODIGO   = "AC4321";   
    const string VALOR_VALIDO_NOME   = "Liz.Costato";   
    const int VALOR_VALIDO_CAPACIDADE   = 100; 

    Sala *sala;                             
    int estado;                             
    void setUp();                           
    void tearDown();                        
    void testarCenarioSucesso();            
public:
    const static int SUCESSO =  0;          
    const static int FALHA   = -1;          
    int run();                              
};

// -------------------------------------------------------
// Testes da Clara - 190017503

//------------ Participante
class TUParticipante {
    private:
        const string VALOR_VALIDO_MATRICULA = "12345";
        const string VALOR_VALIDO_NOME   = "Maria";
        const string VALOR_VALIDO_SOBRENOME   = "Fortes";
        const string VALOR_VALIDO_EMAIL   = "pessoa@hotmail.com";
        const string VALOR_VALIDO_TELEFONE   = "(61)-982277718";
        const string VALOR_VALIDO_SENHA   = "Abc1Df$2";
        const string VALOR_VALIDO_CARGO  = "ator";

        Participante *participante;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
    public:
        const static int SUCESSO =  0;
        const static int FALHA   = -1;
        int run();
};

#endif
