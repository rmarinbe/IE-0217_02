#include <iostream>
#include "polimorfismo_general.h"
using namespace std;

void enviar_mensaje( polimorfismo_general &referencia)
{
  cout << "El mensaje del objeto referenciado es: " << endl;
  referencia.mensaje();
}//___________________________________________________

//+++++++++
// Main()
//+++++++++

int main()
{
  polimorfismo_general padre;
  herencia1 hijo1;
  herencia2 hijo2;
  herencia3 hijo3;

  enviar_mensaje(padre);
  enviar_mensaje(hijo1);
  enviar_mensaje(hijo2);
  enviar_mensaje(hijo3);
  return 0;
}
