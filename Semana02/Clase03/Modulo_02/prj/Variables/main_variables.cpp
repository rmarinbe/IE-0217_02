//===============================================
//Archivo:main_variables.cpp
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include <iostream>

using namespace std;

bool valor    = false;
int  integer1 = 10,  integer2  = 20;
int sum;      /* declaración sin valor inicial*/
float floatante_numero1;
double big_float;
char   a='A';
int main()
{
  bool verdad= false;
  bool funcion_externa(void);
  cout << "Evaluación de variables:" << endl;
  sum =39;

  valor = true;
  verdad = valor;
  {  //Declaración implícita de función en C++
    int sum=10;
    cout << "La variable sum oculta la variable sum global. sum local es "
         << sum << "la externa es " << ::sum << endl;
  }
  cout << "La variable sum local desaparecio ahora sum= "<< sum << endl;
  cout << "Un boolean imprime en cout "<< valor << endl;
  cout << "La función interna da "<< funcion_externa() << endl;
return 0;
}
