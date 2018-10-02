#ifndef MACRO_H
#define MACRO_H

#include "Fila.h"
#include <string>

using namespace std;
class Macro{
 
private:
   
    std::string nome;
    Fila<std::string> macros;

    
public:  
    
  Macro(); 
 ~Macro();    
  void criaMacro(std::string pDado);
  void setNome(std::string pNome);
  std::string getMacro();
  std::string getNome();
  Fila<std::string> getFmacro();
  
    
};
#endif /* MACRO_H */

