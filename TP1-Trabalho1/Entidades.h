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
// Peca
class Peca {
    private:
        Codigo codigo;
        Nome nome;
        Tipo tipo;
        Classificacao classificacao;
    public:
        //Peca();
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

//sessao
class Sessao {
    private:
        Codigo codigo;
        Data data;
        Horario horario;
    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setData(const Data&);
        Data getData() const;
        void setHorario(const Horario&);
        Horario getHorario() const;
};

inline void Sessao::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline void Sessao::setData(const Data& data){
    this->data = data;
}

inline void Sessao::setHorario(const Horario& horario){
    this->horario = horario;
}

inline Codigo Sessao::getCodigo() const{
    return codigo;
}
inline Data Sessao::getData() const{
    return data;
}
inline Horario Sessao::getHorario() const{
    return horario;
}

// -------------------------------------------------------
// Entidades da Liz - 180022261

//sala
class Sala {
    private:
        Codigo codigo;
        Nome nome;
        Capacidade capacidade;
    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setNome(const Nome&);
        Nome getNome() const;
        void setCapacidade(const Capacidade&);
        Capacidade getCapacidade() const;
};

inline void Sala::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline void Sala::setNome(const Nome& nome){
    this->nome = nome;
}

inline void Sala::setCapacidade(const Capacidade& capacidade){
    this->capacidade = capacidade;
}

inline Codigo Sala::getCodigo() const{
    return codigo;
}
inline Nome Sala::getNome() const{
    return nome;
}
inline Capacidade Sala::getCapacidade() const{
    return capacidade;
}

// -------------------------------------------------------
// Entidades da Clara - 190017503
///
/// Padr&atilde;o para representa&ccedil;&atilde;o do Participante.
///
class Participante {
    private:
        Matricula matricula;
        Nome nome;
        Nome sobrenome;
        Email email;
        Telefone telefone;
        Senha senha;
        Cargo cargo;
    public:
        void setMatricula(const Matricula&);
        Matricula getMatricula() const;
        void setNome(const Nome&);
        Nome getNome() const;
        void setSobrenome(const Nome&);
        Nome getSobrenome() const;
        void setEmail(const Email&);
        Email getEmail() const;
        void setTelefone(const Telefone&);
        Telefone getTelefone() const;
        void setSenha(const Senha&);
        Senha getSenha() const;
        void setCargo(const Cargo&);
        Cargo getCargo() const;
};

/// Armazena matrícula.
///
/// @param valor Matricula matrícula.
///
/// @return void
///
inline void Participante::setMatricula(const Matricula& matricula){
    this->matricula = matricula;
}

///
/// Retorna matr&iacute;cula.
///
/// @return Matr&iacute;cula matricula.
///
inline Matricula Participante::getMatricula() const{
    return matricula;
}

/// Armazena nome.
///
/// @param valor Nome nome.
///
/// @return void
///
inline void Participante::setNome(const Nome& nome){
    this->nome = nome;
}

///
/// Retorna nome.
///
/// @return Nome nome.
///
inline Nome Participante::getNome() const{
    return nome;
}

/// Armazena sobrenome.
///
/// @param valor Nome sobrenome.
///
/// @return void
///
inline void Participante::setSobrenome(const Nome& sobrenome){
    this->sobrenome = sobrenome;
}

///
/// Retorna sobrenome.
///
/// @return Nome sobrenome.
///
inline Nome Participante::getSobrenome() const{
    return sobrenome;
}

/// Armazena email.
///
/// @param valor Email email.
///
/// @return void
///
inline void Participante::setEmail(const Email& email){
    this->email = email;
}

///
/// Retorna email.
///
/// @return Email email.
///
inline Email Participante::getEmail() const{
    return email;
}

/// Armazena telefone.
///
/// @param valor Telefone telefone.
///
/// @return void
///
inline void Participante::setTelefone(const Telefone& telefone){
    this->telefone = telefone;
}

///
/// Retorna telefone.
///
/// @return Telefone telefone.
///
inline Telefone Participante::getTelefone() const{
    return telefone;
}

/// Armazena senha.
///
/// @param valor Senha senha.
///
/// @return void
///
inline void Participante::setSenha(const Senha& senha){
    this->senha = senha;
}

///
/// Retorna senha.
///
/// @return Senha senha.
///
inline Senha Participante::getSenha() const{
    return senha;
}

/// Armazena cargo.
///
/// @param valor Cargo cargo.
///
/// @return void
///
inline void Participante::setCargo(const Cargo& cargo){
    this->cargo = cargo;
}

///
/// Retorna cargo.
///
/// @return Cargo cargo.
///
inline Cargo Participante::getCargo() const{
    return cargo;
}
#endif // ENTIDADES_H_INCLUDED
