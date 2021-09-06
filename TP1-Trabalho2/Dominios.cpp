#include "Dominios.h"
#include <iostream>
#include <string>

// -------------------------------------------------------------------------
//Metodos do Leandro - 180145169

Capacidade::Capacidade(int valor){
    validar(valor);
    this->valor = valor;
}

Capacidade::Capacidade(){
    this->valor = 100;
}


void Capacidade::validar(int valor){
    if ((valor!=100) && (valor!=200) && (valor!=300) && (valor!=400) && (valor!=500))
        throw invalid_argument("Argumento invalido.");
}


void Capacidade::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

//------------------------------------

Horario::Horario(){
    this->valor = "00:00";
}

Horario::Horario(string valor){
    validar(valor);
    this-> valor = valor;
}

void Horario::validar(string valor){
    int hora, minuto;
    if (valor.size() != 5)
        throw invalid_argument("Argumento invalido.");
    else{
        hora = stoi(valor.substr(0,2));
        minuto = stoi(valor.substr(3,2));
        if ((hora > 23 || hora < 00) || (minuto != 00 && minuto != 15 && minuto != 30 && minuto != 45) || (valor.substr(2,1) != ":"))
            throw invalid_argument("Argumento invalido.");
    }

}


void Horario::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

//------------------------------------

Senha::Senha(){
    this->valor = "";
}

Senha::Senha(string valor){
    validar(valor);
    this->valor = valor;
}


void Senha::validar(string valor){
    bool cond1, cond2, cond3;
    cond1 = false;
    cond2 = false;
    cond3 = false;
    if (valor.size() != 8)
        throw invalid_argument("Argumento invalido.");
    else{
        for (int i = 0; i < int(valor.length()); ++i){
            for (int j = i+1; j < int(valor.length()); ++j){
                if (valor[i] == valor[j])
                    throw invalid_argument("Argumento invalido.");

            }
        }
        for (int i = 0; i < int(valor.size()); i++){
            if(not((valor[i] >= 97 && valor[i] <= 122) || (valor[i] >= 48 && valor[i] <= 57) || (valor[i] >= 63 && valor[i] <= 90) || (valor[i] = 33) || (valor[i] >= 35 && valor[i] <= 38)))
                throw invalid_argument("Argumento invalido.");
            else{
                if(valor[i] >= 65 && valor[i] <= 90)
                    cond1 = true;
                if(valor[i] >= 48 && valor[i] <= 57)
                    cond2 = true;
                if((valor[i] >= 35 && valor[i] <= 38) || (valor[i] = 33) || (valor[i] = 63) || (valor[i] = 64))
                    cond3 = true;
            }

        }
        if(not(cond1) || not(cond2) || not(cond3))
            throw invalid_argument("Argumento invalido.");
    }
}


void Senha::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}
//-----------------------------------
Telefone::Telefone(){
    this->valor = "";
}

Telefone::Telefone(string valor){
    validar(valor);
    this->valor = valor;
}


void Telefone::validar(string valor){
    string ddd, numinvalido;
    int numddd, numtel;
    numtel = 0;
    if (valor.size() != 14)
        throw invalid_argument("Argumento invalido.");
    else{
        for (int i = 0; i < int(valor.length()); ++i){
            if((valor[i] == 40 && i != 0) || (valor[i] == 41 && i != 3) || (valor[i] == 45 && i != 4))
                throw invalid_argument("Argumento invalido.");
            else
                if((i <= 2 && i >= 1) || (i <= 14 && i >= 5)){
                    if(i <= 2 && i >= 1){
                        ddd += valor[i];
                    }
                    if(i <= 14 && i >= 5){
                        numtel += valor[i] - '0';
                    }
                    if (valor[i] < 48 || valor[i] > 57){
                        throw invalid_argument("Argumento invalido.");
                    }

                }

        }
        numddd = (ddd[0] - '0') * 10 + (ddd[1] - '0');
        if(numtel == 0)
            throw invalid_argument("Argumento invalido.");
        if(not((numddd >= 11 && numddd <= 19) || (numddd == 21) || (numddd == 22) || (numddd == 24) || (numddd >= 27 && numddd <= 28) || (numddd >= 32 && numddd <= 35) || (numddd >= 37 && numddd <= 38) || (numddd >= 41 && numddd <= 49) ||  (numddd == 51) || (numddd >= 53 && numddd <= 55) || (numddd >= 61 && numddd <= 69) || (numddd == 71) || (numddd >= 73 && numddd <= 75) || (numddd == 77) || (numddd == 79) || (numddd >= 81 && numddd <= 89) || (numddd >= 91 && numddd <= 99)))
            throw invalid_argument("Argumento invalido.");
    }
}


void Telefone::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

// -------------------------------------------------------------------------
//Metodos da Liz - 180022261

Cargo::Cargo(){
    this->valor = "";
}

Cargo::Cargo(string valor){
    validar(valor);
    this->valor = valor;
}


void Cargo::validar(string valor){
    if ((valor!="ator") && (valor!="cen�grafo") && (valor!="figurinista") && (valor!="maquiador") && (valor!="sonoplasta") && (valor!="iluminador"))
        throw invalid_argument("Argumento invalido.");
}


