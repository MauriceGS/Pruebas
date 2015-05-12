//
//  ListaEnlazada.h
//  ExamenFinalEstructura
//
//  Created by Alejandra Garay on 12/2/13.
//  Copyright (c) 2013 Alejandra Garay. All rights reserved.
//

#ifndef __ExamenFinalEstructura__ListaEnlazada__
#define __ExamenFinalEstructura__ListaEnlazada__

#include <iostream>

#include "Nodo.h"

template <class N> class ListaEnlazada;
template <class N> ostream & operator <<(ostream & os, ListaEnlazada<N> & le);



template <class N>
class ListaEnlazada {
    
    Nodo<N> * inicio;
    int tamano;
    
public:
    ListaEnlazada()
    {
        inicio = NULL;
        tamano = 0;
    }
    
    ~ListaEnlazada();
    
    void insertAt(int index, Nodo<N> * n);
    void insertBack(Nodo<N> * n);
    void insertFront(Nodo<N> * n);
    
    Nodo<N> * deleteAt(int index);
    Nodo<N> * deleteBack();
    Nodo<N> * deleteFront();
	Nodo<N> * at(int index);
    void deleteAll();
    
    bool find(Nodo<N> * n);
    
    int size();
    bool empty();
    
    friend ostream & operator << <>(ostream & os, ListaEnlazada<N> & le);
    
};

template <class N>
ListaEnlazada<N>::~ListaEnlazada()
{
    deleteAll();
}

template <class N>
void ListaEnlazada<N>::insertAt(int index, Nodo<N> * n)
{
    if (!empty())
    {
        if (index == 0)
        {
            n->setNext(inicio);
            inicio = n;
        }
        else {
            int pos = 0;
            Nodo<N> * temp = inicio;
            Nodo<N> * prev = NULL;
            
            while ((pos < index) && (temp != NULL)) {
                ++pos;
                prev = temp;
                temp = temp->getNext();
            }
            
            n->setNext(temp);
            prev->setNext(n);
            
        }
    }
    else {
        inicio = n;
    }
    
    tamano++;
}

template <class N>
void ListaEnlazada<N>::insertBack(Nodo<N> * n)
{
    insertAt(tamano, n);
    
}

template <class N>
void ListaEnlazada<N>::insertFront(Nodo<N> * n)
{
    insertAt(0, n);
}

template <class N>
Nodo<N> * ListaEnlazada<N>::deleteAt(int index)
{
    Nodo<N> * temp = NULL;
    
    if (!empty())
    {
        temp = inicio;
        
        if (index == 0) {
            inicio = inicio->getNext();
        }
        else {
            int pos = 0;
            Nodo<N> * prev = NULL;
            
            while ((pos < index) && (temp->getNext() != NULL)) {
                ++pos;
                prev = temp;
                temp = temp->getNext();
            }
            
            prev->setNext(temp->getNext());
        }
        
        --tamano;
        
    }
    
    return temp;
}

template <class N>
Nodo<N> * ListaEnlazada<N>::deleteBack()
{
    return deleteAt(tamano);
}

template <class N>
Nodo<N> * ListaEnlazada<N>::deleteFront()
{
    return deleteAt(0);
}

template <class N>
void ListaEnlazada<N>::deleteAll()
{
    if (!empty())
    {
        Nodo<N> * temp = inicio;
        
        while (temp != NULL) {
            inicio = temp->getNext();
            delete temp;
            temp = inicio;
            
        }
    }
}


template <class N>
bool ListaEnlazada<N>::find(Nodo<N> * n)
{
    bool encontrado = false;
    Nodo<N> * temp = inicio;
    
    while (!encontrado && (temp != NULL) ) {
        if (temp->getInfo() == n->getInfo())
        {
            encontrado = true;
        }
        
        temp = temp->getNext();
    }
    
    return encontrado;
}

template <class N>
int ListaEnlazada<N>::size()
{
    return tamano;
}

template <class N>
bool ListaEnlazada<N>::empty()
{
    return (tamano == 0);
}


template <typename N>
ostream & operator <<(ostream & os, ListaEnlazada<N> & le)
{
    Nodo<N> * temp = le.inicio;
    
    while (temp != NULL)
    {
        os << *temp << endl;
        temp = temp->getNext();
        }
        
        return os;
        }
        
        template <class N>
        Nodo<N> * ListaEnlazada<N>::at(int index)
        {
            Nodo<N> * temp = NULL;
            
            if (!empty())
            {
                temp = inicio;
                
                if (index == 0) {
                    return inicio;
                }
                else {
                    int pos = 0;
                    Nodo<N> * prev = NULL;
                    
                    while ((pos < index) && (temp->getNext() != NULL)) {
                        ++pos;
                        prev = temp;
                        temp = temp->getNext();
                    }
                }
                
            }
            
            return temp;
        }


#endif /* defined(__ExamenFinalEstructura__ListaEnlazada__) */
