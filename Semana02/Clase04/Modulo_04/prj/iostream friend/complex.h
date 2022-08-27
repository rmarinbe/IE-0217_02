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
#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

class _complex{
private:
  double real, imaginario;
public:
   _complex(double=0,double=0);
   _complex suma(_complex);
   _complex operator+(_complex);
   _complex operator-(_complex);
   _complex operator*(_complex);
   _complex operator/(_complex);
   friend ostream& operator<<(ostream& ox, _complex a);
};//_________________________________________________________
#endif // COMPLEX_H_INCLUDED
