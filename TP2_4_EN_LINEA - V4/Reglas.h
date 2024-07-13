#ifndef REGLAS_H_
#define REGLAS_H_

#include "Juego.h"

/*
* PRE : -
* POST: Devuelve la cantidad de filas del  tablero
*/
int determinarFilas();

/*
* PRE : -
* POST: Devuelve la cantidad de columnas del tablero
*/
int determinarColumnas();

/*
* PRE : -
* POST: Devuelve la cantidad de planos del tablero
*/
int determinarProfundidad();

/*
* PRE : -
* POST: Devuelve la cantidad de elementos en la columna
*/
int determinarFichasPorCoincidir();

/*
* PRE : -
* POST: Devuelve la cantidad de elementos en la columna
*/
void determinarFichas(Juego *);

#endif // REGLAS_H_
