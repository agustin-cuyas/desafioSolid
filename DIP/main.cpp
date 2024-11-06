/*
Inversión de Dependencias: Las clases de alto nivel no deben depender de las clases de bajo nivel; ambas deben depender de abstracciones.
Ejemplo: Crear una clase FlotaControl que dependa de una interfaz IVehiculoBase, en lugar de depender de una clase concreta como Camion o Automovil. Esto permitirá a FlotaControl funcionar con cualquier clase que implemente IVehiculoBase, permitiendo la adición de nuevos tipos de vehículos sin modificar el código de FlotaControl.
*/
#include "mainHeader.hpp"