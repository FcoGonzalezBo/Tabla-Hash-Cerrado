#include <iostream>


//******************************************************************
template <typename Tipo>
ListaSimple<Tipo>::ListaSimple(): numElem(0), ultimo (NULL), primero(NULL)
{

}
//*****************************************************************
template <typename Tipo>
ListaSimple<Tipo>::~ListaSimple()
{
    Vaciar();
}
//*****************************************************************
template <typename Tipo>
ListaSimple<Tipo>::ListaSimple(const ListaSimple &c):  numElem(0), ultimo (NULL), primero(NULL)
{
   *this = c;
}
//*****************************************************************
template <typename Tipo>
ListaSimple<Tipo> & ListaSimple<Tipo>::operator=(const ListaSimple &c)
{
    if (this == &c) return *this;
    this->Vaciar();
    for (int i=c.numElem-1; i>=0; --i){
        AgregarPrimero(c.ObtenerEnPos(i));
    }
    return *this;
}
//*****************************************************************
template <typename Tipo>
void ListaSimple<Tipo>::AgregarPrimero(Tipo valor)
{
    Elemento* aux = new Elemento(valor, primero);
    if (EstaVacia()) ultimo = aux;
    primero = aux;
    ++numElem;
}
//*****************************************************************
template <typename Tipo>
void ListaSimple<Tipo>::AgregarUltimo(Tipo valor)
{
    Elemento* aux = new Elemento(valor);
    if (EstaVacia()) primero = aux;
    else {
            ultimo->sig = aux;
    }
    ultimo = aux;
    ++numElem;

}
//*****************************************************************
template <typename Tipo>
void ListaSimple<Tipo>::Insertar(Tipo v, int pos)
{
    if (pos < 0 || pos > numElem)throw "Posici\242n fuera de rango";
    if (pos==0)AgregarPrimero(v);
    else if (pos==numElem)AgregarUltimo(v);
    else {
        Elemento *anterior = primero;

        for (int i = 0; i < pos-1; ++i){
            anterior = anterior ->sig;
        }
        Elemento *porInsertar= new Elemento(v,anterior->sig);
        anterior->sig = porInsertar;
    }
    ++numElem;
}
//*****************************************************************
template <typename Tipo>
void ListaSimple<Tipo>::EliminarPrimero()
{
    if(EstaVacia())throw "Lista vac\241a";
    Elemento *temp = primero;
    primero = primero -> sig;
    delete temp;
    --numElem;
    //std::cout << "El Chavo\n"; // < ---------------------------------------------------------------------
}
//*****************************************************************
template <typename Tipo>
void ListaSimple<Tipo>::EliminarUltimo()
{
    if(EstaVacia())throw "Lista vac\241a";
    Elemento *visitado = primero;
    for (int i = 0; i < numElem-2; ++i){
        visitado = visitado -> sig;
    }
    visitado->sig = NULL;
    ultimo = visitado;
    --numElem;
}
//*****************************************************************
template <typename Tipo>
void ListaSimple<Tipo>::EliminarEnPos(int pos)
{
    if (pos < 0 || pos >= numElem) throw "Posici\242n fuera de rango";
    else if (pos == 0) EliminarPrimero();
    else if (pos == numElem-1) EliminarUltimo();
    else {
        Elemento *anterior = primero;
        Elemento *porBorrar = anterior->sig;

        for (int i = 0; i < pos-1; ++i){
            anterior = porBorrar;
            porBorrar = anterior->sig;
        }
        anterior->sig = porBorrar->sig;
        delete porBorrar;
    }
    --numElem;

}
//*****************************************************************
template <typename Tipo>
void ListaSimple<Tipo>::EliminarValor(Tipo v)
{
    int c = ObtenerPosDe(v);
    if (c!=-1) EliminarEnPos(c);
    else throw "Valor no encontrado";
}
//*****************************************************************
template <typename Tipo>
bool ListaSimple<Tipo>::EstaVacia() const
{
    return primero == NULL;  //return numElem == 0;
}
//*****************************************************************
template <typename Tipo>
Tipo ListaSimple<Tipo>::ObtenerPrimero()const
{
    if(EstaVacia())throw "Lista vac\241a";
    return primero->valor;
}
//*****************************************************************
template <typename Tipo>
Tipo ListaSimple<Tipo>::ObtenerUltimo()const
{
    if(EstaVacia())throw "Lista vac\241a";
    return ultimo->valor;
}
//*****************************************************************
template <typename Tipo>
void ListaSimple<Tipo>::Vaciar()
{
    while (numElem >0){
        EliminarPrimero();
    }
}
//*****************************************************************
template <typename Tipo>
int ListaSimple<Tipo>::ContarElem()const
{
    return numElem;
}
//*****************************************************************
template <typename Tipo>
void ListaSimple<Tipo>::Imprimir() const
{
    if(!EstaVacia()){
           Elemento *aux = primero;
    std::cout << "Primero-> ";
   while (aux != NULL){
        std::cout << aux->valor << ", ";
        aux = aux->sig;
    }
    std::cout << "\b\b <-Ultimo\n";
    }else std::cout << "Primero-> <-Ultimo\n";
}
//*****************************************************************
template <typename Tipo>
bool ListaSimple<Tipo>::Buscar (Tipo v) const
{
    return (ObtenerPosDe(v) != -1);
}
//*****************************************************************
template <typename Tipo>
Tipo ListaSimple<Tipo>::ObtenerEnPos(int pos) const
{
    if (pos < 0 || pos >= numElem)throw "Posici\242n fuera de rango";
    Elemento *visitado = primero;
    for (int i = 0; i < pos; ++i){
        visitado = visitado -> sig;
    }
    return visitado -> valor;
}
//*****************************************************************
template <typename Tipo>
int ListaSimple<Tipo>::ObtenerPosDe(Tipo v) const
{
    int pos = 0;
    Elemento *visitado = primero;
    while (visitado != NULL && visitado -> valor != v){
        visitado = visitado -> sig;
        ++pos;
    }

    if (visitado == NULL) return -1;
    else return pos;
}
//Metodos de utileria
