/*
Segregación de Interfaces: Los clientes no deben verse obligados a depender de interfaces que no utilizan.
Ejemplo: Crear interfaces pequeñas y específicas como IMovil para métodos de movimiento y IMantenimiento para métodos de mantenimiento, en lugar de una interfaz única IVehiculo que incluya todo. Así, Automovil podría implementar ambas, pero Remolque podría implementar solo IMovil.
*/

/*
Hacer similar a cuando revisaba si el vehiculo era electrico para cargar, que en este caso si se puede hacer mantenimiento o llenar. Todos pueden ser conducidos, solucionar eso
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
    camion,
    remolque
};

void moverVehiculo(Vehiculo*);

void agregarVehiculo(vector<Vehiculo*>& flota) {
    int tipo;
    char esElectrico;

    cout << "\nIngrese el tipo de vehiculo:\n";
    cout << "1. Auto\n";
    cout << "2. Moto\n";
    cout << "3. Camion\n";
    cout << "4. Remolque\n";
    cout << "Elija una opcion: ";
    cin >> tipo;

    Vehiculo* vehiculo = nullptr; // variable temporal para crear y configurar un nuevo vehiculo
    VehiculoCargar* cargarvehiculo = nullptr; 

    switch (tipo) {
        case enumVehiculo::enumauto:
            vehiculo = new Auto("", "", 0, 0.0, 0, false);
            cargarvehiculo = new AutoCargar();
            break;
        case enumVehiculo::moto:
            vehiculo = new Moto("", "", 0, 0.0, false, false);
            cargarvehiculo = new MotoCargar();
            break;
        case enumVehiculo::camion:
            vehiculo = new Camion("", "", 0, 0.0, 0, 0, false);
            cargarvehiculo = new CamionCargar();
            break;        
        case enumVehiculo::remolque:
            vehiculo = new Remolque("", "", 0, 0.0, false, 0, 0);
            cargarvehiculo = new RemolqueCargar();
            break;
        default:
            cout << "Opcion invalida.\n";
            return;
    }

    cargarvehiculo->ingresarInfo(*vehiculo);
    flota.push_back(vehiculo);
    cout << "Vehiculo agregado exitosamente.\n";
}

void mostrarVehiculos(const vector<Vehiculo*>& flota){

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
            else if(auto* remolquePtr = dynamic_cast<Remolque*>(vehiculo)){
                RemolqueMostrar mostrar;
                mostrar.mostrarInfo(*remolquePtr);
            }

            ILlenar* carguero = dynamic_cast<ILlenar*>(vehiculo);
            if (carguero){
                cout << "Desea cargar el vehículo? (S/N): ";
                char cargar;
                cin >> cargar;
                cargar = towlower(cargar);
                if (cargar == 's')
                    carguero->llenar();
            }

            cout << "\n";
        }

        char mover;
        bool quiereMoverse = false;
        do
        {   cout << "\nDesea conducir algún vehículo? (S/N): ";
            cin >> mover;
            tolower(mover);
            
            if(mover == 's'){
                quiereMoverse = true;

                int indice;
                do{
                    cout << "Ingrese el numero de vehiculo: ";
                    cin >> indice;
                }while(indice<1 || indice > flota.size());

                Vehiculo* vehiculo = flota[indice - 1];
                moverVehiculo(vehiculo);
            }

            else if(mover == 'n')
                quiereMoverse = false;

        }while(quiereMoverse);

    }
}

void moverVehiculo(Vehiculo* vehiculo){
    IMovil* aux = dynamic_cast<IMovil*>(vehiculo);
    aux->mover(aux);
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

        for (auto& vehiculo : flota) {  
            delete vehiculo;
        }

    return 0;
}