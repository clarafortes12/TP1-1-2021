
#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED


#include <conio.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"
#include "UnidadePersistencia.h"

#define CLR_SCR system("cls");
//---------------------------------------------------------------------------
//Classe CntrInteracao.

// Classe obtida dos exemplos disponibilizados pelo professor
class CntrInteracao {
     virtual void apresentarOpcoes() = 0;
public:
     void notificarErroAcesso();
     void notificarErroDigitacao();
     void notificarSucessoOperacao();
     virtual void executar() = 0;
};

//--------------------------------------------------------------------------------------------
// • Módulo Serviço Autenticação
// - Implementado pela classe CntrServicoAutenticacao
// - Responsável por implementar a lógica de negócios e armazenar os dados no que diz respeito
// ao serviço de autenticação de participantes. Ele compara os dados informados de matrícula e
// senha pelo usuário do sistema com os dados cadastrados no banco de dados, de forma a
// permitir ou não o acesso do usuário ao sistema.
//
// Estudante responsável: Liz Costato - 180022261
class CntrServicoAutenticacao:public IServicoAutenticacao{
    bool autenticar(Matricula, Senha);
};

//--------------------------------------------------------------------------------------------
// • Módulo Serviço Participante
// - Implementado pela classe CntrServicoParticipante
// - Responsável por implementar a lógica de negócios e armazenar os dados no que diz respeito
// aos serviços de cadastramento, edição, consulta e descadastramento de um participante, bem
// como ao cadastramento de um participante à uma peça já existente no sistema. De modo a
// executar esses serviços, a tabela “participante” do banco de dados é acessada para incluir
// novos dados, para obter informações desejadas, ou mesmo para editar ou excluir informações
// existentes.
//
// Estudante responsável: Clara Fortes - 190017503
class CntrServicoParticipante:public IServicoParticipante{
    public:
        bool consultarParticipante(Matricula);
        bool cadastrarParticipante(Participante);
        bool editarParticipante(Participante);
        bool descadastrarParticipante(Matricula);
        bool cadastrarParticipantePeca(Participante);
        int pesquisarParticipantePeca(Codigo);
};

//--------------------------------------------------------------------------------------------
// • Módulo Serviço Peça
// - Implementado pela classe CntrServicoPeca
// - Responsável por implementar a lógica de negócios e armazenar os dados no que diz respeito
// aos serviços de listar, incluir, excluir, editar ou visualizar peças cadastradas no sistema.
// De modo a executar esses serviços, a tabela “peca” do banco de dados é acessada para incluir
// novos dados, para obter informações desejadas, ou mesmo para editar ou excluir informações
// existentes.
//
// Estudante responsável: Leandro Bottecchia - 180145169
class CntrServicoPeca:public IServicoPeca{
    public:
        bool listarPeca();
        bool visualizarPeca(Codigo);
        bool incluirPeca(Peca);
        bool editarPeca(Peca);
        bool excluirPeca(Codigo);
};

//--------------------------------------------------------------------------------------------
// • Módulo Serviço Sessão
// - Implementado pela classe CntrServicoSessao
// - Responsável por implementar a lógica de negócios e armazenar os dados no que diz respeito
// aos serviços de listar, incluir, excluir, editar ou visualizar sessões cadastradas no
// sistema. De modo a executar esses serviços, a tabela “sessao” do banco de dados é acessada
// para incluir novos dados, para obter informações desejadas, ou mesmo para editar ou excluir
// informações existentes.
//
// Estudante responsável: Leandro Bottecchia - 180145169
class CntrServicoSessao:public IServicoSessao{
    public:
        bool listarSessao();
        bool visualizarSessao(Codigo);
        bool incluirSessao(Sessao);
        bool editarSessao(Sessao);
        bool excluirSessao(Codigo);
        bool cadastrarSessaoPeca(Sessao);
        bool cadastrarSessaoSala(Sessao);
        int pesquisarSessaoPeca(Codigo);
        int pesquisarSessaoSala(Codigo);
};

//--------------------------------------------------------------------------------------------
// • Módulo Serviço Sala
// - Implementado pela classe CntrServicoSala
// - Responsável por implementar a lógica de negócios e armazenar os dados no que diz respeito
// aos serviços de listar, incluir, excluir, editar ou visualizar salas cadastradas no sistema.
// De modo a executar esses serviços, a tabela “sala” do banco de dados é acessada para incluir
// novos dados, para obter informações desejadas, ou mesmo para editar ou excluir informações
// existentes.
//
// Estudante responsável: Liz Costato - 180022261
class CntrServicoSala:public IServicoSala{
    public:
        bool listarSala();
        bool visualizarSala(Codigo);
        bool incluirSala(Sala);
        bool editarSala(Sala);
        bool excluirSala(Codigo);
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
