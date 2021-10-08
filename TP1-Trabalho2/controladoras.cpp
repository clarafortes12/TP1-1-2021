#include "controladoras.h"
//#include "comandos.h"

//-----------------------------------------------------------------------------------
// Implmentações de métodos de classe controladora.

bool CntrIAAutenticacao::autenticar(Matricula *matricula){

    bool resultado;
    Senha senha;
    int entrada;

    // Solicitar matricula e senha.

    while(true) {
        try {
            cout << "Digite a matricula : ";
            cin >> entrada;
            matricula->setValor(entrada);
            cout << "Digite a senha     : ";
            cin >> entrada;
            senha.setValor(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Dado em formato incorreto." << endl;
        }
    }

    resultado = cntrISAutenticacao->autenticar(*matricula, senha);  // Solicitar autenticação.

    return resultado;                                               // Informar resultado da autenticação.
}

//-----------------------------------------------------------------------------------
// Implmentações de métodos de classe controladora.

void CntrIAGerente::executar(const Matricula &matricula){

    ComandoIAGerente *comando;

    int opcao;

    while(true){

        // Apresentar opções.

        cout << endl << "Gerenciamento de Gerente." << endl << endl;
        cout << "Incluir   - " << INCLUIR << endl;
        cout << "Remover   - " << REMOVER << endl;
        cout << "Pesquisar - " << PESQUISAR << endl;
        cout << "Editar    - " << EDITAR << endl;
        cout << "Retornar  - " << RETORNAR << endl << endl;
        cout << "Selecione uma opcao :";

        cin >> opcao;

        switch(opcao){
            case INCLUIR:   comando = new ComandoIAGerenteIncluir();
                            comando->executar(cntrISGerente);
                            delete comando;
                            break;
            case REMOVER:   comando = new ComandoIAGerenteRemover();
                            comando->executar(cntrISGerente);
                            delete comando;
                            break;
            case PESQUISAR: comando = new ComandoIAGerentePesquisar();
                            comando->executar(cntrISGerente);
                            delete comando;
                            break;
            case EDITAR:    comando = new ComandoIAGerenteEditar();
                            comando->executar(cntrISGerente);
                            delete comando;
                            break;
        }
        if(opcao == RETORNAR){
            break;
        }
    }
    return;
}

void CntrIAPeca::executar(const Matricula &matricula){

    ComandoIAPeca *comando;

    int opcao;

    while(true){

        // Apresentar opções.

        cout << endl << "Gerenciamento de Peca." << endl << endl;
        cout << "Incluir   - " << cadastrar << endl;
        cout << "Remover   - " << descadastrar << endl;
        cout << "Pesquisar - " << listar << endl;
        cout << "Editar    - " << alterar << endl;
        cout << "Retornar  - " << RETORNAR << endl << endl;
        cout << "Selecione uma opcao :";

        cin >> opcao;

        switch(opcao){
            case cadastrar:   comando = new ComandoIAPecaIncluir();
                            comando->executar(cntrISPeca);
                            delete comando;
                            break;
            case descadastrar:   comando = new ComandoIAPecaRemover();
                            comando->executar(cntrISPeca);
                            delete comando;
                            break;
            case listar: comando = new ComandoIAPecaPesquisar();
                            comando->executar(cntrISPeca);
                            delete comando;
                            break;
            case alterar:    comando = new ComandoIAPecaEditar();
                            comando->executar(cntrISPeca);
                            delete comando;
                            break;
        }
        if(opcao == RETORNAR){
            break;
        }
    }
    return;
}

