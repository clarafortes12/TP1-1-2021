#include "controladorasservico.h"

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe CntrInteracao.

void CntrInteracao::notificarErroAcesso(){
    cout << endl << "Erro no acesso ao banco de dados."<< endl << endl;
    cout << "Digite algo para continuar :";
    getchar();
}

void CntrInteracao::notificarErroDigitacao(){
    cout << endl << "Dado informado incorretamente." << endl << endl;
    cout << "Digite algo para continuar :";
    getchar();
}

void CntrInteracao::notificarSucessoOperacao(){
    cout << endl << "Operacao efetuada com sucesso." << endl << endl;
    cout << "Digite algo para continuar :";
    getchar();
}


//--------------------------------------------------------------------------------------------
//Implementa��es de m�todos de classes controladoras.
//
bool CntrServicoAutenticacao::autenticar(Matricula matricula, Senha senhaEntrada)
{

    ComandoLerSenha comandoLerSenha(matricula);

    try
    {
        comandoLerSenha.executar();
        string senhaRecuperada;
        senhaRecuperada = comandoLerSenha.getResultado();

        //Comparar senha informada com a senha recuperada.
        if(senhaRecuperada == senhaEntrada.getValor()) return true;
        return false;
    }
    catch(EErroPersistencia &exp)
    {
        cout << endl << exp.what();
        return false;
    }
    return false;
}

bool CntrServicoParticipante::consultarParticipante(Matricula matricula){
    cout << endl << "Consultar Participante";
    Participante participante;

    ComandoPesquisarParticipante comando(matricula);

    try
    {
        comando.executar();
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";;
        cout << "Digite algo para continuar : ";
        getchar();
        return false;
    }

    try
    {
        getchar();
        participante = comando.getResultado();

        cout << endl << "Resultados obtidos." << endl << endl;
        cout << "Matricula  : " << participante.getMatricula().getValor() << endl;
        cout << "Nome       : " << participante.getNome().getValor() << endl;
        cout << "Sobrenome  : " << participante.getSobrenome().getValor() << endl;
        cout << "Email      : " << participante.getEmail().getValor() << endl;
        cout << "Telefone   : " << participante.getTelefone().getValor() << endl;
        // apresenta a senha? kkkkkkkkk
        cout << "Cargo      : " << participante.getCargo().getValor() << endl;
        cout << "Digite algo para continuar : ";
        getchar();
        return true;
    }
    catch(EErroPersistencia exp)
    {
        cout << endl << exp.what();
        cout << endl << endl << "Digite algo para continuar.";
        getchar();
        return false;
    }
    return false;
}
bool CntrServicoParticipante::cadastrarParticipante(Participante participante){
    cout << endl << "Cadastrar Participante";
    ComandoCadastrarParticipante comando(participante);

    try
    {
        comando.executar();
        return true;
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";
        return false;
    }

    //notificarSucessoOperacao();

    return false;
}
bool CntrServicoParticipante::descadastrarParticipante(Matricula matricula){
    cout << endl << "Descadastrar Participante";
    ComandoRemoverParticipante comando(matricula);

    try
    {
        comando.executar();
        return true;
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";
        return false;
    }
    return false;
}
bool CntrServicoParticipante::editarParticipante(Participante participante){
    cout << endl << "Editar Participante";
    ComandoAtualizarParticipante comando(participante);

    try
    {
        comando.executar();
        return true;
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";
        return false;
    }
    return false;
}

// Assim que der certo Sala, da pra so adaptar para Sessao e Peca
bool CntrServicoSessao::listarSessao(){
    return true;
}
bool CntrServicoSessao::visualizarSessao(Codigo codigo){
    return true;
}
bool CntrServicoSessao::incluirSessao(Sessao sessao){
    return true;
}
bool CntrServicoSessao::editarSessao(Sessao sessao){
    return true;
}
bool CntrServicoSessao::excluirSessao(Codigo codigo){
    return true;
}

bool CntrServicoPeca::listarPeca(){
    return true;
}
bool CntrServicoPeca::visualizarPeca(Codigo codigo){
    return true;
}
bool CntrServicoPeca::incluirPeca(Peca peca){
    return true;
}
bool CntrServicoPeca::editarPeca(Peca peca){
    return true;
}
bool CntrServicoPeca::excluirPeca(Codigo codigo){
    return true;
}

bool CntrServicoSala::listarSala(){
    cout << endl << "Listar Sala";
    return true;
}
bool CntrServicoSala::visualizarSala(Codigo codigoEntrada){

    Sala sala;

    ComandoPesquisarSala comando(codigoEntrada);

    try
    {
        comando.executar();
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";;
        cout << "Digite algo para continuar : ";
        getchar();
        return false;
    }

    try
    {
        getchar();
        sala = comando.getResultado();

        cout << endl << "Resultados obtidos." << endl << endl;
        cout << "Codigo : " << sala.getCodigo().getValor() << endl;
        cout << "Nome : " << sala.getNome().getValor() << endl;
        cout << "Capacidade : " << sala.getCapacidade().getValor() << endl;
        cout << "Digite algo para continuar : ";
        getchar();
        return true;
    }
    catch(EErroPersistencia exp)
    {
        cout << endl << exp.what();
        cout << endl << endl << "Digite algo para continuar.";
        getchar();
        return false;
    }
}
bool CntrServicoSala::incluirSala(Sala sala){

    ComandoCadastrarSala comando(sala);

    try
    {
        comando.executar();
        return true;
    }
    catch (EErroPersistencia exp)
    {
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

    try
    {
        comandoB.executar();
        return true;
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";
        return false;
    }

    //notificarSucessoOperacao();
}
bool CntrServicoSala::excluirSala(Codigo codigo){

    ComandoRemoverSala comando(codigo);

    try
    {
        comando.executar();
        return true;
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";
        return false;
    }

    //notificarSucessoOperacao();
}
