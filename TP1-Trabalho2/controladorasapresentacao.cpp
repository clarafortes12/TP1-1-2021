#include "controladorasapresentacao.h"

//--------------------------------------------------------------------------------------------
// Implementa��es dos m�todos de classes controladoras.

//--------------------- Controladora de Apresentacao e Controle -----------------------------------------------------------------------

void CntrApresentacaoControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Acessar sistema.";
    char texto3[]="2 - Cadastrar participante.";
    char texto4_1[]="3 - Listar pecas.";
    char texto4_2[]="4 - Listar sessoes.";
    char texto4_3[]="5 - Listar salas.";
    char texto5[]="6 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de sele��o de servi�o (usuario autenticado).

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="1 - Selecionar servicos de participante.";
    char texto8_1[]="2 - Selecionar servicos relacionados a pecas.";
    char texto8_2[]="3 - Selecionar servicos relacionados a sessoes.";
    char texto8_3[]="4 - Selecionar servicos relacionados a salas.";
    char texto9[]="5 - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";

    int campo;

    bool apresentar = true;


    while(apresentar)
    {

        // Apresenta tela inicial.

        CLR_SCR;

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4_1 << endl;
        cout << texto4_2 << endl;
        cout << texto4_3 << endl;
        cout << texto5 << endl;

        campo = getchar() - 48;
        fflush(stdin);

        switch(campo)
        {
        case 1:
            if(cntrApresentacaoAutenticacao->autenticar(&matricula))
            {
                bool apresentar = true;
                while(apresentar)
                {

                    // Apresenta tela de sele��o de servi�o.

                    CLR_SCR;

                    cout << texto6 << endl;
                    cout << texto7 << endl;
                    cout << texto8_1 << endl;
                    cout << texto8_2 << endl;
                    cout << texto8_3 << endl;
                    cout << texto9 << endl;

                    campo = getchar() - 48;
                    fflush(stdin);

                    switch(campo)
                    {
                    case 1:
                        apresentar = cntrApresentacaoParticipante->executar(matricula);
                        break;
                    case 2:
                        cntrApresentacaoPeca->executar(matricula);
                        break;
                    case 3:
                        cntrApresentacaoSessao->executar(matricula);
                        break;
                    case 4:
                        cntrApresentacaoSala->executar(matricula);
                        break;
                    case 5:
                        apresentar = false;
                        break;
                    }
                }
            }
            else
            {

                CLR_SCR;
                cout << texto10 << endl;
                getchar();
            }
            break;
        case 2:
            cntrApresentacaoParticipante->executar();
            break;
        case 3:
            cntrApresentacaoPeca->executar();
            break;
        case 4:
            cntrApresentacaoSessao->executar();
            break;
        case 5:
            cntrApresentacaoSala->executar();
            break;
        case 6:
            apresentar = false;
            break;
        }
    }
    return;
}

//--------------------- Controladora de Autenticacao -----------------------------------------------------------------------

bool CntrApresentacaoAutenticacao::autenticar(Matricula *matricula){

    // Mensagens a serem apresentadas na tela de autentica��o.

    char texto1[]="Digite a Matricula    : ";
    char texto2[]="Digite a senha        : ";
    char texto3[]="Dado em formato incorreto. Digite algo para continuar.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    Senha senha;

    while(true)
    {

        // Apresenta tela de autentica��o.
        CLR_SCR;
        cout << texto1 << " ";
        cin >> campo1;
        fflush(stdin);

        cout << texto2 << " ";
        cin >> campo2;
        fflush(stdin);

        try
        {
            matricula->setValor(string(campo1));
            senha.setValor(string(campo2));
            break;
        }
        catch(invalid_argument &exp)
        {
            CLR_SCR;
            cout << texto3 << endl;
            getchar();
            fflush(stdin);
        }
    }
    return (cntrServicoAutenticacao->autenticar(*matricula, senha));
}

//--------------------- Controladoras de Participante -----------------------------------------------------------------------

