#include "Macro.h"
#include "Fila.h"
#include "iostream"
#include "InterfaceUsuario.h"

using namespace std;

Macro::Macro() : macros(10) {

}

Macro::~Macro() {

}

void Macro::criaMacro(std::string pDado) {
    macros.enfileira(pDado);
}

Fila<std::string> Macro::getFmacro() {
    return macros;
}

std::string Macro::getMacro() {
    std::string retorna;
    retorna = macros.desenfileira();
    return retorna;
}

std::string Macro::getNome() {

    return nome;
}

void Macro::setNome(std::string pNome) {
    nome = pNome;
}
