#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <string.h>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"


//--------------------------------------------------------------------------------------------
// Declara��es de classes controladoras e implementa��es de m�todos.

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

inline void CntrApresentacaoControle::setCntrApresentacaoPeca(IApresentacaoPeca *cntr){
            cntrApresentacaoPeca = cntr;
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

class CntrApresentacaoPeca:public IApresentacaoPeca{
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

inline void CntrApresentacaoPeca::setCntrServicoPeca(IServicoPeca *cntr){
    cntrServicoPeca = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoSessao:public IApresentacaoSessao{
    private:
        IServicoSessao *cntrServicoSessao;
        void listarSessao();
        void incluirSessao();
        void excluirSessao();
        void editarSessao();
        void visualizarSessao();
    public:
        void executar(Matricula);
        void executar();
        void setCntrServicoSessao(IServicoSessao*);
};

inline void CntrApresentacaoSessao::setCntrServicoSessao(IServicoSessao *cntr){
    cntrServicoSessao = cntr;
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
