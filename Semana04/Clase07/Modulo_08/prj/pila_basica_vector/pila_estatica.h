//===============================================
//Archivo: pila_estatica.h
//===============================================
// Curso de programacion en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED
#define MAXSTACKSIZE 1024
class _pila{
private:
   int Pila[MAXSTACKSIZE];
   short int Puntero;
public:
    _pila(void);
   ~_pila(void);
   bool push(int);
   int pop(void);
};//_______________________________________________________
#endif
