#include "controladorasapresentacao.h"
#include <iostream>
#include <string.h>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"


//--------------------------------------------------------------------------------------------
// Implementa��es dos m�todos de classes controladoras.

void CntrApresentacaoControle::executar()
{

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

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";                        // Mensagem a ser apresentada.

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                          // Dados sobre tamanho da tela.


    while(apresentar)
    {

        // Apresenta tela inicial.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4_1 << endl;
        cout << texto4_2 << endl;
        cout << texto4_3 << endl;                                                                         // Imprime nome do campo.
        cout << texto5 << endl;                                            // Imprime nome do campo.

        campo = getchar() - 48;

        switch(campo)
        {
        case 1:
            if(cntrApresentacaoAutenticacao->autenticar(&matricula))                          // Solicita autentica��o.
            {
                bool apresentar = true;                                                 // Controle de la�o.
                while(apresentar)
                {

                    // Apresenta tela de sele��o de servi�o.

                    CLR_SCR;                                                            // Limpa janela.

                    cout << texto6 << endl;                                             // Imprime nome do campo.
                    cout << texto7 << endl;                                             // Imprime nome do campo.
                    cout << texto8_1 << endl;
                    cout << texto8_2 << endl;
                    cout << texto8_3 << endl;                                              // Imprime nome do campo.
                    cout << texto9 << endl;                      // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.

                    campo = getchar() - 48;                                               // Leitura do campo de entrada e convers�o de ASCII.


                    switch(campo)
                    {
                    case 1:
                        cntrApresentacaoParticipante->executar(matricula);                 // Solicita servi�o de pessoal.
                        break;
                    case 2:
                        cntrApresentacaoPeca->executar(matricula);                 // Solicita servi�o de peca.
                        break;
                    case 3:
                        cntrApresentacaoSessao->executar(matricula);                 // Solicita servi�o de sessao.
                        break;
                    case 4:
                        cntrApresentacaoSala->executar(matricula);                 // Solicita servi�o de sala.
                        break;
                    case 5:
                        apresentar = false;
                        break;
                    }
                }
            }
            else
            {

                CLR_SCR;                                                                // Limpa janela.
                cout << texto10 << endl;                                                // Imprime mensagem.
                getchar();                                                                 // Habilita eco.
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

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoAutenticacao::autenticar(Matricula *matricula)
{

    // Mensagens a serem apresentadas na tela de autentica��o.

    char texto1[]="Digite a Matricula    : ";
    char texto2[]="Digite a senha        : ";
    char texto3[]="Dado em formato incorreto. Digite algo para continuar.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    Senha senha;                                                                                // Instancia a classe Senha.

    while(true)
    {

        // Apresenta tela de autentica��o.
        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << " ";                                                                  // Imprime nome do campo.
        cin >> campo1;                                                                          // Lê valor do campo.
        cout << texto2 << " ";                                                                  // Imprime nome do campo.
        cin >> campo2;                                                                         // L� valor do campo.

        try
        {
            matricula->setValor(string(campo1));                                                      // Atribui valor ao CPF.
            senha.setValor(string(campo2));                                                     // Atribui Valor � senha.
            break;                                                                              // Abandona la�o em caso de formatos corretos.
        }
        catch(invalid_argument &exp)                                                            // Captura exce��o devido a formato incorreto.
        {
            CLR_SCR;                                                                            // Limpa janela.
            cout << texto3 << endl;                                                             // Informa formato incorreto.
            getchar();
        }
    }
    return (cntrServicoAutenticacao->autenticar(*matricula, senha));                                                     // Solicita servi�o de autentica��o.
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoParticipante::executar(Matricula matricula)
{

    // Mensagens a serem apresentadas na tela de sele��o de servi�o..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar dados pessoais.";
    char texto3[]="2 - Editar dados pessoais.";
    char texto4[]="3 - Deletar cadastro.";
    char texto5[]="4 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar)
    {

        // Apresenta tela de sela��o de servi�o.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;                                                                     // Imprime nome do campo.

        campo = getchar() - 48;                                                                   // Leitura do campo de entrada.

        switch(campo)
        {
        case 1:
            consultarParticipante();
            break;
        case 2:
            editarParticipante();
            break;
        case 3:
            descadastrarParticipante();
            break;
        case 4:
            apresentar = false;
            break;
        }
    }
}

//Ajustar -> acho que n precisa...se vc n tiver a matricula, so tem a opcao de cadastrar um usuario msm (Liz aqui)
void CntrApresentacaoParticipante::executar()
{
    cadastrarParticipante();
    /*
    // Mensagens a serem apresentadas na tela de sele��o de servi�o..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar dados pessoais.";
    char texto3[]="2 - Editar dados pessoais.";
    char texto4[]="3 - Deletar cadastro.";
    char texto5[]="4 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar)
    {

        // Apresenta tela de sela��o de servi�o.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;                                                                     // Imprime nome do campo.

        campo = getchar() - 48;                                                                   // Leitura do campo de entrada.

        switch(campo)
        {
        case 1:
            consultarParticipante();
            break;
        case 2:
            editarParticipante();
            break;
        case 3:
            descadastrarParticipante();
            break;
        case 4:
            apresentar = false;
            break;
        }
    }*/
}

//--------------------------------------------------------------------------------------------

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

    CLR_SCR;                                                                                   // Limpa janela.

    cout << texto1 << endl;                                                                    // Imprime solicitação ao usuário.
    cout << texto2 << " ";                                                                     // Imprime nome do campo.
    //cin.getline(campo_nome,sizeof(campo_nome));                                                        // Lê valor do campo composto.
    cin >> campo_nome;
    //cout << "Valor lido" << campo_nome << " ";

    cout << texto3 << " ";                                                                     // Imprime nome do campo.
    cin >> campo_sobrenome;                                                                             // Lê valor do campo.
    cout << texto4 << " ";                                                                     // Imprime nome do campo.
    cin >> campo_email;                                                                             // Lê valor do campo.
    cout << texto5 << " ";                                                                     // Imprime nome do campo.
    cin >> campo_telefone;                                                                             // Lê valor do campo.
    cout << texto6 << " ";                                                                     // Imprime nome do campo.
    cin >> campo_senha;                                                                             // Lê valor do campo.
    cout << texto7 << " ";                                                                     // Imprime nome do campo.
    cin >> campo_cargo;                                                                             // Lê valor do campo.
    cout << texto8 << " ";                                                                     // Imprime nome do campo.
    cin >> campo_matricula;                                                                             // Lê valor do campo.

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
        return;
    }

    Participante participante;

    participante.setNome(nome);
    participante.setSobrenome(sobrenome);
    participante.setEmail(email);
    participante.setTelefone(telefone);
    participante.setSenha(senha);
    participante.setCargo(cargo);

    if(cntrServicoParticipante->cadastrarParticipante(participante))
    {
        CLR_SCR;
        cout << texto10 << endl;
        getchar();
        return;
    }

    cout << texto11 << endl;
    getchar();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoParticipante::consultarParticipante()
{

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresenta��o de dados pessoais.

    // Dados sobre tamanho da tela.
    // Armazena quantidade de linhas e colunas.

    char texto[]="Servico consultar dados pessoais nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    CLR_SCR;                                                                                     // Limpa janela.
    cout << texto << endl;                                                      // Imprime nome do campo.

    getchar();

}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoParticipante::editarParticipante()
{

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresenta��o de dados pessoais.

    // Dados sobre tamanho da tela.
    // Armazena quantidade de linhas e colunas.

    char texto[]="Servico editar dados pessoais nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    CLR_SCR;                                                                                     // Limpa janela.
    cout << texto << endl;                                                     // Imprime nome do campo.

    getchar();

}

void CntrApresentacaoParticipante::descadastrarParticipante()
{

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresenta��o de dados pessoais.

    // Dados sobre tamanho da tela.
    // Armazena quantidade de linhas e colunas.

    char texto[]="Servico descadastrar dados pessoais nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    CLR_SCR;                                                                                     // Limpa janela.
    cout << texto << endl;                                                      // Imprime nome do campo.

    getchar();

}

//--------------------------------------------------------------------------------------------

// esse ainda falta implementar
void CntrApresentacaoSala::listarSala()  //preciso pegar os dados com controladora servico
{
    cntrServicoSala->listarSala();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::incluirSala()  //preciso pegar os dados com controladora servico
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo      :";
    char texto3[] ="Nome        :";
    char texto4[] ="Capacidade  :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80];                                                   // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;
    Nome nome;
    Capacidade capacidade;

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                     // Limpa janela.

    cout << texto1 << endl;                                                    // Imprime nome do campo.
    cout << texto2 << " ";                                                                     // Imprime nome do campo.
    cin >> campo1;                                                                             // Lê valor do campo.
    cout << texto3 << " ";                                                                     // Imprime nome do campo.
    cin >> campo2;                                                                             // Lê valor do campo.
    cout << texto4 << " ";                                                                     // Imprime nome do campo.
    cin >> campo3;                                                                             // Lê valor do campo.

    try
    {
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        capacidade.setValor(string(campo3));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;                                            // Informa formato incorreto.
        // Desabilita eco.
        getchar();                                                                                // Leitura de caracter digitado.
        // Habilita eco.
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
        cout << texto11 << endl;                                                // Informa sucesso.

        getchar();

        return;
    }

    cout << texto12 << endl;                                                        // Informa falha.

    getchar();


    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::excluirSala()  //preciso pegar os dados com controladora servico
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Informe o codigo da sala a ser excluida: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];                                                                           // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                     // Limpa janela.

    cout << texto1 << " ";                                                    // Imprime nome do campo.                                                                   // Imprime nome do campo.
    cin >> campo1;
    // L� valor do campo.

    try
    {
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;                                           // Informa formato incorreto.
        // Desabilita eco.
        getchar();                                                                                // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Exclui a sala.

    if(cntrServicoSala->excluirSala(codigo))
    {
        cout << texto11 << endl;                                              // Informa sucesso.

        getchar();

        return;
    }

    cout << texto12 << endl;                                                       // Informa falha.

    getchar();


    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::editarSala()  //preciso pegar os dados com controladora servico
{

    // Mensagens a serem apresentadas na tela de edicao de sala.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codido da sala a ser editada:";
    char texto3[] ="Nome                        :";
    char texto4[] ="Capacidade                  :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na edicao. Digite algo.";
    char texto12[]="Falha na edicao. Digite algo.";

    char campo1[80], campo2[80], campo3[80];                                                   // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;
    Nome nome;
    Capacidade capacidade;

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                     // Limpa janela.

    cout << texto1 << endl;                                                     // Imprime nome do campo.
    cout << texto2 << " ";                                                // Imprime nome do campo.
    cin >> campo1;                                                                             // L� valor do campo.
    cout << texto3 << " ";                                                // Imprime nome do campo.
    cin >> campo2;
    cout << texto4 << " ";                                                // Imprime nome do campo.
    cin >> campo3;

    try
    {
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        capacidade.setValor(string(campo3));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;                                           // Informa formato incorreto.
        // Desabilita eco.
        getchar();                                                                                // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Sala sala;

    sala.setCodigo(codigo);
    sala.setNome(nome);
    sala.setCapacidade(capacidade);

    // Incluir sala.

    if(cntrServicoSala->editarSala(sala))
    {
        cout << texto11 << endl;                                               // Informa sucesso.

        getchar();

        return;
    }

    cout << texto12 << endl;                                                       // Informa falha.

    getchar();


    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::visualizarSala()  //preciso pegar os dados com controladora servico
{

    // Mensagens a serem apresentadas na tela de visualizar sala.

    char texto1[] ="Informe o codigo da sala que se deseja visualizar: ";
    char texto2[]="Dado em formato incorreto. Digite algo.";
    char texto3[]="Falha na visualizacao. Digite algo.";

    char campo1[80];                                                                           // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;

    CLR_SCR;                                                                                     // Limpa janela.

    cout << texto1 << " ";                                                     // Imprime nome do campo.
    cin >> campo1;                                                                             // L� valor do campo.

    try
    {
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp)
    {
        cout << texto2 << endl;                                           // Informa formato incorreto.
        // Desabilita eco.
        getchar();                                                                                // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Visualizacao da sala.

    if(cntrServicoSala->visualizarSala(codigo)) return;

    cout << texto3 << endl;                                               // Informa sucesso.
    getchar();
    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::executar()
{

    // Mensagens a serem apresentadas na tela simplificada de salas.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar salas disponiveis.";
    char texto3[]="2 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    // Dados sobre tamanho da tela.
    // Armazena quantidade de linhas e colunas.

    // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar)
    {

        // Apresenta tela simplificada de salas.

        CLR_SCR;                                                                                 // Limpa janela.
        cout << texto1 << endl;                                                // Imprime nome do campo.
        cout << texto2 << endl;                                             // Imprime nome do campo.
        cout << texto3 << endl;                                            // Imprime nome do campo.

        campo = getchar() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.


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

//--------------------------------------------------------------------------------------------

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

    int campo;                                                                                  // Campo de entrada.

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    // Habilita eco.

    while(apresentar)
    {

        // Apresenta tela completa de salas.

        CLR_SCR;                                                                                 // Limpa janela.
        cout << texto1 << endl;                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                             // Imprime nome do campo.
        cout << texto3 << endl;                                             // Imprime nome do campo.
        cout << texto4 << endl;                                            // Imprime nome do campo.
        cout << texto5 << endl;                                             // Imprime nome do campo.
        cout << texto6 << endl;                                            // Imprime nome do campo.
        cout << texto7 << endl;                                            // Imprime nome do campo.

        campo = getchar() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.


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

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::listarSessao()  //preciso pegar os dados com controladora servico
{
    cntrServicoSessao->listarSessao();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::incluirSessao()  //preciso pegar os dados com controladora servico
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo      :";
    char texto3[] ="Data        :";
    char texto4[] ="Horario     :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80];                                                   // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;
    Data data;
    Horario horario;

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                     // Limpa janela.

    cout << texto1 << endl;                                                     // Imprime nome do campo.
    cout << texto2 << " ";                                                 // Imprime nome do campo.
    cin >> campo1;                                                                             // L� valor do campo.
    cout << texto3 << " ";                                                 // Imprime nome do campo.
    cin >> campo2;
    cout << texto4 << " ";                                                 // Imprime nome do campo.
    cin >> campo3;

    try
    {
        codigo.setValor(string(campo1));
        data.setValor(string(campo2));
        horario.setValor(string(campo3));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;                                            // Informa formato incorreto.
        // Desabilita eco.
        getchar();                                                                                // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Sessao sessao;

    sessao.setCodigo(codigo);
    sessao.setData(data);
    sessao.setHorario(horario);

    // Incluir Sessao.

    if(cntrServicoSessao->incluirSessao(sessao))
    {
        cout << texto11 << endl;                                                // Informa sucesso.

        getchar();

        return;
    }

    cout << texto12 << endl;                                                       // Informa falha.

    getchar();


    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::excluirSessao()  //preciso pegar os dados com controladora servico
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Informe o codigo da Sessao a ser excluida: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];                                                                           // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                     // Limpa janela.

    cout << texto1 << " ";                                                      // Imprime nome do campo.
    cin >> campo1;                                                                             // L� valor do campo.

    try
    {
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;                                           // Informa formato incorreto.
        // Desabilita eco.
        getchar();                                                                                // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Exclui a Sessao.

    if(cntrServicoSessao->excluirSessao(codigo))
    {
        cout << texto11 << endl;                                                // Informa sucesso.

        getchar();

        return;
    }

    cout << texto12 << endl;                                                        // Informa falha.

    getchar();


    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::editarSessao()  //preciso pegar os dados com controladora servico
{

    // Mensagens a serem apresentadas na tela de edicao de Sessao.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codido da Sessao a ser editada:";
    char texto3[] ="Data                        :";
    char texto4[] ="Horario                     :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na edicao. Digite algo.";
    char texto12[]="Falha na edicao. Digite algo.";

    char campo1[80], campo2[80], campo3[80];                                                   // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;
    Data data;
    Horario horario;

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                     // Limpa janela.

    cout << texto1 << endl;                                                     // Imprime nome do campo.
    cout << texto2 << " ";                                                  // Imprime nome do campo.
    cin >> campo1;                                                                             // L� valor do campo.
    cout << texto3 << " ";                                                  // Imprime nome do campo.
    cin >> campo2;
    cout << texto4 << " ";                                                  // Imprime nome do campo.
    cin >> campo3;

    try
    {
        codigo.setValor(string(campo1));
        data.setValor(string(campo2));
        horario.setValor(string(campo3));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;                                           // Informa formato incorreto.
        // Desabilita eco.
        getchar();                                                                                // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Sessao sessao;

    sessao.setCodigo(codigo);
    sessao.setData(data);
    sessao.setHorario(horario);

    // Incluir Sessao.

    if(cntrServicoSessao->editarSessao(sessao))
    {
        cout << texto11 << endl;                                               // Informa sucesso.

        getchar();

        return;
    }

    cout << texto12 << endl;                                                       // Informa falha.

    getchar();


    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::visualizarSessao()  //preciso pegar os dados com controladora servico
{

    // Mensagens a serem apresentadas na tela de visualizar Sessao.

    char texto1[] ="Informe o codigo da Sessao que se deseja visualizar: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];                                                                           // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Apresenta tela de visualizacao de Sessao.

    CLR_SCR;                                                                                     // Limpa janela.

    cout << texto1 << " ";                                                     // Imprime nome do campo.
    cin >> campo1;                                                                             // L� valor do campo.

    try
    {
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;                                           // Informa formato incorreto.
        // Desabilita eco.
        getchar();                                                                                // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Visualizacao da Sessao.

    if(cntrServicoSessao->visualizarSessao(codigo))
    {
        cout << texto11 << endl;                                               // Informa sucesso.

        getchar();

        return;
    }

    cout << texto12 << endl;                                                       // Informa falha.

    getchar();


    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::executar()
{

    // Mensagens a serem apresentadas na tela simplificada de Sessaos.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar Sessaos disponiveis.";
    char texto3[]="2 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    // Dados sobre tamanho da tela.
    // Armazena quantidade de linhas e colunas.

    // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar)
    {

        // Apresenta tela simplificada de Sessaos.

        CLR_SCR;                                                                                 // Limpa janela.
        cout << texto1 << endl;                                                // Imprime nome do campo.
        cout << texto2 << endl;                                             // Imprime nome do campo.
        cout << texto3 << endl;                                            // Imprime nome do campo.

        campo = getchar() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.


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

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::executar(Matricula)
{

    // Mensagens a serem apresentadas tela completa de Sessaos.

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Listar Sessoes";
    char texto3[] ="2 - Incluir Sessao.";
    char texto4[] ="3 - Excluir Sessao.";
    char texto5[] ="4 - Editar Sessao.";
    char texto6[] ="5 - Visualizar Sessao.";
    char texto7[] ="6 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    // Habilita eco.

    while(apresentar)
    {

        // Apresenta tela completa de Sessaos.

        CLR_SCR;                                                                                 // Limpa janela.
        cout << texto1 << endl;                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                             // Imprime nome do campo.
        cout << texto3 << endl;                                             // Imprime nome do campo.
        cout << texto4 << endl;                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                             // Imprime nome do campo.
        cout << texto6 << endl;                                          // Imprime nome do campo.
        cout << texto7 << endl;                                             // Imprime nome do campo.

        campo = getchar() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.


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
            apresentar = false;
            break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::listarPeca()  //preciso pegar os dados com controladora servico
{
    cntrServicoPeca->listarPeca();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::incluirPeca()  //preciso pegar os dados com controladora servico
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo         :";
    char texto3[] ="Nome           :";
    char texto4[] ="Tipo           :";
    char texto5[] ="Classificação  :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80];                                                   // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                     // Limpa janela.

    cout << texto1 << endl;                                                      // Imprime nome do campo.
    cout << texto2 << " ";                                                  // Imprime nome do campo.
    cin >> campo1;                                                                             // L� valor do campo.
    cout << texto3 << " ";                                                  // Imprime nome do campo.
    cin >> campo2;                                                                              // L� valor do campo.
    cout << texto4 << " ";                                                  // Imprime nome do campo.
    cin >> campo3;
    cout << texto5 << " ";                                                  // Imprime nome do campo.
    cin >> campo4;

    try
    {
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        tipo.setValor(string(campo3));
        classificacao.setValor(string(campo4));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;                                           // Informa formato incorreto.
        // Desabilita eco.
        getchar();                                                                                // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Peca peca;

    peca.setCodigo(codigo);
    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);

    // Incluir Peca.

    if(cntrServicoPeca->incluirPeca(peca))
    {
        cout << texto11 << endl;                                               // Informa sucesso.

        getchar();

        return;
    }

    cout << texto12 << endl;                                                       // Informa falha.

    getchar();


    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::excluirPeca()  //preciso pegar os dados com controladora servico
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Informe o codigo da peca a ser excluida: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];                                                                           // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                     // Limpa janela.

    cout << texto1 << " ";                                                     // Imprime nome do campo.
    cin >> campo1;                                                                             // L� valor do campo.

    try
    {
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;                                           // Informa formato incorreto.
        // Desabilita eco.
        getchar();                                                                                // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Exclui a Peca.

    if(cntrServicoPeca->excluirPeca(codigo))
    {
        cout << texto11 << endl;                                               // Informa sucesso.

        getchar();

        return;
    }

    cout << texto12 << endl;                                                       // Informa falha.

    getchar();


    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::editarPeca()  //preciso pegar os dados com controladora servico
{

    // Mensagens a serem apresentadas na tela de edicao de Peca.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codido da peca a ser editada:";
    char texto3[] ="Nome                        :";
    char texto4[] ="Tipo                        :";
    char texto5[] ="Classificação               :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na edicao. Digite algo.";
    char texto12[]="Falha na edicao. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80];                                                   // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                     // Limpa janela.

    cout << texto1 << endl;                                                     // Imprime nome do campo.
    cout << texto2 << " ";                                                 // Imprime nome do campo.
    cin >> campo1;                                                                             // L� valor do campo.
    cout << texto3 << " ";                                                 // Imprime nome do campo.
    cin >> campo2;
    cout << texto4 << " ";                                                 // Imprime nome do campo.
    cin >> campo3;                                                                             // L� valor do campo.
    cout << texto5 << " ";                                                 // Imprime nome do campo.
    cin >> campo4;

    try
    {
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        tipo.setValor(string(campo3));
        classificacao.setValor(string(campo4));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;                                           // Informa formato incorreto.
        // Desabilita eco.
        getchar();                                                                                // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Peca peca;

    peca.setCodigo(codigo);
    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);

    // Incluir peca.

    if(cntrServicoPeca->editarPeca(peca))
    {
        cout << texto11 << endl;                                               // Informa sucesso.

        getchar();

        return;
    }

    cout << texto12 << endl;                                                       // Informa falha.

    getchar();


    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::visualizarPeca()  //preciso pegar os dados com controladora servico
{

    // Mensagens a serem apresentadas na tela de visualizar Peca.

    char texto1[] ="Informe o codigo da Peca que se deseja visualizar: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];                                                                           // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Apresenta tela de visualizacao de Peca.

    CLR_SCR;                                                                                     // Limpa janela.

    cout << texto1 << " ";                                                    // Imprime nome do campo.
    cin >> campo1;                                                                             // L� valor do campo.

    try
    {
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp)
    {
        cout << texto10 << endl;                                           // Informa formato incorreto.
        // Desabilita eco.
        getchar();                                                                                // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Visualizacao da Peca.

    if(cntrServicoPeca->visualizarPeca(codigo))
    {
        cout << texto11 << endl;                                               // Informa sucesso.

        getchar();

        return;
    }

    cout << texto12 << endl;                                                       // Informa falha.

    getchar();


    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::executar()
{

    // Mensagens a serem apresentadas na tela simplificada de Pecas.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar Pecas disponiveis.";
    char texto3[]="2 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    // Dados sobre tamanho da tela.
    // Armazena quantidade de linhas e colunas.

    // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar)
    {

        // Apresenta tela simplificada de Pecas.

        CLR_SCR;                                                                                 // Limpa janela.
        cout << texto1 << endl;                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                             // Imprime nome do campo.
        cout << texto3 << endl;                                             // Imprime nome do campo.

        campo = getchar() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.


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

//--------------------------------------------------------------------------------------------

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

    int campo;                                                                                  // Campo de entrada.

    // Dados sobre tamanho da tela.

    // Armazena quantidade de linhas e colunas.

    // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    // Habilita eco.

    while(apresentar)
    {

        // Apresenta tela completa de Pecas.

        CLR_SCR;                                                                                 // Limpa janela.
        cout << texto1 << endl;                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                             // Imprime nome do campo.
        cout << texto3 << endl;                                             // Imprime nome do campo.
        cout << texto4 << endl;                                             // Imprime nome do campo.
        cout << texto5 << endl;                                             // Imprime nome do campo.
        cout << texto6 << endl;                                             // Imprime nome do campo.
        cout << texto7 << endl;                                            // Imprime nome do campo.

        campo = getchar() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.


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

//--------------------------------------------------------------------------------------------
