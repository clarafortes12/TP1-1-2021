/// Exemplo de elementos da sintaxe da linguagem e de documenta��o usando Doxygen.

// Incluir cabe�alhos.

#include <iostream>
#include "Dominios.h"
#include "Entidades.h"
#include "Teste_Dominios.h"
#include "Teste_Entidades.h"


using namespace std;

int main()
{
    // ------------------------------------------------------------------------
    // Criar objetos e interagir com objetos.

    TUCapacidade testeA;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    switch(testeA.run()){
        case TUCapacidade::SUCESSO: cout << "SUCESSO - Capacidade" << endl;
                                break;
        case TUCapacidade::FALHA  : cout << "FALHA   - Capacidade" << endl;
                                break;
    }

    TUHorario testeB;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    switch(testeB.run()){
        case TUHorario::SUCESSO: cout << "SUCESSO - Horario" << endl;
                                break;
        case TUHorario::FALHA  : cout << "FALHA   - Horario" << endl;
                                break;
    }

    TUSenha testeC;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    switch(testeC.run()){
        case TUSenha::SUCESSO: cout << "SUCESSO - Senha" << endl;
                                break;
        case TUSenha::FALHA  : cout << "FALHA   - Senha" << endl;
                                break;
    }
    TUTelefone testeD;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    switch(testeD.run()){
        case TUTelefone::SUCESSO: cout << "SUCESSO - Telefone" << endl;
                                break;
        case TUTelefone::FALHA  : cout << "FALHA   - Telefone" << endl;
                                break;
    }

    TUPeca testeEA;

    // Invocar método e apresentar mensagem acerca do resultado do teste.

    switch(testeEA.run()){
        case TUPeca::SUCESSO: cout << "SUCESSO - PECA" << endl;
                                break;
        case TUPeca::FALHA  : cout << "FALHA   - PECA" << endl;
                                break;
    }

    TUSessao testeEB;

    // Invocar método e apresentar mensagem acerca do resultado do teste.

    switch(testeEB.run()){
        case TUSessao::SUCESSO: cout << "SUCESSO - Sessao" << endl;
                                break;
        case TUSessao::FALHA  : cout << "FALHA   - Sessao" << endl;
                                break;
    }

    Capacidade testar(100);                                    // Criar objeto com valor v�lido.

    cout << "Valor = " << testar.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testar.setValor(200);                                     // Armazenar valor v�lido n�o resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testar.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testar.setValor(101);                                    // Tentativa de armazenar valor inv�lido resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testar.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testar.setValor(101);                                    // Tentativa de armazenar valor inv�lido resulta em lan�amento de exce��o.
    }
    catch(...){                                             // Capturar exce��o de qualquer classe.
        cout << "Excecao : " << endl;
    }

    cout << "Valor = " << testar.getValor() << endl;             // Apresentar valor atual de atributo.

    // ------------------------------------------------------------------------
    // Exemplo de aninhamento blocos de c�digo try-catch.

    try{

        try {
            testar.setValor(101);                                // Tentativa de armazenar valor inv�lido resulta em lan�amento de exce��o.
        }
        catch(...){                                         // Capturar exce��o de qualquer classe.
            cout << "Tratamento parcial." << endl;
            throw;                                          // Relan�amento de exce��o.
        }
    }
    catch (invalid_argument &exp){                          // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }
// ------------------------------------------------------------------------

    Horario testarhorai("10:15");                                    // Criar objeto com valor v�lido.

    cout << "hora = " << testarhorai.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarhorai.setValor("00:00");                                     // Armazenar valor v�lido n�o resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "hora = " << testarhorai.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarhorai.setValor("07:25");                                    // Tentativa de armazenar valor inv�lido resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "hora = " << testarhorai.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarhorai.setValor("400:15");                                    // Tentativa de armazenar valor inv�lido resulta em lan�amento de exce��o.
    }
    catch(...){                                             // Capturar exce��o de qualquer classe.
        cout << "Excecao : " << endl;
    }

    cout << "Valor = " << testarhorai.getValor() << endl;             // Apresentar valor atual de atributo.

    // ------------------------------------------------------------------------
    // Exemplo de aninhamento blocos de c�digo try-catch.

    try{

        try {
            testarhorai.setValor("20:15");                                // Tentativa de armazenar valor inv�lido resulta em lan�amento de exce��o.
        }
        catch(...){                                         // Capturar exce��o de qualquer classe.
            cout << "Tratamento parcial." << endl;
            throw;                                          // Relan�amento de exce��o.
        }
    }
    catch (invalid_argument &exp){                          // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

//--------------------------------------------------------------------------------------

    Cargo testarCargo("ator");                                    // Criar objeto com valor v�lido.

    cout << "Valor = " << testarCargo.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarCargo.setValor("figurinista");                                     // Armazenar valor v�lido n�o resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarCargo.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarCargo.setValor("opa");                                     // Armazenar valor inv�lido que resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarCargo.getValor() << endl;             // Apresentar valor atual de atributo.

//--------------------------------------------------------------------------------------

    Matricula testarMatricula("01234");                                    // Criar objeto com valor v�lido.

    cout << "Valor = " << testarMatricula.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarMatricula.setValor("12345");                                     // Armazenar valor v�lido n�o resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarMatricula.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarMatricula.setValor("1a345");                                     // Armazenar valor inv�lido que resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarMatricula.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarMatricula.setValor("11345");                                     // Armazenar valor inv�lido que resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarMatricula.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarMatricula.setValor("12355");                                     // Armazenar valor inv�lido que resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarMatricula.getValor() << endl;             // Apresentar valor atual de atributo.


//--------------------------------------------------------------------------------------
	Senha testesenha("Abc#def2");                                    // Criar objeto com valor válido.

    cout << "Senha = " << testesenha.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testesenha.setValor("B4%@231#");                                     // Armazenar valor válido não resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Senha = " << testesenha.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testesenha.setValor("b4%8231#");                                    // Tentativa de armazenar valor inválido resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Senha = " << testesenha.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testesenha.setValor("123456789");                                    // Tentativa de armazenar valor inválido resulta em lançamento de exceção.
    }
    catch(...){                                             // Capturar exceção de qualquer classe.
        cout << "Excecao : " << endl;
    }

    cout << "Senha = " << testesenha.getValor() << endl;             // Apresentar valor atual de atributo.

