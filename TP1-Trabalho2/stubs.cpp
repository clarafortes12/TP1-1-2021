#include "stubs.h"

// Adequar os valores.

const string StubServicoAutenticacao::INVALIDO = "12345"; // Essa é a matrícula invalida
const string StubServicoParticipante::INVALIDO = "12345";
const string StubServicoPeca::INVALIDO = "12345"; //Tem que mudar para código inválido
const string StubServicoSala::INVALIDO = "12345";
const string StubServicoSessao::INVALIDO = "12345";

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

bool StubServicoParticipante::consultarParticipante(Participante *participante){
    if(participante->getMatricula().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoParticipante::descadastrarParticipante(Participante *participante){
    if(participante->getMatricula().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoParticipante::editarParticipante(Participante *participante){
    if(participante->getMatricula().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

//--------------------------------------------------------------------------------------------
// Implementações dos métodos dos stubs de peca.


//--------------------------------------------------------------------------------------------
// Implementações dos métodos dos stubs de sala.


//--------------------------------------------------------------------------------------------
// Implementações dos métodos dos stubs de sessão.


bool StubServicoProdutosFinanceiros::cadastrarConta(Conta conta){
    if(conta.getNumero().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

//

bool StubServicoProdutosFinanceiros::consultarConta(Conta *conta){
    if(conta->getNumero().getValor().compare(INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar c�digo que atribui valores ao objeto identificado por conta.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}

bool StubServicoProdutosFinanceiros::cadastrarProdutoInvestimento(Produto produto){
    if(produto.getCodigo().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::descadastrarProdutoInvestimento(Codigo codigo){
    if(codigo.getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::realizarAplicacao(Aplicacao aplicacao){
    if(aplicacao.getCodigo().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::recuperarAplicacao(Aplicacao *aplicacao){
    if(aplicacao->getCodigo().getValor().compare(INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar c�digo que atribui valores ao objeto identificado por aplicacao.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}


