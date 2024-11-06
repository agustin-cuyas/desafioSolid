#ifndef CLASES_HPP
#define CLASES_HPP

#include <iostream>
using namespace std;

class Vehiculo{
    public:
        Vehiculo(const string& marca, const string& modelo, int anio, double kilometraje);
        void setMarca(const string&);
        string getMarca() const;
        void setModelo(const string&);
        void setAnio(int);
        void setKilometraje(double);
    protected: 
        string marca;
        string modelo;
        int anio;
        double kilometraje;
};

class VehiculoCargar{
    public:
        void ingresarInfo(Vehiculo&);
};

class VehiculoServicio{
    public:
        void mantenimiento(Vehiculo&);
};

#endif