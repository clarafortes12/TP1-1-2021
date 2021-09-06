// Exemplo de documenta��o de classe usando ferramenta Doxygen.

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

// -------------------------------------------------------------------------
// Classes do Leandro - 180145169

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da Capacidade.
///
/// @author Leandro Bottecchia - 180145169
///
/// Regras de formato:
///
/// - Capacidade &eacute; v&aacute;lido caso igual a 100, 200, 300, 400 ou 500.
///
class Capacidade {
    private:
            int valor;
            void validar(int);
    public:
///
/// Inicializa o objeto com o Capacidade como 100.
///
            Capacidade();
///
/// Inicializa o objeto caso o Capacidade informado seja v&aacute;lido.
///
/// @param valor int Capacidade.
///
            Capacidade(int);
///
/// Armazena Capacidade.
///
/// @param valor int Capacidade.
///
/// @return void
///
            void setValor(int);
///
/// Retorna Capacidade.
///
/// @return int Capacidade.
///
            int getValor() const;

};

inline int Capacidade::getValor() const{         // Metodo inline e const.
    return valor;
}

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da Hor&aacute;rio.
///
/// @author Leandro Bottecchia - 180145169
///
/// Regras de formato:
///
/// - Hor&aacute;rio &eacute; v&aacute;lido caso igual a "HH:MM"
/// - Em que HH tem-se a indica&ccedil;&atilde;o de um Hor&aacute;rio: 00 a 23
/// - Em que MM tem-se a indica&ccedil;&atilde;o de um Hor&aacute;rio: 00, 15, 30 ou 45.
///
class Horario {
    private:
            string valor;
            void validar(string valor);
    public:
///
/// Inicializa o objeto com o Hor&aacute;rio como 00:00.
///
            Horario();
///
/// Inicializa o objeto caso o Hor&aacute;rio informado seja v&aacute;lido.
///
/// @param valor string Hor&aacute;rio.
///
            Horario(string);
///
/// Armazena Hor&aacute;rio.
///
/// @param valor string Hor&aacute;rio.
///
/// @return void
///
            void setValor(string);
///
/// Retorna Hor&aacute;rio.
///
/// @return string Hor&aacute;rio.
///
            string getValor() const;

};

inline string Horario::getValor() const{         // Metodo inline e const.
    return valor;
}

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da Senha.
///
/// @author Leandro Bottecchia - 180145169
///
/// Regras de formato:
///
/// - Senha &eacute; v&aacute;lido caso tenha formato XXXXXXXX.
/// - Senha &eacute; composta por 8 caracteres.
/// - Cada caractere "X" &eacute; letra (A-Z ou a-z), d&iacute;gito (0-9) ou caractere especial.
/// - Caractere especiais s&atilde;o: "!", "@", "#", "$", "%", "&" ou "?".
/// - N&atilde;o existe caracter repetido.
/// - Existe pelo menos uma letra (mai&uacute;scula ou min&uacute;scula), um d&iacute;gito e um caractere especial
///
class Senha {
    private:
            string valor;
            void validar(string);
    public:
///
/// Inicializa o objeto com o Senha como vazio.
///
            Senha();
///
/// Inicializa o objeto caso o Senha informado seja v&aacute;lido.
///
/// @param valor string Senha.
///
            Senha(string);
///
/// Armazena Senha.
///
/// @param valor string Senha.
///
/// @return void
///
            void setValor(string);
///
/// Retorna Senha.
///
/// @return string Senha.
///
            string getValor() const;
};

inline string Senha::getValor() const{         // Metodo inline e const.
    return valor;
}

///
/// Padr&atilde;o para representa&ccedil;&atilde;o do Telefone.
///
/// @author Leandro Bottecchia - 180145169
///
/// Regras de formato:
///
/// - Telefone &eacute; v&aacute;lido caso tenha formato (XX)-YYYYYYYYY.
/// - 'XX' &eacute; um dos seguintes c&oacute;digos: 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33, 34, 35, 37, 38, 41, 42, 43, 44,
//// 45, 46, 47, 48, 49, 51, 53, 54, 55, 61, 62, 63, 64, 65, 66, 67, 68, 69, 71, 73, 74, 75, 77, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99.
/// - Cada caractere "Y" &eacute; um d&iacute;gito (0-9).
/// - Caractere especiais s&atilde;o: "!", "@", "#", "$", "%", "&" ou "?".
/// - N&atilde;o existe telefone 000000000.
///
class Telefone {
    private:
            string valor;
            void validar(string);
    public:
///
/// Inicializa o objeto com o Telefone como vazio.
///
            Telefone();
///
/// Inicializa o objeto caso o Telefone informado seja v&aacute;lido.
///
/// @param valor string Telefone.
///
            Telefone(string);
///
/// Armazena Telefone.
///
/// @param valor string Telefone.
///
/// @return void
///
            void setValor(string);
///
/// Retorna Telefone.
///
/// @return string Telefone.
///
            string getValor() const;
};

inline string Telefone::getValor() const{         // Metodo inline e const.
    return valor;
}

// -------------------------------------------------------------------------
// Classes da Liz - 180022261

