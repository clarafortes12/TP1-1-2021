#include "controladorasservico.h"

//---------------------------------------------------------------------------
// Implementações de métodos da classe CntrInteracao.

void CntrInteracao::notificarErroAcesso(){
     cout << endl << "Erro no acesso ao banco de dados.";
     cout << "Digite algo para continuar :";
     getch();
}

void CntrInteracao::notificarErroDigitacao() {
     cout << endl << "Dado informado incorretamente." << endl << endl;
     cout << "Digite algo para continuar :";
     getch();
}

void CntrInteracao::notificarSucessoOperacao() {
     cout << endl << "Operacao efetuada com sucesso." << endl << endl;
     cout << "Digite algo para continuar :";
     getch();
}


//--------------------------------------------------------------------------------------------
//Implementações de métodos de classes controladoras.
//
bool CntrServicoAutenticacao::autenticar(Matricula matricula, Senha senhaEntrada){

    ComandoLerSenha comandoLerSenha(matricula);

    try {
            comandoLerSenha.executar();

            string senhaRecuperada;
            senhaRecuperada = comandoLerSenha.getResultado();

            //Comparar senha informada com a senha recuperada.

            if(senhaRecuperada == senhaEntrada) break;
            cout << endl << "Senha digitada diferente da cadastrada.";
            cout << endl << endl << "Digite algo para continuar.";
            getch();
    }
    catch(EErroPersistencia &exp) {
            cout << endl << exp.what();
            cout << endl << endl << "Digite algo para continuar.";
            getch();
    }
}

bool CntrServicoSala::listarSala(){

}

bool CntrServicoSala::visualizarSala(Codigo codigo){
    string codigoEntrada;
    Codigo codigo;
    Sala sala;

    // Mudar para comandos do PDcurses
    CLR_SCR;
    cout << "Visualizar Sala." << endl << endl;
    cout << "Digite o codigo da Sala que deseja visualizar : ";
    cin >> codigoEntrada;

    try {
            codigo.setValor(codigoEntrada);
    }
    catch (invalid_argument &exp) {
            notificarErroDigitacao();
            return;
    }

    ComandoPesquisarSala comando(codigo);

    try {
            comando.executar();
    }
    catch (EErroPersistencia exp) {
            notificarErroAcesso();
            return;
    }

    try {
            sala = comando.getResultado();

            cout << endl << "Resultados obtidos." << endl << endl;
            cout << "Codigo : " << sala.getCodigo().getValor() << endl;
            cout << "Nome : " << sala.getNome().getValor() << endl;
            cout << "Capacidade : " << sala.getCapacidade().getValor() << endl;
            cout << "Digite algo para continuar : ";
            getch();
    }
    catch(EErroPersistencia exp) {
            cout << endl << exp.what();
            cout << endl << endl << "Digite algo para continuar.";
            getch();
    }
}

bool CntrServicoSala::incluirSala(Sala sala){

    string codigoEntrada;
    string nomeEntrada;
    string capacidadeEntrada;

    Codigo codigo;
    Nome nome;
    Capacidade capacidade;

    CLR_SCR;
    cout << "Cadastrar uma sala." << endl << endl;
    cout << "Digite o codigo : ";
    cin >> codigoEntrada;
    cout << "Digite o nome : ";
    cin >> nomeEntrada;
    cout << "Digite a capacidade : ";
    cin >> capacidadeEntrada;

    try {
            codigo.setValor(codigoEntrada);
            nome.setValor(nomeEntrada);
            capacidade.setValor(capacidadeEntrada);
    }
    catch (invalid_argument &exp) {
            notificarErroDigitacao();
            return;
    }

    Sala sala(codigo, nome, capacidade);

    ComandoCadastrarSala comando (sala);

    try {
            comando.executar();
    }
    catch (EErroPersistencia exp) {
            notificarErroAcesso();
            return;
    }

    notificarSucessoOperacao();
}

bool CntrServicoSala::editarSala(Sala sala){
    string codigoEntrada;
    string nomeEntrada;
    string capacidadeEntrada;

    Codigo codigo;
    Nome nome;
    Capacidade capacidade;

    CLR_SCR;

    cout << "Editar uma sala." << endl << endl;
    cout << "Digite o codigo da sala que deseja editar : ";

    cin >> codigoEntrada;

    try {
            codigo.setValor(codigoEntrada);
    }
    catch (invalid_argument &exp) {
            notificarErroDigitacao();
            return;
    }

    ComandoPesquisarSala comandoA(codigo);

    try {
            comandoA.executar();
    }
    catch (EErroPersistencia exp) {
            notificarErroAcesso();
            return;
    }

    Sala sala = comandoA.getResultado();

    cout << endl << "Dados atuais:" << endl << endl;
    cout << "Codigo : " << sala.getCodigo().getValor() << endl;
    cout << "Nome : " << sala.getNome().getValor() << endl;
    cout << "Capacidade : " << sala.getCapacidade().getValor() << endl;

    cout << "Digite os novos dados: " << endl << endl;
    // nao tem codigo pq n pode alterar
    cout << "Nome : ";
    cin >> nomeEntrada;
    cout << "Capacidade : ";

    try {
        codigo.setValor(codigoEntrada);
        nome.setValor(nomeEntrada);
        capacidade.setValor(capacidadeEntrada);
    }
    catch (invalid_argument &exp) {
            notificarErroDigitacao();
            return;
    }

    sala.setCodigo(codigo);
    sala.setNome(nome);
    sala.setCapacidade(capacidade);

    ComandoAtualizarSala comandoB(sala);

    try {
            comandoB.executar();
    }
    catch (EErroPersistencia exp) {
            notificarErroAcesso();
            return;
    }

    notificarSucessoOperacao();
}

bool CntrServicoSala::excluirSala(Codigo codigo){
    string codigoEntrada;
    Codigo codigo;

    CLR_SCR;
    cout << "Excluir uma sala." << endl << endl;
    cout << "Digite o codigo : ";
    cin >> codigoEntrada;

    try {
            codigo.setValor(codigoEntrada);
    }
    catch (invalid_argument &exp) {
            notificarErroDigitacao();
            return;
    }

    ComandoRemoverSala comando(codigo);

    try {
            comando.executar();
    }
    catch (EErroPersistencia exp) {
            notificarErroAcesso();
            return;
    }

    notificarSucessoOperacao();
}
