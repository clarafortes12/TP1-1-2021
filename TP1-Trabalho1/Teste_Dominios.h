#ifndef TESTE_DOMINIOS_H_INCLUDED
#define TESTE_DOMINIOS_H_INCLUDED

#include <string>
#include "Dominios.h"

// -------------------------------------------------------
// Testes do Leandro - 180145169

// Leandro - 180145169
// Capacidade
class TUCapacidade {
private:
    const static int VALOR_VALIDO   = 200;   
    const static int VALOR_INVALIDO = 350;   
    Capacidade *capacidade;                         
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

// Leandro - 180145169
//Horario
class TUHorario {
private:
    const string VALOR_VALIDO   = "12:15";   
    const string VALOR_INVALIDO = "48:32";   
    Horario *horario;                         
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

// Leandro - 180145169
//Senha
class TUSenha {
private:
    const string VALOR_VALIDO   = "Abc1Df$2";   
    const string VALOR_INVALIDO = "AAAA1BBB";   
    Senha *senha;                         
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

// Leandro - 180145169
//Telefone
class TUTelefone {
private:
    const string VALOR_VALIDO   = "(61)-982277718";   
    const string VALOR_INVALIDO = "(09)-000000000";   
    Telefone *telefone;                         
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

// -------------------------------------------------------
// Testes da Liz - 180022261

// Liz - 180022261
//Cargo
class TUCargo {
private:
    const string VALOR_VALIDO   = "ator";    
    const string VALOR_INVALIDO = "atoor";   
    Cargo *cargo;                                
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

// Liz - 180022261
//Horario
class TUMatricula {
private:
    const string VALOR_VALIDO   = "12345";   
    const string VALOR_INVALIDO = "12245";   
    Matricula *matricula;                         
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

// Liz - 180022261
//Nome
class TUNome {
private:
    const string VALOR_VALIDO   = "Liz Costato";   
    const string VALOR_INVALIDO = ".Liz  Costato";   
    Nome *nome;                         
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

// Liz - 180022261
//Data
class TUData {
private:
    const string VALOR_VALIDO   = "02/09/2005";   
    const string VALOR_INVALIDO = "03/08/1900";   
    Data *data;                         
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

// -------------------------------------------------------
// Testes da Clara - 190017503

// Clara - 190017503
//Classificação
class TUClassificacao {
    private:
        const string VALOR_VALIDO   = "livre";
        const string VALOR_INVALIDO = "20";
        Classificacao *classificacao;
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

// Clara - 190017503
//Tipo
class TUTipo {
    private:
        const string VALOR_VALIDO   = "comedia";
        const string VALOR_INVALIDO = "fantasia";
        Tipo *tipo;
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

// Clara - 190017503
//Código
class TUCodigo {
    private:
        const string VALOR_VALIDO   = "LM9999";
        const string VALOR_INVALIDO = "MC200E";
        Codigo *codigo;
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

// Clara - 190017503
//Email
class TUEmail {
    private:
        const string VALOR_VALIDO   = "pessoa@hotmail.com";
        const string VALOR_INVALIDO = "pessoahotmail.com";
        Email *email;
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

#endif
