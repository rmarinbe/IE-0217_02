//===============================================
//Archivo: main_laberinto.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef LABERINTO_H_INCLUDED
#define LABERINTO_H_INCLUDED

typedef enum tipo_celda {pared,pasillo,entrada,salida,error} T_tipocelda;

typedef struct S_posicion{
  int x,y;
}T_posicion;//____________________________________________________________

class _cell	{
private:
  T_tipocelda e_celda;
  char celda;
public:
  _cell(char);
  operator const T_tipocelda&();
  operator const char&();
};//_______________________________________________________________________


class _laberinto {
private:
  vector< vector<_cell> > malla;
  ///  T_posicion             pos;
  const char             *filename;
  int  max_x,max_y,x_in,y_in;
protected:
  ifstream input;
  bool FindStart(void);
public:
  _laberinto (const char *);
  ~_laberinto();
  bool checkfile(void);
  void ver(void);
  bool resolver(void);
  void ver_solucion(void);
};//_________________________________________________________________________

#endif
