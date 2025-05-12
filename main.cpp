#include <iostream>
#include "HashDC.h"
using namespace std;

int main()
{
    try{
    HashDC<int> h1;

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

    cout<<"Numero de elementos: "<<h1.ObtenerNumElem()<<endl;

    h1.Imprimir();


        }catch(const char *mensaje){
        cerr << "\nError: " << mensaje << endl;
    }

    system("pause");

    return 0;
}