///
/// Padr&atilde;o para representa&ccedil;&atilde;o do Cargo.
///
/// @author Liz Costato - 180022261
///
/// Regras de formato:
///
/// - Cargo &eacute; v&aacute;lido, caso seja igual a um dos seguintes valores: "ator", "cen&oacute;grafo", "figurinista", "maquiador", "sonoplasta" ou "iluminador".
///
class Cargo {
    private:
            string valor;
            void validar(string);
    public:
///
/// Inicializa o objeto com o Cargo como vazio.
///
            Cargo();
///
/// Inicializa o objeto, caso o Cargo informado seja v&aacute;lido.
///
/// @param valor string Cargo.
///
            Cargo(string);
///
/// Armazena um novo valor no objeto.
///
/// @param valor string Cargo.
///
/// @return void
///
            void setValor(string);
///
/// Retorna o valor armazenado no objeto.
///
/// @return string Cargo.
///
            string getValor() const;

};

inline string Cargo::getValor() const{         // Metodo inline e const.
    return valor;
}

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da Matricula.
///
/// @author Liz Costato - 180022261
///
/// Regras de formato:
///
/// - Matricula &eacute; v&aacute;lido, caso:
/// - Tenha formato XXXXX.
/// - Cada X é um dígito (0-9).
/// - Não existam dígitos duplicados.
class Matricula {
    private:
            string valor;
            void validar(string);
///
/// Método auxiliar para a validação da Matricula, verificando se cada caractere da string é digito.
///
/// @param valor string teste.
///
/// @return bool
/// - true: A string só possui dígitos;
/// - false: A string possui caractere que não é digito.
///
            bool eh_digito(string);
///
/// Método auxiliar para a validação da Matricula, verificando se há repetição de dígitos na string.
///
/// @param valor string teste.
///
/// @return bool
/// - true: A string possui digitos repetidos;
/// - false: A string não possui digitos repetidos.
///
            bool ha_repeticao(string);
    public:
///
/// Inicializa o objeto com a Matricula como vazio.
///
            Matricula();
///
/// Inicializa o objeto, caso a Matricula informada seja v&aacute;lida.
///
/// @param valor string Matricula.
///
            Matricula(string);
///
/// Armazena um novo valor no objeto.
///
/// @param valor string Matricula.
///
/// @return void
///
            void setValor(string);
///
/// Retorna o valor armazenado no objeto.
///
/// @return string Matricula.
///
            string getValor() const;

};

inline string Matricula::getValor() const{         // Metodo inline e const.
    return valor;
}

///
/// Padr&atilde;o para representa&ccedil;&atilde;o do Nome.
///
/// @author Liz Costato - 180022261
///
/// Regras de formato:
///
/// - Nome &eacute; v&aacute;lido, caso:
/// - Tenha de 5 a 20 caracteres;
/// - Cada caractere seja letra (A-Z ou a-z), ponto (.) ou espaço em branco;
/// - Não haja espaços em branco e sequência;
/// - A primeira letra de cada termo seja letra maiúscula (A-Z).
class Nome {
    private:
            string valor;
            void validar(string);
///
/// Método auxiliar para a validação do Nome, verificando as regras de formato da classe.
///
/// @param valor string Nome.
///
/// @return int
/// - 0: O nome informado é válido;
/// - 1: O nome informado possui caractere não;
/// - 2: O nome informado possui ponto que não foi precedido por letra;
/// - 3: O nome informado possui espaços em branco em sequência;
/// - 4: O nome informado possui termos não iniciados com letra maiúscula (A-Z).
///
            int caracteres_nome(string);
    public:
///
/// Inicializa o objeto com o Nome como vazio.
///
            Nome();
///
/// Inicializa o objeto, caso o Nome informado seja v&aacute;lido.
///
/// @param valor string Nome.
///
            Nome(string);
///
/// Armazena um novo valor no objeto.
///
/// @param valor string Nome.
///
/// @return void
///
            void setValor(string);
///
/// Retorna o valor armazenado no objeto.
///
/// @return string Nome.
///
            string getValor() const;

};

inline string Nome::getValor() const{         // Metodo inline e const.
    return valor;
}

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da Data.
///
/// @author Liz Costato - 180022261
///
/// Regras de formato:
///
/// - Data &eacute; v&aacute;lido caso:
/// - Tenha formato DD/MM/AAAA;
/// - 01 a 31 em DD;
/// - 01 a 12 em MM;
/// - 2000 a 9999 em AAAA;
/// - A data considera a ocorrência de anos bissextos.
///
class Data {
    private:
            string valor;
            void validar(string);
    public:
///
/// Inicializa o objeto com o valor "01/01/2000".
///
            Data();
///
/// Inicializa o objeto, caso a Data informado seja v&aacute;lida.
///
/// @param valor string Data.
///
            Data(string);
///
/// Armazena um novo valor no objeto.
///
/// @param valor string Data.
///
/// @return void
///
            void setValor(string);
///
/// Retorna o valor armazenado no objeto.
///
/// @return string Data.
///
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
/// @author Clara Fortes - 190017503
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
/// @author Clara Fortes - 190017503
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
/// @author Clara Fortes - 190017503
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
/// @author Clara Fortes - 190017503
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

#endif // DOMINIOS_H_INCLUDED
