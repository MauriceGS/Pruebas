//
//  ArbolBinario.h
//  ExamenFinalEstructura
//
//  Created by Alejandra Garay on 12/2/13.
//  Copyright (c) 2013 Alejandra Garay. All rights reserved.
//

#ifndef __ExamenFinalEstructura__ArbolBinario__
#define __ExamenFinalEstructura__ArbolBinario__

#include <iostream>

#include "Nodo.h"
#include <string>
#include <vector>
#include "Cola.h"
#include "Paciente.h"


template <class N>

class ArbolBinario
{
private:
    Nodo<N> * raiz;

public:
    ArbolBinario()
    {
        raiz = NULL;
    }

    ArbolBinario(Nodo<N> * r)
    {
        raiz = r;
    }

    Nodo<N> * getRaiz()
    {
        return raiz;
    }

    void arbolEspejo(Nodo <N> * n);
    void arbolEspejo();

    void Clear();
    void Clear(Nodo<N> * n);

    void Insert(Nodo<N> * n);
    bool InsertAt(N info, Nodo<N> * n);

    Nodo<N> * deleteAt(N info);


    void preOrden();
    void preOrden(Nodo<N> * n);

    int sumatoria();
    int sumatoria(Nodo<N> * n);

    Nodo <N> * sumaArbol();
    void sumaArbol(Nodo<N> * n);

    void inOrden();
    void inOrden(Nodo<N> * n);
    void imprimir();

    Nodo<N> * copiar(Nodo<N> * n);
    ArbolBinario<N> * copiar();

    Nodo <N> * buscar(N info);
    Nodo <N> * buscar(N info, Nodo<N> * n);

    Nodo <N> * buscarHermano(N info);
    Nodo <N> * buscarHermano(N info, Nodo<N> * n);

    bool ancestro(Nodo<N> * n,Nodo<N> * m);

    vector<Nodo <N> *> buscarPrimos(int prof);

    int mostrarHojas();
    int mostrarHojas(Nodo<N> * n);

    int profundidad();
    int profundidad(Nodo<N> * n);

    void posOrden();
    void posOrden(Nodo<N> * n);

    void SADsystem();
    void SADsystem(Nodo<N> * n);


    int size();
    int size(Nodo<N> * n);

    Nodo<N> * buscarLugar();
    Nodo<N> * buscarLugar(Nodo<N> * n);

    void printTree(Nodo<N> *node, string str, string left, string right);

    void arbolReflex(Nodo <N> * n);
    void arbolReflex();

    ~ArbolBinario();

    Cola<Paciente> * pacientesOftalmologo = new Cola<Paciente>();
    Cola<Paciente> * pacientesNeurologo = new Cola<Paciente>();
    Cola<Paciente> * pacientesGastroenterologo = new Cola<Paciente>();
    Cola<Paciente> * pacientesGral = new Cola<Paciente>();



};



template <class N>
int ArbolBinario<N>::size(){

    return size(raiz);
}

template <class N>
int ArbolBinario<N>::profundidad(){

    return profundidad(raiz);
}

template <class N>
int ArbolBinario<N>::profundidad(Nodo<N> * n)
{
    int izq = 0;
    int der = 0;

    if (n!= NULL){

        izq = profundidad(n->getIzq());
        der = profundidad(n->getDer());

        if(izq > der)
            return 1 + izq;
        else
            return 1 + der;



    }
    return 0;
}

template <class N>
int ArbolBinario<N>::mostrarHojas(){
    return mostrarHojas(raiz);
}

template <class N>
int ArbolBinario<N>::mostrarHojas(Nodo<N> * n){
    int cont= 0;

    if (n!= NULL){
        if(n->getIzq()==NULL && n->getDer()== NULL){
            cout<< *n;
            cont++;
        }

        return cont + mostrarHojas(n->getIzq()) + mostrarHojas(n->getDer());
    }
    return cont;
}

template <class N>
void ArbolBinario<N>::SADsystem()
{
    return SADsystem(raiz);
}

