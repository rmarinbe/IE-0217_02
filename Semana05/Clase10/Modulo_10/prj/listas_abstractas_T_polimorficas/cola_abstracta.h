//===============================================
// Archivo: cola_abstracta.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef COLA_ABSTRACTA_H_INCLUDED
#define COLA_ABSTRACTA_H_INCLUDED
typedef struct S_cola{
   void     *dato;
   S_cola   *anterior;
}T_cola;

class _cola_base :public _list{
private:
    T_cola  *inicio,*final,*index;
    int     contador;
protected:
   bool   inserte(void*);
   bool   extraiga(void *x=NULL);
   bool   prev(void *x=NULL);
   bool   gotop(void *x=NULL);
public:
   _cola_base(int);
   ~_cola_base(void);
   const int longitud_cola(void);
};//____________________________
#endif
