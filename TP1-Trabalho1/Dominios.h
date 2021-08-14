// Exemplo de documenta��o de classe usando ferramenta Doxygen.

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

///
/// Padr&atilde;o para representa&ccedil;&atilde;o de cliente.
///
/// Regras de formato:
///
/// - C&oacute;digo &eacute; v&aacute;lido caso <u>menor</u> ou igual a 5.
///

// -------------------------------------------------------------------------
// Classes do Leandro - 180145169

class Capacidade {
    private:
            int valor;
            void validar(int);
    public:
            Capacidade();
            Capacidade(int);
            void setValor(int valor);
            int getValor() const;

};

inline int Capacidade::getValor() const{         // Metodo inline e const.
    return valor;
}

class Horario {
    private:
            string valor;
            void validar(string valor);
    public:
            Horario();
            Horario(string);
            void setValor(string valor);
            string getValor() const;

};

inline string Horario::getValor() const{         // Metodo inline e const.
    return valor;
}

class Senha {
    private:
            string valor;
            void validar(string);
    public:
            Senha();
            Senha(string);
            void setValor(string valor);
            string getValor() const;
};
inline string Senha::getValor() const{         // Metodo inline e const.
    return valor;
}

class Telefone {
    private:
            string valor;
            void validar(string);
    public:
            Telefone();
            Telefone(string);
            void setValor(string valor);
            string getValor() const;
};
inline string Telefone::getValor() const{         // Metodo inline e const.
    return valor;
}

// -------------------------------------------------------------------------
// Classes da Liz - 180022261

class Cargo {
    private:
            string valor;
            void validar(string);
    public:
            Cargo();
            Cargo(string);
            void setValor(string);
            string getValor() const;

};

inline string Cargo::getValor() const{         // Metodo inline e const.
    return valor;
}

class Matricula {
    private:
            string valor;
            void validar(string);
    public:
            Matricula();
            Matricula(string);
            void setValor(string);
            string getValor() const;

};

inline string Matricula::getValor() const{         // Metodo inline e const.
    return valor;
}

class Nome {
    private:
            string valor;
            void validar(string);
    public:
            Nome();
            Nome(string);
            void setValor(string);
            string getValor() const;

};

inline string Nome::getValor() const{         // Metodo inline e const.
    return valor;
}

class Data {
    private:
            string valor;
            void validar(string);
    public:
            Data();
            Data(string);
            void setValor(string);
            string getValor() const;

};

inline string Data::getValor() const{         // Metodo inline e const.
    return valor;
}

// -------------------------------------------------------------------------
// Classes da Clara - 190017503

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classifica&ccedil;&atilde;o.
///
/// Regras de formato:
///
/// - classifica&ccedil;&atilde;o &eacute; v&aacute;lido caso igual a livre, 10, 12, 14 , 16 ou 18.
///

class Classificacao{
    private:
        string idade;
        void validar(string);
    public:

///
/// Inicializa o objeto com o classifica&ccedil;&atilde;o como vazio.
///
        Classificacao();

///
/// Inicializa o objeto caso o classifica&ccedil;&atilde;o informado seja v&aacute;lido.
///
/// @param valor string classifica&ccedil;&atilde;o.
///
        Classificacao(string);

///
/// Armazena classifica&ccedil;&atilde;o.
///
/// @param valor string classifica&ccedil;&atilde;o.
///
/// @return void
///
        void setValor(string);

///
/// Retorna classifica&ccedil;&atilde;o.
///
/// @return string classifica&ccedil;&atilde;o.
///
        string getValor() const;
};

inline string Classificacao::getValor() const{
    return idade;
}

///
/// Padr&atilde;o para representa&ccedil;&atilde;o do tipo.
///
/// Regras de formato:
///
/// - tipo &eacute; v&aacute;lido caso igual a auto, comodia, drama, farsa, melodrama, monologo, musical, opera ou revista.
///
class Tipo{
    private:
        string genero;
        void validar(string);
    public:
///
/// Inicializa o objeto com o Tipo como vazio.
///
        Tipo();

///
/// Inicializa o objeto caso o tipo informado seja v&aacute;lido.
///
/// @param valor string tipo.
///
        Tipo(string);

///
/// Armazena tipo.
///
/// @param valor string tipo.
///
/// @return void
///
        void setValor(string);

///
/// Retorna tipo.
///
/// @return string tipo.
///
        string getValor() const;
};
inline string Tipo::getValor() const{
    return genero;
}

///
/// Padr&atilde;o para representa&ccedil;&atilde;o do c&oacute;digo.
///
/// Regras de formato:
///
/// - c&oacute;digo &eacute; v&aacute;lido caso tem 6 caracteres, sendo os dois primeiros letras mai&uacute;sculas e 4 &uacute;ltimos s&atilde;o d&iacute;gitos.
///
class Codigo{
    private:
        string codigo;
        void validar(string);
        bool eh_maiusculo(char);
        bool eh_numero(char);
    public:
///
/// Inicializa o objeto com o c&oacute;digo como vazio.
///
        Codigo();

///
/// Inicializa o objeto caso o c&oacute;digo informado seja v&aacute;lido.
///
/// @param valor string c&oacute;digo.
///
        Codigo(string);

///
/// Armazena c&oacute;digo.
///
/// @param valor string c&oacute;digo.
///
/// @return void
///
        void setValor(string);
///
/// Retorna c&oacute;digo.
///
/// @return string c&oacute;digo.
///
        string getValor() const;
};

inline string Codigo::getValor() const{
    return codigo;
}

///
/// Padr&atilde;o para representa&ccedil;&atilde;o do email.
///
/// Regras de formato:
///
/// - email &eacute; v&aacute;lido caso tenha formato parte-local@dom&iacute;nio.
/// - parte-local &eacute; composta por at&eacute; 64 caracteres.
/// - dom&iacute;nio &eacute; composto por at&eacute; 255 caracteres.
/// - n&atilde;o tenha ponto nem no &iacute;nicio e nem no fim
/// - n&atilde;o tenha pontos juntos
/// - n&atilde;o tenha mais de um @
///
class Email{
    private:
        string parte_local;
        string dominio;
        void validar(string,string);
        bool pontos_seguidos(string);
        int busca_arroba(string);
        string busca_parte_local(string,int);
        string busca_dominio(string,int);
    public:
///
/// Inicializa o objeto com o email como vazio.
///
        Email();

///
/// Inicializa o objeto caso o email informado seja v&aacute;lido.
///
/// @param valor string email.
///
        Email(string);

/// Armazena email.
///
/// @param valor string email.
///
/// @return void
///
        void setValor(string);

///
/// Retorna email.
///
/// @return string email.
///
        string getValor() const;
};

inline string Email::getValor() const{
    if (parte_local == "")
        return parte_local;
    else{
        string email = parte_local;
        email += "@";
        email += dominio;
        return email;
    }
}

///////////// FUNÇÕES AUXILIARES /////////////

bool eh_digito(string teste);
bool ha_repeticao(string teste);

#endif // DOMINIOS_H_INCLUDED
