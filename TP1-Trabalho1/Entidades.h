#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "Dominios.h"
#include <string>

//-------------Pe�a
// Estrutura de código sugerida para declaração de classe entidade.
// Substituir Entidade por nome da classe.
// Substituir Dominio.
// Substituir nomeAtributo.
/*
class Entidade {
    private:
            Dominio nomeAtributo;                   // Declarar cada atributo da classe.
    public:
            void setnomeAtributo(const Dominio&);   // Declarar método set para cada atributo.
            Dominio getnomeAtributo() const;        // Declarar método get para cada atributo.
};

inline void Entidade::setnomeAtributo(const Dominio &nomeAtributo){
    this->nomeAtributo = nomeAtributo;
}

inline Dominio Entidade::getnomeAtributo() const{
    return nomeAtributo;
}
*/
// -------------------------------------------------------
// Entidades do Leandro - 180145169
class Peca {
    private:
        Codigo codigo;
        Nome nome;
        Tipo tipo;
        Classificacao classificacao;
    public:
        //Projeto();
        //Projeto(Codigo,Nome,Tipo,Classificacao);
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setNome(const Nome&);
        Nome getNome() const;
        void setTipo(const Tipo&);
        Tipo getTipo() const;
        void setClassificacao(const Classificacao&);
        Classificacao getClassificacao() const;
};

inline void Peca::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline void Peca::setNome(const Nome& nome){
    this->nome = nome;
}

inline void Peca::setTipo(const Tipo& tipo){
    this->tipo = tipo;
}

inline void Peca::setClassificacao(const Classificacao& classificacao){
    this->classificacao = classificacao;
}

inline Codigo Peca::getCodigo() const{
    return codigo;
}
inline Nome Peca::getNome() const{
    return nome;
}
inline Tipo Peca::getTipo() const{
    return tipo;
}
inline Classificacao Peca::getClassificacao() const{
    return classificacao;
}

// -------------------------------------------------------
// Entidades da Liz - 180022261

// -------------------------------------------------------
// Entidades da Clara - 190017503



#endif // ENTIDADES_H_INCLUDED
