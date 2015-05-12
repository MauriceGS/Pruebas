//
//  Ordenamiento.h
//  ExamenFinalEstructura
//
//  Created by Alejandra Garay on 12/2/13.
//  Copyright (c) 2013 Alejandra Garay. All rights reserved.
//

#ifndef __ExamenFinalEstructura__Ordenamiento__
#define __ExamenFinalEstructura__Ordenamiento__

#include <iostream>

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

using namespace std;

class Ordenamiento{
    
public:
    
    // de enteros
    void imprime(int[],int);
    void ordenamientoBurbuja(int[],int);
    void selectionSort(int[],int);
    void insertionSort(int[],int);
    void quicksort (int[],int,int);
    void mergesort (int[],int,int);
    void merge (int[],int,int,int);
    void ordenamientoBurbujaD(int[],int);
    void selectionSortD(int[],int);
    void insertionSortD(int[],int);
    void quicksortD(int[],int,int);
    void mergesortD(int[],int,int);
    void mergeD(int[],int,int,int);
    // de floats
    
    void imprime(float[],int);
    void ordenamientoBurbuja(float[],int);
    void selectionSort(float[],int);
    void insertionSort(float[],int);
    void quicksort (float[],int,int);
    void mergesort (float[],int,int);
    void merge (float[],int,int,int);
    void ordenamientoBurbujaD(float[],int);
    void selectionSortD(float[],int);
    void insertionSortD(float[],int);
    void quicksortD(float[],int,int);
    void mergesortD(float[],int,int);
    void mergeD(float[],int,int,int);
    
    void imprimeChar(int[],int);
    void ordenamientoBurbujaChar();
    void ordenamientoBurbujaDChar();
    
    int menu();
    int menu2();
    
};


int menu()
{
    int n;
    cout << "Ingresa opcion de arreglo que quieres: ";
    cin >> n;
    if(n>=1&&n<=5)
        return n;
    else
    {
        cout << "No existe esa opcion." << endl;
        return menu();
    }
}

int menu2()
{
    int n;
    cout << "Ingresa opcion de datos que quieres ordenar ";
    cin >> n;
    if(n>=1&&n<=3)
        return n;
    else
    {
        cout << "No existe esa opcion." << endl;
        return menu();
    }
}





///////////////////////////////// Argumentos tipo INT//////////////////////////////////////////////

void imprime(int v[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << v[i] << ", ";
    cout << endl;
}

void ordenamientoBurbuja(int v[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            if (v[j-1] > v[j])
            {
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            }
        }
    }
}

void insertionSort(int numbers[], int n)
{
    int i, j, index;
    for (i=1; i < n; i++)
    {
        index = numbers[i];
        j = i-1;
        while (j >= 0 && numbers[j] > index) {
            numbers[j + 1] = numbers[j];
            j--; }
        numbers[j+1] = index;
    }
}

void selectionSort(int x[], int n)
{
    int minimo = 0;
    for(int i = 0; i < n-1; i++)
    {
        minimo = i;
        for(int j = i + 1; j < n; j++)
        {
            if (x[minimo] > x[j])
                minimo = j;
        }
        int temp = x[minimo];
        x[minimo] = x[i];
        x[i] = temp;
    }
}

void quicksort (int a[], int primero, int ultimo)
{
    int izquierdo = primero;
    int derecho = ultimo;
    int temp;
    
    
    //Se selecciona pivote
    int pivote = a[primero];
    
    
    if ( primero < ultimo) // Paso base
    {
        // particion
        while ( izquierdo < derecho)
        {
            while ( (izquierdo < derecho) && (a[izquierdo] <= pivote )) izquierdo++;
            while ( a[derecho] > pivote ) derecho--;
            if ( izquierdo < derecho) // se intercambian los contenidos
            {
                temp = a[derecho];
                a[derecho] = a[izquierdo];
                a[izquierdo] = temp;
            }
        }
        // Se intercambia el pivote con el elemento de la posición derecha
        temp = a[derecho];
        a[derecho] = a[primero];
        a[primero] = temp;
        // Paso recursivo
        quicksort ( a, primero, derecho-1);
        quicksort ( a, izquierdo, ultimo);
    }
}
void merge (int v[], int l, int m, int n)
{
    int i, j, k;
    int aux[N];
    
    for (i=m+1; i>l; i--) 		// Vector auxiliar
        aux[i-1] = v[i-1];
    for (j=m; j<n; j++)
        aux[n+m-j] = v[j+1];
    for (k=l; k<=n; k++) 		// Mezcla
        if (aux[i]<aux[j])
            v[k] = aux[i++];
        else
            v[k] = aux[j--];
}

