//
//  Paciente.h
//  ExamenFinalEstructura
//
//  Created by Alejandra Garay on 12/2/13.
//  Copyright (c) 2013 Alejandra Garay. All rights reserved.
//

#ifndef __ExamenFinalEstructura__Paciente__
#define __ExamenFinalEstructura__Paciente__

#include <iostream>

#include <string>
using namespace std;


class Paciente{
private:
    string nombre;
    string apellidos;
    int edad;
    string telefono;
    
    
public:
    Paciente();
    Paciente(string, string, int, string);
    
    string getNombre();
    string getApellidos();
    int getEdad();
    string getTelefono();
    
    void setNombre(string name);
    void setApellidos(string apelli);
    void setEdad(int ed);
    void setTelefono(string tel);
    
    
    friend std::ostream & operator <<(std::ostream &, Paciente &);
};



#endif /* defined(__ExamenFinalEstructura__Paciente__) */