template <class N>
void ArbolBinario<N>::SADsystem(Nodo<N> * n)
{


    Nodo<N> * temp;
    string ans;

    cout<< n->getInfo();
    cin>> ans;

    if (ans == "si")
    {
        temp = n->getIzq();
        cout<< temp->getInfo();
        cin >> ans;

        if (ans == "no")
        {
            temp = temp->getDer();
            cout<< temp->getInfo();
            cin >> ans;

            if(ans == "si")
            {
                temp = temp->getIzq();
                cout<< "Visita a: "<< temp->getInfo();

                pacientesNeurologo->enqueue(n);


            }
            else{
                temp = temp->getDer();
                cout<< "Visita a: "<< temp->getInfo();

                pacientesGral->enqueue(n);
            }


        }

        if(ans == "si")
        {
            temp = temp->getIzq();
            cout<< temp->getInfo();
            cin >> ans;

            if(ans == "si"){

                temp = temp->getIzq();
                cout<< "Visita a: "<< temp->getInfo();

                pacientesOftalmologo->enqueue(n);

            }
        }



    }

    else
    {
        temp = n->getDer();
        cout<< temp->getInfo();
        cin >> ans;
        if(ans == "si")
        {
            temp = temp->getIzq();
            cout<< "Visita a: "<< temp->getInfo();

            pacientesGastroenterologo>enqueue(n);


        }
        else{
            temp = temp->getDer();
            cout<< "Visita a: "<< temp->getInfo();

            pacientesGral->enqueue(n);
        }
    }



}


template <class N>
int ArbolBinario<N>::size(Nodo<N> *n){

    int nodos = 0;

    if(n==NULL){
        return 0;
    }
    else{
        return 1+ size(n->getIzq())+ size(n->getDer());
    }

    return nodos;

}

template <class N>
void ArbolBinario<N>::Clear()
{
    Clear(raiz);
    raiz = NULL;
}

template <class N>
void ArbolBinario<N>::Clear(Nodo<N> * n)
{
    if (n!= NULL){
        Clear(n->getIzq());
        Clear(n->getDer());
        delete n;
    }
}

template <class N>
void ArbolBinario<N>::preOrden()
{
    preOrden(raiz);
}

template <class N>
void ArbolBinario<N>::preOrden(Nodo<N> * n)
{
    if (n!= NULL){

        std::cout << *n;

        preOrden(n->getIzq());
        preOrden(n->getDer());

    }
}

template <class N>
void ArbolBinario<N>::inOrden()
{
    inOrden(raiz);
}

template <class N>
void ArbolBinario<N>::inOrden(Nodo<N> * n)
{
    if (n!= NULL){

        inOrden(n->getIzq());

        std::cout << *n;

        inOrden(n->getDer());

    }
}

template <class N>
void ArbolBinario<N>::posOrden()
{
    posOrden(raiz);
}

template <class N>
void ArbolBinario<N>::posOrden(Nodo<N> * n)
{
    if (n!= NULL){

        posOrden(n->getIzq());

        posOrden(n->getDer());

        std::cout << *n;

    }
}

template <class N>
Nodo<N> * ArbolBinario<N>::buscarLugar()
{
    return buscarLugar(raiz);
}

template <class N>
void ArbolBinario<N>::Insert(Nodo<N> * n)
{
    if(raiz == NULL){
        raiz = n;
    }

    else{
        Nodo<N> * padre = buscarLugar();
        n->setPadre(padre);

        if(padre->getIzq() == NULL){
            padre->setIzq(n);
        }
        else
            padre->setDer(n);


    }
}

template <class N>
Nodo <N> * ArbolBinario<N>::buscar(N info)
{
    return buscar(info, raiz);
}

template <class N>
Nodo <N> * ArbolBinario<N>::buscar(N info,  Nodo<N> * n)
{
    Nodo<N> * temp = NULL;

    if(n != NULL){
        if(n->getInfo() == info){
            return n;
        }
        else{

            temp = buscar(info, n->getIzq());
            if(temp == NULL)
            {
                temp = buscar(info, n->getDer());
            }
            return temp;
        }
    }
    return temp;
}

template <class N>
bool ArbolBinario<N>::InsertAt(N info, Nodo<N> * n)
{

    bool insertado = false;
    Nodo<N> * padre = buscar(info);

    if(padre!= NULL)
    {
        if(padre->getIzq()== NULL)
        {
            padre->setIzq(n);
            n->setPadre(padre);
            insertado = true;
        }
        else if (padre->getDer() == NULL){
            padre->setDer(n);
            insertado = true;
        }
    }
    return insertado;
}

template <class N>
Nodo<N> * ArbolBinario<N>::deleteAt(N info)
{
    Nodo<N> * nodo = buscar(info);
    Nodo<N> * temp;

    if (nodo!= NULL){
        if(nodo->getIzq() == NULL && nodo -> getDer() == NULL){

            temp = nodo->getPadre();

            if(temp->getIzq() == nodo){
                temp ->setIzq(NULL);
            }

            else {
                temp -> setDer(NULL);
            }

            nodo->setPadre(NULL);
        }

        else{
            return nodo = NULL;
        }
    }
    return nodo;
}



