#include "Teste_Entidades.h"
#include "Teste_Dominios.h"

// -------------------------------------------------------
// Testes do Leandro - 180145169
//Peca
void TUPeca::setUp(){
    peca = new Peca();
    estado = SUCESSO;
}

void TUPeca::tearDown(){
    delete peca;
}

void TUPeca::testarCenarioSucesso(){

    Codigo codigo;
    codigo.setValor(VALOR_VALIDO1);
    peca->setCodigo(codigo);
    if(peca->getCodigo().getValor() != VALOR_VALIDO1)
        estado = FALHA;

    Nome nome;
    nome.setValor(VALOR_VALIDO2);
    peca->setNome(nome);
    if(peca->getNome().getValor() != VALOR_VALIDO2)
        estado = FALHA;

    Tipo tipo;
    tipo.setValor(VALOR_VALIDO3);
    peca->setTipo(tipo);
    if(peca->getTipo().getValor() != VALOR_VALIDO3)
        estado = FALHA;

    Classificacao classificacao;
    classificacao.setValor(VALOR_VALIDO4);
    peca->setClassificacao(classificacao);
    if(peca->getClassificacao().getValor() != VALOR_VALIDO4)
        estado = FALHA;
}

int TUPeca::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

//Sessao
void TUSessao::setUp(){
    sessao = new Sessao();
    estado = SUCESSO;
}

void TUSessao::tearDown(){
    delete sessao;
}

void TUSessao::testarCenarioSucesso(){

    Codigo codigo;
    codigo.setValor(VALOR_VALIDO1);
    sessao->setCodigo(codigo);
    if(sessao->getCodigo().getValor() != VALOR_VALIDO1)
        estado = FALHA;

    Horario horario;
    horario.setValor(VALOR_VALIDO2);
    sessao->setHorario(horario);
    if(sessao->getHorario().getValor() != VALOR_VALIDO2)
        estado = FALHA;

    Data data;
    data.setValor(VALOR_VALIDO3, VALOR_VALIDO4, VALOR_VALIDO5);
    sessao->setData(data);
    if(sessao->getData().getValor() != VALOR_VALIDO6)
        estado = FALHA;

}

int TUSessao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

// -------------------------------------------------------
// Testes da Liz - 180022261

// -------------------------------------------------------
// Testes da Clara - 190017503