bool CntrApresentacaoParticipante::executar(Matricula matricula)
{

    // Mensagens a serem apresentadas na tela de sele��o de servi�o..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar dados.";
    char texto3[]="2 - Editar dados.";
    char texto4[]="3 - Deletar cadastro.";
    char texto5[]="4 - Cadastro em peca.";
    char texto6[]="5 - Retornar.";

    int campo;

    bool apresentar = true;
    bool descadastrado = true;
    while(apresentar)
    {

        // Apresenta tela de sela��o de servi�o.

        CLR_SCR;

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;
        cout << texto6 << endl;

        campo = getchar() - 48;
        fflush(stdin);

        switch(campo)
        {
        case 1:
            consultarParticipante(matricula);
            break;
        case 2:
            editarParticipante(matricula);
            break;
        case 3:
            descadastrado = descadastrarParticipante(matricula);
            if(descadastrado == true){
                return false;
            }
            else{
                return true;
            }
            break;
        case 4:
            cadastrarParticipantePeca(matricula);
        case 5:
            apresentar = false;
            break;
        }
    }
    return true;
}

void CntrApresentacaoParticipante::executar()
{
    cadastrarParticipante();
}

void CntrApresentacaoParticipante::cadastrarParticipante()
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome            :";
    char texto3[] ="Sobrenome       :";
    char texto4[] ="E-mail          :";
    char texto5[] ="Telefone        :";
    char texto6[] ="Senha           :";
    char texto7[] ="Matricula       :";
    char texto8[] ="Cargo           :";
    char texto9[]="Dados em formato incorreto. Digite algo.";
    char texto10[]="Sucesso no cadastramento. Digite algo.";
    char texto11[]="Falha no cadastramento. Digite algo.";

    char campo_nome[50], campo_sobrenome[50], campo_email[350];
    char campo_telefone[50], campo_senha[50], campo_cargo[50], campo_matricula[50];

    // Instancia os dom�nios.

    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Matricula matricula;
    Cargo cargo;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin.getline(campo_nome,sizeof(campo_nome));
    fflush(stdin);

    cout << texto3 << " ";
    cin.getline(campo_sobrenome,sizeof(campo_sobrenome));
    fflush(stdin);

    cout << texto4 << " ";
    cin >> campo_email;
    fflush(stdin);

    cout << texto5 << " ";
    cin >> campo_telefone;
    fflush(stdin);

    cout << texto6 << " ";
    cin >> campo_senha;
    fflush(stdin);

    cout << texto7 << " ";
    cin >> campo_matricula;
    fflush(stdin);

    cout << texto8 << " ";
    cin >> campo_cargo;
    fflush(stdin);

    try
    {
        nome.setValor(string(campo_nome));
        sobrenome.setValor(string(campo_sobrenome));
        email.setValor(string(campo_email));
        telefone.setValor(string(campo_telefone));
        senha.setValor(string(campo_senha));
        matricula.setValor(string(campo_matricula));
        cargo.setValor(string(campo_cargo));

    }
    catch(invalid_argument &exp)
    {
        CLR_SCR;
        cout << texto9 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    Participante participante;

    participante.setNome(nome);
    participante.setSobrenome(sobrenome);
    participante.setEmail(email);
    participante.setTelefone(telefone);
    participante.setSenha(senha);
    participante.setCargo(cargo);
    participante.setMatricula(matricula);

    if(cntrServicoParticipante->cadastrarParticipante(participante)){
        CLR_SCR;
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }
    cout << texto11 << endl;
    getchar();
    fflush(stdin);
    return;
}

void CntrApresentacaoParticipante::consultarParticipante(Matricula matricula)
{
    char texto2[]="Falha na visualizacao. Digite algo.";

    if(cntrServicoParticipante->consultarParticipante(matricula)) return;

    cout << texto2 << endl;
    getchar();
    fflush(stdin);
    return;

}

