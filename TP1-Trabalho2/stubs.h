#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Classe stub do serviço autenticação.

class StubServicoAutenticacao:public IServicoAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(Matricula, Senha);
};

//--------------------------------------------------------------------------------------------
// Classe stub do serviço participante.

class StubServicoParticipante:public IServicoParticipante {
    private:
        static const string INVALIDO;
    public:
        bool cadastrar(Participante);
        bool consultar(Participante*);
        bool editar(Participante*);
        bool excluir(Participante*);
};

//--------------------------------------------------------------------------------------------
// Classe stub do serviço produtos financeiros.

class StubServicoProdutosFinanceiros:public IServicoProdutosFinanceiros {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarConta(Conta);
        bool consultarConta(Conta*);
        bool cadastrarProdutoInvestimento(Produto);
        bool descadastrarProdutoInvestimento(Codigo);
        bool realizarAplicacao(Aplicacao);
        bool recuperarAplicacao(Aplicacao*);                        // Adaptar assinatura.
};

#endif // STUBS_H_INCLUDED
