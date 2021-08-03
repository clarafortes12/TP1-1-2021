#include "Dominios.h"
#include <iostream>
#include <string>
//---------------------------------------------------------------------
// Inicializacao de atributo estatico.


Capacidade::Capacidade(int valor){
    validar(valor);
    this->valor = valor;
}

// Método para validação com lançamento de exceção.

void Capacidade::validar(int valor){
    if ((valor!=100) && (valor!=200) && (valor!=300) && (valor!=400) && (valor!=500))
        throw invalid_argument("Argumento invalido.");
}

// Método para acesso a atributo.

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

// Método para acesso a atributo.

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

Cargo::Cargo(string valor){
    validar(valor);
    this->valor = valor;
}

// Método para validação com lançamento de exceção.

void Cargo::validar(string valor){
    if ((valor!="ator") && (valor!="cenógrafo") && (valor!="figurinista") && (valor!="maquiador") && (valor!="sonoplasta") && (valor!="iluminador"))
        throw invalid_argument("Argumento invalido.");
}

// Método para acesso a atributo.

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

// Método para validação com lançamento de exceção.

void Matricula::validar(string valor){
    if (valor[5]!='\0')
        throw invalid_argument("Tamanho incorreto. A matricula deve ter 5 digitos");
    if (!eh_digito(valor))
        throw invalid_argument("Sao aceitos apenas digitos na matricula");
    if (ha_repeticao(valor))
        throw invalid_argument("Os digitos da matricula nao podem ser repetidos");
}

// Método para acesso a atributo.

void Matricula::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}