void mergesort (int v[], int l, int n)
{
    int m = (n+l)/2;
    if (n > l)
    {
        mergesort (v, l, m);
        mergesort (v, m+1, n);
        merge (v, l, m, n);
    }
}


//Descendiente
void ordenamientoBurbujaD(int v[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (v[j-1] < v[j])
            {
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            }
        }
    }
}


void insertionSortD(int numbers[], int n)
{
    int i, j, index;
    for (i=1; i < n; i++)
    {
        index = numbers[i];
        j = i-1;
        while (j >= 0 && numbers[j] < index) {
            numbers[j + 1] = numbers[j];
            j--; }
        numbers[j+1] = index;
    }
}

void selectionSortD(int x[], int n)
{
    int minimo = 0;
    for(int i = 0; i < n-1; i++)
    {
        minimo = i;
        for(int j = i + 1; j < n; j++)
        {
            if (x[minimo] < x[j])
                minimo = j;
        }
        int temp = x[minimo];
        x[minimo] = x[i];
        x[i] = temp;
    }
}


void quicksortD(int a[], int primero, int ultimo)
{
    int izquierdo = primero;
    int derecho = ultimo;
    int temp;
    //Se selecciona pivote
    int pivote = a[primero];
    
    if ( primero < ultimo) // Paso base
    {
        // particion
        while ( izquierdo < derecho)
        {
            while ( (izquierdo < derecho) && (a[izquierdo] >= pivote )) izquierdo++;
            while ( a[derecho] < pivote ) derecho--;
            if ( izquierdo < derecho) // se intercambian los contenidos
            {
                temp = a[derecho];
                a[derecho] = a[izquierdo];
                a[izquierdo] = temp;
            }
        }
        // Se intercambia el pivote con el elemento de la posición derecha
        temp = a[derecho];
        a[derecho] = a[primero];
        a[primero] = temp;
        // Paso recursivo
        quicksortD(a,primero,derecho-1);
        quicksortD(a,izquierdo,ultimo);
    }
}
void mergeD(int v[], int l, int m, int n)
{
    int i, j, k;
    int aux[N];
    
    for (i=m+1; i>l; i--) 		// Vector auxiliar
        aux[i-1] = v[i-1];
    for (j=m; j<n; j++)
        aux[n+m-j] = v[j+1];
    for (k=l; k<=n; k++) 		// Mezcla
        if (aux[i]>aux[j])
            v[k] = aux[i++];
        else
            v[k] = aux[j--];
}
void mergesortD(int v[], int l, int n)
{
    int m = (n+l)/2;
    if (n > l)
    {
        mergesortD(v, l, m);
        mergesortD(v, m+1, n);
        mergeD(v, l, m, n);
    }
}












///////////////////////////////////////// Argumentos tipo FLOAT /////////////////////////////////

void imprime(float v[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << v[i] << ", ";
    cout << endl;
}

void ordenamientoBurbuja(float v[], int n)
{
    float temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            if (v[j-1] > v[j])
            {
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            }
        }
    }
}

void insertionSort(float numbers[], int n)
{
    int i, j;
    float index;
    
    for (i=1; i < n; i++)
    {
        index = numbers[i];
        j = i-1;
        while (j >= 0 && numbers[j] > index) {
            numbers[j + 1] = numbers[j];
            j--; }
        numbers[j+1] = index;
    }
}

void selectionSort(float x[], int n)
{
    int minimo = 0;
    for(int i = 0; i < n-1; i++)
    {
        minimo = i;
        for(int j = i + 1; j < n; j++)
        {
            if (x[minimo] > x[j])
                minimo = j;
        }
        float temp = x[minimo];
        x[minimo] = x[i];
        x[i] = temp;
    }
}

void quicksort (float a[], int primero, int ultimo)
{
    int izquierdo = primero;
    int derecho = ultimo;
    float temp;
    
    
    //Se selecciona pivote
    float pivote = a[primero];
    
    
    if ( primero < ultimo) // Paso base
    {
        // particion
        while ( izquierdo < derecho)
        {
            while ( (izquierdo < derecho) && (a[izquierdo] <= pivote )) izquierdo++;
            while ( a[derecho] > pivote ) derecho--;
            if ( izquierdo < derecho) // se intercambian los contenidos
            {
                temp = a[derecho];
                a[derecho] = a[izquierdo];
                a[izquierdo] = temp;
            }
        }
        // Se intercambia el pivote con el elemento de la posición derecha
        temp = a[derecho];
        a[derecho] = a[primero];
        a[primero] = temp;
        // Paso recursivo
        quicksort ( a, primero, derecho-1);
        quicksort ( a, izquierdo, ultimo);
    }
}
void merge (float v[], int l, int m, int n)
{
    int i, j, k;
    float aux[N];
    
    for (i=m+1; i>l; i--) 		// Vector auxiliar
        aux[i-1] = v[i-1];
    for (j=m; j<n; j++)
        aux[n+m-j] = v[j+1];
    for (k=l; k<=n; k++) 		// Mezcla
        if (aux[i]<aux[j])
            v[k] = aux[i++];
        else
            v[k] = aux[j--];
}

