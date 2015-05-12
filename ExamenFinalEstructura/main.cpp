//
//  main.cpp
//  ExamenFinalEstructura
//
//  Created by Alejandra Garay on 12/2/13.
//  Copyright (c) 2013 Alejandra Garay. All rights reserved.
//

#include <iostream>
#include "ArbolBinario.h"
#include "Medico.h"
#include "Paciente.h"
#include <string>
#include "ListaEnlazada.h"
#include "Pila.h"
#include "Cola.h"
#include <vector>


using namespace std;




int main(int argc, const char * argv[])
{

    
    ArbolBinario<string> * SAD = new ArbolBinario<string>();
    
    Nodo<string> * p1 = new Nodo<string>("te duele la cabeza");
    SAD->Insert(p1);
    
    Nodo<string> * p01 = new Nodo<string>("Te duelen los ojos");
    Nodo<string> * p2 = new Nodo<string>("Te duele el estomago");
    SAD->InsertAt("te duele la cabeza", p01);
    SAD->InsertAt("te duele la cabeza", p2);
    
    Nodo<string> * p001 = new Nodo<string>("Te sientes mareado");
    Nodo<string> * p002 = new Nodo<string>("Te sientes cansado");
    SAD->InsertAt("Te duelen los ojos", p001);
    SAD->InsertAt("Te duelen los ojos", p002);
   
    Nodo<string> * p0001 = new Nodo<string>("Oftalmologo");
    SAD->InsertAt("Te sientes mareado", p0001);
    
    Nodo<string> * p0002 = new Nodo<string>("Neurologo");
    Nodo<string> * p00021 = new Nodo<string>("Gral");
    SAD->InsertAt("Te sientes cansado", p0002);
    SAD->InsertAt("Te sientes cansado", p00021);
    
    Nodo<string> * p20 = new Nodo<string>("Gastroenterologo");
    Nodo<string> * p21 = new Nodo<string>("Gral");
    SAD->InsertAt("te duele el estomago", p20);
     SAD->InsertAt("te duele el estomago", p21);
    
    Medico * m1 = new Medico("Alejandra", "Garay", "oftalmologo");
    Medico * m2 = new Medico("German", "Ruiz", "neurologo");
    Medico * m3 = new Medico("Norberto", "Perez", "gral");
    Medico * m4 = new Medico("Luisa", "Garcia", "gastroenterologo");
    
     ListaEnlazada<Medico> * cuerpoGuardia = new ListaEnlazada<Medico>();
    
    cuerpoGuardia->insertBack(m1);
    cuerpoGuardia->insertBack(m2);
    cuerpoGuardia->insertBack(m3);
    cuerpoGuardia->insertBack(m4);
   
    
    Paciente * pa1 = new Paciente("Juan", "Perez", 18, "4544526");
     SAD->SADsystem();
    
    Paciente * pa2 = new Paciente("Juana", "estevez", 8, "4237806");
     SAD->SADsystem();
    
    Paciente * pa3 = new Paciente("Martin", "garmendia", 10, "679726");
     SAD->SADsystem();
    
    Paciente * pa4 = new Paciente("Maria", "Roque", 21, "8765236");
     SAD->SADsystem(); //metodo en arbol binario.h
    
    cout<<endl<< "Para reporte de medicos y pacientes escribe 1, para reporte de # pacientes escribe 2, 3 para reporte por paciente"<<endl;
    int tf;
    cin>> tf;
    
    if(tf==1)
    {
    
    cout<< "el reporte: "<<endl;
    cout<<"el cuerpo de guardia es: "<< cuerpoGuardia->size();
    cout << "los medicos son: ";
    for(int i = 0; cuerpoGuardia->size()>0; i++)
    {
        cout << cuerpoGuardia->at(i);
         cout<< "sus pacientes son: ";
        if(cuerpoGuardia->at(i)->getEspecialidad()=="oftalmologo")
        {
           for(int i = 0; pacientesOftalmologo->size()>0; i++)
           {
               cout<< pacientesOftalmologo->dequeue();
           }
        }
        
        if(cuerpoGuardia->at(i)->getEspecialidad()=="neurologo")
        {
            for(int i = 0; pacientesNeurologo->size()>0; i++)
            {
                cout<< pacientesNeurologo->dequeue();
            }
        }
        
        if(cuerpoGuardia->at(i)->getEspecialidad()=="gral")
        {
            for(int i = 0; pacientesGral->size()>0; i++)
            {
                cout<< pacientesGral->dequeue();
            }
        }
        
        if(cuerpoGuardia->at(i)->getEspecialidad()=="gastroenterologo")
        {
            for(int i = 0; pacientesGral->size()>0; i++)
            {
                cout<< pacientesGral->dequeue();
            }
        }
        
    }
    
   
    
    }
    else if (tf==2){
        cout<< "Reporte de numero de Pacientes por especialidad: ";
        
        cout << "Oftalmologia: " << pacientesOftalmologo->size();
        
        cout << "Neurologia: " << pacientesNeurologo->size();
        
        cout << "Gastroenterologia: " << pacientesGastroenterologo->size();
        
        cout << "Gral: " << pacientesGral->size();
        
    }
    
    else{
        
        cout << "Los pacientes ordenados ascendentemente por edad: "
        
        vector <Paciente> pacientes;
        
        
        for(int i = 0; pacientesGral->size()>0; i++)
        {
            pacientesGral->dequeue();
        }
        
        
    }
       
    

    
}



