#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

//-----------------------------------------------------------------------------------
// Declaração de classe controladora.

class CntrIAAutenticacao:public IAAutenticacao {
private:
    ISAutenticacao *cntrISAutenticacao;            // Referência para servidor.
public:
    bool autenticar(Matricula*);
    void setCntrISAutenticacao(ISAutenticacao*);
};

void inline CntrIAAutenticacao::setCntrISAutenticacao(ISAutenticacao *cntrISAutenticacao){
        this->cntrISAutenticacao = cntrISAutenticacao;
}

//-----------------------------------------------------------------------------------
// Declaração de classe controladora.

class CntrIAGerente:public IAGerente {
private:

    // Códigos dos serviços.

    const static int INCLUIR   = 1;
    const static int REMOVER   = 2;
    const static int PESQUISAR = 3;
    const static int EDITAR    = 4;
    const static int RETORNAR  = 5;

    ISGerente *cntrISGerente;                  // Referência para servidor.

public:
    void executar(const Matricula&);
    void setCntrISGerente(ISGerente *);
};

inline void CntrIAGerente::setCntrISGerente(ISGerente *cntrISGerente){
    this->cntrISGerente = cntrISGerente;
}


class CntrIAPeca:public IAPeca {
private:

    // Códigos dos serviços.

    const static int cadastrar   = 1;
    const static int descadastrar   = 2;
    const static int listar = 3;
    const static int alterar    = 4;
    const static int RETORNAR  = 5;

    ISPeca *cntrISPeca;                  // Referência para servidor.

public:
    void executar(const Matricula&);
    void setCntrISPeca(ISPeca *);
};

inline void CntrIAPeca::setCntrISPeca(ISPeca *cntrISPeca){
    this->cntrISPeca = cntrISPeca;
}
#endif // CONTROLADORAS_H_INCLUDED
