//===============================================
//Archivo: for_each_example.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include <algorithm>
#include <iostream>
using namespace std;

class Sum {
private:
    double total;

public:
    Sum(double d) : total(d)
    {}//________________________________

    operator double()
    {
      return total;
    }

    double operator()(double val)
    {
      total += val;
      return total;
    }

    double getTotal()
    {
      return total;
    }
};//______________________________________________

template <typename T>
void show(T i)
{
  cout << i << " " ;
}//______________________________________________

void for_each_example(void)
{
    double d1[10] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};

    // Create an instance of the function object
    Sum summer(0.0);
    cout << "La iteración sobre summer es: " << for_each(d1, d1 + 10, summer);
    //    for (double* p=d1; p< d1+10; p++) summer(*p);
    //    return summer;
    cout << endl;

    cout << "Sum of range is " << summer.getTotal() << endl;
    getchar();
}//_______________________________________________________________
