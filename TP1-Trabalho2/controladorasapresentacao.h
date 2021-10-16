#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"

#define CLR_SCR system("cls");

//--------------------------------------------------------------------------------------------
// • Módulo MAC
// - MAC é uma abreviação para o nome Módulo Apresentação e Controle
// - Implementado pela classe CntrApresentacaoControle
// - Responsável por intermediar o acesso do participante às diferentes funcionalidades do
// sistema. Esse módulo será responsável por apresentar a tela inicial do sistema com as opções
// possíveis para o caso em que o usuário foi autenticado e também para o caso em que o usuário
// ainda não foi autenticado.
//
// Estudante responsável: Clara Fortes - 190017503
class CntrApresentacaoControle
{
private:
    Matricula matricula;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoParticipante *cntrApresentacaoParticipante;
    IApresentacaoPeca *cntrApresentacaoPeca;
    IApresentacaoSala *cntrApresentacaoSala;
    IApresentacaoSessao *cntrApresentacaoSessao;
public:
    void executar();
    void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
    void setCntrApresentacaoParticipante(IApresentacaoParticipante*);
    void setCntrApresentacaoPeca(IApresentacaoPeca*);
    void setCntrApresentacaoSala(IApresentacaoSala*);
    void setCntrApresentacaoSessao(IApresentacaoSessao*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr)
{
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoParticipante(IApresentacaoParticipante *cntr)
{
    cntrApresentacaoParticipante = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPeca(IApresentacaoPeca *cntr)
{
    cntrApresentacaoPeca = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoSala(IApresentacaoSala *cntr)
{
    cntrApresentacaoSala = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoSessao(IApresentacaoSessao *cntr)
{
    cntrApresentacaoSessao = cntr;
}

//--------------------------------------------------------------------------------------------
// • Módulo Apresentação Autenticação
// - Implementado pela classe CntrApresentacaoAutenticacao
// - Responsável pela interface com o usuário e pela validação dos dados de entrada no que diz
// respeito à autenticação do participante. Ou seja, é responsável por receber a matrícula e a
// senha do participante e por validar o formato dessas duas entradas.
//
// Estudante responsável: Liz Costato - 180022261
class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao
{
private:
    IServicoAutenticacao *cntrServicoAutenticacao;
public:
    bool autenticar(Matricula*);
    void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr)
{
    cntrServicoAutenticacao = cntr;
}

//--------------------------------------------------------------------------------------------
// • Módulo Apresentação Participante
// - Implementado pela classe CntrApresentacaoParticipante
// - Responsável pela interface com o usuário e pela validação dos dados de entrada no que diz
// respeito ao cadastramento, à edição, à consulta e ao descadastramento de um participante,
// bem como ao cadastramento de um participante à uma peça já existente no sistema.
//
// Estudante responsável: Clara Fortes - 190017503
class CntrApresentacaoParticipante:public IApresentacaoParticipante
{
private:
    IServicoParticipante *cntrServicoParticipante;
    void cadastrarParticipante();
    void consultarParticipante(Matricula);
    void editarParticipante(Matricula);
    bool descadastrarParticipante(Matricula);
    void cadastrarParticipantePeca(Matricula);
public:
    bool executar(Matricula);
    void executar();
    void setCntrServicoParticipante(IServicoParticipante*);
};

inline void CntrApresentacaoParticipante::setCntrServicoParticipante(IServicoParticipante *cntr)
{
    cntrServicoParticipante = cntr;
}

//--------------------------------------------------------------------------------------------
// • Módulo Apresentação Peça
// - Implementado pela classe CntrApresentacaoPeca
// - Responsável pela interface com o usuário e pela validação dos dados de entrada no que diz
// respeito a listar, incluir, excluir, editar ou visualizar peças cadastradas no sistema.
//
// Estudante responsável: Leandro Bottecchia - 180145169
class CntrApresentacaoPeca:public IApresentacaoPeca
{
private:
    IServicoPeca *cntrServicoPeca;
    void listarPeca();
    void incluirPeca();
    void excluirPeca();
    void editarPeca();
    void visualizarPeca();
public:
    void executar(Matricula);
    void executar();
    void setCntrServicoPeca(IServicoPeca*);
};

inline void CntrApresentacaoPeca::setCntrServicoPeca(IServicoPeca *cntr)
{
    cntrServicoPeca = cntr;
}

//--------------------------------------------------------------------------------------------
// • Módulo  Apresentação Sessão
// - Implementado pela classe CntrApresentacaoSessao
// - Responsável pela interface com o usuário e pela validação dos dados de entrada no que diz
// respeito a listar, incluir, excluir, editar ou visualizar sessões cadastradas no sistema.
// Além disso, é responsável pela interface com o usuário e pela validação dos dados de entrada
// no que diz respeito a criar relacionamentos entre sessões e salas e entre sessões e peças.
//
// Estudante responsável: Leandro Bottecchia - 180145169
class CntrApresentacaoSessao:public IApresentacaoSessao
{
private:
    IServicoSessao *cntrServicoSessao;
    void listarSessao();
    void incluirSessao();
    void excluirSessao();
    void editarSessao();
    void visualizarSessao();
    void cadastrarSessaoPeca();
    void cadastrarSessaoSala();
public:
    void executar(Matricula);
    void executar();
    void setCntrServicoSessao(IServicoSessao*);
};

inline void CntrApresentacaoSessao::setCntrServicoSessao(IServicoSessao *cntr)
{
    cntrServicoSessao = cntr;
}

//--------------------------------------------------------------------------------------------
// • Módulo  Apresentação Sala
// - Implementado pela classe CntrApresentacaoSala
// - Responsável pela interface com o usuário e pela validação dos dados de entrada no que diz
// respeito a listar, incluir, excluir, editar ou visualizar salas cadastradas no sistema.
//
// Estudante responsável: Liz Costato - 180022261
class CntrApresentacaoSala:public IApresentacaoSala
{
private:
    IServicoSala *cntrServicoSala;
    void listarSala();
    void incluirSala();
    void excluirSala();
    void editarSala();
    void visualizarSala();
public:
    void executar(Matricula);
    void executar();
    void setCntrServicoSala(IServicoSala*);
};

inline void CntrApresentacaoSala::setCntrServicoSala(IServicoSala *cntr)
{
    cntrServicoSala = cntr;
}

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
