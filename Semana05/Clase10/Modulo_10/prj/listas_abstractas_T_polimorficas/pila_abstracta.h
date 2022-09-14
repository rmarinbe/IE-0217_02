//===============================================
// Archivo: pila_abstracta.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef PILA_ABSTRACTA_H_INCLUDED
#define PILA_ABSTRACTA_H_INCLUDED

typedef struct S_pila{
   void   *dato;
   S_pila *anterior;
}T_pila;

class _pila_base :public _list{
private:
    T_pila  *Pila;
    T_pila	*Aux;
protected:
   bool inserte(void*);
   bool extraiga(void* p=NULL);
   bool prev(void*  p=NULL);
   bool gotop(void* p=NULL);
public:
   _pila_base(int);
   ~_pila_base(void);
};//____________________________
#endif


