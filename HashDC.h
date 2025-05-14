#ifndef HASHDC_H_INCLUDED
#define HASHDC_H_INCLUDED

#include"ListaSimple.h"

template <typename T>
class HashDC{

    public:

    // METODOS DE CONSTRUCTOR -----------------------------------------------------------------------------------

    /** \brief Constructor
     * \param d Dimension del arreglo de la tabla Hash
     */
    HashDC(int d = 8);

    /** \brief Destructor
     */
    ~HashDC();

    /** \brief Constructor de copias
     * \param b Tabla Hash por referencia
     */
    HashDC(const HashDC &b);

    /** \brief Operador =
     * \param b Tabla Hash por referencia
     */

    HashDC & operator=(const HashDC &th);

    // METODOS PUBLICOS -----------------------------------------------------------------------------------

    /** \brief Agrega un valor a la tabla Hash
     * \param valor Valor a agregar a la Tabla Hash
     */
    void Agregar(T valor); //-

    /** \brief Elimina un valor de la tabla Hash
     * \param valor Valor a eliminar a la Tabla Hash
     */
    void Eliminar(T valor); //-

    /** \brief Revisa si el valor dado existe en la Tabla Hash
     * \param valor Valor a buscar en la Tabla Hash
     * \return true Si se encuentra | false En caso contrario
     */
    bool Buscar(T valor)const; //-

    /** \brief Retorna el numero de valores dentro de la Tabla Hash
     * \return Numero de valores
     */
    int ObtenerNumElem()const; //-

    /** \brief Vacia la Tabla Hash por completo
     */
    void Vaciar(); //-

    /** \brief Imprime la Tabla Hash
     */
    void Imprimir()const; //-

    private:

        struct Tabla {

            // Numero de contenedores       // Numero de contenedores ocupados
            int cont = 0,                   ocupados = 0;

            // Arreglo de punteros a Listas Simples
            ListaSimple<T>** celdas = NULL;


            // Constructor de Tabla
            Tabla(int c)
            {
                cont = c; // Se define el numero de contenedores que va a tener la tabla
                celdas = new ListaSimple<T>*[cont]; // Crea el arreglo de listas simples

                for (int i = 0; i < cont; i++) // Inicializa las celdas a punteros nulos
                    celdas[i] = NULL;
            }


            // Destructor de Tabla
            ~Tabla () {
                for (int i = 0; i < cont; ++i) // Por cada celda que existe en la Tabla Hash
                    if (celdas[i] != NULL){ // Las listas que no sean nulas, las borra y las apunta a null
                        delete celdas[i];
                        celdas[i] = NULL;
                    }

                ocupados = 0;       // La cantidad de contenedores ocupados los devolvemos a 0
                cont = 0;           // La cantidad de contenedores lo devolvemos a 0
                delete[] celdas;    // Borramos el arreglo de Listas simples
                celdas = NULL;      //y lo apuntamos a null
            }

            // Calcula el Factor de carga (Porcentaje de las celdas ocupadas / no vacias)
            double CalcularFactorCarga(){
                double fact;    // Definimos un double
                fact = double(ocupados)/cont;   // Calculamos el porcentaje
                return fact;                    //y lo regresamos
            }

            // Agregar un valor dentro del contenedor en el indice dado
            void Agregar(int idx, T val){
                if (celdas[idx]==NULL)  // Si la celda esta vacia
                {
                    celdas[idx] = new ListaSimple<T>;   // Creamos una nueva lista dentro de ella
                    ocupados++;                         // y le sumamos +1 a la cantidad de contedores ocupados
                }

             celdas[idx]-> AgregarUltimo(val);  // Se agrega el valor
           }

            // Elimina un valor dentro del contenedor en el indice dado
            void Eliminar(int idx, T val){
                if (celdas[idx] != NULL){                // Si el contenedor no esta vacio
                    celdas[idx] -> EliminarValor(val);  // Elimina el valor de la lista (usando metodo de la lista simple)
                }
                else                                                        // Si no
                    std::cout << "El valor no se encuentra en la celda!\n"; // Notifica que la lista no contiene el valor, porque no existe

                if (celdas[idx] -> EstaVacia()){    // Si la lista dentro del contenedor queda vacia
                    ocupados--;                     // le restamos -1 a la cantidad de contenedores ocupados
                    delete celdas[idx];             // Borra la lista vacia en el contenedor
                    celdas[idx] = NULL;             // y lo apunta a nulo.
                }
            }

            // Busca un valor dado dentro del contenedor en el indice dado
            bool Buscar(int idx, T valor){
                if (celdas[idx] != NULL)                    // Si el contenedor no esta vacio
                    return celdas[idx] -> Buscar(valor);    // Buscamos el valor dentro de la lista (usando el metodo de la lista simple)

                else return false;                          // Si el contenedor SI esta vacio, retorna falso (no esta el valor)
            }


            // Imprime todas las listas de la tabla
            void Imprimir()const{

                for (int i=0; i<cont; i++)  // Recorre cada contenedor
                {
                    std::cout<<"Lista "<<i+1<<":"<<std::endl;   // Imprime el indice del contenedor
                    if (celdas[i]!=NULL) celdas[i]->Imprimir(); // Si no esta vacia imprime la lista
                        else std::cout<<"Vacia"<<std::endl;     // Si lo esta, avisa que si esta vacia
                }
            }
        };

        // Numero total de elementos    // Dimension de la Tabla Hash
        int numElem,                    dim;

        // Puntero al objeto Tabla Hash de la instancia
        Tabla *hashT;

        // METODOS DE PRIVADOS -----------------------------------------------------------------------------------

        /** \brief Calcula un índice dado el valor
         * \param val Valor con el cual calcular el indice
         * \return Indice
         */
        int Hash(T val)const;

        /** \brief Redimensiona la Tabla Hashm, cuando supera un cierto factor de carga
         */
        void Rehash();

        /** \brief Copia todos los valores de una Tabla Hash a otra
         * \param tb Puntero de la tabla de donde vas a copiar los elementos
         */
        void CopiarVal(const Tabla *tb);

};

#include "HashDC.tpp"
#endif // HASHDC_H_INCLUDED