void Cargo::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

//------------------------------------

// funcao auxiliar
bool Matricula::eh_digito(string teste){
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

// funcao auxiliar
bool Matricula::ha_repeticao(string teste){
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

Matricula::Matricula(){
    this->valor = "";
}

Matricula::Matricula(string valor){
    validar(valor);
    this->valor = valor;
}


void Matricula::validar(string valor){
    if (valor[5]!='\0')
        throw invalid_argument("Tamanho incorreto. A matricula deve ter 5 digitos");
    if (!eh_digito(valor))
        throw invalid_argument("Sao aceitos apenas digitos na matricula");
    if (ha_repeticao(valor))
        throw invalid_argument("Os digitos da matricula nao podem ser repetidos");
}


void Matricula::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

//--------------------

// funcao auxiliar
int Nome::caracteres_nome(string nome){
    int resposta = 0;
    int i = 0;

    do{
        if(i == 0){
            if (nome[i] == '.'){
                return resposta = 2;
            }
            if ((nome[i] >= 'a' && nome[i] <= 'z') || nome[i] == ' '){
                return resposta = 4;
            }
        }
        if (nome[i] == '0' || nome[i] == '1' || nome[i] == '2' || nome[i] == '3' || nome[i] == '4' ||
            nome[i] == '5' || nome[i] == '6' || nome[i] == '7' || nome[i] == '8' || nome[i] == '9' ||
            (nome[i] >= 'a' && nome[i] <= 'z') || (nome[i] >= 'A' && nome[i] <= 'Z') || nome[i] == '.' ||
            nome[i] == ' '){
            resposta = 0;
        }
        else
            return resposta = 1;

        if(nome[i] == '.' && i >0){
            if(nome[i-1] < 'A' || nome[i-1] > 'z' || (nome[i-1] > 'Z' && nome[i-1] < 'a')){
                return resposta = 2;
            }
        }

        if(nome[i] == ' ' && i >0){
            if(nome[i-1] == ' '){
                return resposta = 3;
            }
        }
        i++;
    }while(nome[i] != '\0');

    return resposta;
}

Nome::Nome(){
    this->valor = "";
}

Nome::Nome(string valor){
    validar(valor);
    this->valor = valor;
}


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
            return;
    }
}


void Nome::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

//------------------------------------

Data::Data(){
    this->valor = "01/01/2000";
}

Data::Data(string valor){
    validar(valor);
    this-> valor = valor;
}

void Data::validar(string valor){
    int dia, mes, ano;
    if (valor.size() != 10)
        throw invalid_argument("Argumento invalido. A data deve ser do formato DD/MM/AAAA, sendo 01 a 31 em DD, 01 a 12 em MM e 2000 a 9999 em AAAA.");
    else{
        dia = stoi(valor.substr(0,2));
        mes = stoi(valor.substr(3,2));
        ano = stoi(valor.substr(6,4));
        if (dia < 1 || dia > 28){
            if(mes == 2 && ano%4 != 0 && dia > 28){
                throw invalid_argument("Argumento invalido. Fevereiro tem apenas 28 dias.");
            }else if(mes == 2 && ano%4 == 0 && dia > 29){
                throw invalid_argument("Argumento invalido. Fevereiro tem apenas 29 dias.");
            }else if (dia == 31){
                if (mes != 1 && mes != 3 && mes != 5 && mes != 7 && mes != 8 && mes != 10 && mes != 12){
                    throw invalid_argument("Argumento invalido. Esse m�s tem apenas 30 dias.");
                }
            }else if (dia > 31 || dia < 1){
                throw invalid_argument("Argumento invalido."); /*Ao menos mes errado*/
            }
        }
        if (mes < 1 || mes > 12)
            throw invalid_argument("Argumento invalido."); /*Ao menos mes errado*/
        if (ano < 2000 || ano > 9999)
            throw invalid_argument("Argumento invalido."); /*Ao menos ano errado*/
        }

}


void Data::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

// -------------------------------------------------------------------------
//Metodos da Clara - 190017503
// M�todos da Clara

// ---------- Classifica��o
void Classificacao::validar(string idade){
    if ((idade!="livre") && (idade!="10") && (idade!="12") && (idade!="14") && (idade!="16") && (idade!="18"))
        throw invalid_argument("Argumento invalido.");
}

Classificacao::Classificacao(){
    this->idade = "";
}

Classificacao::Classificacao(string idade){
    validar(idade);
    this->idade = idade;
}

void Classificacao::setValor(string idade){
    validar(idade);
    this->idade = idade;
}

// ---------- Tipo
void Tipo::validar(string genero){
    if ((genero!="auto") && (genero!="comedia") && (genero!="drama") && (genero!="farsa") && (genero!="melodrama")
        && (genero!="monologo") && (genero!="musical")&& (genero!="opera")&& (genero!="revista"))
        throw invalid_argument("Argumento invalido.");
}

Tipo::Tipo(){
    this->genero = "";
}

Tipo::Tipo(string genero){
    validar(genero);
    this->genero = genero;
}

