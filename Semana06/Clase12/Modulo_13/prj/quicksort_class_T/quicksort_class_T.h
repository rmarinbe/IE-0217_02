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
#ifndef QUICKSORT_CLASS_T_H_INCLUDED
#define QUICKSORT_CLASS_T_H_INCLUDED
template <class T>
class quicksort {
 private:
   T    *Vector;
   int   Size;
   void _quicksort(int,int);
 public:
   quicksort(T [],int);
   void sort(void);
};//_______________________________________________________________

//**************************
// class quicksort_class_T
//+++++++++++++++++++++++++
// implementation
//*************************
template <class T> void quicksort<T>::_quicksort(int left, int right)
{
  T element = Vector[left];
  int left_in=left,right_in=right,reference;

  while(left < right)
  {
     while ((Vector[right] >= element) && (left < right)) right--;
     if (left != right)
     {
       Vector[left] = Vector[right];
       Vector[right] = element;
       left++;
     }

     while ((Vector[left] < element) && (left < right)) left++;
     if (left != right)
     {
       Vector[right] = Vector[left];
       Vector[left] = element;
       right--;
     }
  }
  reference =left;
  left=left_in;
  right=right_in;
  if (left  < reference) _quicksort(left,reference-1);
  if (right > reference) _quicksort(reference+1,right);
}//_________________________________________________________


template <class T> void quicksort<T>::sort(void)
{
  _quicksort(0,Size-1);
}//__________________________________________________________

template <class T> quicksort<T>::quicksort(T vector[],int size)
{
  Vector=vector;
  Size=size;
}//___________________________________________________________

#endif // QUICKSORT_CLASS_T_H_INCLUDED
