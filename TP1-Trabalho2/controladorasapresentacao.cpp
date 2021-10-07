#include "controladorasapresentacao.h"

//--------------------------------------------------------------------------------------------
// Implementa��es dos m�todos de classes controladoras.

void CntrApresentacaoControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Acessar sistema.";
    char texto3[]="2 - Cadastrar participante.";
    char texto4_1[]="3 - Listar pe�as.";
    char texto4_2[]="3 - Listar sess�es.";
    char texto4_3[]="3 - Listar salas.";
    char texto5[]="4 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de sele��o de servi�o (usuario autenticado).

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="1 - Selecionar servicos de participante.";
    char texto8_1[]="2 - Selecionar servicos relacionados a pe�as.";
    char texto8_2[]="2 - Selecionar servicos relacionados a sess�es.";
    char texto8_3[]="2 - Selecionar servicos relacionados a salas.";
    char texto9[]="3 - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";                        // Mensagem a ser apresentada.

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        // Apresenta tela inicial.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4_1);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4_2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4_3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.

        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
        echo();

        switch(campo){
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&cpf)){                         // Solicita autentica��o.
                        bool apresentar = true;                                                 // Controle de la�o.
                        while(apresentar){

                            // Apresenta tela de sele��o de servi�o.

                            clear();                                                            // Limpa janela.
                            mvprintw(linha/4,coluna/4,"%s",texto6);                             // Imprime nome do campo.
                            mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 4,coluna/4,"%s",texto8_1);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 4,coluna/4,"%s",texto8_2);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 4,coluna/4,"%s",texto8_3);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 6,coluna/4,"%s",texto9);                         // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.
                            noecho();
                            campo = getch() - 48;                                               // Leitura do campo de entrada e convers�o de ASCII.
                            echo();

                            switch(campo){
                                case 1: cntrApresentacaoPessoal->executar(cpf);                 // Solicita servi�o de pessoal.
                                        break;
                                case 2: cntrApresentacaoProdutosFinanceiros->executar(cpf);     // Solicita servi�o de produto financeiro.
                                        break;
                                case 3: apresentar = false;
                                        break;
                            }
                        }
                    }
                    else {
                        clear();                                                                // Limpa janela.
                        mvprintw(linha/4,coluna/4,"%s",texto10);                                // Imprime mensagem.
                        noecho();                                                               // Desabilita eco.
                        getch();                                                                // Leitura de caracter digitado.
                        echo();                                                                 // Habilita eco.
                    }
                    break;
            case 2: cntrApresentacaoPessoal->cadastrar();
                    break;
            case 3: cntrApresentacaoProdutosFinanceiros->executar();
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
    return;
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoAutenticacao::autenticar(Matricula *matricula){

    // Mensagens a serem apresentadas na tela de autentica��o.

    char texto1[]="Digite a Matr�cula   : ";
    char texto2[]="Digite a senha       : ";
    char texto3[]="Dado em formato incorreto. Digite algo para continuar.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    Senha senha;                                                                                // Instancia a classe Senha.

    echo();                                                                                     // Habilita eco.

    while(true){

        // Apresenta tela de autentica��o.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        getstr(campo1);                                                                         // L� valor do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        getstr(campo2);                                                                         // L� valor do campo.

        try{
            matricula->setValor(string(campo1));                                                      // Atribui valor ao CPF.
            senha.setValor(string(campo2));                                                     // Atribui Valor � senha.
            break;                                                                              // Abandona la�o em caso de formatos corretos.
        }
        catch(invalid_argument &exp){                                                           // Captura exce��o devido a formato incorreto.
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s",texto3);                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
        }
    }
    return (cntr->autenticar(*matricula, senha));                                                     // Solicita servi�o de autentica��o.
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoParticipante::executar(Matricula matricula){

    // Mensagens a serem apresentadas na tela de sele��o de servi�o..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar dados pessoais.";
    char texto3[]="2 - Editar dados pessoais.";
    char texto4[]="3 - Deletar cadastro.";
    char texto5[]="4 - Retornar.";

    int campo;

    int linha,coluna;

    getmaxyx(stdscr,linha,coluna);

    bool apresentar = true;

    echo();

    while(apresentar){

        // Apresenta tela de sela��o de servi�o.

        clear();
        mvprintw(linha/4,coluna/4,"%s",texto1);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);
        mvprintw(linha/4 + 4,coluna/4,"%s",texto4);
        mvprintw(linha/4 + 4,coluna/4,"%s",texto5);
        noecho();
        campo = getch() - 48;
        echo();

        switch(campo){
            case 1: consultarParticipante(Matricula);
                    break;
            case 2: editarParticipante(Matricula);
                    break;
            case 3: descadastrarParticipante(Matricula);
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoParticipante::cadastrarParticipante(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome            :";
    char texto3[] ="Sobrenome       :";
    char texto4[] ="E-mail          :";
    char texto5[] ="Telefone        :";
    char texto6[] ="Senha           :";
    char texto7[] ="Matrícula       :";
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

    int linha,coluna;
    getmaxyx(stdscr,linha,coluna);

    clear();

    mvprintw(linha/4,coluna/4,"%s",texto1);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
    getstr(campo_nome);
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);
    getstr(campo_sobrenome);
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);
    getstr(campo_email);
    mvprintw(linha/4 + 8,coluna/4,"%s",texto5);
    getstr(campo_telefone);
    mvprintw(linha/4 + 10,coluna/4,"%s",texto6);
    getstr(campo_senha);
    mvprintw(linha/4 + 12,coluna/4,"%s",texto7);
    getstr(campo_matricula);
    mvprintw(linha/4 + 14,coluna/4,"%s",texto8);
    getstr(campo_cargo);

    try{
        nome.setValor(string(campo_nome));
        sobrenome.setValor(string(campo_sobrenome));
        email.setValor(string(campo_email));
        telefone.setValor(string(campo_telefone));
        senha.setValor(string(campo_senha));
        matricula.setValor(string(campo_matricula));
        cargo.setValor(string(campo_cargo));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);
        noecho();
        getch();
        echo();
        return;
    }

    Participante participante;

    participante.setNome(nome);
    participante.setSobrenome(sobrenome);
    participante.setEmail(email);
    participante.setTelefone(telefone);
    participante.setSenha(senha);
    participante.setCargo(cargo);

    if(CntrServicoParticipante->cadastrar(participante)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoParticipante::consultarParticipante(Matricula){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresenta��o de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico consultar dados pessoais nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoParticipante::editarParticipante(Matricula){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresenta��o de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico editar dados pessoais nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

void CntrApresentacaoParticipante::descadastrarParticipante(Matricula){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresenta��o de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico descadastrar dados pessoais nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::listarSala(){ //preciso pegar os dados com controladora servico
    cntrServicoSala->listar();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::incluirSala(){ //preciso pegar os dados com controladora servico

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codido      :";
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

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);

    try{
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        capacidade.setValor(string(campo3));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Sala sala;

    sala.setCodigo(codigo);
    sala.setNome(nome);
    sala.setCapacidade(capacidade);

    // Incluir sala.

    if(cntrServicoSala->incluir(sala)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::excluirSala(){ //preciso pegar os dados com controladora servico

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Informe o codigo da sala a ser excluida: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];                                                                           // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Exclui a sala.

    if(cntrServicoSala->excluir(codigo)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::editarSala(){ //preciso pegar os dados com controladora servico

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

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);

    try{
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        capacidade.setValor(string(campo3));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Sala sala;

    sala.setCodigo(codigo);
    sala.setNome(nome);
    sala.setCapacidade(capacidade);

    // Incluir sala.

    if(cntrServicoSala->editar(Sala)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::visualizarSala(){ //preciso pegar os dados com controladora servico

    // Mensagens a serem apresentadas na tela de visualizar sala.

    char texto1[] ="Informe o codigo da sala que se deseja visualizar: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];                                                                           // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de visualizacao de sala.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Visualizacao da sala.

    if(cntrServicoSala->visualizar(codigo)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::executar(){

    // Mensagens a serem apresentadas na tela simplificada de salas.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar salas disponiveis.";
    char texto3[]="2 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        // Apresenta tela simplificada de salas.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
        echo();

        switch(campo){
            case 1: listarSala();
                    break;
            case 2: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::executar(Matricula){

    // Mensagens a serem apresentadas tela completa de salas.

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Listar salas";
    char texto3[] ="2 - Incluir sala.";
    char texto4[] ="3 - Excluir sala.";
    char texto5[] ="4 - Editar sala.";
    char texto6[] ="5 - Visualizar sala.";
    char texto7[] ="6 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela completa de salas.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                            // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
        echo();

        switch(campo){
            case 1: listarSala();
                    break;
            case 2: incluirSala();
                    break;
            case 3: excluirSala();
                    break;
            case 4: editarSala();
                    break;
            case 5: visualizarSala();
                    break;
            case 6: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::listarSessao(){ //preciso pegar os dados com controladora servico
    cntrServicoSessao->listar();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::incluirSessao(){ //preciso pegar os dados com controladora servico

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codido      :";
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

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);

    try{
        codigo.setValor(string(campo1));
        data.setValor(string(campo2));
        horario.setValor(string(campo3));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Sessao sessao;

    sessao.setCodigo(codigo);
    sessao.setData(data);
    sessao.setHorario(horario);

    // Incluir Sessao.

    if(cntrServicoSessao->incluir(sessao)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::excluirSessao(){ //preciso pegar os dados com controladora servico

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Informe o codigo da Sessao a ser excluida: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];                                                                           // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Exclui a Sessao.

    if(cntrServicoSessao->excluir(codigo)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::editarSessao(){ //preciso pegar os dados com controladora servico

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

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);

    try{
        codigo.setValor(string(campo1));
        data.setValor(string(campo2));
        horario.setValor(string(campo3));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Sessao sessao;

    sessao.setCodigo(codigo);
    sessao.setData(data);
    sessao.setHorario(horario);

    // Incluir Sessao.

    if(cntrServicoSessao->editar(sessao)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::visualizarSessao(){ //preciso pegar os dados com controladora servico

    // Mensagens a serem apresentadas na tela de visualizar Sessao.

    char texto1[] ="Informe o codigo da Sessao que se deseja visualizar: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];                                                                           // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de visualizacao de Sessao.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Visualizacao da Sessao.

    if(cntrServicoSessao->visualizar(codigo)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::executar(){

    // Mensagens a serem apresentadas na tela simplificada de Sessaos.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar Sessaos disponiveis.";
    char texto3[]="2 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        // Apresenta tela simplificada de Sessaos.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
        echo();

        switch(campo){
            case 1: listarSessao();
                    break;
            case 2: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::executar(Matricula){

    // Mensagens a serem apresentadas tela completa de Sessaos.

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Listar Sessoes";
    char texto3[] ="2 - Incluir Sessao.";
    char texto4[] ="3 - Excluir Sessao.";
    char texto5[] ="4 - Editar Sessao.";
    char texto6[] ="5 - Visualizar Sessao.";
    char texto7[] ="6 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela completa de Sessaos.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                            // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
        echo();

        switch(campo){
            case 1: listarSessao();
                    break;
            case 2: incluirSessao();
                    break;
            case 3: excluirSessao();
                    break;
            case 4: editarSessao();
                    break;
            case 5: visualizarSessao();
                    break;
            case 6: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::listarPeca(){ //preciso pegar os dados com controladora servico
    cntrServicoPeca->listar();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::incluirPeca(){ //preciso pegar os dados com controladora servico

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

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);
    mvprintw(linha/4 + 6,coluna/4,"%s",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);

    try{
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        tipo.setValor(string(campo3));
        classificacao.setValor(string(campo4));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Peca peca;

    peca.setCodigo(codigo);
    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);

    // Incluir Peca.

    if(cntrServicoPeca->incluir(peca)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::excluirPeca(){ //preciso pegar os dados com controladora servico

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Informe o codigo da peca a ser excluida: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];                                                                           // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Exclui a Peca.

    if(cntrServicoPeca->excluir(codigo)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::editarPeca(){ //preciso pegar os dados com controladora servico

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

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);
    mvprintw(linha/4 + 6,coluna/4,"%s",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);

    try{
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        tipo.setValor(string(campo3));
        classificacao.setValor(string(campo4));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Peca peca;

    peca.setCodigo(codigo);
    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);

    // Incluir peca.

    if(cntrServicoPeca->editar(Peca)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::visualizarPeca(){ //preciso pegar os dados com controladora servico

    // Mensagens a serem apresentadas na tela de visualizar Peca.

    char texto1[] ="Informe o codigo da Peca que se deseja visualizar: ";
    char texto10[]="Dado em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na exclusao. Digite algo.";
    char texto12[]="Falha na exclusao. Digite algo.";

    char campo1[80];                                                                           // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de visualizacao de Peca.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Visualizacao da Peca.

    if(cntrServicoPeca->visualizar(codigo)){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::executar(){

    // Mensagens a serem apresentadas na tela simplificada de Pecas.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar Pecas disponiveis.";
    char texto3[]="2 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        // Apresenta tela simplificada de Pecas.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
        echo();

        switch(campo){
            case 1: listarPeca();
                    break;
            case 2: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::executar(Matricula){

    // Mensagens a serem apresentadas tela completa de Pecas.

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Listar Pecas";
    char texto3[] ="2 - Incluir Peca.";
    char texto4[] ="3 - Excluir Peca.";
    char texto5[] ="4 - Editar Peca.";
    char texto6[] ="5 - Visualizar Peca.";
    char texto7[] ="6 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela completa de Pecas.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                            // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
        echo();

        switch(campo){
            case 1: listarPeca();
                    break;
            case 2: incluirPeca();
                    break;
            case 3: excluirPeca();
                    break;
            case 4: editarPeca();
                    break;
            case 5: visualizarPeca();
                    break;
            case 6: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------

void CntrApresentacaoProdutosFinanceiros::executar(){

    // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar produto de investimento.";
    char texto3[]="2 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        // Apresenta tela simplificada de produtos financeiros.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
        echo();

        switch(campo){
            case 1: consultarProdutoInvestimento();
                    break;
            case 2: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoProdutosFinanceiros::executar(CPF){

    // Mensagens a serem apresentadas tela completa de produtos financeiros.

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Consultar conta corrente.";
    char texto3[] ="2 - Cadastrar produto de investimento.";
    char texto4[] ="3 - Descadastrar produto de investimento.";
    char texto5[] ="4 - Consultar produto de investimento.";
    char texto6[] ="5 - Realizar aplicacao em produto de investimento.";
    char texto7[] ="6 - Listar aplicacoes em produto de investimento.";
    char texto8[] ="7 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de la�o.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela completa de produtos financeiros.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 14,coluna/4,"%s",texto8);                                            // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
        echo();

        switch(campo){
            case 1: consultarConta();
                    break;
            case 2: cadastrarProdutoInvestimento();
                    break;
            case 3: descadastrarProdutoInvestimento();
                    break;
            case 4: consultarProdutoInvestimento();
                    break;
            case 5: realizarAplicacao();
                    break;
            case 6: listarAplicacoes();
                    break;
            case 7: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoProdutosFinanceiros::consultarConta(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico consultar conta nao implementado. Digite algo.";                      // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoProdutosFinanceiros::cadastrarProdutoInvestimento(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico cadastrar produto investimento nao implementado. Digite algo.";       // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoProdutosFinanceiros::descadastrarProdutoInvestimento(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico descadastrar produto investimento nao implementado. Digite algo.";    // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoProdutosFinanceiros::consultarProdutoInvestimento(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico consultar produto investimento nao implementado. Digite algo.";       // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoProdutosFinanceiros::realizarAplicacao(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico realizar aplicacao nao implementado. Digite algo.";                   // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoProdutosFinanceiros::listarAplicacoes(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico listar aplicacoes nao implementado. Digite algo.";                    // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}
