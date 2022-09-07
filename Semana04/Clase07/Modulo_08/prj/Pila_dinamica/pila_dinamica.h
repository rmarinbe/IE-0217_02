//===============================================
//Archivo: pila_dinamica.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED
typedef struct S_pila{
   int  dato;
   S_pila *proximo;
}T_pila;

class _pila{
private:
  T_pila  *array,*index;
  int      contador;
public:
  bool push(int);
  bool pop(int*);
  _pila(void);
  ~_pila(void);
};//____________________________
#endif


