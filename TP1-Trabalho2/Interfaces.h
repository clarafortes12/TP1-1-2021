#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED



class IAPeca {
public:
    virtual void executar(const Matricula&) = 0;                    // Método por meio do qual é solicitado o serviço.
    virtual void setCntrISPeca(ISPeca *) = 0;                 // Método para estabelecer ligação (link) com a controladora de serviço.
    virtual ~IAPeca(){}                                          // Método destrutor virtual.
};

class ISPeca {
public:

    // Métodos por meio dos quais são solicitados os serviços.

    virtual bool cadastrar(const Peca&) = 0;
    virtual bool descadastrar(const Codigo&) = 0;
    virtual bool listar(Peca&) = 0;
    virtual bool alterar(const Peca&) = 0;

    virtual ~ISPeca(){}                                         // Método destrutor virtual.
};




#endif // INTERFACES_H_INCLUDED


// controladora.h



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
    void executar(const Codigo&);
    void setCntrISPeca(ISPeca *);
};

inline void CntrIAPeca::setCntrISPeca(ISPeca *cntrISPeca){
    this->cntrISPeca = cntrISPeca;
}


