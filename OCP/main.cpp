/*
Apertura/Cierre: Las clases deben estar abiertas a la extensión, pero cerradas a la modificación.
Ejemplo: Crear una clase base Vehiculo y varias clases derivadas (Camion, Automovil, Moto) que extiendan la funcionalidad de Vehiculo sin modificar su estructura interna. Agregar una función calcularCosto que pueda ser sobrescrita en cada clase derivada para calcular costos específicos.
*/

#include "mainHeader.hpp"

enum Opcion{
    agregar = 1,
    mostrar,
    salir
};

enum enumVehiculo   //si pongo Vehiculo lo confunde con la clase
{
    enumauto = 1,   //si pongo auto lo confunde con el tipo de dato
    moto,
    camion
};

void agregarVehiculo(vector<Vehiculo*>& flota) {
    int tipo;
    char esElectrico;

    cout << "\nIngrese el tipo de vehiculo:\n";
    cout << "1. Auto\n";
    cout << "2. Moto\n";
    cout << "3. Camion\n";
    cout << "Elija una opcion: ";
    cin >> tipo;

    Vehiculo* vehiculo = nullptr; // variable temporal para crear y configurar un nuevo vehiculo
    VehiculoCargar* cargarvehiculo = nullptr; 

    switch (tipo) {
        case enumVehiculo::enumauto:
            vehiculo = new Auto("", "", 0, 0.0, 0);
            cargarvehiculo = new AutoCargar();
            break;
        case enumVehiculo::moto:
            vehiculo = new Moto("", "", 0, 0.0, false);
            cargarvehiculo = new MotoCargar();
            break;
        case enumVehiculo::camion:
            vehiculo = new Camion("", "", 0, 0.0, 0.0);
            cargarvehiculo = new CamionCargar();
            break;        
        default:
            cout << "Opcion invalida.\n";
            return;
    }

    cargarvehiculo->ingresarInfo(*vehiculo);
    flota.push_back(vehiculo);
    cout << "Vehiculo agregado exitosamente.\n";
}

void calculoCosto(const vector<Vehiculo*>& flota){

    if(flota.size()==0)
        cout << "\nNo tiene vehiculos cargados." << endl;
    else
    {   
        VehiculoMostrar* mostrar;
        for (size_t i = 0; i < flota.size(); ++i) {    //size() devuelve una variable type_t, por eso defino i asi
            cout << "\nVehiculo " << i + 1 << ":\n";
            Vehiculo* vehiculo = flota[i];
            
            if (auto* car = dynamic_cast<Auto*>(vehiculo)) {
                AutoMostrar mostrar;
                mostrar.mostrarInfo(*car);
            } 
            else if (auto* motoPtr = dynamic_cast<Moto*>(vehiculo)) {
                MotoMostrar mostrar;
                mostrar.mostrarInfo(*motoPtr);
            } 
            else if (auto* camionPtr = dynamic_cast<Camion*>(vehiculo)) {
                CamionMostrar mostrar;
                mostrar.mostrarInfo(*camionPtr);
            }
        }

        char calcular;
        bool quiereCalcular = false;
        do
        {   cout << "\nDesea calcular el costo de algún vehículo? (S/N): ";
            cin >> calcular;
            tolower(calcular);
            
            if(calcular == 's'){
                quiereCalcular = true;

                int indice;
                do{
                    cout << "Ingrese el numero de vehiculo: ";
                    cin >> indice;
                }while(indice<1 || indice > flota.size());

                Vehiculo* vehiculo = flota[indice - 1];
                vehiculo->calcularCostos();
            }

            else if(calcular == 'n')
                quiereCalcular = false;

        }while(quiereCalcular);
    }
}

int main(){
    vector<Vehiculo*> flota; //coleccion que mantiene todos los vehiculos creados
    int opcion;    

    do {
            cout << "\nMenu Principal:\n";
            cout << "1. Agregar vehiculo\n";
            cout << "2. Mostrar vehiculos\n";
            cout << "3. Salir\n";
            cout << "Elija una opcion: ";
            cin >> opcion;

            switch (opcion) {
                case Opcion::agregar:
                    agregarVehiculo(flota);
                    break;
                case Opcion::mostrar:
                    calculoCosto(flota);
                    break;
                case Opcion::salir:
                    cout << "Saliendo...\n";
                    break;
                default:
                    cout << "Opcion invalida. Intente nuevamente.\n";
            }
        } while (opcion != 3);

        for (auto vehiculo : flota) {
            delete vehiculo;
        }

    return 0;
}