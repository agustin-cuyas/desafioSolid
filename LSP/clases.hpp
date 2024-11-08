#ifndef CLASES_HPP
#define CLASES_HPP

#include <iostream>
using namespace std;

class Vehiculo{
    public:
        Vehiculo(const string& marca, const string& modelo, const int anio, double kilometraje);
        virtual ~Vehiculo() = default; // Destructor virtual para clase polimórfica

        void setMarca(const string&);
        string getMarca() const;

        void setModelo(const string&);
        string getModelo() const;

        void setAnio(const int);
        int getAnio() const;

        void setKilometraje(double);
        double getKilometraje();

        void mover(double);

    protected: 
        string marca;
        string modelo;
        int anio;
        double kilometraje;
};


class Auto : public Vehiculo{
    public:
        Auto(const string& marca, const string& modelo, const int anio, double kilometraje, const int cantidadPuertas);
        
        void setPuertas(const int);
        int getPuertas() const;

    protected:
        int cantidadPuertas;    
};

class Moto : public Vehiculo{
    public:
        Moto(const string& marca, const string& modelo, const int anio, double kilometraje, const bool tieneSidecar);

        void setSidecar(const char);
        bool getSidecar() const;

    protected:
        bool tieneSidecar;
};

class Camion : public Vehiculo{
    public:
        Camion(const string& marca, const string& modelo, const int anio, double kilometraje, const double capacidadCarga);
        
        void setCapacidad(const double);
        int getCapacidad() const;

    protected:
        double capacidadCarga;
};


class VehiculoCargar{
    public:
        virtual void ingresarInfo(Vehiculo&) = 0;

    protected:
        string marca;
        string modelo;
        int anio;
        double km;
};


class AutoCargar : public VehiculoCargar{
    public:
        AutoCargar() = default;
        void ingresarInfo(Vehiculo&) override;

    private:
        int cantidadPuertas;  
};

class MotoCargar : public VehiculoCargar{
    public:
        void ingresarInfo(Vehiculo&) override;

    private:
        char tieneSidecar;  
};

class CamionCargar : public VehiculoCargar{
    public:
        void ingresarInfo(Vehiculo&) override;
    private:
        double capacidadCarga;
};


class VehiculoMostrar{
    public:
        virtual void mostrarInfo(Vehiculo&) = 0;
};

class AutoMostrar : public VehiculoMostrar{
    public:
        void mostrarInfo(Vehiculo&) override;
};

class MotoMostrar : public VehiculoMostrar{
    public:
        void mostrarInfo(Vehiculo&) override;
};

class CamionMostrar : public VehiculoMostrar{
    public:
        void mostrarInfo(Vehiculo&) override;
};

#endif