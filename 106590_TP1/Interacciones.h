#ifndef INTERACCIONES_H_
#define INTERACCIONES_H_

#include <string>

#include "Constantes.h"

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/*
*   Camabia todos los valores del tablero a valores de vacio
*/

void limpiarTablero(int tablero[MAX_FILAS][MAX_COLUMNAS]);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/*
*   Muestra en la consola el estado actual del juego y lo guarda en un .txt
*/

void mostrarTablero(int tablero[MAX_FILAS][MAX_COLUMNAS], std::string rutaSalida);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/*
*   Le pide al jugador que ingrese la columna que quiere poner su ficha
*/

int pedirJugada(int tablero[MAX_FILAS][MAX_COLUMNAS], int jugador);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/*
*   Acomoda la ficha del jugador en la fila correspondiente de la columna que eligió
*/

int acomodarJugada(int tablero[MAX_FILAS][MAX_COLUMNAS], int columna, int jugador);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

#endif // INTERACCIONES_H_
