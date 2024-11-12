# Cuarto desafío C++
## Implementación de los Principios SOLID

- #### Descripción general del ejercicio y propósito.
  El desafío pide desarrollar programas que implementen los principios SOLID. El propósito de éste es afianzar los conceptos llevandolos a la práctica con un ejemplo concreto, en este caso el manejo de una flota de vehículos.
- #### Explicación de cada principio SOLID, cómo se implementó y cómo mejora el diseño del software.
  - ##### Principio de Responsabilidad Única:
    Una clase debería tener una única responsabilidad.  
    Para implementar este principio en el manejo de una flota de vehiculos, cree una clase Vehiculo que solamente tiene atributos. Para agregar y mostrar vehiculos a la flota utilicé dos clases aparte, cada una sólo con un método (ingresarInfo y mostrarInfo). De esta manera se tienen 3 clases y cada una tiene una sola responsabilidad.
  - ##### Principio de Apertura y Cierre:
    Una clase debería estar abierta a la extensión pero cerrada a la modificación.  
    En este caso, agregué 3 clases que extiendan a Vehiculo: Auto, Moto y Camion. En la clase base añadí un método virtual calcularCosto que se implementa de distinta manera en las subclases, utilizando override. De esta manera, si quisiera agregar un tipo de vehiculo más, no modifico el método calcularCosto ni la clase vehiculo.
  - ##### Principio de Sustitución de Liskov:
    Los objetos de una clase derivada deberían ser sustituibles por objetos de su clase base sin alterar la funcionalidad.  
    Para este principio, creé un método mover() en vehículo. Las clases derivadas Auto, Moto y Camion heredan este método y pueden acceder a este sin necesidad de overridearlo.
  - ##### Principio de Segregación de Interfaces:
    Una clase no debería verse obligada a implementar interfaces que no utiliza.  
    Para implementar ese principio, quité algunos atributos de las clases y los redistribuí en 3 interfaces: IMovil (atributos kilometraje y enMovimiento), IMantenimiento ( atributo necesitaMantenimiento) e ILlenar ( atributos capacidadCarga y cajas). A su vez, estas implementan métodos mover, service y llenar respectivamente. Así, los vehiculos que pueden trasladarse heredan IMovil con sus atributos, los que requieren servicio técnico heredan IMantenimiento y los que pueden transportar carga heredan ILlenar.
  - ##### Principio de Inversión de Dependencias:
    Las clases de alto nivel no deberían depender de las clases de bajo nivel; ambas deben depender de abstracciones.  
    En este caso, reordené un poco las clases para el manejo de la carga de vehiculos. Agregué una clase FlotaControl la cual hereda la interfaz IVehiculoBase, así tiene acceso a los atributos comunes a todos los vehiculos. Luego esta clase será heredada por VehiculoCargar que overridea el método de ingresarInfo. Este método será llamado en las demás clases (AutoCargar, MotoCargar , CamionCargar y RemolqueCargar) cada vez que se requiera ingresar los atributos comunes a éstas (marca, modelo y anio).
- #### Desafíos y decisiones tomadas durante la implementación.
  La idea que seguí en este desafío fue ir agregandole funcionalidades al código y optimizarlo al sumarle la aplicación de los principios. Así, al llegar al último código, obtuve un programa que agrupa las funciones de todos los anteriores y cumple todos los principios SOLID.
  Desarrollando los códigos tuve ciertos problemas a los que me enfrenté. El último que me llevó un rato resolver fue un error al crear una nueva instancia de AutoCargar, etc (es decir al hacer `new AutoCargar();`). Esto sucedió cuando hice el agregado de FlotaControl. El error era el siguiente:  
  `The Default Constructor Cannot Be Referenced -- It Is a Deleted Function`  
  El constructor `AutoCargar() = default` existía, por lo cuál el mensaje de error no era muy claro. Después de renegar e investiga en foros ( como este: https://dede.dev/posts/Avoid-Default-Constructor-Cannot-Be-Referenced-Issue/) me dí cuenta que el error estaba en que las clases que AutoCargar extendía no tenían constructor default. Deshaciendo el camino hacia atrás me di cuenta que AutoControl era bisnieto de IVehiculoBase, y en esta interfaz no había constructor default ya que se utilizaba un constructor personalizado. Agregandole el constructor extra el error se solucionó.
- #### Guía para ejecutar cada sección del ejercicio y cualquier configuración adicional necesaria.
  El uso del programa es intuitivo y maneja correctamente los errores.  
  Se presenta un menú principal con 3 opciones, agregar vehiculos, mostrar la flota o salir y cerrar el programa.  
  Al cargar vehiculos, primero se selecciona el tipo (auto, moto, camión o remolque) y una vez elegido se ingresan los parámetros solicitados que son distintos en cada caso. Algunos parámetros tienen validaciones para que no se ingrese un valor incoherente.
  Una vez que se cargaron los vehiculos se puede ver la flota. En este caso pueden pasar varias cosas:
  - Si a medida que se recorren los vehiculos se detecta que alguno necesita servicio técnico, se realiza automáticamente. Esto se ve reflejado si se vuelve a pedir una muestra de la lista, el vehiculo tendrá el service al día.
  - Si detecta que un vehículo puede transportar carga, se pregunta al usuario si quiere cargarlo con cajas. De aceptar, se pedirá una cantidad que tiene que tener correlación con la capacidad del vehículo. Si ingresa una cantidad válida se llena exitosamente.
  - Finalizado el recorrido de la lista, se pregunta si se quiere conducir alguno de los vehiculos. En caso de hacerlo, se pide el indice del vehiculo deseado.
    
  La última opción es la de Salir, al seleccionarse primero se borran los vehiculos para liberar memoria y se cierra el programa.
