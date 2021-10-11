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

        cout << endl << "Seus Dados" << endl << endl;
        cout << "Matricula  : " << participante.getMatricula().getValor() << endl;
        cout << "Nome       : " << participante.getNome().getValor() << endl;
        cout << "Sobrenome  : " << participante.getSobrenome().getValor() << endl;
        cout << "Email      : " << participante.getEmail().getValor() << endl;
        cout << "Telefone   : " << participante.getTelefone().getValor() << endl;
        cout << "Senha      : " << participante.getSenha().getValor() << endl;
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
    list<Sessao> sessoes;
    Sessao sessao;

    ComandoListarSessao comando;

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
        sessoes = comando.getResultado();

        cout << "Resultados obtidos:" << endl << endl;

        if (sessoes.empty()){
            cout << endl << "Retorno vazio de sessoes.";;
            cout << "Digite algo para continuar : ";
            getchar();
            return false;
        }

        while(!sessoes.empty()){
            sessao = sessoes.back();
            cout << "Codigo : " << sessao.getCodigo().getValor() << endl;
            cout << "Data : " << sessao.getData().getValor() << endl << endl;
            sessoes.pop_back();
        }

        cout << "Essas sao as sessoes cadastradas." << endl;
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
bool CntrServicoSessao::visualizarSessao(Codigo codigoEntrada){
    Sessao sessao;

    ComandoPesquisarSessao comando(codigoEntrada);

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
        sessao = comando.getResultado();

        cout << endl << "Resultados obtidos." << endl << endl;
        cout << "Codigo  : " << sessao.getCodigo().getValor() << endl;
        cout << "Data    : " << sessao.getData().getValor() << endl;
        cout << "Horário : " << sessao.getHorario().getValor() << endl;
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
bool CntrServicoSessao::incluirSessao(Sessao sessao){

    ComandoCadastrarSessao comando(sessao);

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
}
bool CntrServicoSessao::editarSessao(Sessao sessao){
    ComandoAtualizarSessao comandoB(sessao);

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
}
bool CntrServicoSessao::excluirSessao(Codigo codigo){
    ComandoRemoverSessao comando(codigo);

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
}

bool CntrServicoPeca::listarPeca(){
    return true;
}
bool CntrServicoPeca::visualizarPeca(Codigo codigoEntrada){
    Peca peca;

    ComandoPesquisarPeca comando(codigoEntrada);

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
        peca = comando.getResultado();

        cout << endl << "Resultados obtidos." << endl << endl;
        cout << "Codigo : " << peca.getCodigo().getValor() << endl;
        cout << "Nome : " << peca.getNome().getValor() << endl;
        cout << "Tipo : " << peca.getTipo().getValor() << endl;
        cout << "Capacidade : " << peca.getClassificacao().getValor() << endl;
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
bool CntrServicoPeca::incluirPeca(Peca peca){

    ComandoCadastrarPeca comando(peca);

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
}
bool CntrServicoPeca::editarPeca(Peca peca){
    ComandoAtualizarPeca comandoB(peca);

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
}
bool CntrServicoPeca::excluirPeca(Codigo codigoEntrada){
    ComandoRemoverPeca comando(codigoEntrada);

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
}

bool CntrServicoSala::listarSala(){

    list<Sala> salas;
    Sala sala;

    ComandoListarSala comando;

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
        salas = comando.getResultado();

        cout << "Resultados obtidos:" << endl << endl;

        if (salas.empty()){
            cout << endl << "Retorno vazio de salas.";;
            cout << "Digite algo para continuar : ";
            getchar();
            return false;
        }

        while(!salas.empty()){
            sala = salas.back();
            cout << "Codigo : " << sala.getCodigo().getValor() << endl;
            cout << "Nome : " << sala.getNome().getValor() << endl << endl;
            salas.pop_back();
        }

        cout << "Essas sao as salas cadastradas." << endl;
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

        cout << endl << "Resultados obtidos:" << endl << endl;
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

    /*Codigo codigo;

    codigo = sala.getCodigo();

    ComandoPesquisarSala comandoA(codigo);

    try {
            comandoA.executar();
    }
    catch (EErroPersistencia exp) {
        cout << endl << "Erro no acesso ao banco de dados.";
            //notificarErroAcesso();
        return false;
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
