//===============================================
//Archivo: main_variables_mixtas.cpp
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
//Hablitar la siguiente línea cambia el main()
#define REITERATIVAS

static int  dato_main=10;
      int dato_publico=20;
extern bool funcion_general(void);
extern void funcion_reiterativa_1(void);
extern void funcion_reiterativa_2(void);

int main()
{
    dato_main++;
#ifndef REITERATIVAS
    cout << "El valor de dato_main es " << dato_main<< endl;
    funcion_general();
#else
    //Función sin memoria
    funcion_reiterativa_1();
    funcion_reiterativa_1();
    funcion_reiterativa_1();

    //Función con memoria
    funcion_reiterativa_2();
    funcion_reiterativa_2();
    funcion_reiterativa_2();
    funcion_reiterativa_2();
#endif
    return 0;
}
