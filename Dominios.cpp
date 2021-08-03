#include "Dominios.h"
#include <iostream>
#include <string>
//---------------------------------------------------------------------
// Inicializacao de atributo estatico.


Capacidade::Capacidade(int valor){
    validar(valor);
    this->valor = valor;
}

// M�todo para valida��o com lan�amento de exce��o.

void Capacidade::validar(int valor){
    if ((valor!=100) && (valor!=200) && (valor!=300) && (valor!=400) && (valor!=500))
        throw invalid_argument("Argumento invalido.");
}

// M�todo para acesso a atributo.

void Capacidade::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

//------------------------------------

Horario::Horario(int hora, int minuto){
    validar(hora, minuto);
    if (hora<10)
        if (minuto)
            this->valor = "0"+to_string(hora)+":"+to_string(minuto);
        else
           this->valor = "0"+to_string(hora)+":"+"0"+to_string(minuto);
    else
        if (minuto)
            this->valor = to_string(hora)+":"+to_string(minuto);
        else
           this->valor = to_string(hora)+":"+"0"+to_string(minuto);
}

void Horario::validar(int hora, int minuto){
    if (hora > 23 || hora < 0)
        throw invalid_argument("Argumento invalido.");
    else
        if (minuto != 00 && minuto != 15 && minuto != 30 && minuto != 45)
            throw invalid_argument("Argumento invalido.");
}

// M�todo para acesso a atributo.

void Horario::setValor(int hora, int minuto) {
    validar(hora, minuto);
    if (hora<10)
        if (minuto)
            this->valor = "0"+to_string(hora)+":"+to_string(minuto);
        else
           this->valor = "0"+to_string(hora)+":"+"0"+to_string(minuto);
    else
        if (minuto)
            this->valor = to_string(hora)+":"+to_string(minuto);
        else
           this->valor = to_string(hora)+":"+"0"+to_string(minuto);
}

//------------------------------------


Senha::Senha(string valor){
    validar(valor);
    this->valor = valor;
}

// Método para validação com lançamento de exceção.

void Senha::validar(string valor){
    bool cond1, cond2, cond3;
    cond1 = false;
    cond2 = false;
    cond3 = false;
    if (valor.size() != 8)
        throw invalid_argument("Argumento invalido.");
    else
        for (int i = 0; i < valor.length(); ++i){
            for (int j = i+1; j < valor.length(); ++j){
                if (valor[i] == valor[j])
                    throw invalid_argument("Argumento invalido.");

            }
        }
        for (int i = 0; i < valor.size(); i++){
            if(not((valor[i] >= 97 && valor[i] <= 122) || (valor[i] >= 48 && valor[i] <= 57) || (valor[i] >= 63 && valor[i] <= 90) || (valor[i] = 33) || (valor[i] >= 35 && valor[i] <= 38)))
                throw invalid_argument("Argumento invalido.");
            else
                if(valor[i] >= 65 && valor[i] <= 90)
                    cond1 = true;
                if(valor[i] >= 48 && valor[i] <= 57)
                    cond2 = true;
                if((valor[i] >= 35 && valor[i] <= 38) || (valor[i] = 33) || (valor[i] = 63) || (valor[i] = 64))
                    cond3 = true;
        }
        if(not(cond1) || not(cond2) || not(cond3))
            throw invalid_argument("Argumento invalido.");
}

// Método para acesso a atributo.

void Senha::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

//------------------------------------

Cargo::Cargo(string valor){
    validar(valor);
    this->valor = valor;
}

// M�todo para valida��o com lan�amento de exce��o.

void Cargo::validar(string valor){
    if ((valor!="ator") && (valor!="cen�grafo") && (valor!="figurinista") && (valor!="maquiador") && (valor!="sonoplasta") && (valor!="iluminador"))
        throw invalid_argument("Argumento invalido.");
}

// M�todo para acesso a atributo.

void Cargo::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

//------------------------------------

bool eh_digito(string teste){
    bool resposta = false;
    int i = 0;

    do{
        if (teste[i] == '0' || teste[i] == '1' || teste[i] == '2' || teste[i] == '3' || teste[i] == '4' ||
            teste[i] == '5' || teste[i] == '6' || teste[i] == '7' || teste[i] == '8' || teste[i] == '9')
            resposta = true;
        else
            resposta = false;
        i++;
    }while(teste[i] != '\0' && resposta == true);

    return resposta;
}

bool ha_repeticao(string teste){
    bool resposta = false;
    int i, j;

    for(i = 0; i<4; i++){
        for(j = i+1; j<5; j++){
            if(teste[i]==teste[j])
                resposta = true;
        }
    }

    return resposta;
}

Matricula::Matricula(string valor){
    validar(valor);
    this->valor = valor;
}

// M�todo para valida��o com lan�amento de exce��o.

void Matricula::validar(string valor){
    if (valor[5]!='\0')
        throw invalid_argument("Tamanho incorreto. A matricula deve ter 5 digitos");
    if (!eh_digito(valor))
        throw invalid_argument("Sao aceitos apenas digitos na matricula");
    if (ha_repeticao(valor))
        throw invalid_argument("Os digitos da matricula nao podem ser repetidos");
}

// M�todo para acesso a atributo.

void Matricula::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

//--------------------

int caracteres_nome(string nome){
    int resposta = 0;
    int i = 0;

    do{
        if(i == 0){
            if (nome[i] == '.'){
                //cout << "parou no 1 " << endl;
                return resposta = 2;
            }
            if ((nome[i] >= 'a' && nome[i] <= 'z') || nome[i] == ' '){
                //cout << "Parou no 2 " << endl;
                return resposta = 4;
            }
        }
        if (nome[i] == '0' || nome[i] == '1' || nome[i] == '2' || nome[i] == '3' || nome[i] == '4' ||
            nome[i] == '5' || nome[i] == '6' || nome[i] == '7' || nome[i] == '8' || nome[i] == '9' ||
            (nome[i] >= 'a' && nome[i] <= 'z') || (nome[i] >= 'A' && nome[i] <= 'Z') || nome[i] == '.' ||
            nome[i] == ' '){
            //cout << "Parou no 3 " << endl;
            resposta = 0;
        }
        else
            return resposta = 1;

        if(nome[i] == '.' && i >0){
            if(nome[i-1] < 'A' || nome[i-1] > 'z' || (nome[i-1] > 'Z' && nome[i-1] < 'a')){
                //cout << "Parou no 4 " << endl;
                return resposta = 2;
            }
        }

        if(nome[i] == ' ' && i >0){
            if(nome[i-1] == ' '){
                //cout << "Parou no 5 " << endl;
                return resposta = 3;
            }
        }
        i++;
    }while(nome[i] != '\0');

    //cout << "Era pra ter dado bom"<< endl;

    return resposta;
}

Nome::Nome(string valor){
    validar(valor);
    this->valor = valor;
}

// Método para validação com lançamento de exceção.

void Nome::validar(string valor){
    if (valor.length()<5 || valor.length()>20)
        throw invalid_argument("Tamanho incorreto. O nome deve ter de 5 a 20 caracteres");
    switch(caracteres_nome(valor)){
        case 1:
            throw invalid_argument("O nome so pode ter letras, ponto (.) ou espaco em branco");
        case 2:
            throw invalid_argument("O ponto (.) deve ser prcedido por letra");
        case 3:
            throw invalid_argument("Nao deve haver espacos em branco em sequencia");
        case 4:
            throw invalid_argument("Cada termo deve ser iniciado com letra maiuscula (A-Z)");
        default:
            cout << "Tudo Certo!" << endl;
    }
}

// Método para acesso a atributo.

void Nome::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

