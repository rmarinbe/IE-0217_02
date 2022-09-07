//===============================================
//Archivo: pila_vector_dinamico.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef PILA_VECTOR_DINAMICO_H_INCLUDED
#define PILA_VECTOR_DINAMICO_H_INCLUDED
class _pila{
private:
   int *Pila;
   short int Puntero;
   const short int Maxsize;
public:
    _pila(int);
    _pila(_pila&);
   ~_pila(void);
   bool push(int);
   int pop(void);
};//_______________________________________________________
#endif
