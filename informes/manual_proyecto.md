# Manual de proyecto: Remake Argentum

Elaborado por Martín Andrés Suarez - Padrón 101.540

## División de tareas

Inicialmente yo estaba a cargo de la parte gráfica del juego. Al quedar como único integrante del juego debí encargar la lógica del juego, la cual encaré de cero.

## Inconvenientes encontrados

Los principales inconvenientes fueron en el diseño de partes esenciales del modelo. Por ejemplo, como hacer que un jugador muestre una animación correctamente al moverse, como lograr que el mapa renderice solo lo necesario y la vista siga al jugador.

Las últimas semanas fueron principalmente de agregar features. A pesar de que muchos de ellos tuve que pensar como implementarlos, no sufrí demasiados inconventientes. Considero que la arquitectura de mensajes por colas me permitió adaptarme fácilmente a la situación.

## Puntos pendientes

A pesar de que obviamente no he podido implementar todos los features del trabajo original, creo que el sistema podría ser fácilmente adaptable a una arquitectura cliente servidor. Por ejemplo, las clases Intention y Command en su mayoría transimiten poca información, podrían ser fácilmente codificables con un protocolo de mensajes de tamaño fijo (esta era nuestra idea original cuando todavía eramos dos integrantes).

El sistema también está preparado para que haya más de un jugador, en ningun lado hay restricciones para un único desarrollo singleplayer.

Puntos a perfeccionar sería la refactorización de distintas clases siguiendo el paradigma de objetos. De esta manera sería más facilmente expandible la jugabilidad. En la documentación técnica hago incapié en distintos lugares donde claramente se puede mejorar el diseño de algunas clases.

## Herramientas

No utilicé demasiadas herramientas. Para crear los mapas la aplicación Tiled, git como control de verisones y gdb para debuggeo.