void CntrApresentacaoParticipante::editarParticipante(Matricula matricula)
{
     // Mensagens a serem apresentadas na tela de cadastramento.
    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome            :";
    char texto3[] ="Sobrenome       :";
    char texto4[] ="E-mail          :";
    char texto5[] ="Telefone        :";
    char texto6[] ="Senha           :";
    char texto7[] ="Cargo           :";
    char texto8[]="Dados em formato incorreto. Digite algo.";
    char texto9[]="Sucesso no cadastramento. Digite algo.";
    char texto10[]="Falha no cadastramento. Digite algo.";

    char campo_nome[50], campo_sobrenome[50], campo_email[350];
    char campo_telefone[50], campo_senha[50], campo_cargo[50];

    // Instancia os dom�nios.

    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin.getline(campo_nome,sizeof(campo_nome));
    fflush(stdin);

    cout << texto3 << " ";
    cin.getline(campo_sobrenome,sizeof(campo_sobrenome));
    fflush(stdin);

    cout << texto4 << " ";
    cin >> campo_email;
    fflush(stdin);

    cout << texto5 << " ";
    cin >> campo_telefone;
    fflush(stdin);

    cout << texto6 << " ";
    cin >> campo_senha;
    fflush(stdin);

    cout << texto7 << " ";
    cin >> campo_cargo;
    fflush(stdin);
    try
    {
        nome.setValor(string(campo_nome));
        sobrenome.setValor(string(campo_sobrenome));
        email.setValor(string(campo_email));
        telefone.setValor(string(campo_telefone));
        senha.setValor(string(campo_senha));
        cargo.setValor(string(campo_cargo));

    }
    catch(invalid_argument &exp)
    {
        CLR_SCR;
        cout << texto8 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    Participante participante;

    participante.setNome(nome);
    participante.setSobrenome(sobrenome);
    participante.setEmail(email);
    participante.setTelefone(telefone);
    participante.setMatricula(matricula);
    participante.setSenha(senha);
    participante.setCargo(cargo);

    if(cntrServicoParticipante->editarParticipante(participante))
    {
        CLR_SCR;
        cout << texto9 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    cout << texto10 << endl;
    getchar();
    fflush(stdin);

    return;

}

bool CntrApresentacaoParticipante::descadastrarParticipante(Matricula matricula)
{

    char texto1[] ="Informe a sua matricula: ";
    char texto2[]="Dado em formato incorreto. Digite algo.";
    char texto3[]="Sucesso na exclusao. Digite algo.";
    char texto4[]="Falha na exclusao. Digite algo.";
    char texto5[]="Matricula informada incorretamente.Digite algo.";

    char campo_matricula[80];

    Matricula matricula_nova;

    CLR_SCR;

    cout << texto1 << " ";
    cin >> campo_matricula;
    fflush(stdin);

    try
    {
        matricula_nova.setValor(string(campo_matricula));
    }
    catch(invalid_argument &exp)
    {
        cout << texto2 << endl;
        getchar();
        fflush(stdin);
        return false;
    }
    if(matricula_nova.getValor() == matricula.getValor()){
        if(cntrServicoParticipante->descadastrarParticipante(matricula)){
            cout << texto3 << endl;
            getchar();
            fflush(stdin);
            return true;
        }
    }
    else{
        cout << texto5 << endl;
        getchar();
        fflush(stdin);
        return false;
    }
    cout << texto4 << endl;
    getchar();
    fflush(stdin);
    return false;

}

void CntrApresentacaoParticipante::cadastrarParticipantePeca(Matricula matricula)
{
     // Mensagens a serem apresentadas na tela de cadastramento de participante em peca.
    char texto1[] ="Preencha o seguinte campo: ";
    char texto2[] ="Codigo Peca     :";
    char texto3[]="Dados em formato incorreto. Digite algo.";
    char texto4[]="Sucesso no cadastramento. Digite algo.";
    char texto5[]="Falha no cadastramento. Digite algo.";

    char campo_peca[50];

    // Instancia os dom�nios.

    Codigo codigo_peca;
    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin >> campo_peca;
    fflush(stdin);

    try
    {
        codigo_peca.setValor(string(campo_peca));

    }
    catch(invalid_argument &exp)
    {
        CLR_SCR;
        cout << texto3 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    Participante participante;

    participante.setMatricula(matricula);
    participante.setCodigoPeca(codigo_peca);

    if(cntrServicoParticipante->cadastrarParticipantePeca(participante))
    {
        CLR_SCR;
        cout << texto4 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    cout << texto5 << endl;
    getchar();
    fflush(stdin);

    return;

}

//--------------------- Controladoras de Sala -----------------------------------------------------------------------

void CntrApresentacaoSala::listarSala()
{
    CLR_SCR;
    cntrServicoSala->listarSala();
}

void CntrApresentacaoSala::incluirSala()
{

    // Mensagens a serem apresentadas na tela de inclusao de sala.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo      :";
    char texto3[] ="Nome        :";
    char texto4[] ="Capacidade  :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80];

    // Instancia os dom�nios.

    Codigo codigo;
    Nome nome;
    Capacidade capacidade;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin >> campo1;
    fflush(stdin);

    cout << texto3 << " ";
    cin.getline(campo2,sizeof(campo2));
    fflush(stdin);

    cout << texto4 << " ";
    cin >> campo3;
    fflush(stdin);

    try
    {
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        capacidade.setValor(string(campo3));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    // Instancia e inicializa entidade.

    Sala sala;

    sala.setCodigo(codigo);
    sala.setNome(nome);
    sala.setCapacidade(capacidade);

    // Incluir sala.

    if(cntrServicoSala->incluirSala(sala))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoSala::excluirSala()
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Informe o codigo da sala a ser excluida: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];

    // Instancia os dom�nios.

    Codigo codigo;

    CLR_SCR;

    cout << texto1 << " ";
    cin >> campo1;
    fflush(stdin);

    try
    {
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    if(cntrServicoSala->excluirSala(codigo))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoSala::editarSala()
{

    // Mensagens a serem apresentadas na tela de edicao de sala.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codido da sala a ser editada:";
    char texto3[] ="Nome                        :";
    char texto4[] ="Capacidade                  :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na edicao. Digite algo.";
    char texto12[]="Falha na edicao. Digite algo.";

    char campo1[80], campo2[80], campo3[80];

    // Instancia os dom�nios.

    Codigo codigo;
    Nome nome;
    Capacidade capacidade;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin >> campo1;
    fflush(stdin);

    cout << texto3 << " ";
    cin.getline(campo2,sizeof(campo2));
    fflush(stdin);

    cout << texto4 << " ";
    cin >> campo3;
    fflush(stdin);

    try
    {
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        capacidade.setValor(string(campo3));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    // Instancia e inicializa entidade.

    Sala sala;

    sala.setCodigo(codigo);
    sala.setNome(nome);
    sala.setCapacidade(capacidade);

    if(cntrServicoSala->editarSala(sala))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoSala::visualizarSala()
{

    // Mensagens a serem apresentadas na tela de visualizar sala.

    char texto1[] ="Informe o codigo da sala que se deseja visualizar: ";
    char texto2[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso. Digite algo para continuar.";
    char texto3[]="Falha na visualizacao. Digite algo.";

    char campo1[80];

    // Instancia os dom�nios.

    Codigo codigo;

    CLR_SCR;

    cout << texto1 << " ";
    cin >> campo1;
    fflush(stdin);

    try
    {
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp)
    {
        cout << texto2 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    if(cntrServicoSala->visualizarSala(codigo)){
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto3 << endl;
    getchar();
    fflush(stdin);
    return;
}

void CntrApresentacaoSala::executar()
{

    // Mensagens a serem apresentadas na tela simplificada de salas.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar salas disponiveis.";
    char texto3[]="2 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar)
    {

        // Apresenta tela simplificada de salas.

        CLR_SCR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;

        campo = getchar() - 48;
        fflush(stdin);

        switch(campo)
        {
        case 1:
            listarSala();
            break;
        case 2:
            apresentar = false;
            break;
        }
    }
}

void CntrApresentacaoSala::executar(Matricula)
{

    // Mensagens a serem apresentadas tela completa de salas.

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Listar salas";
    char texto3[] ="2 - Incluir sala.";
    char texto4[] ="3 - Excluir sala.";
    char texto5[] ="4 - Editar sala.";
    char texto6[] ="5 - Visualizar sala.";
    char texto7[] ="6 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar)
    {

        // Apresenta tela completa de salas.

        CLR_SCR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;
        cout << texto6 << endl;
        cout << texto7 << endl;

        campo = getchar() - 48;
        fflush(stdin);

        switch(campo)
        {
        case 1:
            listarSala();
            break;
        case 2:
            incluirSala();
            break;
        case 3:
            excluirSala();
            break;
        case 4:
            editarSala();
            break;
        case 5:
            visualizarSala();
            break;
        case 6:
            apresentar = false;
            break;
        }
    }
}

//--------------------- Controladoras de Sessao -----------------------------------------------------------------------

void CntrApresentacaoSessao::listarSessao()
{
    CLR_SCR;
    cntrServicoSessao->listarSessao();
}

void CntrApresentacaoSessao::incluirSessao()
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo      :";
    char texto3[] ="Data        :";
    char texto4[] ="Horario     :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80];

    // Instancia os dom�nios.

    Codigo codigo;
    Data data;
    Horario horario;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin >> campo1;
    fflush(stdin);

    cout << texto3 << " ";
    cin >> campo2;
    fflush(stdin);

    cout << texto4 << " ";
    cin >> campo3;
    fflush(stdin);

    try
    {
        codigo.setValor(string(campo1));
        data.setValor(string(campo2));
        horario.setValor(string(campo3));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    // Instancia e inicializa entidade.

    Sessao sessao;

    sessao.setCodigo(codigo);
    sessao.setData(data);
    sessao.setHorario(horario);

    if(cntrServicoSessao->incluirSessao(sessao))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoSessao::excluirSessao()
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Informe o codigo da Sessao a ser excluida: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];

    // Instancia os dom�nios.

    Codigo codigo;

    CLR_SCR;

    cout << texto1 << " ";
    cin >> campo1;
    fflush(stdin);

    try
    {
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    if(cntrServicoSessao->excluirSessao(codigo))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoSessao::editarSessao()
{

    // Mensagens a serem apresentadas na tela de edicao de Sessao.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codido da Sessao a ser editada:";
    char texto3[] ="Data                        :";
    char texto4[] ="Horario                     :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na edicao. Digite algo.";
    char texto12[]="Falha na edicao. Digite algo.";

    char campo1[80], campo2[80], campo3[80];

    // Instancia os dom�nios.

    Codigo codigo;
    Data data;
    Horario horario;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin >> campo1;
    fflush(stdin);

    cout << texto3 << " ";
    cin >> campo2;
    fflush(stdin);

    cout << texto4 << " ";
    cin >> campo3;
    fflush(stdin);

    try
    {
        codigo.setValor(string(campo1));
        data.setValor(string(campo2));
        horario.setValor(string(campo3));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    // Instancia e inicializa entidade.

    Sessao sessao;

    sessao.setCodigo(codigo);
    sessao.setData(data);
    sessao.setHorario(horario);

    if(cntrServicoSessao->editarSessao(sessao))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoSessao::cadastrarSessaoPeca()
{

    // Mensagens a serem apresentadas na tela de cadastro de Peca associada a Sessao.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo da Sessao a ser editada  :";
    char texto3[] ="Codigo da Peca a ser relacionada:";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na edicao. Digite algo.";
    char texto12[]="Falha na edicao. Digite algo.";

    char campo1[80], campo2[80];

    // Instancia os dom�nios.

    Codigo codigo;
    Codigo codigo_peca;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin >> campo1;
    fflush(stdin);

    cout << texto3 << " ";
    cin >> campo2;
    fflush(stdin);


    try
    {
        codigo.setValor(string(campo1));
        codigo_peca.setValor(string(campo2));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    // Instancia e inicializa entidade.

    Sessao sessao;

    sessao.setCodigo(codigo);
    sessao.setCodigoPeca(codigo_peca);

    if(cntrServicoSessao->cadastrarSessaoPeca(sessao))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoSessao::cadastrarSessaoSala()
{

    // Mensagens a serem apresentadas na tela de edicao de Sessao.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo da Sessao a ser editada  :";
    char texto3[] ="Codigo da Sala a ser relacionada:";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na edicao. Digite algo.";
    char texto12[]="Falha na edicao. Digite algo.";

    char campo1[80], campo2[80];

    // Instancia os dom�nios.

    Codigo codigo;
    Codigo codigo_sala;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin >> campo1;
    fflush(stdin);

    cout << texto3 << " ";
    cin >> campo2;
    fflush(stdin);


    try
    {
        codigo.setValor(string(campo1));
        codigo_sala.setValor(string(campo2));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    // Instancia e inicializa entidade.

    Sessao sessao;

    sessao.setCodigo(codigo);
    sessao.setCodigoSala(codigo_sala);

    if(cntrServicoSessao->cadastrarSessaoSala(sessao))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoSessao::visualizarSessao()
{

    // Mensagens a serem apresentadas na tela de visualizar Sessao.

    char texto1[] ="Informe o codigo da Sessao que se deseja visualizar: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso. Digite algo.";
    char texto12[]="Falha. Digite algo.";

    char campo1[80];

    // Instancia os dom�nios.

    Codigo codigo;

    CLR_SCR;

    cout << texto1 << " ";
    cin >> campo1;
    fflush(stdin);

    try
    {
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    if(cntrServicoSessao->visualizarSessao(codigo))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoSessao::executar()
{

    // Mensagens a serem apresentadas na tela simplificada de Sessaos.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar Sessaos disponiveis.";
    char texto3[]="2 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar)
    {

        // Apresenta tela simplificada de Sessao.

        CLR_SCR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;

        campo = getchar() - 48;
        fflush(stdin);

        switch(campo)
        {
        case 1:
            listarSessao();
            break;
        case 2:
            apresentar = false;
            break;
        }
    }
}

void CntrApresentacaoSessao::executar(Matricula)
{

    // Mensagens a serem apresentadas tela completa de Sessaos.

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Listar Sessoes";
    char texto3[] ="2 - Incluir Sessao.";
    char texto4[] ="3 - Excluir Sessao.";
    char texto5[] ="4 - Editar Sessao.";
    char texto6[] ="5 - Visualizar Sessao.";
    char texto7[] ="6 - Cadastrar em Peca.";
    char texto8[] ="7 - Cadastrar em Sala.";
    char texto9[] ="8 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar)
    {

        // Apresenta tela completa de Sessao.

        CLR_SCR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;
        cout << texto6 << endl;
        cout << texto7 << endl;
        cout << texto8 << endl;
        cout << texto9 << endl;

        campo = getchar() - 48;
        fflush(stdin);

        switch(campo)
        {
        case 1:
            listarSessao();
            break;
        case 2:
            incluirSessao();
            break;
        case 3:
            excluirSessao();
            break;
        case 4:
            editarSessao();
            break;
        case 5:
            visualizarSessao();
            break;
        case 6:
            cadastrarSessaoPeca();
            break;
        case 7:
            cadastrarSessaoSala();
            break;
        case 8:
            apresentar = false;
            break;
        }
    }
}

//--------------------- Controladoras de Peca -----------------------------------------------------------------------

void CntrApresentacaoPeca::listarPeca()
{
    CLR_SCR;
    cntrServicoPeca->listarPeca();
}

void CntrApresentacaoPeca::incluirPeca()
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo         :";
    char texto3[] ="Nome           :";
    char texto4[] ="Tipo           :";
    char texto5[] ="Classificacao  :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80];

    // Instancia os dom�nios.

    Codigo codigo;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin >> campo1;
    fflush(stdin);

    cout << texto3 << " ";
    cin.getline(campo2,sizeof(campo2));
    fflush(stdin);

    cout << texto4 << " ";
    cin >> campo3;
    fflush(stdin);

    cout << texto5 << " ";
    cin >> campo4;
    fflush(stdin);

    try
    {
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        tipo.setValor(string(campo3));
        classificacao.setValor(string(campo4));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    // Instancia e inicializa entidade.

    Peca peca;

    peca.setCodigo(codigo);
    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);

    if(cntrServicoPeca->incluirPeca(peca))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoPeca::excluirPeca()
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Informe o codigo da peca a ser excluida: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];

    // Instancia os dom�nios.

    Codigo codigo;

    CLR_SCR;

    cout << texto1 << " ";
    cin >> campo1;
    fflush(stdin);

    try
    {
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    if(cntrServicoPeca->excluirPeca(codigo))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoPeca::editarPeca()
{

    // Mensagens a serem apresentadas na tela de edicao de Peca.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codido da peca a ser editada:";
    char texto3[] ="Nome                        :";
    char texto4[] ="Tipo                        :";
    char texto5[] ="Classificacao               :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na edicao. Digite algo.";
    char texto12[]="Falha na edicao. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80];

    // Instancia os dom�nios.

    Codigo codigo;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin >> campo1;
    fflush(stdin);

    cout << texto3 << " ";
    cin.getline(campo2,sizeof(campo2));
    fflush(stdin);

    cout << texto4 << " ";
    cin >> campo3;
    fflush(stdin);

    cout << texto5 << " ";
    cin >> campo4;
    fflush(stdin);

    try
    {
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        tipo.setValor(string(campo3));
        classificacao.setValor(string(campo4));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    // Instancia e inicializa entidade.

    Peca peca;

    peca.setCodigo(codigo);
    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);

    if(cntrServicoPeca->editarPeca(peca))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoPeca::visualizarPeca()
{

    // Mensagens a serem apresentadas na tela de visualizar Peca.

    char texto1[] ="Informe o codigo da Peca que se deseja visualizar: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso. Digite algo.";
    char texto12[]="Falha. Digite algo.";

    char campo1[80];

    // Instancia os dom�nios.

    Codigo codigo;

    CLR_SCR;

    cout << texto1 << " ";
    cin >> campo1;
    fflush(stdin);

    try
    {
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;
        getchar();
        fflush(stdin);
        return;
    }

    if(cntrServicoPeca->visualizarPeca(codigo))
    {
        cout << texto11 << endl;

        getchar();
        fflush(stdin);
        return;
    }

    cout << texto12 << endl;

    getchar();
    fflush(stdin);

    return;
}

void CntrApresentacaoPeca::executar()
{

    // Mensagens a serem apresentadas na tela simplificada de Pecas.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar Pecas disponiveis.";
    char texto3[]="2 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar)
    {

        // Apresenta tela simplificada de Pecas.

        CLR_SCR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;

        campo = getchar() - 48;
        fflush(stdin);

        switch(campo)
        {
        case 1:
            listarPeca();
            break;
        case 2:
            apresentar = false;
            break;
        }
    }
}

void CntrApresentacaoPeca::executar(Matricula)
{

    // Mensagens a serem apresentadas tela completa de Pecas.

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Listar Pecas";
    char texto3[] ="2 - Incluir Peca.";
    char texto4[] ="3 - Excluir Peca.";
    char texto5[] ="4 - Editar Peca.";
    char texto6[] ="5 - Visualizar Peca.";
    char texto7[] ="6 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar)
    {

        // Apresenta tela completa de Pecas.

        CLR_SCR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;
        cout << texto6 << endl;
        cout << texto7 << endl;

        campo = getchar() - 48;
        fflush(stdin);

        switch(campo)
        {
        case 1:
            listarPeca();
            break;
        case 2:
            incluirPeca();
            break;
        case 3:
            excluirPeca();
            break;
        case 4:
            editarPeca();
            break;
        case 5:
            visualizarPeca();
            break;
        case 6:
            apresentar = false;
            break;
        }
    }
}
