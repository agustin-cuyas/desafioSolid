/*
Segregación de Interfaces: Los clientes no deben verse obligados a depender de interfaces que no utilizan.
Ejemplo: Crear interfaces pequeñas y específicas como IMovil para métodos de movimiento y IMantenimiento para métodos de mantenimiento, en lugar de una interfaz única IVehiculo que incluya todo. Así, Automovil podría implementar ambas, pero Remolque podría implementar solo IMovil.
*/