template <class N>
Nodo<N> * ArbolBinario<N>::buscarLugar(Nodo<N> * n)
{
    if((n->getIzq()==NULL)||(n->getDer()==NULL))
    {
        return n;

    }
    else{
        return buscarLugar(n->getIzq());

    }


}

template <class N>
ArbolBinario<N>::~ArbolBinario(void)
{
    Clear();
}

template <class N>
Nodo <N> * ArbolBinario<N>::buscarHermano(N info)
{
    Nodo<N> * temp = buscar(info);

    return buscarHermano(info, temp);
}

template <class N>
Nodo <N> * ArbolBinario<N>::buscarHermano(N info,  Nodo<N> * n)
{


    if(n != NULL && n->getPadre()!= NULL)
    {


        if(n->getPadre()->getIzq()==n)
        {
            return n->getPadre()->getDer();

        }

        else
        {
            return n->getPadre()->getIzq();

        }

    }

    return NULL;

}



template <class N>
vector<Nodo <N> *> ArbolBinario<N>::buscarPrimos(int prof)
{
    vector <Nodo <N> * > padres;


    padres.enqueue_back(raiz);

    while(prof-- > 0)
    {
        vector <Nodo <N> * > hijos;

        for(int i=0; i<padres.size(); i++)
        {
            if(padres[i]->getDer()!=NULL)
            {
                hijos.enqueue_back(padres[i]->getDer());
            }
            if(padres[i]->getIzq()!=NULL)
            {
                hijos.enqueue_back(padres[i]->getIzq());
            }

        }

        padres = hijos;

    }
    return padres;

}

template <class N>
bool ArbolBinario<N>::ancestro(Nodo<N> * n,Nodo<N> * m)
{

}

template <class N>
int ArbolBinario<N>::sumatoria()
{
    return sumatoria(raiz);

}

template <class N>
int ArbolBinario<N>::sumatoria(Nodo<N> * n)
{
    if (n!= NULL){


        return n->getInfo() + sumatoria (n->getIzq()) + sumatoria(n->getDer());


    }
    return 0;
}

template <class N>
ArbolBinario<N> * ArbolBinario<N>::copiar()
{
    return new ArbolBinario <N> (copiar(raiz));
}


template <class N>
Nodo<N> * ArbolBinario<N>::copiar(Nodo<N> * n){

    if(n!= NULL)
    {
        Nodo<N> * temp = new Nodo<N>(0);

        temp->setInfo(n->getInfo());

        Nodo<N> * izq= copiar(n->getIzq());

        Nodo<N> * der = copiar(n->getDer());


        if(izq!= NULL){
            temp->setIzq(izq);
            izq->setPadre(temp);
        }

        if(der != NULL){
            temp->setDer(der);
            der->setPadre(temp);
        }
        return temp;


    }
    else
        return NULL;


}





template <class N>
Nodo<N> * ArbolBinario<N>::sumaArbol()
{
    sumaArbol(raiz);
}

template <class N>
void ArbolBinario<N>::sumaArbol(Nodo<N> * n)
{
    if (n!= NULL){

        n->setInfo(sumatoria(n));

        sumaArbol(n->getIzq());

        sumaArbol(n->getDer());


    }

}

template <class N>
void ArbolBinario<N>::printTree(Nodo<N> *node, string str, string left, string right)
{

    if (node != NULL)
    {
        printTree(node->getDer(), right + "    ", right + "    |", right + "     ");
        cout << str << "|----" << *node << endl;
        printTree(node->getIzq(), left + "    ", left + "     ", left + "    |");
    }



}

template <class N>
void ArbolBinario <N>::imprimir(){

    printTree(raiz, " ", " ", " ");


}


template <class N>
void ArbolBinario <N>::arbolReflex()
{
    arbolReflex(raiz);
}

template <class N>
void ArbolBinario <N>::arbolReflex(Nodo <N> * n){

    Nodo <N> * temp;
    if(n!=NULL){
        temp = n->getIzq();
        n->setIzq(n->getDer());
        n->setDer(temp);

        arbolReflex(n->getIzq());
        arbolReflex(n->getDer());

    }



}



#endif /* defined(__ExamenFinalEstructura__ArbolBinario__) */
