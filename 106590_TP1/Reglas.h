#ifndef REGLAS_H_
#define REGLAS_H_

#include "Constantes.h"

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/*
*   Busca si hay 4 o mas fichas iguales en forma Vertical
*/

bool busquedaVertical(int tablero[MAX_FILAS][MAX_COLUMNAS], int columna, int fila, int jugador);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/*
*   Busca si hay 4 o mas fichas iguales en forma Horizontal
*/

bool busquedaHorizontal(int tablero[MAX_FILAS][MAX_COLUMNAS], int columna, int fila, int jugador);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/*
*   Busca si hay 4 o mas fichas iguales en forma de una diagonal descendiente
*/

bool busquedaDiagonalDes(int tablero[MAX_FILAS][MAX_COLUMNAS], int columna, int fila, int jugador);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/*
*   Busca si hay 4 o mas fichas iguales en forma de una diagonal ascendiente
*/

bool busquedaDiagonalAsc(int tablero[MAX_FILAS][MAX_COLUMNAS], int columna, int fila, int jugador);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/*
*   Revisa si es que ya no pueden hacerse mas jugadas, indicando un empate
*/

bool empate(int tablero [MAX_FILAS][MAX_COLUMNAS]);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

#endif // REGLAS_H_
