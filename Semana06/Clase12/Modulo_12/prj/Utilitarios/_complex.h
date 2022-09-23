//===============================================
//Archivo: complex.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef COMPLEX_H_DEFINED
#define COMPLEX_H_DEFINED

#define REAL 0
#define IMAGINARIO 1
class _complex{
private:
  double real, imaginario;

public:
   _complex(double=0,double=0);
   _complex suma(_complex);
   void set(double,double);
   _complex operator+(_complex);
   _complex operator-(_complex);
   _complex operator*(_complex);
   _complex operator/(_complex);
   _complex operator/=(_complex);
   _complex operator*=(_complex);
   _complex operator+=(_complex);
   _complex operator-();
   bool operator==(_complex);
   bool operator!=(_complex);
   double &operator[](int);
   friend ostream& operator<<(ostream& cout, _complex a);
};//_________________________________________________________
#endif
