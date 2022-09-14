//===============================================
// Archivo: lista_polimorfica.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
typedef unsigned char byte;
class _list {
private:
protected:
        const int Size;
        _list(int size);
        virtual ~_list(void);
  bool  virtual inserte(void*)=0;
  bool  virtual extraiga(void*)=0;
  bool  virtual prev(void*)=0;
  bool  virtual gotop(void*)=0;

public:
  _list& operator =(_list &);
};//____________________________

