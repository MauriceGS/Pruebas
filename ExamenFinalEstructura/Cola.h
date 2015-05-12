//
//  Cola.h
//  ExamenFinalEstructura
//
//  Created by Alejandra Garay on 12/2/13.
//  Copyright (c) 2013 Alejandra Garay. All rights reserved.
//

#ifndef __ExamenFinalEstructura__Cola__
#define __ExamenFinalEstructura__Cola__

#include <iostream>
#include "Nodo.h"

template <class N> class Cola;
template <class N> ostream & operator <<(ostream & os, Cola<N> & c);



template <class N>
class Cola {
    
    Nodo<N> * inicio;
    Nodo<N> * fin;
    int tamano;
    
public:
    Cola()
    {
        inicio = fin = NULL;
        tamano = 0;
    }
    
    ~Cola();
    
    void enqueue(Nodo<N> * n);
    
    
    Nodo<N> * dequeue();
    
    Nodo<N> * getInicio();
    
	Nodo<N> * at(int index);
    void clear();
    
    bool find(Nodo<N> * n);
    
    int size();
    bool empty();
    
    friend ostream & operator << <>(ostream & os, Cola<N> & c);
    
};

template <class N>
Cola<N>::~Cola()
{
    clear();
}

template <class N>
void Cola<N>::enqueue(Nodo<N> * n)
{
    if (!empty())
    {
        fin -> setNext(n);
        fin = n;
        
    }
    
    
    else {
        inicio = fin = n;
    }
    
    tamano++;
}

template <class N>
Nodo<N> * Cola<N>::getInicio(){
    return inicio;
    
}

template <class N>
Nodo<N> * Cola<N>::dequeue()
{
    Nodo<N> * temp = NULL;
    
    if (!empty())
    {
        temp = inicio;
        
        inicio = inicio -> getNext();
        
        --tamano;
        
    }
    
    return temp;
}


template <class N>
void Cola<N>::clear()
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
bool Cola<N>::find(Nodo<N> * n)
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
int Cola<N>::size()
{
    return tamano;
}

template <class N>
bool Cola<N>::empty()
{
    return (tamano == 0);
}


template <typename N>
ostream & operator <<(ostream & os, Cola<N> & c)
{
    Nodo<N> * temp = c.inicio;
    
    while (temp != NULL)
    {
        os << *temp << endl;
        temp = temp->getNext();
        }
        
        return os;
        }
        
        template <class N>
        
        Nodo<N> * Cola<N>::at(int index)
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
        


#endif /* defined(__ExamenFinalEstructura__Cola__) */
