//===============================================
//Archivo: main_laberinto.h
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

class _cell	: public T_posicion{
private:
  T_tipocelda e_celda;
  char celda;
  bool visited;
public:
  bool path;
  _cell(char,int x=0,int y=0);
  operator const T_tipocelda&();
  operator const char&();
  operator bool&();
};//_______________________________________________________________________

class _laberinto {
private:
  stack<T_posicion> stk;
  vector< vector<_cell> > malla;
  const char *filename;
  int         max_x,max_y,x_in,y_in;
  T_posicion  current;

protected:
  ifstream input;
  bool FindStart(void);
  bool left(void);
  bool up(void);
  bool right(void);
  bool down(void);

public:
  _laberinto (const char *);
  ~_laberinto();
  bool checkfile(void);
  void ver(void);
  bool resolver(void);
  void ver_solucion(void);
  void ver_coordenadas_solucion(void);
};//_________________________________________________________________________

#endif
