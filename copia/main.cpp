#include <iostream>
#include "InterfaceUsuario.h"
#include "Macro.h"
#include "Historico.h"
#include "Fila.h"
#include "pilha.h"
#include "shell.h"


using namespace std;

InterfaceUsuario::InterfaceUsuario(string umPrompt) : fMacro(10), Fila_Macro(10) {
    prompt = umPrompt;
    tamanho = 0;
} // construtor

InterfaceUsuario::~InterfaceUsuario() {
} // destrutor

// aguarda um comando, executa-o e retorna o status de terminação

int InterfaceUsuario::leUmComando() {

    string comando;
    cout << prompt;
    getline(cin, comando);
    obj.addHist(comando);
    //obHist.addHist(comando);
    if (getterMacro1(comando)) {

        Fila_Macro = getterMacro(comando);
        while (!Fila_Macro.vazia()) {
            string smacro = Fila_Macro.desenfileira();
            int r = cmd.execute(smacro);
            return 0;

        }
    }

  /*  if (comando[0] == '!') {
        comando = obj.enesimo(comando);
        return 0;

    }*/
    if (comando == "historico") {
        obj.imprimiHist();
        return 0;

    }
    if (comando == "sair") return 10;
    int r = cmd.execute(comando);
    return r;
}

bool InterfaceUsuario::getterMacro1(string dado) {
    Fila<Macro> aux(10);
    aux = fMacro;
    Macro algo;

    while (!aux.vazia()) {
        algo = aux.desenfileira();
        string getname = algo.getNome();
        if (getname == dado) {
            return true;
        }
    }
    return false;
}

Fila<string> InterfaceUsuario::getterMacro(string dado) {

    Fila<Macro> aux(10);
    aux = fMacro;
    Macro algo;

    while (!aux.vazia()) {
        algo = aux.desenfileira();
        string stringname = algo.getNome();
        if (stringname == dado) {
            break;
        }
    }
    return algo.getFmacro();

}

void InterfaceUsuario::addMacro(Macro dado) {
    fMacro.enfileira(dado);
    tamanho++;
}

int main() {
    InterfaceUsuario interface("comando>");
    Pilha<string> hst(1000);

    Macro m1;
    m1.setNome("m1");
    m1.criaMacro("ls -l");
    m1.criaMacro("pwd");
    m1.criaMacro("ps ax");
    m1.criaMacro("eject");
    interface.addMacro(m1);

    Macro m2;
    m2.setNome("m2");
    m2.criaMacro("ls");
    m2.criaMacro("date");
    m2.criaMacro("eject");
    interface.addMacro(m2);

    Macro m3;
    m3.setNome("m3");
    m3.criaMacro("ls");
    m3.criaMacro("pwd");
    m3.criaMacro("date");
    interface.addMacro(m3);

    Macro m4;
    m4.setNome("m4");
    m4.criaMacro("ls");
    m4.criaMacro("eject");
    interface.addMacro(m4);

    Macro m5;
    m5.setNome("m5");
    m5.criaMacro("ls");
    m5.criaMacro("uname -a");
    m5.criaMacro("eject");
    interface.addMacro(m5);

    Macro m6;
    m6.setNome("m6");
    m6.criaMacro("eject");
    m6.criaMacro("sudo apt-get update");
    m6.criaMacro("ls");
    interface.addMacro(m6);

    Macro m7;
    m7.setNome("m7");
    m7.criaMacro("pwd");
    m7.criaMacro("eject");
    interface.addMacro(m7);

    Macro m8;
    m8.setNome("m8");
    m8.criaMacro("pwd");
    m8.criaMacro("eject");
    interface.addMacro(m8);

    Macro m9;
    m9.setNome("m9");
    m9.criaMacro("pwd");
    m9.criaMacro("eject");
    interface.addMacro(m9);

    while (true) {

        int status = interface.leUmComando();
        cout << "Executou com status: " << status << endl;
        if (status == 10) break;
    }
    return 0;
}