void mergesort (float v[], int l, int n)
{
    int m = (n+l)/2;
    if (n > l)
    {
        mergesort (v, l, m);
        mergesort (v, m+1, n);
        merge (v, l, m, n);
    }
}


//Descendente
void ordenamientoBurbujaD(float v[], int n)
{
    float temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (v[j-1] < v[j])
            {
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            }
        }
    }
}


void insertionSortD(float numbers[], int n)
{
    int i, j;
    float index;
    for (i=1; i < n; i++)
    {
        index = numbers[i];
        j = i-1;
        while (j >= 0 && numbers[j] < index) {
            numbers[j + 1] = numbers[j];
            j--; }
        numbers[j+1] = index;
    }
}

void selectionSortD(float x[], int n)
{
    int minimo = 0;
    for(int i = 0; i < n-1; i++)
    {
        minimo = i;
        for(int j = i + 1; j < n; j++)
        {
            if (x[minimo] < x[j])
                minimo = j;
        }
        float temp = x[minimo];
        x[minimo] = x[i];
        x[i] = temp;
    }
}


void quicksortD(float a[], int primero, int ultimo)
{
    int izquierdo = primero;
    int derecho = ultimo;
    float temp;
    //Se selecciona pivote
    float pivote = a[primero];
    
    if ( primero < ultimo) // Paso base
    {
        // particion
        while ( izquierdo < derecho)
        {
            while ( (izquierdo < derecho) && (a[izquierdo] >= pivote )) izquierdo++;
            while ( a[derecho] < pivote ) derecho--;
            if ( izquierdo < derecho) // se intercambian los contenidos
            {
                temp = a[derecho];
                a[derecho] = a[izquierdo];
                a[izquierdo] = temp;
            }
        }
        // Se intercambia el pivote con el elemento de la posición derecha
        temp = a[derecho];
        a[derecho] = a[primero];
        a[primero] = temp;
        // Paso recursivo
        quicksortD(a,primero,derecho-1);
        quicksortD(a,izquierdo,ultimo);
    }
}
void mergeD(float v[], int l, int m, int n)
{
    int i, j, k;
    float aux[N];
    
    for (i=m+1; i>l; i--) 		// Vector auxiliar
        aux[i-1] = v[i-1];
    for (j=m; j<n; j++)
        aux[n+m-j] = v[j+1];
    for (k=l; k<=n; k++) 		// Mezcla
        if (aux[i]>aux[j])
            v[k] = aux[i++];
        else
            v[k] = aux[j--];
}
void mergesortD(float v[], int l, int n)
{
    int m = (n+l)/2;
    if (n > l)
    {
        mergesortD(v, l, m);
        mergesortD(v, m+1, n);
        mergeD(v, l, m, n);
    }
}
/////////////////////////CARACTERES////////////////////////////////////////////

void imprimeChar(int v[], int n)
{
    char strrnd[n];
    
    for (int i = 0; i < n; ++i){
        strrnd[i]=v[i];
        
        cout << strrnd[i]<<endl;
        
    }
}

void ordenamientoBurbujaChar()
{
    
    
    for(int j=0; j < 8; j++){
        
        char strrnd[8];
        int ascii[8];
        
        for(int i=0; i < 8; i++){
            
            int nuevo = 65 + rand() % (91 - 65);
            
            strrnd[i] = nuevo;
            
            ascii[i]=nuevo;
            
            cout<<strrnd[i]<<","<<endl;
        }
        
        ordenamientoBurbuja(ascii,N);
        imprimeChar(ascii, N);
        cout<<endl;
    }
}

void ordenamientoBurbujaDChar() //strcmp(s1,s2)  s.strcmp(s2)
{
    char strrnd[9];
    int ascii[9];
    
    for(int j=0; j < 8; j++){
        
        for(int i=0; i < 8; i++){
            
            int nuevo = 65 + rand() % (91 - 65);
            
            strrnd[i] = nuevo;
            
            ascii[i]=nuevo;
            
        }
        
        ordenamientoBurbujaD(ascii,N);
        imprimeChar(ascii, N);
        cout<<endl;
    }
}




#endif /* defined(__ExamenFinalEstructura__Ordenamiento__) */
