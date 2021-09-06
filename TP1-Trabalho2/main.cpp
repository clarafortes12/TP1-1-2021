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
// Testes de Entidade do Leandro - 180145169

//------------ Peça

    TUPeca testePeca;

    switch(testePeca.run()){
        case TUPeca::SUCESSO: cout << "SUCESSO - Peca" << endl;
                                break;
        case TUPeca::FALHA  : cout << "FALHA   - Peca" << endl;
                                break;
    }

//------------ Sessão
    TUSessao testeSessao;

    switch(testeSessao.run()){
        case TUSessao::SUCESSO: cout << "SUCESSO - Sessao" << endl;
                                break;
        case TUSessao::FALHA  : cout << "FALHA   - Sessao" << endl;
                                break;
    }

// Testes de Domínio do Leandro - 180145169

//------------ Capacidade
    TUCapacidade testeCapacidade;

    switch(testeCapacidade.run()){
        case TUCapacidade::SUCESSO: cout << "SUCESSO - Capacidade" << endl;
                                break;
        case TUCapacidade::FALHA  : cout << "FALHA   - Capacidade" << endl;
                                break;
    }

//------------ Horário
    TUHorario testeHorario;

    switch(testeHorario.run()){
        case TUHorario::SUCESSO: cout << "SUCESSO - Horario" << endl;
                                break;
        case TUHorario::FALHA  : cout << "FALHA   - Horario" << endl;
                                break;
    }

//------------ Senha
    TUSenha testeSenha;

    switch(testeSenha.run()){
        case TUSenha::SUCESSO: cout << "SUCESSO - Senha" << endl;
                                break;
        case TUSenha::FALHA  : cout << "FALHA   - Senha" << endl;
                                break;
    }

//------------ Telefone
    TUTelefone testeTelefone;

    switch(testeTelefone.run()){
        case TUTelefone::SUCESSO: cout << "SUCESSO - Telefone" << endl;
                                break;
        case TUTelefone::FALHA  : cout << "FALHA   - Telefone" << endl;
                                break;
    }

//--------------------------------------------------------------------------------------
// Testes de Entidade da Liz - 180022261

//------------ Sala
    TUSala testeSala;

    switch(testeSala.run()){
        case TUSala::SUCESSO: cout << "SUCESSO - Sala" << endl;
                                break;
        case TUSala::FALHA  : cout << "FALHA   - Sala" << endl;
                                break;
    }

// Testes de Domínio da Liz - 180022261

//------------ Cargo
    TUCargo testeCargo;

    switch(testeCargo.run()){
        case TUCargo::SUCESSO: cout << "SUCESSO - Cargo" << endl;
                                break;
        case TUCargo::FALHA  : cout << "FALHA   - Cargo" << endl;
                                break;
    }

//------------ Matrícula
    TUMatricula testeMatricula;

    switch(testeMatricula.run()){
        case TUMatricula::SUCESSO: cout << "SUCESSO - Matricula" << endl;
                                break;
        case TUMatricula::FALHA  : cout << "FALHA   - Matricula" << endl;
                                break;
    }

//------------ Nome
    TUNome testeNome;

    switch(testeNome.run()){
        case TUNome::SUCESSO: cout << "SUCESSO - Nome" << endl;
                                break;
        case TUNome::FALHA  : cout << "FALHA   - Nome" << endl;
                                break;
    }

//------------ Data
    TUData testeData;

    switch(testeData.run()){
        case TUData::SUCESSO: cout << "SUCESSO - Data" << endl;
                                break;
        case TUData::FALHA  : cout << "FALHA   - Data" << endl;
                                break;
    }

//--------------------------------------------------------------------------------------
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
