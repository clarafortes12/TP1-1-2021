#include "controladorasservico.h"

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe CntrInteracao.

void CntrInteracao::notificarErroAcesso(){
     cout << endl << "Erro no acesso ao banco de dados.";
     cout << "Digite algo para continuar :";
     getchar();
}

void CntrInteracao::notificarErroDigitacao() {
     cout << endl << "Dado informado incorretamente." << endl << endl;
     cout << "Digite algo para continuar :";
     getchar();
}

void CntrInteracao::notificarSucessoOperacao() {
     cout << endl << "Operacao efetuada com sucesso." << endl << endl;
     cout << "Digite algo para continuar :";
     getchar();
}


//--------------------------------------------------------------------------------------------
//Implementa��es de m�todos de classes controladoras.
//
bool CntrServicoAutenticacao::autenticar(Matricula matricula, Senha senhaEntrada){

    ComandoLerSenha comandoLerSenha(matricula);

    try {
            comandoLerSenha.executar();

            string senhaRecuperada;
            senhaRecuperada = comandoLerSenha.getResultado();

            //Comparar senha informada com a senha recuperada.

            if(senhaRecuperada == senhaEntrada.getValor()) return true;
            cout << endl << "Senha digitada diferente da cadastrada.";
            return false;
    }
    catch(EErroPersistencia &exp) {
            cout << endl << exp.what();
            cout << endl << endl << "Digite algo para continuar.";
            getchar();
    }
}

bool CntrServicoSala::listarSala(){

}

bool CntrServicoSala::visualizarSala(Codigo codigoEntrada){

    Sala sala;

    ComandoPesquisarSala comando(codigoEntrada);

    try {
            comando.executar();
    }
    catch (EErroPersistencia exp) {
            cout << endl << "Erro no acesso ao banco de dados.";;
            return false;
    }

    try {
            sala = comando.getResultado();

            cout << endl << "Resultados obtidos." << endl << endl;
            cout << "Codigo : " << sala.getCodigo().getValor() << endl;
            cout << "Nome : " << sala.getNome().getValor() << endl;
            cout << "Capacidade : " << sala.getCapacidade().getValor() << endl;
            cout << "Digite algo para continuar : ";
            getchar();
    }
    catch(EErroPersistencia exp) {
            cout << endl << exp.what();
            cout << endl << endl << "Digite algo para continuar.";
            getchar();
    }
}

bool CntrServicoSala::incluirSala(Sala sala){

    ComandoCadastrarSala comando (sala);

    try {
            comando.executar();
    }
    catch (EErroPersistencia exp) {
            cout << endl << "Erro no acesso ao banco de dados.";
            return false;
    }

    //notificarSucessoOperacao();
}

bool CntrServicoSala::editarSala(Sala sala){
    /*
    Codigo codigo;

    codigo = sala.getCodigo();

    ComandoPesquisarSala comandoA(codigo);

    try {
            comandoA.executar();
    }
    catch (EErroPersistencia exp) {
            notificarErroAcesso();
            return;
    }

    Sala salaAtual = comandoA.getResultado();

    cout << endl << "Dados atuais:" << endl << endl;
    cout << "Codigo : " << salaAtual.getCodigo().getValor() << endl;
    cout << "Nome : " << salaAtual.getNome().getValor() << endl;
    cout << "Capacidade : " << salaAtual.getCapacidade().getValor() << endl;*/

    // talvez seja melhor deixar so daqui pra baixo:
    ComandoAtualizarSala comandoB(sala);

    try {
            comandoB.executar();
    }
    catch (EErroPersistencia exp) {
            cout << endl << "Erro no acesso ao banco de dados.";
            return false;
    }

    //notificarSucessoOperacao();
}

bool CntrServicoSala::excluirSala(Codigo codigo){

    ComandoRemoverSala comando(codigo);

    try {
            comando.executar();
    }
    catch (EErroPersistencia exp) {
            cout << endl << "Erro no acesso ao banco de dados.";
            return false;
    }

    //notificarSucessoOperacao();
}
