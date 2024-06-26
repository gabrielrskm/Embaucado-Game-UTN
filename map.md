# Código de Juego en C++

## Funciones principales

### game
- Limpiar pantalla
- Declarar variables
  - `player1`, `player2`
  - `pointP1[3]`, `pointP2[3]`
  - `discountP1[2]`, `discountP2[2]`
- Obtener nombres de los jugadores
- Ejecutar turnos
  - `firstTurn`
  - `secondTurn`
  - `thirdTurn`
- Mostrar resultado
- Final del juego

### stats
- Limpiar pantalla

### credits
- Limpiar pantalla

## Función main
- Configurar salida UTF-8
- Limpiar pantalla
- Declarar variables
  - `score[100]`
  - `option`
- Ciclo principal
  - `introduction`
  - Ejecutar según la opción
    - `game(score)`
    - `stats()`
    - `credits()`
- Limpiar pantalla
- Retornar 0

## Funciones auxiliares

### sumPoints
- Declarar y asignar valores a `points[20]`
- Asignar puntos a los jugadores según `deck` y `specialDeck`

### shuffleCards
- Declarar y asignar valores a `sortDek[20]`
- Declarar y asignar valores a `unsortDeck[10]`
- Barajar las cartas y asignarlas a `deck`
- Determinar `specialDeck`

### getNames
- Mostrar introducción
- Obtener nombres de jugadores
- Confirmar nombres

### firstTurn
- Barajar cartas
- Mostrar estado inicial
- Sumar puntos
- Mostrar puntos
- Continuar a la siguiente ronda

### secondTurn
- Barajar cartas
- Mostrar estado inicial
- Verificar y cambiar carta embaucadora
- Sumar puntos
- Mostrar puntos
- Continuar a la siguiente ronda

### thirdTurn
- Barajar cartas
- Mostrar estado inicial
- Verificar y cambiar carta embaucadora
- Sumar puntos
- Mostrar puntos
- Continuar a la siguiente ronda

### showCard
- Devolver carta en formato de string

### showSumPoints
- Sumar puntos de las cartas

### showStage
- Mostrar estado del juego

### showPoints
- Mostrar puntos de los jugadores

### showResult
- Mostrar resultado final del juego