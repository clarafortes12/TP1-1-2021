#include "comandos.h"

//-----------------------------------------------------------------------------------
// Implementações de métodos de comandos.

void ComandoIAGerenteIncluir::executar(ISGerente* cntrISGerente){

    bool resultado;
    Gerente gerente;

    // Código de interação com o usuário.

    while(true){
        try{
            int valor;
            Matricula matricula;
            cout << "Digite a matricula: ";
            cin >> valor;
            matricula.setValor(valor);
            gerente.setMatricula(matricula);
            break;
        }
        catch(invalid_argument &exp){
            cout << "Matricula com formato incorreto" << endl;
        }
    }

    // Solicitar serviço.

    resultado = cntrISGerente->incluir(gerente);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
}

// Método por meio do qual é solicitada a execução do comando.

void ComandoIAGerenteRemover::executar(ISGerente* cntrISGerente){

    bool resultado;
    Matricula matricula;

    // Código de interação com o usuário.

    while(true){
        try{
            int valor;
            cout << "Digite a matricula: ";
            cin >> valor;
            matricula.setValor(valor);
            break;
        }
        catch(invalid_argument &exp){
            cout << "Matricula com formato incorreto" << endl;
        }
    }

    // Solicitar serviço.

    resultado = cntrISGerente->remover(matricula);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
}

// Método por meio do qual é solicitada a execução do comando.

void ComandoIAGerentePesquisar::executar(ISGerente* cntrISGerente){

    bool resultado;
    Gerente gerente;

    // A seguir, incluir código de interação com o usuário.

    // Solicitar serviço.

    resultado = cntrISGerente->pesquisar(gerente);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
}

// Método por meio do qual é solicitada a execução do comando.

void ComandoIAGerenteEditar::executar(ISGerente* cntrISGerente){

    bool resultado;
    Gerente gerente;

    // A seguir, incluir código de interação com o usuário.

    // Solicitar serviço.

    resultado = cntrISGerente->editar(gerente);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }

}
