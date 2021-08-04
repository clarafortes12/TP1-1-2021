#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "Dominios.h"
#include <string>

//-------------Peça
class Projeto {
    private:
        Codigo identificador;
        Nome nome;
        Tipo tipo;
        Classificacao classificacao;
    public:
        //Projeto();
        //Projeto(Codigo,Nome,Tipo,Classificacao);
        void setCodigo(Codigo);
        Codigo getCodigo() const;
        void setNome(Nome);
        Nome getNome() const;
        void setTipo(Tipo);
        Tipo getTipo() const;
        void setClassificacao(Classificacao);
        Classificacao getClassificacao() const;
};

inline Codigo Projeto::getCodigo() const{
    return identificador;
}
inline Nome Projeto::getNome() const{
    return nome;
}
inline Tipo Projeto::getTipo() const{
    return tipo;
}
inline Classificacao Projeto::getClassificacao() const{
    return classificacao;
}

#endif // ENTIDADES_H_INCLUDED
