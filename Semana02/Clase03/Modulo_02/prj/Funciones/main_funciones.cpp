//===============================================
//Archivo:main_funciones.cpp
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

double funcion_intereses(double);
double funcion_externa(double value);


int main()
{
    double amount=0.0;

    /* Funcion externa con llamado a funciones del sistema.    */
    cout << "Calcular amortización para un monto inicial" << endl;
    cout << "Digitar el monto inicial: ";
    cin >> amount;
    cout << "Amortizacion usuando librería matemática para " << amount << " es: " << funcion_intereses(amount) << endl;

    /* Funcion externa con llamado a funciones locales */
    cout << "Elevación al cuadrado de 20.5 es " << funcion_externa(20.5) << endl;


    return 0;
}
