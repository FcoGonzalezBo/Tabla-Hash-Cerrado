#ifndef HASHDC_H_INCLUDED
#define HASHDC_H_INCLUDED

#include"ListaSimple.h"

template <typename T, int dim = 5>
class HashDC{

    public:
    HashDC();

    ~HashDC();

    HashDC(const HashDC &b);

    HashDC & operator=(const HashDC &b);

    void Agregar(T valor);

    void Eliminar(T valor);

    bool Buscar(T valor)const;

    int ObtenerNumElem()const;

    void Vaciar();

    void Imprimir()const;

    private:

        struct Tabla {

            int cont, ocupados;

            ListaSimple<T>** celdas =  new ListaSimple<T>*[cont];

            // Constructor de Tabla
            Tabla(int c) :cont(dim)
            {
                cont = c;
                for (int i = 0; i <= cont; i++)
                celdas[i] = NULL;
            }

            // Destructor de Tabla
            ~Tabla () {
                for (int i = 0; i <= cont; ++i)
                    if (celdas[i] != nullptr) delete celdas[i];

                delete[] celdas;
            }


            float CalcularFactorCarga(){
                float fact;
                fact = ocupados/cont;
                return fact;
            }
        };


        int elementos;

        Tabla *hashT;

        int Hash(T val)const;

        void Rehash();

};

#include "HashDC.tpp"
#endif // HASHDC_H_INCLUDED
