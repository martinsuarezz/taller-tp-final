# Manual de usuario: Remake Argentum

## 1. Instalación

### Requerimientos

El programa fue elaborado y testeado utilizando Manjaro Linux 20.0.3. Para poder ejecutarlo es necesario tener instaladas las siguientes librerías:

- sdl2 2.0.12-1
- sdl2_image 2.0.5-2
- sdl2_mixer 2.0.4-4
- sdl2_ttf 2.0.15-2
- Compilador g++

### Instalación

Para instalar ejecutar el script `install.sh`.

## 2. Configuración

Dentro de la carpeta src se puede encontrar el archivo de configuración `config.json`. Desde allí es posible modificar el alto y ancho de la pantalla. También se pueden reducir los fps en caso de que el juego no esté funcionando correctamente. 45 fps (default) suele ser una buena configuración, muestra un movimiento fluido sin caer en problemas de performance. No es recomendable subir los fps ya que probablemente no se note una diferencia.

## 3. Forma de uso

### Inicio del juego

Para iniciarl el juego es necesario correr el programa de la siguiente manera: `./argentum [raza] [clase]`.

Las razas disponibles son las siguientes:
- `human`: El humano es una clase balanceada en todos sus stats.
- `elf`: El elfo es una clase débil pero extremadamente ágil y con buen poder mágico.
- `dwarf`: El enano es muy fuerte y con una gran resistencia, sin embargo son muy poco ágiles y con poco poder mágico.
- `gnome`: El gnomo es fuerte y con un buen poder mágico pero tienen poca agilidad.

Las clases disponibles son las siguientes:
- `mage`: El mago es una clase enfocada en ataques mágicos. Sin embargo, tiene muy poca resistencia.
- `cleric`: El clérigo es una clase balanceada entre poder mágico y resistencia.
- `paladin`: El paladin es una clase muy resistente con poco poder mágico.
- `warrior`: El guerrero es una clase extremadamente resistente. Sin embargo es incapaz de utilizar armas mágicas.

### Jugabilidad

Una vez iniciado el juego, aparecerás en las tierras de Argentum. Estas son habitadas por zombies que intentarán atacarte.

### Controles

- Movimiento: es posible moverte utilizando las teclas `w`, `a`, `s`, `d`.
- Ataques: es posible atacar a otra critatura haciendo click derecho sobre la misma con el mouse. Distintas armas tienen distinto rango de ataque.
- Recoger ítem: es posible recoger un ítem del piso posicionando tu personaje sobre el mismo y apretando la tecla `h`.
- Tirar item: es posible tirar un item al piso. Para hacerlo primero debes seleccionarlo en tu inventario y luego apretar `b`.
- Interactuar con un NPC: para interactuar con un NPC, debes ubicarte al lado y apretar la tecla `e`.
- Reproducción de música: es posible apagar la reproducción de música con la tecla `m`. Para cambiar de canción es posible utilizar `,` y `.`.

### Inventario

A lo largo del juego conseguirás ítems que te ayudarán a lanzar poderosos ataques o mejorar tu defensa. Una vez obtenido un ítem, este aparecerá en tu inventario. Para poder usarlo es necesario equiparlo.

Para equipar un ítem hacer click izquierdo sobre el mismo para seleccionarlo, luego hacer click derecho en el lugar de equipamiento correspondiente.

### Stats del jugador

Debajo del inventario es posible observar los stats del jugador.

- Oro: es la moneda utilizada en Argentum. Se puede utilizar para comprar ítems de un comerciante. Es posible obtener oro matando criaturas.
- Mana: es tu poder disponible para lanzar ataques mágicos. Se regenera con el tiempo.
- HP: esta es tu vida, si llega a 0 te convertis en fantasma.
- Exp: la experiencia se gana al atacar y matar criaturas del juego. Sirve para subir de nivel.
- Level: tu nivel es una muestra de tu poder, mientras mejor nivel tengas, mejor será tu HP y mana.

### NPC

En el mapa es posible encontrar NPC's que te ayudarán. Para interactuar, debés estar en su rango y apretar la tecla `e`.

- Comerciante: el comerciante vende ítems a cambio de oro. Al interactuar con el mostrará por consola varias opciones de items para comprar. Para elegir uno, simplemente apretar en el teclado el número correspondiente al ítem (dentro del juego, no ingresarlo por consola).
- Sanador: el sanador permite resucitar a un jugador que ha muerto.

### Muerte

Cuando tus puntos de vida llegan a 0 te convertis en fantasma. En este estado es imposible interactuar con el mundo. Para resucitar acercarse a un sanador e interactuar con él.
