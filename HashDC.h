#ifndef HASHDC_H_INCLUDED
#define HASHDC_H_INCLUDED

#include"ListaSimple.h"

template <typename T>
class HashDC{

    public:
    HashDC(int d = 8);

    ~HashDC();

    HashDC(const HashDC &b);

    HashDC & operator=(const HashDC &th);

    void Agregar(T valor);

    void Eliminar(T valor);

    bool Buscar(T valor)const;

    int ObtenerNumElem()const;

    void Vaciar();

    void Imprimir()const;

    private:

        struct Tabla {

            int cont = 0, ocupados = 0;

            ListaSimple<T>** celdas =  new ListaSimple<T>*[cont];

            // Constructor de Tabla
            Tabla(int c)
            {
                cont = c;
                for (int i = 0; i <= cont; i++)
                celdas[i] = NULL;
            }

            // Destructor de Tabla
            ~Tabla () {
//                for (int i = 0; i < cont; ++i)
//                    if (celdas[i] != NULL){
//                        ListaSimple<T> *temp = celdas[i];
//                        celdas[i] = NULL;
//                        delete temp;
//                    }
                ocupados = 0;
                delete[] celdas;
            }


            double CalcularFactorCarga(){
                double fact;
                fact = double(ocupados)/cont;
                return fact;
            }

            void Agregar(int idx, T val){
                if (celdas[idx]==NULL)
                {
                    celdas[idx] = new ListaSimple<T>;
                    ocupados++;
                }
             celdas[idx]->AgregarUltimo(val);
           }

           void Imprimir()const{
               for (int i=0; i<cont; i++)
                {
                    std::cout<<"Lista "<<i+1<<":"<<std::endl;
                    if (celdas[i]!=NULL) celdas[i]->Imprimir();
                        else std::cout<<"Vacia"<<std::endl;
                }
           }

        };


        int numElem, dim;

        Tabla *hashT;

        int Hash(T val)const;

        void Rehash();

        void CopiarVal(const Tabla *tb);

};

#include "HashDC.tpp"
#endif // HASHDC_H_INCLUDED
