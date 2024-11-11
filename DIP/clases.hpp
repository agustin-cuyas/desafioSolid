#ifndef CLASES_HPP
#define CLASES_HPP

#include <iostream>
using namespace std;

class IVehiculoBase{
    public:
        IVehiculoBase() = default;  //constructor default ya que algunas clases que lo heredan no se construyen con todos loa parametros
        IVehiculoBase(const string& marca, const string& modelo, const int anio);
        virtual ~IVehiculoBase() = default; // Destructor virtual para clase polimórfica

        void setMarca(const string& marca){ IVehiculoBase::marca = marca; }
        string getMarca() const{ return marca; }

        void setModelo(const string& modelo){ IVehiculoBase::modelo = modelo; }
        string getModelo() const{ return modelo; }

        void setAnio(const int anio){ IVehiculoBase::anio = anio; }
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

class Auto : public IVehiculoBase, public IMovil, public IMantenimiento{
    public:
        Auto(const string& marca, const string& modelo, const int anio, double kilometraje, const int cantidadPuertas, const bool necesitaMantenimiento);
        
        void setPuertas(const int puertas){ Auto::cantidadPuertas = puertas; }
        int getPuertas() const{ return cantidadPuertas; }

    protected:
        int cantidadPuertas;    
};

class Moto : public IVehiculoBase, public IMovil, public IMantenimiento{
    public:
        Moto(const string& marca, const string& modelo, const int anio, double kilometraje, const bool tieneSidecar, const bool necesitaMantenimiento);

        void setSidecar(const char);
        bool getSidecar() const { return tieneSidecar; }

    protected:
        bool tieneSidecar;
};

class Camion : public IVehiculoBase, public IMovil, public IMantenimiento, public ILlenar{
    public:
        Camion(const string& marca, const string& modelo, const int anio, double kilometraje, const int capacidadCarga, const int& carga, const bool necesitaMantenimiento);
    private:
        int carga;
};

class Remolque : public IVehiculoBase, public IMovil, public ILlenar{
    public:
        Remolque(const string& marca, const string& modelo, const int anio, double kilometraje, bool esCerrado, const int capacidadCarga, const int& carga);
        void setCerrado(const char esCerrado);
        bool getCerrado(){ return esCerrado; }
    protected:
        bool esCerrado;
        int carga;
};

class FlotaControl : public IVehiculoBase{
    public:
        FlotaControl() = default;       
        virtual ~FlotaControl() = default;
        virtual void ingresarInfo(IVehiculoBase&) = 0;
};

class VehiculoCargar : public FlotaControl{
    public:
        VehiculoCargar() = default;
        void ingresarInfo(IVehiculoBase&) override;

    protected:
        string marca;
        string modelo;
        int anio;
        double km;
};


class AutoCargar : public VehiculoCargar{
    public:
        AutoCargar() = default;
        void ingresarInfo(IVehiculoBase&) override;

    private:
        int cantidadPuertas;  
        char mantenimiento;
};

class MotoCargar : public VehiculoCargar{
    public:
        MotoCargar() = default;
        void ingresarInfo(IVehiculoBase&) override;

    private:
        char tieneSidecar;  
        char mantenimiento;
};

class CamionCargar : public VehiculoCargar{
    public:
        CamionCargar() = default;
        void ingresarInfo(IVehiculoBase&) override;
    private:
        int capacidadCarga;
        int cajas;
        char mantenimiento;
};

class RemolqueCargar: public VehiculoCargar{
    public:
        RemolqueCargar() = default;
        void ingresarInfo(IVehiculoBase&) override;
    private:
        int capacidadCarga;
        int cajas;
        char esCerrado;
};


class VehiculoMostrar{
    public:
        virtual void mostrarInfo(IVehiculoBase&) = 0;
};

class AutoMostrar : public VehiculoMostrar{
    public:
        void mostrarInfo(IVehiculoBase&) override;
};

class MotoMostrar : public VehiculoMostrar{
    public:
        void mostrarInfo(IVehiculoBase&)override;
};

class CamionMostrar : public VehiculoMostrar{
    public:
        void mostrarInfo(IVehiculoBase&) override;
};

class RemolqueMostrar : public VehiculoMostrar{
    public:
        void mostrarInfo(IVehiculoBase&) override;
};

#endif