/*
Agregar clase Remolque que herede vehiculo, movil y llenar.
atributos: bool esCerrado

IMantenimiento atributo bool necesitaMantenimiento y hacer similar a los vehiculos electricos que al cargar se pedía una caracteristica mas. método service cambia esta variable de ser necesario
ILlenar atributo capacidadCarga (sacarsela a camion y poner en esta, total la hereda). método llenar que pida cantidad de cajas

Constructores para estas clases, ver el de electricidad

*/
#ifndef CLASES_HPP
#define CLASES_HPP

#include <iostream>
using namespace std;

class Vehiculo{
    public:
        Vehiculo(const string& marca, const string& modelo, const int anio);
        virtual ~Vehiculo() = default; // Destructor virtual para clase polimórfica

        void setMarca(const string& marca){ Vehiculo::marca = marca; }
        string getMarca() const{ return marca; }

        void setModelo(const string& modelo){ Vehiculo::modelo = modelo; }
        string getModelo() const{ return modelo; }

        void setAnio(const int anio){ Vehiculo::anio = anio; }
        int getAnio() const{ return anio; }

    protected: 
        string marca;
        string modelo;
        int anio;
};

class IMovil{
    public:
        IMovil(double kilometraje);
        void mover(IMovil*);

        bool getMovimiento(){ return enMovimiento; }
        void setMovimiento(bool enMovimiento){ IMovil::enMovimiento = enMovimiento; }

        void setKilometraje(double km){ IMovil::kilometraje = km; }
        double getKilometraje(){ return kilometraje; }

    protected:
        double kilometraje;
        bool enMovimiento;
};

class IMantenimiento{
    public:
        IMantenimiento(bool);
        void service();

        void setMantenimiento(char mantenimiento);
        bool getMantenimiento(){ return necesitaMantenimiento; }

    protected:
        bool necesitaMantenimiento;
};

class ILlenar{
    public:
        ILlenar(const int& capacidadCarga);
        void llenar();
        
        void setCapacidad(const int capacidad){ ILlenar::capacidadCarga = capacidad; }
        int getCapacidad() const{ return capacidadCarga; }

        void setCajas(const int cajas);
        int getCajas(){ return cajas; }

    protected:
        int capacidadCarga;
        int cajas;
};

class Auto : public Vehiculo, public IMovil, public IMantenimiento{
    public:
        Auto(const string& marca, const string& modelo, const int anio, double kilometraje, const int cantidadPuertas, const bool necesitaMantenimiento);
        
        void setPuertas(const int);
        int getPuertas() const;

    protected:
        int cantidadPuertas;    
};

class Moto : public Vehiculo, public IMovil, public IMantenimiento{
    public:
        Moto(const string& marca, const string& modelo, const int anio, double kilometraje, const bool tieneSidecar, const bool necesitaMantenimiento);

        void setSidecar(const char);
        bool getSidecar() const { return tieneSidecar; }

    protected:
        bool tieneSidecar;
};

class Camion : public Vehiculo, public IMovil, public IMantenimiento, public ILlenar{
    public:
        Camion(const string& marca, const string& modelo, const int anio, double kilometraje, const int capacidadCarga, const int& carga, const bool necesitaMantenimiento);
    private:
        int carga;
};

class Remolque : public Vehiculo, public IMovil, public ILlenar{
    public:
        Remolque(const string& marca, const string& modelo, const int anio, double kilometraje, bool esCerrado, const int capacidadCarga, const int& carga);
        void setCerrado(const char esCerrado);
        bool getCerrado(){ return esCerrado; }
    protected:
        bool esCerrado;
        int carga;
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
        char mantenimiento;
};

class MotoCargar : public VehiculoCargar{
    public:
        void ingresarInfo(Vehiculo&) override;

    private:
        char tieneSidecar;  
        char mantenimiento;
};

class CamionCargar : public VehiculoCargar{
    public:
        void ingresarInfo(Vehiculo&) override;
    private:
        int capacidadCarga;
        int cajas;
        char mantenimiento;
};

class RemolqueCargar: public VehiculoCargar{
    public:
        void ingresarInfo(Vehiculo&) override;
    private:
        int capacidadCarga;
        int cajas;
        char esCerrado;
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

class RemolqueMostrar : public VehiculoMostrar{
    public:
        void mostrarInfo(Vehiculo&) override;
};

#endif