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
    data.setValor(VALOR_VALIDO3);
    sessao->setData(data);
    if(sessao->getData().getValor() != VALOR_VALIDO3)
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

//Sala
void TUSala::setUp(){
    sala = new Sala();
    estado = SUCESSO;
}

void TUSala::tearDown(){
    delete sala;
}

void TUSala::testarCenarioSucesso(){

    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    sala->setCodigo(codigo);
    if(sala->getCodigo().getValor() != VALOR_VALIDO_CODIGO)
        estado = FALHA;

    Nome nome;
    nome.setValor(VALOR_VALIDO_NOME);
    sala->setNome(nome);
    if(sala->getNome().getValor() != VALOR_VALIDO_NOME)
        estado = FALHA;

    Capacidade capacidade;
    capacidade.setValor(VALOR_VALIDO_CAPACIDADE);
    sala->setCapacidade(capacidade);
    if(sala->getCapacidade().getValor() != VALOR_VALIDO_CAPACIDADE)
        estado = FALHA;
}

int TUSala::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

// -------------------------------------------------------
// Testes da Clara - 190017503

//------------ Participante
void TUParticipante::setUp(){
    participante = new Participante();
    estado = SUCESSO;
}

void TUParticipante::tearDown(){
    delete participante;
}

void TUParticipante::testarCenarioSucesso(){
    Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;

    try{
        matricula.setValor(VALOR_VALIDO_MATRICULA);
        participante->setMatricula(matricula);
        if(participante->getMatricula().getValor() != VALOR_VALIDO_MATRICULA)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }

    try{
        nome.setValor(VALOR_VALIDO_NOME);
        participante->setNome(nome);
        if(participante->getNome().getValor() != VALOR_VALIDO_NOME)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }

    try{
        sobrenome.setValor(VALOR_VALIDO_SOBRENOME);
        participante->setSobrenome(sobrenome);
        if(participante->getSobrenome().getValor() != VALOR_VALIDO_SOBRENOME)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }

    try{
        email.setValor(VALOR_VALIDO_EMAIL);
        participante->setEmail(email);
        if(participante->getEmail().getValor() != VALOR_VALIDO_EMAIL)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }

    try{
        telefone.setValor(VALOR_VALIDO_TELEFONE);
        participante->setTelefone(telefone);
        if(participante->getTelefone().getValor() != VALOR_VALIDO_TELEFONE)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }

    try{
        senha.setValor(VALOR_VALIDO_SENHA);
        participante->setSenha(senha);
        if(participante->getSenha().getValor() != VALOR_VALIDO_SENHA)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }

    try{
        cargo.setValor(VALOR_VALIDO_CARGO);
        participante->setCargo(cargo);
        if(participante->getCargo().getValor() != VALOR_VALIDO_CARGO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUParticipante::testarCenarioFalha(){
    Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;

    try{
        matricula.setValor(VALOR_INVALIDO_MATRICULA);
        participante->setMatricula(matricula);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if(participante->getMatricula().getValor() == VALOR_INVALIDO_MATRICULA)
            estado = FALHA;
    }

    try{
        nome.setValor(VALOR_INVALIDO_NOME);
        participante->setNome(nome);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if(participante->getNome().getValor() == VALOR_INVALIDO_NOME)
            estado = FALHA;
    }

    try{
        sobrenome.setValor(VALOR_INVALIDO_SOBRENOME);
        participante->setSobrenome(sobrenome);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if(participante->getSobrenome().getValor() == VALOR_INVALIDO_SOBRENOME)
            estado = FALHA;
    }

    try{
        email.setValor(VALOR_INVALIDO_EMAIL);
        participante->setEmail(email);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if(participante->getEmail().getValor() == VALOR_INVALIDO_EMAIL)
            estado = FALHA;
    }

    try{
        telefone.setValor(VALOR_INVALIDO_TELEFONE);
        participante->setTelefone(telefone);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if(participante->getTelefone().getValor() == VALOR_INVALIDO_TELEFONE)
            estado = FALHA;
    }

    try{
        senha.setValor(VALOR_INVALIDO_SENHA);
        participante->setSenha(senha);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if(participante->getSenha().getValor() == VALOR_INVALIDO_SENHA)
            estado = FALHA;
    }

    try{
        cargo.setValor(VALOR_INVALIDO_CARGO);
        participante->setCargo(cargo);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if(participante->getCargo().getValor() == VALOR_INVALIDO_CARGO)
            estado = FALHA;
    }
}

int TUParticipante::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}
