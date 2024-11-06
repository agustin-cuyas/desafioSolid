/*
Responsabilidad Única: Cada clase debe tener una única responsabilidad, es decir, una única razón para cambiar.
Ejemplo: Crear una clase Vehiculo que solo sea responsable de almacenar y manejar información básica del vehículo (marca, modelo, año, etc.), mientras que otra clase VehiculoServicio maneje los servicios (como mantenimiento y reparaciones).
*/
#include "mainHeader.hpp"



int main(){
    vector<Vehiculo*> flota;
    Vehiculo* vehiculo;
    VehiculoCargar cargarvehiculo;
    vehiculo = new Vehiculo(" ", " ", 0, 0.0);
    cargarvehiculo.ingresarInfo(*vehiculo);
    flota.push_back(vehiculo);

    cout << (*vehiculo).getMarca();
}