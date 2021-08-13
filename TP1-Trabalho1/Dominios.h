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

// ---------- Classifica��o
class Classificacao{
    private:
        string idade;
        void validar(string);
    public:
        Classificacao();
        Classificacao(string);
        void setValor(string);
        string getValor() const;
};

inline string Classificacao::getValor() const{
    return idade;
}

// ---------- Tipo
class Tipo{
    private:
        string genero;
        void validar(string);
    public:
        Tipo();
        Tipo(string);
        void setValor(string);
        string getValor() const;
};
inline string Tipo::getValor() const{
    return genero;
}

// ---------- C�digo
class Codigo{
    private:
        string codigo;
        void validar(string);
        bool eh_maiusculo(char);
        bool eh_numero(char);
    public:
        Codigo();
        Codigo(string);
        void setValor(string);
        string getValor() const;
};

inline string Codigo::getValor() const{
    return codigo;
}

// ---------- Email
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
        Email();
        Email(string);
        void setValor(string);
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
