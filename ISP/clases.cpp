#include "mainHeader.hpp"
#include "clases.hpp"

Vehiculo::Vehiculo(const string& marca, const string& modelo, const int anio) 
         : marca(marca), modelo(modelo), anio(anio) {} //member initializer list


IMovil::IMovil(double kilometraje) : kilometraje(kilometraje){};

void IMovil::mover(IMovil* vehiculo)
{    
    if(vehiculo->getMovimiento() == 1){
        cout << "El vehiculo ya estaba en movimiento, deteniendo..." << endl;
        vehiculo->setMovimiento(0);
    }
    else{
        vehiculo->setMovimiento(1);
        cout << "Vehiculo en movimiento" << endl;
    }
}

IMantenimiento::IMantenimiento(bool necesitaMantenimiento) : necesitaMantenimiento(necesitaMantenimiento) {}

void IMantenimiento::setMantenimiento(char mantenimiento){
    if (mantenimiento == 's')
        IMantenimiento::necesitaMantenimiento = false;
    else if(mantenimiento == 'n')
        IMantenimiento::necesitaMantenimiento = true;
}

void IMantenimiento::service()
{
    if (getMantenimiento() == 1){
        cout << "Haciendole el service al vehiculo" << endl;  
        setMantenimiento('s');  //sí tiene el service al día
    }     
}


ILlenar::ILlenar(const int& capacidadCarga) : capacidadCarga(capacidadCarga){}

void ILlenar::llenar()
{
    int cargaPosible = getCapacidad() -  cajas;
    double cargaDeseada;
    bool cargaValida = false;

    if(cargaPosible == 0)
        cout << "Vehiculo lleno, no se puede cargar." << endl;
    
    else
    {    
        cout << "Puede cargar " << cargaPosible << " cajas más." <<  endl;

        do{   
            try
            {
                cout << "Cuantas cajas desea cargar? ";
                cin >> cargaDeseada;
                    
                if (cargaDeseada > cargaPosible || cargaDeseada < 0)
                    throw out_of_range("No se puede superar la capacidad ni ingresar numeros negativos.");

                cargaValida = true; //si no hay excepciones, no se vuelve a pedir.

                setCajas(cajas + cargaDeseada);
            }
            catch(const invalid_argument& ex){
                cout << ex.what() << endl;
            }
            catch(const out_of_range& ex){
                cout << ex.what() << endl;
            }
        }while (!cargaValida);    
    }
}

void ILlenar::setCajas(const int cajas)
{
    if (cajas > capacidadCarga){
        cout << "Capacidad superada" << endl;
        ILlenar::cajas = capacidadCarga;
    }
    else
        ILlenar::cajas = cajas;
}

Auto::Auto(const string& marca, const string& modelo, const int anio, double kilometraje, const int cantidadPuertas, const bool necesitaMantenimiento) : Vehiculo(marca, modelo, anio), IMovil(kilometraje),cantidadPuertas(cantidadPuertas), IMantenimiento(necesitaMantenimiento) {} //los constructores no tienen acceso a las variables heredadas, por eso llamo al otro constructor


Moto::Moto(const string& marca, const string& modelo, const int anio, double kilometraje, const bool tieneSidecar, const bool necesitaMantenimiento) : Vehiculo(marca, modelo, anio), IMovil(kilometraje), tieneSidecar(tieneSidecar), IMantenimiento(necesitaMantenimiento) {}


void Moto::setSidecar(const char sidecar)
{    
    if (sidecar == 's')
        Moto::tieneSidecar = true;
    else if(tieneSidecar == 'n')
        Moto::tieneSidecar = false;
    
}


Camion::Camion(const string& marca, const string& modelo, const int anio, double kilometraje, const int capacidadCarga, const int& carga, const bool necesitaMantenimiento) : Vehiculo(marca, modelo, anio), IMovil(kilometraje), ILlenar(capacidadCarga), carga(carga), IMantenimiento(necesitaMantenimiento){}

Remolque::Remolque(const string& marca, const string& modelo, const int anio, double kilometraje, bool esCerrado, const int capacidadCarga, const int& carga) : Vehiculo(marca, modelo, anio), IMovil(kilometraje), esCerrado(esCerrado), ILlenar(capacidadCarga), carga(carga){}

void Remolque::setCerrado(const char esCerrado)
{
    if (esCerrado == 's')
        Remolque::esCerrado = true;
    else if(esCerrado == 'n')
        Remolque::esCerrado = false;
}



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
    cout << "Tiene el service al día? (S/N): ";
    cin >> mantenimiento;
    mantenimiento = tolower(mantenimiento);
    car.setMantenimiento(mantenimiento);
    
}


