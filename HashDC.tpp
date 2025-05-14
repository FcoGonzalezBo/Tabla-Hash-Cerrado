#include <iostream>
#include <cmath>
using namespace std;

#include "ListaSimple.h"

// METODOS DE CONSTRUCTOR --------------------------------------------------------------------------------------

// Constructor
template <typename T>
HashDC<T>::HashDC(int d /* = 8 */): numElem(0), hashT (NULL) // La instancia se inicializa con 0 numero de elementos y con puntero de la Tabla Hash a nulo
{
    dim = d; // Dimension de la Tabla Hash
}

// Destructor
template <typename T>
HashDC<T>::~HashDC()
{
    Vaciar(); // El destructor solamente vacia completamente la tabla utilizando el metodo de Vaciar (vease abajo). Lo devuelve a nulo
}

// Constructor de copias
template <typename T>
HashDC<T>::HashDC(const HashDC &th) {
    *this = th;
}

template <typename T>
HashDC<T>& HashDC<T>::operator=(const HashDC &th) {
    if (this == &th) return *this;  // Si la tabla con la que se esta comparando es igual, se queda igual
    this -> Vaciar();       // Vaciamos la tabla
    dim = th.dim;           // Se hereda la dimension de la tabla a copiar
    CopiarVal(th.hashT);    // Se copian los valores de la otra tabla con el metodo privado CopiarVal (vease abajo)
    return *this;           // Retorna el resutado de todo el procedimiento previo
}

// METODOS PUBLICOS  --------------------------------------------------------------------------------------

// Agrega un valor dado
template <typename T>
void HashDC<T>::Agregar(T valor)
 {
     if (Buscar(valor)){ // ESTE IF DECIDE SI LA TABLA NO ACEPTA VALORES REPETIDOS
        std::cout << "El valor ya esta en la tabla!\n";  // COMENTE SI DESEA VALORES REPETIDOS
        return;
     }

     if (hashT==NULL) hashT = new Tabla(dim);   // Si no existe niguna Tabla Hash, se crea la tabla con la dimension de la instancia

     while (hashT -> CalcularFactorCarga() > 0.75) // Mientras a el factor de carga sea mayor al 75%
            Rehash();                              // Redimensiona la Tabla Hash

    int idx = Hash(valor);          // El indice del contenedor a insertar el valor que agregara se calcula con el metodo Privado Hash (vease abajo)
    hashT -> Agregar(idx,valor);    // Agregamos el valor dado al contenedor con el indice indicado usando el metodo Agregar del Struct Tabla
    numElem++;                      // Le sumamos +1 al numero de elementos de la Tabla Hash
 }

// Elimina un valor dado
template <typename T>
void HashDC<T>::Eliminar(T valor){
    if (hashT == NULL) {                                // Si no hay Tabla Hash
        std::cout << "No hay nada que eliminar!\n";     // Notificamos
        return;                                         // y nos salimos del metodo
    }

    int idx = Hash(valor);           // Calculamos el indice del contenedor en donde se eliminara el valor con el metodo Privado Hash (vease abajo)
    hashT -> Eliminar(idx, valor);   // Eliminamos el valor dado del contenedor con el indice indicado usando el metodo Eliminar del Struct Tabla
    numElem--;                       // Le restamos -1 al numero de elementos de la Tabla Hash
}


// Busca un valor dado
template <typename T>
bool HashDC<T>::Buscar(T valor) const {
    if (hashT == NULL) return false; // Si no hay Tabla Hash, decimos que el valor no esta y retornamos false

    int idx = Hash(valor);          // Calculamos el indice del contenedor en donde se econtraria el valor con el metodo Privado Hash (vease abajo)

    return hashT -> Buscar(idx, valor); // Llamamos el metodo Buscar del Struct Tabla y devolvemos su resultado
 }

// Obtiene el numero de elementos de la Tabla Hash
template <typename T>
int HashDC<T>::ObtenerNumElem() const
{
    return numElem; // Retorna el numero de elementos del objeto
}

// Vacia la tabla
template <typename T>
void HashDC<T>::Vaciar()
{
    Tabla *temp = hashT;    // Creamos un puntero temporal a la Tabla Hash
    hashT = NULL;           // Decimos que la tabla Hash es NULL
    numElem = 0;            // El numero de elemntos lo ponemos a 0
    delete temp;            // y borramos la Tabla vieja referenciada en el puntero temp
}

// Imprime la Tabla Hash
template <typename T>
void HashDC<T>::Imprimir()const
{
    if (hashT == NULL)  std::cout << "Tabla vacia" << endl; // Si no hay Tabla Hash, notificamos
    else hashT -> Imprimir();                               // Si lo hay, Imprimimos, usando el metodo del Struct Tabla
}

// METODOS PRIVADOS  --------------------------------------------------------------------------------------

// Calcula el indice del contenedor del arreglo en donde se va a trabajar, dependiendo del valor recibido
template <typename T>
int HashDC<T>::Hash(T val) const
{
    // Parte entera         // Parte fraccionaria       // Parametro
    double intpart,         fractpart,                  param;

    param = double(val * 0.13);               // Calculamos el parametro: ValorRecibido * Constante
    fractpart = modf (param, &intpart);       // Calculamos la parte fraccionaria usando el metodo modf del C++, el cual separa el parametro entre la parte entera y la fraccionaria

    int res = dim * fractpart;                // El resultado es la dimension del arreglo y la parte fraccionaria, creando un numero entero entre 0 y dim (dimension),
    return res;                               // y lo devolvemos
}

// Redimensiona la Tabla Hash
template <typename T>
void HashDC<T>::Rehash()
{
    Tabla *temp = hashT;    // Guardamos la Tabla Hash existente en un puntero temporal
    dim = dim * 2;          // Duplicamos la dimension
    hashT = new Tabla(dim); // Creamos una Tabla Hash nueva con la nueva dimension
    numElem = 0;            // Igualamos el numero de elementos a 0
    CopiarVal(temp);        // Copiamos todos los valores de la Tabla Hash antigua a la nueva (reordenando los valores con la nueva dimension y el valor del Hash)
    delete temp;            // y borramos la tabla vieja, liberando la memoria
}

// Copiamos los valores de una tabla dada a la tabla actual
template <typename T>
void HashDC<T>::CopiarVal(const Tabla *tb)
{
    for (int i = 0; i < tb -> cont; i++)    // Recorremos las celdas del arreglo
        {
            if (tb -> celdas[i] != NULL){                       // Si no estan vacias

            int num = (tb -> celdas[i] -> ContarElem());        // Conseguimos la cantidad de elementos de la lista simple, usando el metodo de le lista simple

            for (int j = 0; j < num; ++j){                      // Recorremos cada elemento de la lista simple
                Agregar(tb -> celdas[i] -> ObtenerEnPos(j));    // y lo llamamos a agregar
            }
        }
    }
}

