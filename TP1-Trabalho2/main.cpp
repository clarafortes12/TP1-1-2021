#include <string.h>
#include <stdexcept>
#include <iostream>

#include "sqlite3.h"
#include "dominios.h"
#include "interfaces.h"
#include "controladorasapresentacao.h"
#include "controladorasservico.h"

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

    // Instanciar cntr de serviço.
    IServicoAutenticacao *cntrServicoAutenticacao;
    IServicoParticipante *cntrServicoParticipante;
    IServicoPeca *cntrServicoPeca;
    IServicoSala *cntrServicoSala;
    IServicoSessao *cntrServicoSessao;

    cntrServicoAutenticacao = new CntrServicoAutenticacao();
    cntrServicoParticipante = new CntrServicoParticipante();
    cntrServicoPeca = new CntrServicoPeca();
    cntrServicoSala = new CntrServicoSala();
    cntrServicoSessao = new CntrServicoSessao();
        // IServicoAutenticacao *stubServicoAutenticacao;
        // IServicoParticipante *stubServicoParticipante;
        // IServicoPeca *stubServicoPeca;
        // IServicoSala *stubServicoSala;
        // IServicoSessao *stubServicoSessao;

        // stubServicoAutenticacao = new StubServicoAutenticacao();
        // stubServicoParticipante = new StubServicoParticipante();
        // stubServicoPeca = new StubServicoPeca();
        // stubServicoSala = new StubServicoSala();
        // stubServicoSessao = new StubServicoSessao();
        // Interligar controladoras e stubs.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoParticipante(cntrApresentacaoParticipante);
    cntrApresentacaoControle->setCntrApresentacaoPeca(cntrApresentacaoPeca);
    cntrApresentacaoControle->setCntrApresentacaoSala(cntrApresentacaoSala);
    cntrApresentacaoControle->setCntrApresentacaoSessao(cntrApresentacaoSessao);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);
    cntrApresentacaoParticipante->setCntrServicoParticipante(cntrServicoParticipante);
    cntrApresentacaoPeca->setCntrServicoPeca(cntrServicoPeca);
    cntrApresentacaoSala->setCntrServicoSala(cntrServicoSala);
    cntrApresentacaoSessao->setCntrServicoSessao(cntrServicoSessao);

        // cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);
        // cntrApresentacaoParticipante->setCntrServicoParticipante(stubServicoParticipante);
        // cntrApresentacaoPeca->setCntrServicoPeca(stubServicoPeca);
        // cntrApresentacaoSala->setCntrServicoSala(stubServicoSala);
        // cntrApresentacaoSessao->setCntrServicoSessao(stubServicoSessao);

    //initscr(); // possivel funcai definida pelo prof
    cntrApresentacaoControle->executar();
    //endwin(); // possivel funcai definida pelo prof

    return 0;
}

