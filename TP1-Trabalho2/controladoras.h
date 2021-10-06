#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

//-----------------------------------------------------------------------------------
// Declara��o de classe controladora.

class CntrIAAutenticacao:public IAAutenticacao {
private:
    ISAutenticacao *cntrISAutenticacao;            // Refer�ncia para servidor.
public:
    bool autenticar(Matricula*);
    void setCntrISAutenticacao(ISAutenticacao*);
};

void inline CntrIAAutenticacao::setCntrISAutenticacao(ISAutenticacao *cntrISAutenticacao){
        this->cntrISAutenticacao = cntrISAutenticacao;
}

//-----------------------------------------------------------------------------------
// Declara��o de classe controladora.
class CntrIAPeca:public IAPeca {
private:

    // C�digos dos servi�os.

    const static int cadastrar   = 1;
    const static int descadastrar   = 2;
    const static int listar = 3;
    const static int alterar    = 4;
    const static int RETORNAR  = 5;

    ISPeca *cntrISPeca;                  // Refer�ncia para servidor.

public:
    void executar(const Matricula&);
    void setCntrISPeca(ISPeca *);
};

inline void CntrIAPeca::setCntrISPeca(ISPeca *cntrISPeca){
    this->cntrISPeca = cntrISPeca;
}
#endif // CONTROLADORAS_H_INCLUDED
