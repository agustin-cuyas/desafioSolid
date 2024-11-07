#ifndef CLASES_HPP
#define CLASES_HPP

#include <iostream>
using namespace std;

class Vehiculo{
    public:
        Vehiculo(const string& tipo, const string& marca, const string& modelo, const int anio, double kilometraje);

        void setTipo(const string&);
        string getTipo() const;

        void setMarca(const string&);
        string getMarca() const;

        void setModelo(const string&);
        string getModelo() const;

        void setAnio(const int);
        int getAnio() const;

        void setKilometraje(double);
        double getKilometraje();

    protected: 
        string tipo;
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
        void mostrarInfo(Vehiculo&);
};

#endif