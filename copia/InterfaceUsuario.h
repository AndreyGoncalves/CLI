#ifndef INTERFACEUSUARIO_H
#define INTERFACEUSUARIO_H

#include <string>
#include <iostream>
#include "shell.h"
#include "Fila.h"
#include "pilha.h"
#include "Historico.h"
#include "Macro.h"

using namespace std;
 
class InterfaceUsuario {
    

    
 private:
  Shell cmd; // o executor de comandos
  string prompt; // o prompt a ser mostrado na linha que espera comando
  Historico obj;
  Fila<Macro> fMacro;
  Fila<string> Fila_Macro;
  
  
 public:
  InterfaceUsuario(string umPrompt);
  ~InterfaceUsuario(); // destrutor
  int tamanho;
  // aguarda um comando, executa-o e retorna o status de terminação
  int leUmComando();
  void addMacro(Macro dado);
  bool getterMacro1(string dado);
  Fila<string> getterMacro(string dado);
    
  // lê e executa comandos indefinidamente ...
  void serve_comandos();
  
  
  
};



#endif	// INTERFACEUSUARIO_H

