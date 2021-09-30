#include "comandos.h"

//-----------------------------------------------------------------------------------
// Implementa��es de m�todos de comandos.

void ComandoIAGerenteIncluir::executar(ISGerente* cntrISGerente){

    bool resultado;
    Gerente gerente;

    // C�digo de intera��o com o usu�rio.

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

    // Solicitar servi�o.

    resultado = cntrISGerente->incluir(gerente);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
}

// M�todo por meio do qual � solicitada a execu��o do comando.

void ComandoIAGerenteRemover::executar(ISGerente* cntrISGerente){

    bool resultado;
    Matricula matricula;

    // C�digo de intera��o com o usu�rio.

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

    // Solicitar servi�o.

    resultado = cntrISGerente->remover(matricula);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
}

// M�todo por meio do qual � solicitada a execu��o do comando.

void ComandoIAGerentePesquisar::executar(ISGerente* cntrISGerente){

    bool resultado;
    Gerente gerente;

    // A seguir, incluir c�digo de intera��o com o usu�rio.

    // Solicitar servi�o.

    resultado = cntrISGerente->pesquisar(gerente);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
}

// M�todo por meio do qual � solicitada a execu��o do comando.

void ComandoIAGerenteEditar::executar(ISGerente* cntrISGerente){

    bool resultado;
    Gerente gerente;

    // A seguir, incluir c�digo de intera��o com o usu�rio.

    // Solicitar servi�o.

    resultado = cntrISGerente->editar(gerente);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }

}
