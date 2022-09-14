//===============================================
// Archivo: habitacional.h
//===============================================
// Curso de Estructuras Abstractas y Algoritmos
// Profesor: Freddy Rojas.
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didáctico.
//===============================================
#ifndef HABITACIONAL_H_INCLUDED
#define HABITACIONAL_H_INCLUDED
#define METROS_PARQUEO 15
typedef struct S_pareja{
  float ancho,largo;
}T_pareja;

typedef struct S_apartamento{
  float ancho,largo;
}T_apartamento;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++
// CLASS PISO
//+++++++++++++++++++++
class _piso{
private:
  _cola<T_apartamento> apartamentos;
  float total_area,total_area_efectiva;
  int   total_apartamentos;
public:
  _piso(void);
  bool inserte_apartamento(float,float);
  void calcular_area(void);
  float area_total(void);
  float area_efectiva(void);
  int   numero_apartamentos(void);
};//________________________________________

////+++++++++++++++++++++
//// CLASS _EDIFICIO
////+++++++++++++++++++++
class _edificio{
private:
  _cola<_piso*> pisos;
  float total_area_construccion,total_area_efectiva_construccion,
        total_area_terreno,total_area_vehiculos;
  int   total_apartamentos;

public:
  _edificio(void);
  bool inserte_piso(T_pareja[],int);
  void calcular_edificio(void);
  float area_total_construccion(void);
  float area_efectiva_construccion(void);
  float area_terreno(void);
};//_______________________________________

////+++++++++++++++++++++
//// CLASS _HABITACIONAL
////+++++++++++++++++++++
class _habitacional{
private:
  _cola<_edificio*> edificios;
  float total_area_construccion,total_area_efectiva_construccion,
        total_area_terreno,total_area_vehiculos;
  int   total_apartamentos;

public:
  _habitacional(void);
  bool inserte_edificio(_edificio*);
  void calcular_habitacional(void);
  float area_total_construccion(void);
  float area_efectiva_construccion(void);
  float area_terreno(void);
};//_______________________________________


#endif // HABITACIONAL_H_INCLUDED
