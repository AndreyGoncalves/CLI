#include "pilha.h"
#include <string>
#include"InterfaceUsuario.h"

#ifndef HISTORICO_H
#define HISTORICO_H

class Historico {
private:

    Pilha<string> hst;

public:

    Historico();
    ~Historico();
    bool enesimo1;
    void imprimiHist();
    void addHist(string dado);
    string enesimo(string frase);
    Pilha<string> separador(string str, char delimiter);
};
#endif /* HISTORICO_H */

