//===============================================
//Archivo: quicksort_class.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef QUICKSORT_CLASS_H_INCLUDED
#define QUICKSORT_CLASS_H_INCLUDED
class quicksort {
 private:
   int  *Vector;
   int   Size;
   void _quicksort(int,int);
 public:
   quicksort(int[],int);
   void sort(void);
};//_______________________________________________________________
#endif // QUICKSORT_CLASS_H_INCLUDED
