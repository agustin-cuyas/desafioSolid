/*
Responsabilidad Única: Cada clase debe tener una única responsabilidad, es decir, una única razón para cambiar.
Ejemplo: Crear una clase Vehiculo que solo sea responsable de almacenar y manejar información básica del vehículo (marca, modelo, año, etc.), mientras que otra clase VehiculoServicio muestre la flota
*/
#include "mainHeader.hpp"

enum Opcion{
    agregar = 1,
    mostrar,
    salir
};

void agregarVehiculo(vector<Vehiculo*>& flota){
    Vehiculo* vehiculo;
    VehiculoCargar cargarvehiculo;

    vehiculo = new Vehiculo(" " ," ", " ", 0, 0.0);
    cargarvehiculo.ingresarInfo(*vehiculo);
    flota.push_back(vehiculo);

    cout << "Vehiculo agregado exitosamente.\n";
}

void mostrarVehiculos(const vector<Vehiculo*>& flota){

    if(flota.size()==0)
        cout << "\nNo tiene vehiculos cargados." << endl;
    else
    {   
        VehiculoServicio mostrar;
        for (size_t i = 0; i < flota.size(); ++i) {    //size() devuelve una variable type_t, por eso defino i asi
            cout << "\nVehiculo " << i + 1 << ":\n";
            Vehiculo* vehiculo = flota[i];
            //flota[i]->mostrarInfo();
            mostrar.mostrarInfo(*vehiculo);
        }
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
                    mostrarVehiculos(flota);
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