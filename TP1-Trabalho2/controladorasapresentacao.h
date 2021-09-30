#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <string.h>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"


//--------------------------------------------------------------------------------------------
// Declarações de classes controladoras e implementações de métodos.

class CntrApresentacaoControle{
    private:
        Matricula matricula;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoPessoal *cntrApresentacaoPessoal;
        IApresentacaoPeca *cntrApresentacaoPeca;
        IApresentacaoSessao *cntrApresentacaoSessao;
        IApresentacaoSala *cntrApresentacaoSala;
    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoPessoal(IApresentacaoPessoal*);
        void setCntrApresentacaoPeca(IApresentacaoPeca*);
        void setCntrApresentacaoSessao(IApresentacaoSessao*);
        void setCntrApresentacaoSala(IApresentacaoSala*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPessoal(IApresentacaoPessoal *cntr){
            cntrApresentacaoPessoal = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPessa(IApresentacaoPessa *cntr){
            cntrApresentacaoPessa = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoSessao(IApresentacaoSessao *cntr){
            cntrApresentacaoSessao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoSala(IApresentacaoSala *cntr){
            cntrApresentacaoSala = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
    private:
        IServicoAutenticacao *cntr;
    public:
        bool autenticar(Matricula*);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoPessoal:public IApresentacaoPessoal{
    private:
        IServicoPessoal *cntrServicoPessoal;
        IServicoProdutosFinanceiros *cntrServicoProdutosFinanceiros;
        void consultarDadosPessoais();
    public:
        void executar(CPF);
        void cadastrar();
        void setCntrServicoPessoal(IServicoPessoal*);
        void setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros*);
};

inline void CntrApresentacaoPessoal::setCntrServicoPessoal(IServicoPessoal *cntr){
    cntrServicoPessoal = cntr;
}

inline void CntrApresentacaoPessoal::setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros *cntr){
    cntrServicoProdutosFinanceiros = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoSala:public IApresentacaoSala{
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

inline void CntrApresentacaoSala::setCntrServicoSala(IServicoSala *cntr){
    cntrServicoSala = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoProdutosFinanceiros:public IApresentacaoProdutosFinanceiros{
    private:
        IServicoProdutosFinanceiros *cntr;
        void consultarConta();
        void cadastrarProdutoInvestimento();
        void descadastrarProdutoInvestimento();
        void consultarProdutoInvestimento();
        void realizarAplicacao();
        void listarAplicacoes();
    public:
        void executar();
        void executar(CPF);
        void setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros*);
};

inline void CntrApresentacaoProdutosFinanceiros::setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros *cntr){
    this->cntr = cntr;
}


#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
