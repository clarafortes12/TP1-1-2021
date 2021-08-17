#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "Dominios.h"
#include <string>

// -------------------------------------------------------
// Entidades do Leandro - 180145169
// Peca
///
/// Padr&atilde;o para representa&ccedil;&atilde;o da Pe&ccedil;a.
///
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

/// Armazena codigo.
///
/// @param valor Codigo codigo.
///
/// @return void
///
inline void Peca::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

/// Armazena nome.
///
/// @param valor Nome nome.
///
/// @return void
///
inline void Peca::setNome(const Nome& nome){
    this->nome = nome;
}

/// Armazena tipo.
///
/// @param valor Tipo tipo.
///
/// @return void
///
inline void Peca::setTipo(const Tipo& tipo){
    this->tipo = tipo;
}

/// Armazena classificacao.
///
/// @param valor Classificacao classificacao.
///
/// @return void
///
inline void Peca::setClassificacao(const Classificacao& classificacao){
    this->classificacao = classificacao;
}

///
/// Retorna codigo.
///
/// @return Codigo codigo.
///
inline Codigo Peca::getCodigo() const{
    return codigo;
}

///
/// Retorna nome.
///
/// @return Nome nome.
///
inline Nome Peca::getNome() const{
    return nome;
}

///
/// Retorna tipo.
///
/// @return Tipo tipo.
///
inline Tipo Peca::getTipo() const{
    return tipo;
}

///
/// Retorna classificacao.
///
/// @return Classificacao classificacao.
///
inline Classificacao Peca::getClassificacao() const{
    return classificacao;
}

//sessao
///
/// Padr&atilde;o para representa&ccedil;&atilde;o da Sess&atilde;o.
///
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

/// Armazena codigo.
///
/// @param valor Codigo codigo.
///
/// @return void
///
inline void Sessao::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

/// Armazena data.
///
/// @param valor Data data.
///
/// @return void
///
inline void Sessao::setData(const Data& data){
    this->data = data;
}

/// Armazena horario.
///
/// @param valor Horario horario.
///
/// @return void
///
inline void Sessao::setHorario(const Horario& horario){
    this->horario = horario;
}

///
/// Retorna codigo.
///
/// @return Codigo codigo.
///
inline Codigo Sessao::getCodigo() const{
    return codigo;
}

///
/// Retorna data.
///
/// @return Data data.
///
inline Data Sessao::getData() const{
    return data;
}

///
/// Retorna horario.
///
/// @return Horario horario.
///
inline Horario Sessao::getHorario() const{
    return horario;
}

// -------------------------------------------------------
// Entidades da Liz - 180022261

//sala
///
/// Padr&atilde;o para representa&ccedil;&atilde;o da Sala.
///
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

/// Armazena codigo.
///
/// @param valor Codigo codigo.
///
/// @return void
///
inline void Sala::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

/// Armazena nome.
///
/// @param valor Nome nome.
///
/// @return void
///
inline void Sala::setNome(const Nome& nome){
    this->nome = nome;
}

/// Armazena capacidade.
///
/// @param valor Capacidade capacidade.
///
/// @return void
///
inline void Sala::setCapacidade(const Capacidade& capacidade){
    this->capacidade = capacidade;
}

///
/// Retorna codigo.
///
/// @return Codigo codigo.
///
inline Codigo Sala::getCodigo() const{
    return codigo;
}

///
/// Retorna nome.
///
/// @return Nome nome.
///
inline Nome Sala::getNome() const{
    return nome;
}
///
/// Retorna sala.
///
/// @return Sala sala.
///
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

/// Armazena matricula.
///
/// @param valor Matricula matricula.
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
