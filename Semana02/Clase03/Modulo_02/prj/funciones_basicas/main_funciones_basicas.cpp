//===============================================
//Archivo: main_funciones_basicas.cpp
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
int maximo(int,int,int);

int main()
{
    /* Funcion en este mismo archivo*/
    int a,b,c;
    a=20;
    b=30;
    c=50;
    int d=maximo(a,b,c);
    cout << "El máximo de a="<< a <<" y b="<< b  << "es d =" << d << " en tanto c= "<< c << endl;
    return 0;
}

//Formato y contenido de los valores pasados a una funcion
int maximo(int a,int b, int result)
{
  int max = a;

   if (b > max)
      max = b;
   a=b=0;
   result=max;
   return max;
}
