#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = this->size;
    }

    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* auxNode = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex < len)
    {
        auxNode=this->pFirstNode;
        while(nodeIndex>0)
        {
            auxNode=auxNode->pNextNode;
            nodeIndex--;
        }
    }

    return auxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* prev = NULL;
    Node* nuevoNodo = NULL;

    len = ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= len)
    {
        nuevoNodo = (Node*)malloc(sizeof(Node));
        if(nuevoNodo != NULL)
        {
            nuevoNodo->pElement = pElement;
            nuevoNodo->pNextNode = NULL;
            if(nodeIndex == 0)
            {
                nuevoNodo->pNextNode =  this->pFirstNode;
                this->pFirstNode = nuevoNodo;
            }
            else
            {
                prev = getNode(this, nodeIndex-1);
                nuevoNodo->pNextNode = prev->pNextNode;
                prev->pNextNode = nuevoNodo;
            }
            this->size++;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);

    if(this != NULL)
    {
        addNode(this, len, pElement);
        returnAux = 0;
    }

    return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNodo = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
        auxNodo = getNode(this, index);
        returnAux = auxNodo->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* auxNodo = NULL;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
        auxNodo = getNode(this, index);
        auxNodo->pElement = pElement;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len;
    Node* auxNode = NULL;
    Node* auxNodeAnterior = NULL;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
        if(index == 0)
        {
            auxNode = this->pFirstNode;
            this->pFirstNode = auxNode->pNextNode;
            returnAux = 0;
        }
        else
        {
            if(index > 0 && index < len)
            {
                auxNode = getNode(this, index);
                auxNodeAnterior = getNode(this, index-1);
                auxNodeAnterior->pNextNode = auxNode->pNextNode;
                returnAux = 0;
            }
            else
            {
                auxNodeAnterior = getNode(this, len-1);
                auxNodeAnterior->pNextNode = NULL;
                returnAux = 0;
            }
        }
        free(auxNode);
        this->size--;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len;

    if(this != NULL)
    {
        len = ll_len(this);

        for(i=0; i<len; i++)
        {
            ll_remove(this, i);
            len = ll_len(this);
        }

        len = ll_len(this);

        if(len == 0)
        {
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* pAuxElement;
    int i;
    int len;

    len = ll_len(this);

    if(this != NULL)
    {
        for(i=0; i<len; i++)
        {
            pAuxElement = ll_get(this, i);

            if(pAuxElement == pElement)
            {
                returnAux = i;
            }

            len = ll_len(this);
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(this->size > 0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
        returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
        returnAux = ll_get(this, index);
        ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int verificacion = -1;

    if(this != NULL)
    {
        verificacion = ll_indexOf(this, pElement);
        if(verificacion >= 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int len;
    int verificacion;
    void* pAuxElement = NULL;

    len = ll_len(this);

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(i=0; i<len; i++)
        {
            pAuxElement = ll_get(this2, i);
            if(pAuxElement != NULL)
            {
                verificacion = ll_contains(this, pAuxElement);
                if(verificacion == 0)
                {
                    returnAux = 0;
                }
            }
            ll_len(this);
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pAuxElement;
    int len;

    len = ll_len(this);

    if(this != NULL && from >= 0 && from < to && to > from && to <= len)
    {
        cloneArray = ll_newLinkedList();
        for(i=from; i<to; i++)
        {
            pAuxElement = ll_get(this, i);
            ll_add(cloneArray, pAuxElement);
        }
    }

    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, len);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

/// pFunc: SI EL PRIMERO ES MAYOR RETORNA 1 Y SI EL SEGUNDO ES MAYOR RETORNA -1, SI SON IGUALES RETORNA 0
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pElement1;
    void* pElement2;
    void* aux;
    int verificacion;
    int i;
    int j;
    int len;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        len = ll_len(this);

        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                pElement1 = ll_get(this, i);
                pElement2 = ll_get(this, j);
                verificacion = pFunc(pElement1, pElement2);
                if(verificacion > 0 && order == 1)
                {
                    aux = pElement1;
                    pElement1 = pElement2;
                    pElement2 = aux;

                    ll_set(this, i, pElement1);
                    ll_set(this, j, pElement2);
                }
                else
                {
                    if(verificacion < 0 && order == 0)
                    {
                        aux = pElement2;
                        pElement2 = pElement1;
                        pElement1 = aux;

                        ll_set(this, i, pElement1);
                        ll_set(this, j, pElement2);
                    }
                }
            }
        }
        returnAux=0;
    }

    return returnAux;
}

