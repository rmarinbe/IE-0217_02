//===============================================
//Archivo: uniones.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
// Archivo de uniones
//=====================
#include <iostream>
using namespace std;
#include "../../utilitarios/utilitarios.h"

typedef struct S_IPLC {
  int  plc_src;
  int  plc_dest;
  char rack_id;
  char size;
  char buffer[2];
}T_IPLC;//__________________________________

typedef struct S_OPLC {
  int  plc_src;
  int  plc_dest;
  char rack_id;
  char size;
  char buffer[2];
}T_OPLC;//__________________________________

typedef struct S_MPLC {
  int  plc_src;
  int  plc_dest;
  char size;
  char buffer[300];
}T_MPLC;//__________________________________

typedef struct S_PLC{
  char msg_id;
  struct {
    T_IPLC  input;
    T_OPLC  output;
    T_MPLC  mark;
  };
}T_PLC;

void estructuras_uniones(void)
{
  T_PLC   escazu;
  typedef enum E_tipo {tipo_I,tipo_O,tipo_M} T_tipo;
  T_tipo  tipo = tipo_I;

  switch( tipo )
  {
    case tipo_I:
      escazu.msg_id=tipo;
      escazu.input.plc_src=0;
      escazu.input.plc_dest=1;
	    escazu.input.rack_id=20;
	    escazu.input.size=1;
    break;

    case tipo_O:
      escazu.msg_id=tipo;
	    escazu.output.plc_src=0;
	    escazu.output.plc_dest=2;
	    escazu.output.rack_id=4;
	    escazu.output.size=0;
    break;

    case tipo_M:
      escazu.msg_id=tipo;
	    escazu.mark.plc_src=0;
	    escazu.mark.plc_dest=2;
	    escazu.mark.size=0;
    break;
  }//switch
  end_function();
}//__________________________________________________

