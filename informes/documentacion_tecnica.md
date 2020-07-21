# Documentación técnica: Remake Argentum

## 1. Requerimientos

El programa fue elaborado y testeado utilizando Manjaro Linux 20.0.3. Para poder ejecutarlo es necesario tener instaladas las siguientes librerías:

- sdl2 2.0.12-1
- sdl2_image 2.0.5-2
- sdl2_mixer 2.0.4-4
- sdl2_ttf 2.0.15-2
- Compilador g++

## 2. Descripción general del proyecto

El proyecto es un único programa con una fuerte distinción entre la parte gráfica y la lógica del juego, emulando en cierto modo una arquitectura cliente - servidor.

La clase principal de la parte gráfica `Client` dicta el funcionamiento de la misma y vincula a su ritmo a la parte lógica del juego, organizada por la clase `Sender`.

## 3. Módulos

### 3.1. Parte gráfica

En esta sección voy a mencionar las clases de mayor importancia en la parte gráfica junto con una breve descripción de las mismas.

#### 3.1.A Clases generales

##### Client

La parte gráfica esta comandada por la clase `Client`. Esta ejecuta el game loop y notifica el paso del tiempo a los distintos componentes de la parte gráfica. Se encarga además de implementar el patrón *Mediator*, siendo la que comunica los cambios del estado del juego a las clases correspondientes.

##### EventHandler

Esta clase se encarga de recibir los eventos de entrada: uso de teclas, clicks del mouse. Los interpreta y los comunica como intenciones de acción a la parte lógica del juego. Este mecanismo de comunciación se describirá en detalla en la parte **3.3 Comunicación**.

Para tratar de evitar que otras clases de la parte gráfica manejen eventos de teclado o mouse me alejé un poco de la filosofía de programación orientada a objetos. Por ejemplo, actualmanete cuando el usuario hace click, EventHandler le pregunta al mapa si estas coordenadas corresponden a una parte del mismo, y luego, si es positivo, le pide las coordenadas del tile. En vez de realizar esta suerte de doble getter, podría decirle al mapa que hubo un click en cierta ubicación. La clase MapGraphic podría tener dentro suyo una clase propia que maneje los eventos de teclado y que actúe acordemente.

##### EntityContainer

Almacena las entidades del juego, con sus respectivos ids para que sea de fácil acceso. Permite agregar, quitar y mandar acciones a las distintas entidades del juego.

##### SFXGenerator

Esta clase genera animaciones y sónidos para mostrar por pantalla. Especialmente se usa al realizar ataques donde se debe reproducir el sonido del arma y mostrar una animación en caso del uso de armas mágicas.

##### MusicPlayer

Esta clase se encarga de manejar lá música de fondo del juego. Se ocupa de que siempre haya una canción reproduciendose y que se pueda detener o cambiar la canción.

##### GraphicalInterface

Esta clase se encarga de mostrar la interfaz gráfica, es decir, todo lo que no sea el mapa del juego. Maneja los items del inventario, y las estadísticas del jugador (oro, vida, mana, etc).

##### AssetsLoader

Esta clase carga todos los assets que el juego necesita y devuelve referencia a los mismos segun se le pida. Los assets incluyen texturas, sonidos, música, textos y frames de animaciones.

##### Screen

La clase `Screen` se encarga de manejar la vista del mapa por parte de la parte gráfica. Realiza los calculos necesarios para que siempre el jugador esté centrado en la misma.

##### MapGraphic

Esta clase maneja el renderizado del mapa. Recibe un archivo en formato json que descibre el mapa, lo almacena y renderiza las partes que se le requieran.

#### 3.1.B Entidades

Para gráficar las entidades movibles del juego (jugador, NPCs, zombies), delego la funcionabilidad en la clase `Entity`. Se describen a continuación el funcionamineto de esta y otras clases relacionadas.

##### Entity

La clase `Entity` modela una entidad del juego. Contiene distinta información como su ubicación, texturas, sónidos. Para poder mantener una animación sostenida en el paso del tiempo se utiliza el patrón *State*, modelado en este caso por las clases `Action`.

