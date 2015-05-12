//
//  Medico.h
//  ExamenFinalEstructura
//
//  Created by Alejandra Garay on 12/2/13.
//  Copyright (c) 2013 Alejandra Garay. All rights reserved.
//

#ifndef __ExamenFinalEstructura__Medico__
#define __ExamenFinalEstructura__Medico__

#include <iostream>
#include <string>
using namespace std;


class Medico{
private:
    string nombre;
    string apellidos;
    string especialidad;
    
    
public:
    Medico();
    Medico(string, string, string);
    
    string getNombre();
    string getApellidos();
    string getEspecialidad();
    
    void setNombre(string name);
    void setApellidos(string apelli);
    void setEspecialidad(string espe);
    
    
    friend std::ostream & operator <<(std::ostream &, Medico &);
};

#endif /* defined(__ExamenFinalEstructura__Medico__) */