//--------------------------------------------------------------------------------------

Telefone teldapessoa("(61)-983669929");                                    // Criar objeto com valor válido.

    cout << "tel = " << teldapessoa.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        teldapessoa.setValor("(61)-982423897");                                     // Armazenar valor válido não resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "tel = " << teldapessoa.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        teldapessoa.setValor("(09)-982423897");                                    // Tentativa de armazenar valor inválido resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "tel = " << teldapessoa.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        teldapessoa.setValor("(61)-000000000");                                    // Tentativa de armazenar valor inválido resulta em lançamento de exceção.
    }
    catch(...){                                             // Capturar exceção de qualquer classe.
        cout << "Excecao : " << endl;
    }

    cout << "tel = " << teldapessoa.getValor() << endl;             // Apresentar valor atual de atributo.

//--------------------------------------------------------------------------------------
    Nome testarNome("Minim");                                    // Criar objeto com valor válido.

    cout << "Valor = " << testarNome.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarNome.setValor("Liz Carolina");                                     // Armazenar valor válido não resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarNome.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarNome.setValor("a Liz");                                     // Armazenar valor inválido que resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarNome.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarNome.setValor("A  Liz");                                     // Armazenar valor inválido que resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarNome.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarNome.setValor("A Liz..");                                     // Armazenar valor inválido que resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarNome.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarNome.setValor("Estou testando maximo");                                     // Armazenar valor inválido que resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarNome.getValor() << endl;             // Apresentar valor atual de atributo.

