#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

/**
 *Clase contenedora tipo Lista Enlazada Simple
 *\tparam Tipo Tipo de dato almacenado en la lista
 */
template <typename Tipo>
class ListaSimple{
public:
    /** \brief Constructor por default. Define una lista vac&iacute;a
     *
     *
    */
    ListaSimple();

    /** \brief Destructor de la clase
     *
    */
    ~ListaSimple();

    /** \brief Constructor de copias
     *
     * \param p un objeto de tipo Cola
     *
    */
    ListaSimple(const ListaSimple &c);

    /** \brief Operador "=" copia los elementos de una lista en otra
     *
     * \param p un objeto de tipo Cola
     *
    */
    ListaSimple & operator=(const ListaSimple &c);

    /** \brief Agrega un nuevo elemento al inicio de la lista
     *
     * \param valor Nuevo valor a agregar
     *
     */
    void AgregarPrimero(Tipo valor);

     /** \brief Agrega un nuevo elemento al final de la lista
     *
     * \param valor Nuevo valor a agregar
     *
     */
    void AgregarUltimo(Tipo valor);

     /** \brief Agrega un nuevo elemento a la lista en una posici&oacuten dada
     *
     * \param valor Nuevo valor a agregar
     * \param pos Posici&oacuten en la lista donde insertar valor
     *
     */
    void Insertar(Tipo valor, int pos);


    /** \brief Elimina el primer elemento de la lista
     *
     *
     */
    void EliminarPrimero();

     /** \brief Elimina el &uacuteltimo elemento de la lista
     *
     *
     */
    void EliminarUltimo();


     /** \brief Elimina el elemento en la posici&oacuten dada
     *
     * \param pos Posici&oacuten en la lista del valor a eliminar
     *
     */
    void EliminarEnPos(int pos);

     /** \brief Elimina el primer elemento que posea el valor correspondiente
     *
     * \param v Valor del elemento a eliminar
     *
     */
    void EliminarValor(Tipo v);


    /** \brief Indica si la lista est&aacute; vac&iacute;a
     *
     * \return  true Cuando la lista est&aacute; vac&iacute;a y false en caso contrario
     *
     */
     bool EstaVacia() const;

     /** \brief Obtiene el primer valor de la lista
      *
      * \return El primer valor
      *
      */
    Tipo ObtenerPrimero() const;

       /** \brief Obtiene el &uacuteltimo valor de la lista
      *
      * \return El &uacuteltimo valor
      *
      */
    Tipo ObtenerUltimo() const;

    /** \brief Vac&iacute;a la lista
     *
     *
     */
     void Vaciar();

    /** \brief Obtiene la cantidad actual de elementos en la lista
     *
     * \return La cantidad de elementos
     */
     int ContarElem() const;

    //para pruebas
    /** \brief Imprimir la lista
     *
     *
     */
     void Imprimir() const;

     /** \brief Verifica si un valor dado est&aacute presente en la lista
      *
      * \param v Valor que se desea buscar en la lista
      * \return Verdadero si el valor se encuentra en la lista, falso en caso contrario
      *
      */
      bool Buscar (Tipo v) const;

     /** \brief Dada una posici&oacuten en la lista, regresa el valor correspondiente
      *
      * \param pos Posici&oacuten del valor solicitado
      * \return El valor en la posici&oacuten dada
      *
      */
      Tipo ObtenerEnPos(int pos) const;

      /** \brief Busca un valor en la lista y da su posici&oacuten
       *
       * \param v Valor que se busca en la lista
       * \return La posici&oacuten del valor, -1 si no se enuentra en la lista
       *
       */
      int ObtenerPosDe(Tipo v) const;



private:

    int numElem;
    struct Elemento{
        Tipo valor;
        Elemento * sig;
        Elemento (Tipo v, Elemento *siguiente = NULL){
            this -> valor = v;
            this -> sig = siguiente;
        }
    } *ultimo, *primero;
};
#include "ListaSimple.tpp"

#endif // LISTASIMPLE_H_INCLUDED
