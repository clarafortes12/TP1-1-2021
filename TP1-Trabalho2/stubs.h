#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Classe stub do servi�o autentica��o.

class StubServicoAutenticacao:public IServicoAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(Matricula, Senha);
};

//--------------------------------------------------------------------------------------------
// Classe stub do servi�o participante.

class StubServicoParticipante:public IServicoParticipante {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarParticipante(Participante);
        bool consultarParticipante(Participante*);
        bool editarParticipante(Participante*);
        bool descadastrarParticipante(Participante*);
};

//--------------------------------------------------------------------------------------------
// Classe stub do servi�o pe�a.

class StubServicoPeca:public IServicoPeca {
    private:
        static const string INVALIDO;
    public:
        bool incluirPeca(Peca);
        bool visualizarPeca(Peca*);
        bool editarPeca(Peca*);
        bool excluirPeca(Peca);
        bool listarPeca(Peca);
        bool recuperarAplicacao(Aplicacao*);
};

//--------------------------------------------------------------------------------------------
// Classe stub do servi�o sala.

class StubServicoSala:public IServicoSala {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarConta(Conta);
        bool consultarConta(Conta*);
        bool cadastrarProdutoInvestimento(Produto);
        bool descadastrarProdutoInvestimento(Codigo);
        bool realizarAplicacao(Aplicacao);
        bool recuperarAplicacao(Aplicacao*);
};

//--------------------------------------------------------------------------------------------
// Classe stub do servi�o sess�o.

class StubServicoSessao:public IServicoSessao {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarConta(Conta);
        bool consultarConta(Conta*);
        bool cadastrarProdutoInvestimento(Produto);
        bool descadastrarProdutoInvestimento(Codigo);
        bool realizarAplicacao(Aplicacao);
        bool recuperarAplicacao(Aplicacao*);
};

#endif // STUBS_H_INCLUDED
