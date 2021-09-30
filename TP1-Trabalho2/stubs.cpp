#include "stubs.h"

//----------------------------------------------------------------------------
// Implementação de método de classe stub.

bool StubISAutenticacao::autenticar(const Matricula &matricula, const Senha &senha){

    // Apresentar dados recebidos.

    cout << endl << "StubISAutenticacao::autenticar" << endl ;

    cout << "Matricula = " << matricula.getValor() << endl ;
    cout << "Senha     = " << senha.getValor()     << endl ;

    bool resultado = true;

    // Diferentes comportamentos dependendo do valor da matrícula.

    switch(matricula.getValor()){
        case TRIGGER_FALHA:
            resultado = false;
            break;
        case TRIGGER_ERRO_SISTEMA:
            throw runtime_error("Erro de sistema");
        }

    return resultado;
}

//----------------------------------------------------------------------------
// Implementações de métodos de classe stub.

bool StubISGerente::incluir(const Gerente &gerente){

    // Apresentar dados recebidos.

    cout << endl << "StubISGerente::incluir" << endl ;

    bool resultado = true;

    // Diferentes comportamentos dependendo do valor da matrícula.

    switch(gerente.getMatricula().getValor()){
        case TRIGGER_FALHA:
            resultado = false;
            break;
        case TRIGGER_ERRO_SISTEMA:
            throw runtime_error("Erro de sistema");
        }

    return resultado;
}

bool StubISGerente::remover(const Matricula &matricula) {

    // Apresentar dados recebidos.

    cout << endl << "StubISGerente::remover" << endl ;

    bool resultado = true;

    // Diferentes comportamentos dependendo do valor da matrícula.

    switch(matricula.getValor()){
        case TRIGGER_FALHA:
            resultado = false;
            break;
        case TRIGGER_ERRO_SISTEMA:
            throw runtime_error("Erro de sistema");
        }

    return resultado;
}

bool StubISGerente::pesquisar(Gerente &gerente) {

    // Apresentar dados recebidos.

    cout << endl << "StubISGerente::pesquisar" << endl ;

    bool resultado = true;

    // A seguir devem ser implementados os diferentes comportamentos.

    // Sucesso.

    // Falha.

    // Erro de sistema.

    return resultado;
}

bool StubISGerente::editar(const Gerente &gerente) {

    // Apresentar dados recebidos.

    cout << endl << "StubISGerente::editar" << endl ;

    bool resultado = true;

    // A seguir devem ser implementados os diferentes comportamentos.

    // Sucesso.

    // Falha.

    // Erro de sistema.

    return resultado;
}
