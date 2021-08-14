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

    TUCapacidade testeCapacidade;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    switch(testeCapacidade.run()){
        case TUCapacidade::SUCESSO: cout << "SUCESSO - Capacidade" << endl;
                                break;
        case TUCapacidade::FALHA  : cout << "FALHA   - Capacidade" << endl;
                                break;
    }

    TUHorario testeHorario;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    switch(testeHorario.run()){
        case TUHorario::SUCESSO: cout << "SUCESSO - Horario" << endl;
                                break;
        case TUHorario::FALHA  : cout << "FALHA   - Horario" << endl;
                                break;
    }

    TUSenha testeSenha;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    switch(testeSenha.run()){
        case TUSenha::SUCESSO: cout << "SUCESSO - Senha" << endl;
                                break;
        case TUSenha::FALHA  : cout << "FALHA   - Senha" << endl;
                                break;
    }

    TUTelefone testeTelefone;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    switch(testeTelefone.run()){
        case TUTelefone::SUCESSO: cout << "SUCESSO - Telefone" << endl;
                                break;
        case TUTelefone::FALHA  : cout << "FALHA   - Telefone" << endl;
                                break;
    }

    TUPeca testePeca;

    // Invocar método e apresentar mensagem acerca do resultado do teste.

    switch(testePeca.run()){
        case TUPeca::SUCESSO: cout << "SUCESSO - PECA" << endl;
                                break;
        case TUPeca::FALHA  : cout << "FALHA   - PECA" << endl;
                                break;
    }

    TUSessao testeSessao;

    // Invocar método e apresentar mensagem acerca do resultado do teste.

    switch(testeSessao.run()){
        case TUSessao::SUCESSO: cout << "SUCESSO - Sessao" << endl;
                                break;
        case TUSessao::FALHA  : cout << "FALHA   - Sessao" << endl;
                                break;
    }

    TUSala testeSala;

    // Invocar método e apresentar mensagem acerca do resultado do teste.

    switch(testeSala.run()){
        case TUSala::SUCESSO: cout << "SUCESSO - Sala" << endl;
                                break;
        case TUSala::FALHA  : cout << "FALHA   - Sala" << endl;
                                break;
    }

    TUCargo testeCargo;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    switch(testeCargo.run()){
        case TUCargo::SUCESSO: cout << "SUCESSO - Cargo" << endl;
                                break;
        case TUCargo::FALHA  : cout << "FALHA   - Cargo" << endl;
                                break;
    }

    TUMatricula testeMatricula;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    switch(testeMatricula.run()){
        case TUMatricula::SUCESSO: cout << "SUCESSO - Matricula" << endl;
                                break;
        case TUMatricula::FALHA  : cout << "FALHA   - Matricula" << endl;
                                break;
    }

    TUNome testeNome;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    switch(testeNome.run()){
        case TUNome::SUCESSO: cout << "SUCESSO - Nome" << endl;
                                break;
        case TUNome::FALHA  : cout << "FALHA   - Nome" << endl;
                                break;
    }

    TUData testeData;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    switch(testeData.run()){
        case TUData::SUCESSO: cout << "SUCESSO - Data" << endl;
                                break;
        case TUData::FALHA  : cout << "FALHA   - Data" << endl;
                                break;
    }

    /////////////////////TESTES ANTIGOS//////////////////////

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
    //tirei testes de data

// Testes de Entidade da Clara - 190017503

//------------ Participante
    TUParticipante testeParticipante;

    switch(testeParticipante.run()){
        case TUParticipante::SUCESSO: cout << "SUCESSO - Participante" << endl;
                                break;
        case TUParticipante::FALHA  : cout << "FALHA   - Participante" << endl;
                                break;
    }

// Testes de Domínio da Clara - 190017503

//------------ Classificacao
    TUClassificacao testeClassificacao;

    switch(testeClassificacao.run()){
        case TUClassificacao::SUCESSO: cout << "SUCESSO - Classificacao" << endl;
                                break;
        case TUClassificacao::FALHA  : cout << "FALHA   - Classificacao" << endl;
                                break;
    }
//------------ Tipo
    TUTipo testeTipo;

    switch(testeTipo.run()){
        case TUTipo::SUCESSO: cout << "SUCESSO - Tipo" << endl;
                                break;
        case TUTipo::FALHA  : cout << "FALHA   - Tipo" << endl;
                                break;
    }

//------------ C�digo
    TUCodigo testeCodigo;

    switch(testeCodigo.run()){
        case TUCodigo::SUCESSO: cout << "SUCESSO - Codigo" << endl;
                                break;
        case TUCodigo::FALHA  : cout << "FALHA   - Codigo" << endl;
                                break;
    }

//------------ Email
    TUEmail testeEmail;

    switch(testeEmail.run()){
        case TUEmail::SUCESSO: cout << "SUCESSO - Email" << endl;
                                break;
        case TUEmail::FALHA  : cout << "FALHA   - Email" << endl;
                                break;
    }

    return 0;
}
