#include <string.h>
#include <stdexcept>
#include <iostream>

#include "curses.h"
#include "dominios.h"
#include "interfaces.h"
#include "controladorasapresentacao.h"
#include "controladorasservico.h"
#include "stubs.h"

using namespace std;

int main()
{
    // Instanciar controladoras de apresentação.

    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoParticipante *cntrApresentacaoParticipante;
    IApresentacaoPeca *cntrApresentacaoPeca;
    IApresentacaoSala *cntrApresentacaoSala;
    IApresentacaoSessao *cntrApresentacaoSessao;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoParticipante = new CntrApresentacaoParticipante();
    cntrApresentacaoPeca = new CntrApresentacaoPeca();
    cntrApresentacaoSala = new CntrApresentacaoSala();
    cntrApresentacaoSessao = new CntrApresentacaoSessao();

    // Instanciar stubs de serviço.

    IServicoAutenticacao *stubServicoAutenticacao;
    IServicoParticipante *stubServicoParticipante;
    IServicoPeca *stubServicoPeca;
    IServicoSala *stubServicoSala;
    IServicoSessao *stubServicoSessao;

    stubServicoAutenticacao = new StubServicoAutenticacao();
    stubServicoParticipante = new StubServicoParticipante();
    stubServicoPeca = new StubServicoPeca();
    stubServicoSala = new StubServicoSala();
    stubServicoSessao = new StubServicoSessao();

    // Interligar controladoras e stubs.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoParticipante(cntrApresentacaoParticipante);
    cntrApresentacaoControle->setCntrApresentacaoPeca(cntrApresentacaoPeca);
    cntrApresentacaoControle->setCntrApresentacaoSala(cntrApresentacaoSala);
    cntrApresentacaoControle->setCntrApresentacaoSessao(cntrApresentacaoSessao);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);
    cntrApresentacaoParticipante->setCntrServicoParticipante(stubServicoParticipante);
    cntrApresentacaoPeca->setCntrServicoPeca(stubServicoPeca);
    cntrApresentacaoSala->setCntrServicoSala(stubServicoSala);
    cntrApresentacaoSessao->setCntrServicoSessao(stubServicoSessao);

    initscr();
    cntrApresentacaoControle->executar();
    endwin();

    return 0;
}

