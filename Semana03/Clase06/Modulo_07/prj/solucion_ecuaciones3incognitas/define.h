//===============================================
//Archivo: define.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED
  #define _COMPLEX_ true
  #if (_COMPLEX_==true)
    #define TYPE _complex
  #else
    #define TYPE double
  #endif
#endif
