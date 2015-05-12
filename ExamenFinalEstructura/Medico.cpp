//
//  Medico.cpp
//  ExamenFinalEstructura
//
//  Created by Alejandra Garay on 12/2/13.
//  Copyright (c) 2013 Alejandra Garay. All rights reserved.
//

#include "Medico.h"

Medico::Medico()
{
    Medico("Sin definir", "Sin definir", "Sin definir");
}

Medico::Medico(string n, string a, string es)
{
    nombre = n;
    apellidos = a;
    especialidad = es;
    
}

string Medico::getNombre()
{
    return nombre;
}

string Medico::getApellidos()
{
    return apellidos;
}

string Medico::getEspecialidad()
{
    return especialidad;
}

void Medico::setNombre(string name)
{
    nombre = name;
}

void Medico::setApellidos(string apell)
{
    apellidos = apell;
}

void Medico::setEspecialidad(string espe)
{
    especialidad = espe;
}




std::ostream & operator <<(std::ostream & os, Medico & m)
{
    os << m.nombre << " ";
    os << m.apellidos << "  "<<endl;
    os <<" Especialidad: "<< " : "<< m.especialidad<<endl;
    
    return os;
}