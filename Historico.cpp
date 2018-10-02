#include <iostream>
#include <string>
#include "shell.h"
#include <string>
#include "Historico.h"
#include <sstream>
#include "Fila.h"

Historico::Historico() : hst(30) {
}

Historico::~Historico() {
}

void Historico::imprimiHist() {
    Pilha<string> p(30);
    int n = 1;
    while (!hst.vazia()) {
        p.push(hst.pop());
    }
    while (!p.vazia()) {
        cout << n << " - " << p.pop() << endl;
        n++;
    }
}

void Historico::addHist(string dado) {
    hst.push(dado);
}

string Historico::enesimo(string frase) {
    Pilha<string> aux(30);
    aux = separador(frase, '!');
    Pilha<string> aux_inteiro(30);
    int pass_to_int;
    string oi;

    aux_inteiro = hst;
    string teste = aux.top();
    istringstream inp(teste);
    inp >> pass_to_int;

    int i = 0;
    while (!aux_inteiro.vazia()) {
        if (i == pass_to_int) {
            oi = aux_inteiro.pop();
            cout << "oi é" << oi << endl;
            break;
        } else {
            aux_inteiro.pop();

        }
        i++;
    }
    return oi;
}

Pilha<string> Historico::separador(string str, char delimiter) {
    Pilha<string> internal(30);
    stringstream ss(str);
    string tok;

    while (getline(ss, tok, delimiter)) {
        internal.push(tok);
    }
    return internal;
}