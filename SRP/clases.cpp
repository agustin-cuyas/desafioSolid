#include "mainHeader.hpp"
#include "clases.hpp"

//Vehiculo::Vehiculo(const string &marca, const string &modelo, const int anio, double kilometraje){}
Vehiculo::Vehiculo(const string& tipo, const string& marca, const string& modelo, const int anio, double kilometraje) : tipo(tipo), marca(marca), modelo(modelo), anio(anio), kilometraje(kilometraje) {} //member initializer list

void Vehiculo::setTipo(const string& tipo)
{
    Vehiculo::tipo = tipo;
}

string Vehiculo::getTipo() const
{
    return tipo;
}

void Vehiculo::setMarca(const string& marca)
{
    Vehiculo::marca = marca;
}

string Vehiculo::getMarca() const
{
    return marca;
}

void Vehiculo::setModelo(const string& modelo)
{
    Vehiculo::modelo = modelo;
}

string Vehiculo::getModelo() const
{
    return modelo;
}

void Vehiculo::setAnio(const int anio)
{
    Vehiculo::anio = anio;
}

int Vehiculo::getAnio() const
{
    return anio;
}

void Vehiculo::setKilometraje(double km)
{
    Vehiculo::kilometraje = km;
}

double Vehiculo::getKilometraje()
{
    return kilometraje;
}

void VehiculoCargar::ingresarInfo(Vehiculo& vehiculo)
{
    string tipo;
    string marca;
    string modelo;
    int anio;
    double km;

    cin.ignore();

    cout << "\nIngrese los datos del Vehículo." << endl;
    cout << "Tipo de vehículo: ";
    getline(cin, tipo);
    vehiculo.setTipo(tipo);
    cout << "Marca: ";
    getline(cin, marca);
    vehiculo.setMarca(marca);
    cout << "Modelo: ";
    getline(cin,modelo);
    vehiculo.setModelo(modelo);
    cout << "Año: ";
    cin >> anio;
    vehiculo.setAnio(anio);
    cout << "Kilometraje: ";
    cin >> km;
    vehiculo.setKilometraje(km);
}

void VehiculoServicio::mostrarInfo(Vehiculo& vehiculo)
{
    cout << vehiculo.getTipo() << endl
         << "Marca: " << vehiculo.getMarca() << endl
         << "Modelo: " << vehiculo.getModelo() << endl
         << "Año: " << vehiculo.getAnio() << endl
         << "Kilometraje: " << vehiculo.getKilometraje() << endl;

}
