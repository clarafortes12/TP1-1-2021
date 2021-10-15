#include "controladorasservico.h"

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe CntrInteracao.

void CntrInteracao::notificarErroAcesso(){
    cout << endl << "Erro no acesso ao banco de dados."<< endl << endl;
    cout << "Digite algo para continuar :";
    getchar();
    fflush(stdin);
}

void CntrInteracao::notificarErroDigitacao(){
    cout << endl << "Dado informado incorretamente." << endl << endl;
    cout << "Digite algo para continuar :";
    getchar();
    fflush(stdin);
}

void CntrInteracao::notificarSucessoOperacao(){
    cout << endl << "Operacao efetuada com sucesso." << endl << endl;
    cout << "Digite algo para continuar :";
    getchar();
    fflush(stdin);
}


//--------------------------------------------------------------------------------------------
//Implementa��es de m�todos de classes controladoras.
//
bool CntrServicoAutenticacao::autenticar(Matricula matricula, Senha senhaEntrada){

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
    Participante participante;
    Peca peca;
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

    try{
        participante = comando.getResultado();
        if(participante.getCodigoPeca().getValor() == ""){
            cout << endl << "Seus Dados" << endl << endl;
            cout << "Matricula  : " << participante.getMatricula().getValor() << endl;
            cout << "Nome       : " << participante.getNome().getValor() << endl;
            cout << "Sobrenome  : " << participante.getSobrenome().getValor() << endl;
            cout << "Email      : " << participante.getEmail().getValor() << endl;
            cout << "Telefone   : " << participante.getTelefone().getValor() << endl;
            cout << "Senha      : " << participante.getSenha().getValor() << endl;
            cout << "Cargo      : " << participante.getCargo().getValor() << endl;
            cout << endl << "Participante de nenhuma peca" << endl << endl;
            cout << "Digite algo para continuar : ";
            getchar();
            return true;
        }else{
            ComandoPesquisarPeca comando(participante.getCodigoPeca().getValor());

            try
            {
                comando.executar();
            }
            catch (EErroPersistencia exp)
            {
                cout << endl << "Erro no acesso ao banco de dados.";;
                return false;
            }

            try
            {
                peca = comando.getResultado();
                cout << endl << "Seus Dados" << endl << endl;
                cout << "Matricula  : " << participante.getMatricula().getValor() << endl;
                cout << "Nome       : " << participante.getNome().getValor() << endl;
                cout << "Sobrenome  : " << participante.getSobrenome().getValor() << endl;
                cout << "Email      : " << participante.getEmail().getValor() << endl;
                cout << "Telefone   : " << participante.getTelefone().getValor() << endl;
                cout << "Senha      : " << participante.getSenha().getValor() << endl;
                cout << "Cargo      : " << participante.getCargo().getValor() << endl;
                cout << endl << "Dados da Peca que e Participante" << endl << endl;
                cout << "Codigo : " << peca.getCodigo().getValor() << endl;
                cout << "Nome : " << peca.getNome().getValor() << endl;
                cout << "Tipo : " << peca.getTipo().getValor() << endl;
                cout << "Classificacao : " << peca.getClassificacao().getValor() << endl;
                cout << "Digite algo para continuar : ";
                getchar();
                return true;
            }
            catch(EErroPersistencia exp)
            {
                cout << endl << exp.what();
                return false;
            }
        }
    }
    catch(EErroPersistencia exp){
        cout << endl << exp.what();
        cout << endl << endl << "Digite algo para continuar.";
        getchar();
        return false;
    }
    return false;
}
bool CntrServicoParticipante::cadastrarParticipante(Participante participante){
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

    return false;
}
bool CntrServicoParticipante::descadastrarParticipante(Matricula matricula){
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
bool CntrServicoParticipante::cadastrarParticipantePeca(Participante participante){
    Peca peca;
    int pecas;
    ComandoPesquisarPeca comando(participante.getCodigoPeca().getValor());
    try
    {
        comando.executar();
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";;
        return false;
    }

    try
    {
        peca = comando.getResultado();

        pecas = pesquisarParticipantePeca(participante.getCodigoPeca().getValor());
        if(pecas <= 10){
            ComandoCadastrarParticipantePeca comando(participante);
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
        }else{
            cout << endl << "Peca com numero maximo de participantes.";
            return false;
        }
    }
    catch(EErroPersistencia exp)
    {
        cout << endl << exp.what();
        return false;
    }

    return false;
}
int CntrServicoParticipante::pesquisarParticipantePeca(Codigo codigo){
    int pecas;

    ComandoPesquisarParticipantePeca comando(codigo);

    try
    {
        comando.executar();
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";;
        cout << "Digite algo para continuar : ";
        getchar();
        fflush(stdin);
        return -1;
    }

    try
    {
        pecas = comando.getResultado();
        return pecas;
    }
    catch(EErroPersistencia exp)
    {
        cout << endl << exp.what();
        cout << endl << endl << "Digite algo para continuar.";
        getchar();
        return -1;
    }
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
        fflush(stdin);
        return false;
    }

    try
    {
        sessoes = comando.getResultado();

        cout << "Resultados obtidos:" << endl << endl;

        if (sessoes.empty()){
            cout << endl << "Retorno vazio de sessoes.";;
            cout << "Digite algo para continuar : ";
            getchar();
            fflush(stdin);
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
        fflush(stdin);
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
    Peca peca;
    Sala sala;

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
        sessao = comando.getResultado();
        if((sessao.getCodigoPeca().getValor()=="") && (sessao.getCodigoSala().getValor()=="")){

            cout << endl << "Resultados obtidos." << endl << endl;
            cout << "Codigo  : " << sessao.getCodigo().getValor() << endl;
            cout << "Data    : " << sessao.getData().getValor() << endl;
            cout << "Horario : " << sessao.getHorario().getValor() << endl;
            cout << endl << "Sessao sem Peca e sem Sala." << endl << endl;
            return true;
        }
        else{
            if(sessao.getCodigoPeca().getValor()==""){
                ComandoPesquisarSala comando(sessao.getCodigoSala().getValor());
                try
                {
                    comando.executar();
                }
                catch (EErroPersistencia exp)
                {
                    cout << endl << "Erro no acesso ao banco de dados.";;
                    return false;
                }
                sala = comando.getResultado();
                cout << endl << "Resultados obtidos." << endl << endl;
                cout << "Codigo    : " << sessao.getCodigo().getValor() << endl;
                cout << "Data      : " << sessao.getData().getValor() << endl;
                cout << "Horario   : " << sessao.getHorario().getValor() << endl;
                cout << endl << "Sessao sem Peca." << endl << endl;
                cout << endl << "Dados da sala:" << endl << endl;
                cout << "Codigo    : " << sala.getCodigo().getValor() << endl;
                cout << "Nome      : " << sala.getNome().getValor() << endl;
                cout << "Capacidade: " << sala.getCapacidade().getValor() << endl;
                return true;
            }
            else{
                ComandoPesquisarPeca comando(sessao.getCodigoPeca().getValor());
                 try
                {
                    comando.executar();
                }
                catch (EErroPersistencia exp)
                {
                    cout << endl << "Erro no acesso ao banco de dados.";;
                    return false;
                }
                peca = comando.getResultado();
                if(sessao.getCodigoSala().getValor()==""){
                    cout << endl << "Resultados obtidos." << endl << endl;
                    cout << "Codigo  : " << sessao.getCodigo().getValor() << endl;
                    cout << "Data    : " << sessao.getData().getValor() << endl;
                    cout << "Horario : " << sessao.getHorario().getValor() << endl;
                    cout << endl << "Dados da peca da sessao:" << endl << endl;
                    cout << "Codigo : " << peca.getCodigo().getValor() << endl;
                    cout << "Nome : " << peca.getNome().getValor() << endl;
                    cout << "Tipo : " << peca.getTipo().getValor() << endl;
                    cout << "Classificacao : " << peca.getClassificacao().getValor() << endl;
                    cout << endl << "Sessao sem Sala." << endl << endl;
                    return true;
                }
                else{
                    ComandoPesquisarSala comando(sessao.getCodigoSala().getValor());
                    try
                    {
                        comando.executar();
                    }
                    catch (EErroPersistencia exp)
                    {
                        cout << endl << "Erro no acesso ao banco de dados.";;
                        return false;
                    }
                    sala = comando.getResultado();
                    cout << endl << "Resultados obtidos." << endl << endl;
                    cout << "Codigo  : " << sessao.getCodigo().getValor() << endl;
                    cout << "Data    : " << sessao.getData().getValor() << endl;
                    cout << "Horario : " << sessao.getHorario().getValor() << endl;
                    cout << endl << "Dados da peca da sessao:" << endl << endl;
                    cout << "Codigo : " << peca.getCodigo().getValor() << endl;
                    cout << "Nome : " << peca.getNome().getValor() << endl;
                    cout << "Tipo : " << peca.getTipo().getValor() << endl;
                    cout << "Classificacao : " << peca.getClassificacao().getValor() << endl;
                    cout << endl << "Dados da sala:" << endl << endl;
                    cout << "Codigo    : " << sala.getCodigo().getValor() << endl;
                    cout << "Nome      : " << sala.getNome().getValor() << endl;
                    cout << "Capacidade: " << sala.getCapacidade().getValor() << endl;
                    return true;
                }
            }
        }
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
int CntrServicoSessao::pesquisarSessaoPeca(Codigo codigo){
    int pecas;

    ComandoPesquisarParticipantePeca comando(codigo);

    try
    {
        comando.executar();
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";;
        cout << "Digite algo para continuar : ";
        getchar();
        fflush(stdin);
        return -1;
    }

    try
    {
        pecas = comando.getResultado();
        return pecas;
    }
    catch(EErroPersistencia exp)
    {
        cout << endl << exp.what();
        cout << endl << endl << "Digite algo para continuar.";
        getchar();
        return -1;
    }

}
bool CntrServicoSessao::cadastrarSessaoPeca(Sessao sessao){
    Peca peca;
    int pecas;

    ComandoPesquisarPeca comando(sessao.getCodigoPeca().getValor());
    try
    {
        comando.executar();
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";;
        return false;
    }

    try
    {
        peca = comando.getResultado();

        pecas = pesquisarSessaoPeca(sessao.getCodigoPeca().getValor());
        if(pecas <= 5){
            ComandoCadastrarSessaoPeca comando(sessao);
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
        }else{
            cout << endl << "Peca com numero maximo de participantes.";
            return false;
        }
    }
    catch(EErroPersistencia exp)
    {
        cout << endl << exp.what();
        return false;
    }

    return false;
}
bool CntrServicoSessao::cadastrarSessaoSala(Sessao sessao){
    Sala sala;

    ComandoPesquisarSala comando(sessao.getCodigoSala().getValor());
    try
    {
        comando.executar();
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";;
        return false;
    }

    try
    {
        sala = comando.getResultado();

        ComandoCadastrarSessaoPeca comando(sessao);
        try{
            comando.executar();
            return true;
        }
        catch (EErroPersistencia exp){
            cout << endl << "Erro no acesso ao banco de dados.";
            return false;
        }
        return false;
    }
    catch(EErroPersistencia exp)
    {
        cout << endl << exp.what();
        return false;
    }

    return false;
}


bool CntrServicoPeca::listarPeca(){
    list<Peca> pecas;
    Peca peca;

    ComandoListarPeca comando;

    try
    {
        comando.executar();
    }
    catch (EErroPersistencia exp)
    {
        cout << endl << "Erro no acesso ao banco de dados.";;
        cout << "Digite algo para continuar : ";
        getchar();
        fflush(stdin);
        return false;
    }

    try
    {
        pecas = comando.getResultado();
        cout << "Resultados obtidos:" << endl << endl;

        if (pecas.empty()){
            cout << endl << "Retorno vazio de pecas.";;
            cout << "Digite algo para continuar : ";
            getchar();
            fflush(stdin);
            return false;
        }

        while(!pecas.empty()){
            peca = pecas.back();
            cout << "Codigo : " << peca.getCodigo().getValor() << endl;
            cout << "Nome : " << peca.getNome().getValor() << endl << endl;
            pecas.pop_back();
        }

        cout << "Essas sao as pecas cadastradas." << endl;
        cout << "Digite algo para continuar : ";
        getchar();
        fflush(stdin);
        return true;
    }
    catch(EErroPersistencia exp)
    {
        cout << endl << exp.what();
        cout << endl << endl << "Digite algo para continuar.";
        getchar();
        fflush(stdin);
        return false;
    }
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
        return false;
    }

    try
    {
        peca = comando.getResultado();

        cout << endl << "Resultados obtidos." << endl << endl;
        cout << "Codigo : " << peca.getCodigo().getValor() << endl;
        cout << "Nome : " << peca.getNome().getValor() << endl;
        cout << "Tipo : " << peca.getTipo().getValor() << endl;
        cout << "Classificacao : " << peca.getClassificacao().getValor() << endl;
        return true;
    }
    catch(EErroPersistencia exp)
    {
        cout << endl << exp.what();
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
        fflush(stdin);
        return false;
    }

    try
    {
        salas = comando.getResultado();

        cout << "Resultados obtidos:" << endl << endl;

        if (salas.empty()){
            cout << endl << "Retorno vazio de salas.";;
            cout << "Digite algo para continuar : ";
            getchar();
            fflush(stdin);
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
        fflush(stdin);
        return true;
    }
    catch(EErroPersistencia exp)
    {
        cout << endl << exp.what();
        cout << endl << endl << "Digite algo para continuar.";
        getchar();
        fflush(stdin);
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
        sala = comando.getResultado();

        cout << endl << "Resultados obtidos:" << endl << endl;
        cout << "Codigo : " << sala.getCodigo().getValor() << endl;
        cout << "Nome : " << sala.getNome().getValor() << endl;
        cout << "Capacidade : " << sala.getCapacidade().getValor() << endl;
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
