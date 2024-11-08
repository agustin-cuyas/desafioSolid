/*
Ver constructor electricidad para eliminar el error
*/

#include "mainHeader.hpp"
#include "clases.hpp"

Vehiculo::Vehiculo(const string& marca, const string& modelo, const int anio, double kilometraje) 
         : marca(marca), modelo(modelo), anio(anio), kilometraje(kilometraje) {} //member initializer list

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



void ILlenar::setCapacidad(const double capacidad)
{
    ILlenar::capacidadCarga = capacidad;
}

int ILlenar::getCapacidad() const
{
    return capacidadCarga;
}


Auto::Auto(const string& marca, const string& modelo, const int anio, double kilometraje, const int cantidadPuertas) : Vehiculo(marca, modelo, anio, kilometraje),cantidadPuertas(cantidadPuertas) {} //los constructores no tienen acceso a las variables heredadas, por eso llamo al otro constructor

void Auto::setPuertas(const int puertas)
{
    Auto::cantidadPuertas = puertas;
}

int Auto::getPuertas() const
{
    return cantidadPuertas;
}



Moto::Moto(const string& marca, const string& modelo, const int anio, double kilometraje, const bool tieneSidecar) : Vehiculo(marca, modelo, anio, kilometraje), tieneSidecar(tieneSidecar) {}


void Moto::setSidecar(const char sidecar)
{    
    if (sidecar == 's')
        Moto::tieneSidecar = true;
    else if(tieneSidecar == 'n')
        Moto::tieneSidecar = false;
    
}

bool Moto::getSidecar() const
{
    return tieneSidecar;
}



Camion::Camion(const string& marca, const string& modelo, const int anio, double kilometraje, const double capacidadCarga) : Vehiculo(marca, modelo, anio, kilometraje), ILlenar(capacidadCarga){}




void AutoCargar::ingresarInfo(Vehiculo& vehiculo)
{
    Auto& car = dynamic_cast<Auto&>(vehiculo);

    cin.ignore();

    cout << "\nIngrese los datos del auto." << endl;
    cout << "Marca: ";
    getline(cin, marca);
    car.setMarca(marca);
    cout << "Modelo: ";
    getline(cin,modelo);
    car.setModelo(modelo);
    cout << "Año: ";
    cin >> anio;
    car.setAnio(anio);
    cout << "Kilometraje: ";
    cin >> km;
    car.setKilometraje(km);
    cout << "Cantidad de puertas: ";
    cin >> cantidadPuertas;
    car.setPuertas(cantidadPuertas);
    
}


void MotoCargar::ingresarInfo(Vehiculo& vehiculo)
{
    Moto& moto = dynamic_cast<Moto&>(vehiculo);
    
    cin.ignore();
  
    cout << "\nIngrese los datos de la Moto.\n";
    cout << "Marca: ";
    cin >> marca;
    moto.setMarca(marca);
    cout << "Modelo: ";
    cin >> modelo;
    moto.setModelo(modelo);
    cout << "Año: ";
    cin >> anio;
    moto.setAnio(anio);
    cout << "Kilometraje: ";
    cin >> km;
    moto.setKilometraje(km);
    cout << "Tiene sidecar? (S/N): ";
    cin >> tieneSidecar;
    tieneSidecar = tolower(tieneSidecar);
    moto.setSidecar(tieneSidecar);
}

void CamionCargar::ingresarInfo(Vehiculo& vehiculo)
{
    Camion& camion = dynamic_cast<Camion&>(vehiculo);

    cin.ignore();

    cout << "\nIngrese los datos del camión." << endl;
    cout << "Marca: ";
    cin >> marca;
    camion.setMarca(marca);
    cout << "Modelo: ";
    cin >> modelo;
    camion.setModelo(modelo);
    cout << "Año: ";
    cin >> anio;
    camion.setAnio(anio);
    cout << "Kilometraje: ";
    cin >> km;
    camion.setKilometraje(km);
    cout << "Capacidad de carga (kg): ";
    cin >> capacidadCarga;
    camion.setCapacidad(capacidadCarga);
}


void AutoMostrar::mostrarInfo(Vehiculo &vehiculo)
{
    Auto& car = dynamic_cast<Auto&>(vehiculo);

    cout << "Marca: " << car.getMarca() << endl
         << "Modelo: " << car.getModelo() << endl
         << "Año: " << car.getAnio() << endl
         << "Kilometraje: " << car.getKilometraje() << endl
         << "Cantidad de puertas: " << car.getPuertas() << endl;
}

void MotoMostrar::mostrarInfo(Vehiculo& vehiculo)
{
    Moto& moto = dynamic_cast<Moto&>(vehiculo);

    cout << "Marca: " << moto.getMarca() << endl
         << "Modelo: " << moto.getModelo() << endl
         << "Año: " << moto.getAnio() << endl
         << "Kilometraje: " << moto.getKilometraje() << endl
         << "Tiene sidecar: " << (moto.getSidecar() ? "Sí" : "No") << endl;
}

void CamionMostrar::mostrarInfo(Vehiculo& vehiculo)
{
    Camion& camion = dynamic_cast<Camion&>(vehiculo);

    cout << "Marca: " << camion.getMarca() << endl
         << "Modelo: " << camion.getModelo() << endl
         << "Año: " << camion.getAnio() << endl
         << "Kilometraje: " << camion.getKilometraje() << endl
         << "Capacidad: " << camion.getCapacidad() << endl;
}