//--------------------------------------------------------------------------------------
    Data testarData(10,10,2000);                                    // Criar objeto com valor válido.

    cout << "Valor = " << testarData.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarData.setValor(2,1,9000);                                     // Armazenar valor válido não resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarData.getValor() << endl;             // Apresentar valor atual de atributo.

     try{
        testarData.setValor(29,2,2000);                                     // Armazenar valor válido não resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarData.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarData.setValor(0,2,2000);                                     // Armazenar valor inválido que resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarData.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarData.setValor(1,13,2000);                                     // Armazenar valor inválido que resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarData.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarData.setValor(1,2,10000);                                     // Armazenar valor inválido que resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarData.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarData.setValor(29,2,2001);                                     // Armazenar valor inválido que resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testarData.getValor() << endl;             // Apresentar valor atual de atributo.

//------------ Classifica��o
    Classificacao classificar1;
    cout << "Classifica��o1 = " << classificar1.getValor() << endl;

    Classificacao classificar2("livre");
    cout << "Classificacao = " << classificar2.getValor() << endl;


    try{
        classificar2.setValor("10");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Classificacao = " << classificar2.getValor() << endl;

    try{
        classificar2.setValor("12");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Classificacao = " << classificar2.getValor() << endl;

    try{
        classificar2.setValor("14");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Classificacao = " << classificar2.getValor() << endl;

    try{
        classificar2.setValor("16");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Classificacao = " << classificar2.getValor() << endl;

    try{
        classificar2.setValor("18");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Classificacao = " << classificar2.getValor() << endl;

    try{
        classificar2.setValor("20");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Classificacao = " << classificar2.getValor() << endl;

//------------ Tipo
    Tipo genero1;
    cout << "Genero1 = " << genero1.getValor() << endl;

    Tipo genero2("auto");
    cout << "Genero = " << genero2.getValor() << endl;

    try{
        genero2.setValor("comedia");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Genero = " << genero2.getValor() << endl;

    try{
        genero2.setValor("drama");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Genero = " << genero2.getValor() << endl;

    try{
        genero2.setValor("farsa");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Genero = " << genero2.getValor() << endl;

    try{
        genero2.setValor("melodrama");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Genero = " << genero2.getValor() << endl;

    try{
        genero2.setValor("monologo");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Genero = " << genero2.getValor() << endl;

    try{
        genero2.setValor("musical");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Genero = " << genero2.getValor() << endl;

    try{
        genero2.setValor("opera");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Genero = " << genero2.getValor() << endl;

    try{
        genero2.setValor("revista");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Genero = " << genero2.getValor() << endl;

    try{
        genero2.setValor("fantasia");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Genero = " << genero2.getValor() << endl;

//------------ C�digo
    Codigo codigo1;
    cout << "Codigo1 = " << codigo1.getValor() << endl;

    Codigo codigo2("LM9999");
    cout << "Codigo = " << codigo2.getValor() << endl;

    try{
        codigo2.setValor("MC2001");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Codigo = " << codigo2.getValor() << endl;

    try{
        codigo2.setValor("mC2001");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Codigo = " << codigo2.getValor() << endl;

    try{
        codigo2.setValor("M22001");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Codigo = " << codigo2.getValor() << endl;

    try{
        codigo2.setValor("MC200E");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Codigo = " << codigo2.getValor() << endl;

    try{
        codigo2.setValor("MC200e");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Codigo = " << codigo2.getValor() << endl;

//------------ Email
    Email email1;
    cout << "Email1 = " << email1.getValor() << endl;

    Email email2("pessoa@hotmail.com");
    cout << "Email = " << email2.getValor() << endl;

    try{
        email2.setValor("pessoahotmail.com");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Email = " << email2.getValor() << endl;

    try{
        email2.setValor("pessoa@@hotmail.com");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Email = " << email2.getValor() << endl;

    try{
        email2.setValor("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa@hotmail.com");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Email = " << email2.getValor() << endl;

    try{
        email2.setValor("pessoa@aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Email = " << email2.getValor() << endl;

    try{
        email2.setValor("pessonhinha@hotmail.com");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Email = " << email2.getValor() << endl;

    try{
        email2.setValor(".pessonhinha@hotmail.com");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Email = " << email2.getValor() << endl;

    try{
        email2.setValor("pessonhinha.@hotmail.com");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Email = " << email2.getValor() << endl;

    try{
        email2.setValor("pessonhinha@hotmail.com.");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Email = " << email2.getValor() << endl;

    try{
        email2.setValor("pessonhinha@hotmail..com");
    }
    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what() << endl;
    }
    cout << "Email = " << email2.getValor() << endl;

    return 0;
}
