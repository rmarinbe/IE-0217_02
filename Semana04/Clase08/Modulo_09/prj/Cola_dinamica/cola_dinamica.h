//===============================================
// Archivo: cola_dinamica.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED
typedef struct S_cola{
   int       dato;
   S_cola   *proximo;
}T_cola;

class _cola {
private:
    T_cola  *inicio,*final,*index;
    int     contador;
public:
        _cola(void);
        ~_cola(void);
   bool inserte(int);
   bool extraiga(int *x=NULL);
   int  longitud_cola(void);
   bool prev(int  *x=NULL);
   bool gotop(int *x=NULL);
};//____________________________
#endif
