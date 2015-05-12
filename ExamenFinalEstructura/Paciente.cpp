//
//  Paciente.cpp
//  ExamenFinalEstructura
//
//  Created by Alejandra Garay on 12/2/13.
//  Copyright (c) 2013 Alejandra Garay. All rights reserved.
//

#include "Paciente.h"

Paciente::Paciente()
{
    Paciente("Sin definir", "Sin definir", 0, "Sin definir");
}

Paciente::Paciente(string n, string a, int ed, string t)
{
    nombre = n;
    apellidos = a;
    edad = ed;
    telefono = t;
    
}

string Paciente::getNombre()
{
    return nombre;
}

string Paciente::getApellidos()
{
    return apellidos;
}

int Paciente::getEdad()
{
    return edad;
}

string Paciente::getTelefono()
{
    return telefono;
}

void Paciente::setNombre(string name)
{
    nombre = name;
}

void Paciente::setApellidos(string apelli)
{
    apellidos = apelli;
}

void Paciente::setEdad(int ed)
{
    edad = ed;
}

void Paciente::setTelefono(string tel)
{
     telefono= tel;
}




std::ostream & operator <<(std::ostream & os, Paciente & p)
{
    os << p.nombre << " ";
    os << p.apellidos << "  "<<endl;
    os <<" Edad: "<< " : "<< p.edad<<endl;
    os <<"Tel: "<< p.edad<<endl;
    
    return os;
}