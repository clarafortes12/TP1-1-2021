#include <string.h>
#include <stdexcept>
#include <iostream>

#include "sqlite3.h"
#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"
#include "controladorasapresentacao.h"
#include "controladorasservico.h"
#include "UnidadePersistencia.h"

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

    cntrApresentacaoControle->executar();

    return 0;
}