En el siguiente diagrama, se muestra un esquema básico de clases sobre la clase `Entity`.

![diagrama clases](https://github.com/martinsuarezz/taller-tp-final/blob/master/informes/class2.png)

##### EntityFactory

Para abstraer la inicialización de las entidades hago uso de esta clase que implementa el patrón *Factory*.

##### Action

Las clases que heredan de `Action` implementan una interfaz básica de renderizado y animación de texturas. Hacen uso de la clase `Animation` para mostrar las animaciones.

##### Animation

La clase `Animation` realiza los cálculos necesarios para poder mostrar una animación fluida. Contiene información de la duración de los frames y que parte de la textura se debe renderizar en cada frame.

#### 3.1.C Wrappers básicos de SDL

Para simplificar el uso de SDL, y hacerlo más orientado a objetos, elaboré clases que implementen distintas funcionalidades. Las menciono brevemente:

- Texture: brinda la funcionalidad básica de una textura: carga de imágenes, renderizado, cambio de dimensiones, etc.
- Text: encapsula el comportamiento de una textura para solo permitir textos.
- Sound: otorga funcionalidades básicas de sonidos: cargar, reproducir.
- Music: otorga funcionalidades básicas de música: cargar, reproducir, pausar, detener.
- Renderer: wrappea funcionalidades del renderer de SDL, parte fundamental para el renderizado.
- SDLHandler: invoca a los inicializadores de los módulos de SDL y los libera al destruir la clase.

### 3.2. Lógica del juego

En esta sección voy a explicar las clases esenciales en el funcionamiento de la lógica del juego.

#### 3.2.A Clases generales

##### Sender

Originalmente la clase que manejaba el envío de datos del cliente al servidor. En esta arquitectura recibe la información de la parte gráfica, y ejecuta la lógica del juego.

##### GameMap

Clase que maneja el mapa desde la parte lógica del juego.

##### GameEntityContainer

Almacena y administra las entidades del juego.

#### 3.2.B Entidades

En la lógica del juego existe la clase `GameEntity`. Inicialmente iba a ser una clase de la que hereden tanto unidades del juego (jugador, zombies, npcs) como otras entidades que pueden aparecer en el mapa (items, obstáculos como casas o árboles). Finalmente utilicé la clase solo para modelar las primeras. La clase `MovableEntity` representa esto.

El siguiente es un diagrama de clases general de las entidades del juego. Decidí solo poner los métodos y objetos más representativos del funcionamiento del modelo

![diagrama clases](https://github.com/martinsuarezz/taller-tp-final/blob/master/informes/class1.png)

##### Movable Entity

Una clase abstracta que brinda las funcionalidades de una unidad móvil. Almacena una gran cantidad de atributos como vida, experiencia, oro, nivel y un estado de acción modelado por las clases `State`.

##### Player, Zombie, Merchant y Healer

Estas clases heredan de `MovableEntity` e implementan los métodos abstractos de la misma. Player es la clase que más funcionalidad tiene, muchos de los métodos abstractos de MovableEntity no hacen nada en las otras clases. Por ejemplo, un zombie o un comerciante (`Merchant`) no pueden ser revividos, por lo tanto llamar el método `revive()` de estas clases no realiza nada.

La implementación actual soporta que en un futuro se quieran agregar features como que los zombies suban de nivel, o ganen oro, o tengan mana. Sin embargo actualmente no es una implentación del todo correcta, va en contra del *principio de segregación de la interfaz*.

Soluciones posibles a este problema sería crear una nueva interfaz de **entidad jugable**, que posea nivel, oro, mana, etc.

Otra solución posible sería quitar comportamiento polimorfico y migrarlo a clases iternas con el patrón *Composite*.

##### Health, Mana, GoldContainer, Level

Estas clases implementan de manera bastante similar los distintos atributos de un objeto `MovableEntity`.

##### State

La clase `State` otorga una interfaz básica para implementar un estado en el que se puede encontrar una MovableEntity. En lineas generales una MovableEntity tiene dos estados, el actual y el próximo. El estado actual está fijo hasta que este se termine de ejecutar. El estado `IdleState`, por ejemplo, no tiene tiempo de ejecución, siempre esta listo para avanzar al proximo estado. Por otro lado, estados como `WalkingState` o `AttackingState` si tienen tiempo de ejecución. Solo podrán cambiar al próximo cuando se hayan completado.

El estado próximo se puede cambiar libremente según las instrucciones que le lleguen a la entidad, guardando siempre la última recibida.

Las clases `State`, deben tambien encargarse de saber si son válidas. Por ejemplo, `WalkingState` tiene que saber si se puede mover en la dirección pedida o es una ubicación no disponible.

Por último, las clases `State` una vez activadas, llevan a cabo la ejecución propia de su acción. `WalkingState` mueve la unidad en cada frame, `AttackingState` ataca al objetivo.

##### GameItem

Los items del juego son manejados desde la lógica con la clase GameItem. Para esta implemtación evité realizar algo del estilo clase Item de la que heredan Escudo, Armadura, Arma, etc. Preferí ir por utilizar el patrón Composite haciendo items más genéricos y flexibles. Básicamente un GameItem contiene dos módulos: DamageDealer, encargado de calcular el daño al atacar con el item, y DefenseDealer, encargado de obtener la defensa del item.

Creo que esta implementación fue correcta, sin embargo debí haber ido por un camino más orientado a objetos. Actualmente las clases GameItem quedaron prácticamente como contenedores de estadísticas como cuanto daño realiza un item, su rango de ataque, etc. La única funcionalidad que poseen es devolver un número de ataque o defensa aleatorio que esté entre los valores mínimo y máximo.

Para realizar un ataque, una implementación más orientada a objetos, podría pasarle al ítem la entidad objetivo y dejar que este ítem se encargue de realizarle daño.

### 3.3 Comunicación

A pesar de que la clase `Client` tiene dentro a la clase `Sender`, nunca se comunican llamando sus métodos directamente. El envío de información entre la parte lógica y la parte gráfica del juego se realiza utilizando las colas bloqueantes de comandos e intenciones.

##### IntentionsQueue e Intention

IntentionsQueue es una clase que implementa una cola bloqueante. Dentro de ellas se colocan intenciones de acciones que quiere realizar el jugador. Estas intenciones están modeladas por clases que heredan de `Intention`. Por ejemplo, cuando se apreta la tecla `w` para moverse hacia arriba, la clase `EventHandler` lo detecta. Esta clase crea una intención `MoveIntention` y encola esta intención. Paralelamente, la clase `Sender` constantemente quita intenciones de esta cola y ejecuta sus acciones.

Un uso importante de la clase `Intention`, es para marcar el tiempo del game loop. En cada game loop de la parte gráfica, se encola en la cola de intenciones una clase `TimeOutIntention`, de esta manera, se despierta necesariamente a la clase `Sender` en cada loop del juego. Gracias a esto, tanto la parte gráfica, como la lógica, funcionan sincronizadas.

En el siguiente diagrama se muestra la secuencia de recibir una orden de movimiento y como se transmite a la lógica del juego.

![diagrama intentions](https://github.com/martinsuarezz/taller-tp-final/blob/master/informes/seq2.png)

##### CommandsQueue y Command

El funcionamiento de `CommandsQueue` y las clases que heredan de `Command` es similar al anterior. La única diferencia es el sentido de comunicación. Las clases `Command` indican actualizaciones del estado del juego que la lógica le envía a la parte gráfica para que pueda mostrarlas.

En el siguiente diagrama se muestra la secuencia que se da luego de que se actualiza una entidad en la lógica del juego, y como esta información llega a la parte gráfica del programa.

![diagrama commands](https://github.com/martinsuarezz/taller-tp-final/blob/master/informes/seq1.png)

### 4. Archivos utilizados

Para los distintos archivos de configuración se utilizó el formato .json. Para parsearlos, la librería nhlomman/json.

Los archivos de configuración, son simplementente con el formato clave: valor, y se utilizan para configuración de valores de juego (config.json), las rutas de los assets a usar (archivos */roots.json) y para el mapa del juego.

La única distinción, en el mapa del juego, es que se utilizó el programa Tiled y el formato .json producido por el mismo.
