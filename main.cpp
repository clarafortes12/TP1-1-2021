// Exemplo de elementos da sintaxe da linguagem e de documenta��o usando Doxygen.

// Incluir cabe�alhos.

#include <iostream>

#include "Dominios.h"
#include "Dominios.cpp"

using namespace std;

int main()
{
    // ------------------------------------------------------------------------
    // Criar objetos e interagir com objetos.

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

    Horario testarhorai(10,15);                                    // Criar objeto com valor v�lido.

    cout << "hora = " << testarhorai.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarhorai.setValor(00,00);                                     // Armazenar valor v�lido n�o resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "hora = " << testarhorai.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarhorai.setValor(07,25);                                    // Tentativa de armazenar valor inv�lido resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "hora = " << testarhorai.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testarhorai.setValor(400,15);                                    // Tentativa de armazenar valor inv�lido resulta em lan�amento de exce��o.
    }
    catch(...){                                             // Capturar exce��o de qualquer classe.
        cout << "Excecao : " << endl;
    }

    cout << "Valor = " << testarhorai.getValor() << endl;             // Apresentar valor atual de atributo.

    // ------------------------------------------------------------------------
    // Exemplo de aninhamento blocos de c�digo try-catch.

    try{

        try {
            testarhorai.setValor(20,15);                                // Tentativa de armazenar valor inv�lido resulta em lan�amento de exce��o.
        }
        catch(...){                                         // Capturar exce��o de qualquer classe.
            cout << "Tratamento parcial." << endl;
            throw;                                          // Relan�amento de exce��o.
        }
    }
    catch (invalid_argument &exp){                          // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

//--------------

    Cargo testar1("ator");                                    // Criar objeto com valor v�lido.

    cout << "Valor = " << testar1.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testar1.setValor("figurinista");                                     // Armazenar valor v�lido n�o resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testar1.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testar1.setValor("opa");                                     // Armazenar valor inv�lido que resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testar1.getValor() << endl;             // Apresentar valor atual de atributo.

//--------------

    Matricula testar2("01234");                                    // Criar objeto com valor v�lido.

    cout << "Valor = " << testar2.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testar2.setValor("12345");                                     // Armazenar valor v�lido n�o resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testar2.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testar2.setValor("1a345");                                     // Armazenar valor inv�lido que resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testar2.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testar2.setValor("11345");                                     // Armazenar valor inv�lido que resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testar2.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        testar2.setValor("12355");                                     // Armazenar valor inv�lido que resulta em lan�amento de exce��o.
    }
    catch(invalid_argument &exp){                           // Capturar exce��o da classe invalid_argument, refer�ncia para objeto para evitar c�pia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << testar2.getValor() << endl;             // Apresentar valor atual de atributo.

    return 0;
}
