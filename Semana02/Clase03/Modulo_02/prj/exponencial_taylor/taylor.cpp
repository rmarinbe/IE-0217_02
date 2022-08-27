//===============================================
//Archivo:tailor.cpp
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
//Solución de series de taylor para exponencial real
//+++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <math.h>
//#define DEBUG
using namespace std;

int main()
{
  double x,             //Valor a calcular
         errorFinal,    //Error final
         error,         //Error transitorio
         factorial,     //Factorial calculado en cada ciclo acumulativamente.
         resultado,     //Resultado de la serie.
         resultado_ant, //Resultado para cálculo de error.
         producto;      //x^n
  int    k=1;           //Número de ciclo

  cout << "Cálculo de Serie de Taylor " << endl;
  cout << "==========================="<< endl;
  cout << "Error? " << endl;
  cin >> errorFinal;

  while(true)
  {
    cout << "Valor de x: ";
    cin >> x;
    if (x== -1.0) break;    //Cpondición de salida del algoritmo (ejemplo)
                            //=============================================
    factorial=1,
    resultado=1.0,
    resultado_ant=0,
    producto=1.0;
    k=1;          // sumatoria k=1;k<=oo (error)

    do {
      #ifdef DEBUG
      cout << "Producto =" << producto <<" Resultado = " << resultado;
      cout << " Ciclo = " << k << " factorial= " << factorial << endl;
      cout << "Press any key to continue..." << endl;
      getchar();
      #endif


      /*Algoritmo de la serie de Taylor
      ==========================================================
        e(x) = 1 +x + x^2/2! +x^3/3!+x^4/4!+ ...
        El primer elemento 1 se precarga antes de la serie (do)
      ===========================================================*/
      producto*=x;
      factorial*=k++;
      resultado+=producto/factorial;
      error=fabs(resultado - resultado_ant);
      resultado_ant=resultado;
    }while(fabs(error) > errorFinal);
    cout << "Resultado el exponcial de :" << x << " es: " << resultado << endl;
  }
  return 0;
}//__________________________________________________-
