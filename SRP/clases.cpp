#include "mainHeader.hpp"
#include "clases.hpp"

//Vehiculo::Vehiculo(const string &marca, const string &modelo, const int anio, double kilometraje){}
Vehiculo::Vehiculo(const string& marca, const string& modelo, const int anio, double kilometraje) : marca(marca), modelo(modelo), anio(anio), kilometraje(kilometraje) {} //member initializer list

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

void Vehiculo::setAnio(int anio)
{
    Vehiculo::anio = anio;
}

void Vehiculo::setKilometraje(double km)
{
    Vehiculo::kilometraje = km;
}

void VehiculoCargar::ingresarInfo(Vehiculo& vehiculo)
{
    string marca;
    string modelo;
    int anio;
    double km;

    cout << "\nIngrese los datos del auto." << endl;
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

void VehiculoServicio::mantenimiento(Vehiculo&)
{
}
