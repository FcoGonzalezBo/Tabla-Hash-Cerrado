#include <iostream>
#include "HashDC.h"
using namespace std;

int main()
{
    try{
        cout<<"Creamos una tabla hash 1 y le agregamos valores..." << endl;
        HashDC<int> h1, h2;

        h1.Agregar(67);
        h1.Agregar(32);
        h1.Agregar(34);
        h1.Agregar(9);
        h1.Agregar(12);
        h1.Agregar(134);
        h1.Agregar(53);
        h1.Agregar(99);
        h1.Agregar(2);
        h1.Agregar(28);
        //h1.Agregar(28);  <- Para demostrar repetición. Vea el metodo Agregar en el HashDC.tpp

        h2 = h1;

        h1.Imprimir();

        cout<<"Numero de elementos: " << h1.ObtenerNumElem()<<endl;
        cout<< "28 esta en el hash?: " << h1.Buscar(28) <<endl;

        cout<<"Eliminamos los elementos 28 y 99 de la tabla hash 1..." << endl;
        h1.Eliminar(28);
        h1.Eliminar(99);

        h1.Imprimir();

        cout<<"Numero de elementos: " << h1.ObtenerNumElem()<<endl;
        cout<< "28 esta en el hash?: " << h1.Buscar(28) <<endl;

        cout<<"Creamos una tabla hash 2 y la igualamos a la tabla hash 1 antes de borrar los valores 28 y 99" << endl;

        h2.Imprimir();

        cout<< "Numero de elementos: " << h2.ObtenerNumElem() << endl;

        cout << "Vaciamos la tabla hash 1..." << endl;

        h1.Vaciar();
        h1.Imprimir();

        cout<<"Numero de elementos: " << h1.ObtenerNumElem() << endl;

    }catch(const char *mensaje){ cerr << "\nError: " << mensaje << endl; }

    system("pause");

    return 0;
}
