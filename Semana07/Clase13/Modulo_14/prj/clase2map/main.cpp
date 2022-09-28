#include <iostream>
#include <map>
#include <string>

using namespace std;

/// Forma 1
///++++++++++
class Persona{
private:
    long int Cedula;
    string Nombre;
    float  Salario;

public:
    Persona(long int a,string b,float c):Cedula(a),Nombre(b),Salario(c)
    {}

    long int gCedula() const
    {
        return Cedula;
    }

    string gNombre() const
    {
        return Nombre;
    }

    float gSalario() const
    {
        return Salario;
    }

    bool operator <( const Persona &otra) const
    {
       return Cedula < otra.Cedula;
    }
};//_______________________________________________________________________________________

/// Forma 2
///++++++++++
class Persona1{
private:
    long int Cedula;
    string Nombre;
    float  Salario;

public:
    Persona1(long int a,string b,float c):Cedula(a),Nombre(b),Salario(c)
    {}

    long int gCedula() const
    {
        return Cedula;
    }

    string gNombre() const
    {
        return Nombre;
    }

    float gSalario() const
    {
        return Salario;
    }

    friend class lessthan;
};

class lessthan{
public:
    bool operator()(const Persona1 &antes, const Persona1 &nueva)
    {
           return antes.Cedula < nueva.Cedula;
    }
};//_________________________________________________________________________


///++++++++++
/// MAIN()
///++++++++++
int main()
{
    /// Forma 1
    ///++++++++++
    map<Persona,int> EstudianteUCR;
    Persona B1( 10200200, "Juan", 100300.0),
            B2( 10500200, "Carlos", 400300.0);

    EstudianteUCR[B1]=100;
    EstudianteUCR[B2]=50;

    map<Persona,int>::iterator inicio=EstudianteUCR.begin(), fin=EstudianteUCR.end();
    int i=1;
    while(inicio !=fin)
    {
      cout << "Campo "<< i << " Cedula: " << (*inicio).first.gCedula() << " Nombre: "  << (*inicio).first.gNombre() << " Salario: " << (*inicio).first.gSalario()  <<
      " Parte entera: " << (*inicio).second << endl;
      i++;
      inicio++;
    }

    /// Forma 2
    ///++++++++++
    map<Persona1,int,lessthan> EstudianteUCR1;
    Persona1 B3( 10200200, "Juan", 100300.0),
             B4( 10500200, "Carlos", 400300.0);

    EstudianteUCR1[B3]=100;
    EstudianteUCR1[B4]=50;

    map<Persona1,int>::iterator inicio1=EstudianteUCR1.begin(), fin1=EstudianteUCR1.end();
    int j=1;
    while(inicio1 !=fin1)
    {
      cout << "Campo "<< j << " Cedula: " << (*inicio1).first.gCedula() << " Nombre: "  << (*inicio1).first.gNombre() << " Salario: " << (*inicio1).first.gSalario()  <<
      " Parte entera: " << (*inicio1).second << endl;
      j++;
      inicio1++;
    }
    return 0;
}