void Tipo::setValor(string genero){
    validar(genero);
    this->genero = genero;
}


// ---------- C�digo
bool Codigo::eh_maiusculo(char teste){
    if (teste == 'A' || teste == 'B' || teste == 'C' || teste == 'D' || teste == 'E' ||
        teste == 'F' || teste == 'G' || teste == 'H' || teste == 'I' || teste == 'J' ||
        teste == 'K' || teste == 'L' || teste == 'M' || teste == 'N' || teste == 'O' ||
        teste == 'P' || teste == 'Q' || teste == 'R' || teste == 'S' || teste == 'T' ||
        teste == 'U' || teste == 'V' || teste == 'W' || teste == 'X' || teste == 'Y' ||
        teste == 'Z')
        return true;
    else
        return false;
}

bool Codigo::eh_numero(char teste){
    if (teste == '0' || teste == '1' || teste == '2' || teste == '3' || teste == '4' ||
        teste == '5' || teste == '6' || teste == '7' || teste == '8' || teste == '9' )
        return true;
    else
        return false;
}

void Codigo::validar(string codigo){
    if (codigo.size()!= 6)
        throw invalid_argument("Tamanho incorreto, deve ser 6 digitos");
    if (!eh_maiusculo(codigo[0]))
        throw invalid_argument("Os dois primeiros deve ser letras maiusculos e os quatro ultimos digitos");
    if (!eh_maiusculo(codigo[1]))
        throw invalid_argument("Os dois primeiros deve ser letras maiusculos e os quatro ultimos digitos");
    if (!eh_numero(codigo[2]))
        throw invalid_argument("Os dois primeiros deve ser letras maiusculos e os quatro ultimos digitos");
    if (!eh_numero(codigo[3]))
        throw invalid_argument("Os dois primeiros deve ser letras maiusculos e os quatro ultimos digitos");
    if (!eh_numero(codigo[4]))
        throw invalid_argument("Os dois primeiros deve ser letras maiusculos e os quatro ultimos digitos");
    if (!eh_numero(codigo[5]))
        throw invalid_argument("Os dois primeiros deve ser letras maiusculos e os quatro ultimos digitos");
}

Codigo::Codigo(){
    this->codigo = "";
}

Codigo::Codigo(string codigo){
    validar(codigo);
    this->codigo = codigo;
}

void Codigo::setValor(string codigo){
    validar(codigo);
    this->codigo = codigo;
}


// ---------- Email
int Email::busca_arroba(string email){
    int arrobas = 0;
    int busca = 0;
    int i = 0;

    do{
        if(email[i] == '@'){
            arrobas++;
            busca = i;
        }
        i++;
    }while(email[i] != '\0');

    if(arrobas < 1)
        throw invalid_argument("Faltou o dominio");
    else if(arrobas > 1)
        throw invalid_argument("Nao pode ter dois @ no email");
    else
        return busca;
}

string Email::busca_parte_local(string email,int arroba){
    int i = 0;
    string parte_local = "";

    do{
        parte_local += email[i];
        i++;
    }while(i < arroba);

    return parte_local;
}

string Email::busca_dominio(string email,int arroba){
    int i = arroba+1;
    string dominio = "";

    do{
        dominio += email[i];
        i++;
    }while(email[i] != '\0');

    return dominio;
}
bool Email::pontos_seguidos(string teste){
    int i = 1;
    do{
        if (teste[i] == '.' && teste[i] == teste[i-1])
            return true;
        i++;
    }while(teste[i] != '\0');
    return false;
}

void Email::validar(string parte_local, string dominio){
    if (parte_local.size() > 64)
        throw invalid_argument("Tamanho incorreto, deve ser no maximo 64 caracteres antes do @ e ate 255 depois");
    if (dominio.size() > 255)
        throw invalid_argument("Tamanho incorreto, deve ser no maximo 64 caracteres antes do @ e ate 255 depois");
    if ((parte_local[0] == '.') || (parte_local[(parte_local.size()-1)] == '.'))
        throw invalid_argument("Nao pode ter ponto no primeiro e nem no ultimo caracteres");
    if ((dominio[0] == '.') || (dominio[(dominio.size()-1)] == '.'))
        throw invalid_argument("Nao pode ter ponto no primeiro e nem no ultimo caracteres");
    if (pontos_seguidos(parte_local))
        throw invalid_argument("Nao pode ter pontos seguidos");
    if (pontos_seguidos(dominio))
        throw invalid_argument("Nao pode ter pontos seguidos");
}

Email::Email(){
    this->parte_local = "";
    this->dominio = "";
}

Email::Email(string email){
    int arroba = busca_arroba(email);
    string parte_local = busca_parte_local(email,arroba);
    string dominio = busca_dominio(email,arroba);
    validar(parte_local,dominio);
    this->parte_local = parte_local;
    this->dominio = dominio;
}

void Email::setValor(string email){
    int arroba = busca_arroba(email);
    string parte_local = busca_parte_local(email,arroba);
    string dominio = busca_dominio(email,arroba);
    validar(parte_local,dominio);
    this->parte_local = parte_local;
    this->dominio = dominio;
}