void MotoCargar::ingresarInfo(Vehiculo& vehiculo)
{
    Moto& moto = dynamic_cast<Moto&>(vehiculo);
    
    cin.ignore();
  
    cout << "\nIngrese los datos de la moto.\n";
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
    cout << "Tiene el service al día? (S/N): ";
    cin >> mantenimiento;
    mantenimiento = tolower(mantenimiento);
    moto.setMantenimiento(mantenimiento);
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
    cout << "Capacidad de carga (cajas): ";
    cin >> capacidadCarga;
    camion.setCapacidad(capacidadCarga);
    cout << "Cajas cargadas: ";
    cin >> cajas;
    camion.setCajas(cajas);
    cout << "Tiene el service al día? (S/N): ";
    cin >> mantenimiento;
    mantenimiento = tolower(mantenimiento);
    camion.setMantenimiento(mantenimiento);
}

void RemolqueCargar::ingresarInfo(Vehiculo& vehiculo)
{
    Remolque& remolque = dynamic_cast<Remolque&>(vehiculo);

    cin.ignore();

    cout << "\nIngrese los datos del remolque." << endl;
    cout << "Marca: ";
    cin >> marca;
    remolque.setMarca(marca);
    cout << "Modelo: ";
    cin >> modelo;
    remolque.setModelo(modelo);
    cout << "Año: ";
    cin >> anio;
    remolque.setAnio(anio);
    cout << "Kilometraje: ";
    cin >> km;
    remolque.setKilometraje(km);
    cout << "El remolque es cerrado? (S/N):";
    cin >> esCerrado;
    esCerrado = tolower(esCerrado);
    remolque.setCerrado(esCerrado);
    cout << "Capacidad de carga (cajas): ";
    cin >> capacidadCarga;
    remolque.setCapacidad(capacidadCarga);
    cout << "Cajas cargadas: ";
    cin >> cajas;
    remolque.setCajas(cajas);

}



void AutoMostrar::mostrarInfo(Vehiculo &vehiculo)
{
    Auto& car = dynamic_cast<Auto&>(vehiculo);

    cout << "Marca: " << car.getMarca() << endl
         << "Modelo: " << car.getModelo() << endl
         << "Año: " << car.getAnio() << endl
         << "Kilometraje: " << car.getKilometraje() << endl
         << "Cantidad de puertas: " << car.getPuertas() << endl
         << "Tiene service al día: " << (car.getMantenimiento() ? "No" : "Sí") << endl;
}

void MotoMostrar::mostrarInfo(Vehiculo& vehiculo)
{
    Moto& moto = dynamic_cast<Moto&>(vehiculo);

    cout << "Marca: " << moto.getMarca() << endl
         << "Modelo: " << moto.getModelo() << endl
         << "Año: " << moto.getAnio() << endl
         << "Kilometraje: " << moto.getKilometraje() << endl
         << "Tiene sidecar: " << (moto.getSidecar() ? "Sí" : "No") << endl
         << "Tiene service al día: " << (moto.getMantenimiento() ? "No" : "Sí") << endl;
}

void CamionMostrar::mostrarInfo(Vehiculo& vehiculo)
{
    Camion& camion = dynamic_cast<Camion&>(vehiculo);

    cout << "Marca: " << camion.getMarca() << endl
         << "Modelo: " << camion.getModelo() << endl
         << "Año: " << camion.getAnio() << endl
         << "Kilometraje: " << camion.getKilometraje() << endl
         << "Capacidad: " << camion.getCapacidad() << endl
         << "Cajas cargadas: " << camion.getCajas() << endl
         << "Tiene service al día: " << (camion.getMantenimiento() ? "No" : "Sí") << endl;
}

void RemolqueMostrar::mostrarInfo(Vehiculo& vehiculo)
{
    Remolque& remolque = dynamic_cast<Remolque&>(vehiculo);

    cout << "Marca: " << remolque.getMarca() << endl
         << "Modelo: " << remolque.getModelo() << endl
         << "Año: " << remolque.getAnio() << endl
         << "Kilometraje: " << remolque.getKilometraje() << endl
         << "Es cerrado: " << (remolque.getCerrado() ? "Sí" : "No") << endl
         << "Capacidad: " << remolque.getCapacidad() << endl
         << "Cajas cargadas: " << remolque.getCajas() << endl;
}

