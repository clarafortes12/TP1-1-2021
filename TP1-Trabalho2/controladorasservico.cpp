#include "controladorasservico.h"

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
}

bool CntrServicoSala::incluirSala(Sala sala){
}

bool CntrServicoSala::editarSala(Sala sala){
}

bool CntrServicoSala::excluirSala(Codigo codigo){
}
