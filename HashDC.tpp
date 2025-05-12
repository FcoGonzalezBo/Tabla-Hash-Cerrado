#include <iostream>
#include <cmath>
using namespace std;

#include "ListaSimple.h"

template <typename T>
HashDC<T>::HashDC(int d): numElem(0), hashT (NULL)
{
    dim = d;
}

template <typename T>
HashDC<T>::~HashDC()
{
    Vaciar();
}

template <typename T>
HashDC<T>::HashDC(const HashDC &th) {
    *this = th;
}

template <typename T>
HashDC<T>& HashDC<T>::operator=(const HashDC &th) {
    if (this == &th) return *this;
    this -> Vaciar();
    CopiarVal(th.hashT);
    return *this;
}

template <typename T>
 int HashDC<T>::Hash(T val)const
 {
    double intpart, fractpart, param;
    param = double(val*0.13);
    fractpart = modf (param, &intpart);
    int res = dim*fractpart;
    return res;
 }

template <typename T>
void HashDC<T>::Agregar(T valor)
 {
     if (hashT==NULL) hashT = new Tabla(dim);
     while (hashT->CalcularFactorCarga()>0.75){
        Rehash();
     }
    int idx = Hash(valor);
    hashT->Agregar(idx,valor);
     numElem++;
 }

 template <typename T>
void HashDC<T>::Rehash()
{
    Tabla *temp = hashT;
    dim = dim*2;
    hashT = new Tabla(dim);
    numElem = 0;
    CopiarVal(temp);
    //delete temp;
}

 template <typename T>
void HashDC<T>::Imprimir()const
{
    if (hashT== NULL)std::cout<<"Tabla vacia"<<endl;
    else hashT->Imprimir();
}

template <typename T>
void HashDC<T>::Vaciar()
{
    Tabla *temp = hashT;
    hashT = NULL;
    numElem = 0;
    delete temp;
}

 template <typename T>
int HashDC<T>::ObtenerNumElem()const
{
    return numElem;
}

 template <typename T>
void HashDC<T>::CopiarVal(const Tabla *tb)
{
    for (int i=0; i<tb->cont; i++)
        {
            if (tb->celdas[i]!=NULL){
                for (int j=(tb->celdas[i]->ContarElem())-1; j>=0; --j){
                    Agregar(tb->celdas[i]->ObtenerEnPos(j));
                }
            }
        }
}
