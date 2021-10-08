#include "stubs.h"


// Adequar os valores.

const string StubServicoAutenticacao::INVALIDO = "12345"; // Essa é a matrícula invalida
const string StubServicoParticipante::INVALIDO = "12345";
const string StubServicoPeca::INVALIDO = "12345"; //Tem que mudar para código inválido
//const string StubServicoSala::INVALIDO = "12345";
//const string StubServicoSessao::INVALIDO = "12345";

//--------------------------------------------------------------------------------------------
// Implementações dos métodos dos stubs de autenticação.

bool StubServicoAutenticacao::autenticar(Matricula matricula, Senha senha){
    if(matricula.getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

//--------------------------------------------------------------------------------------------
// Implementações dos métodos dos stubs de participante.

bool StubServicoParticipante::cadastrarParticipante(Participante participante){
    if(participante.getMatricula().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoParticipante::consultarParticipante(Matricula matricula){
    if(participante->getMatricula().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoParticipante::descadastrarParticipante(Matricula matricula){
    if(participante->getMatricula().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoParticipante::editarParticipante(Participante participante){
    if(participante.getMatricula().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

//--------------------------------------------------------------------------------------------
// Implementações dos métodos dos stubs de peca.




