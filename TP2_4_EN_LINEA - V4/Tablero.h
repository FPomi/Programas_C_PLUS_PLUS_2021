#ifndef TABLERO_H_
#define TABLERO_H_

#include "Espacio.h"

class Tablero {
private:
	int numeroDeFilas;
	int numeroDeColumnas;
	int numeroDeProfundidad;

	Espacio *espacio;
public:

	/*
	 * PRE : -
	 * POST: Inicia un tablero nuevo indicando cantidad de filas, columna y profundidad.
	 */
	Tablero(int numeroDeFilas, int numeroDeColumnas, int numeroDeProfundidad);

	/*
	 * PRE : -
	 * POST: Destructor
	 */
	~Tablero();

	/*
	 * PRE : -
	 * POST: Devuelve el numero de filas
	 */
	int getNumeroDeFilas();

	/*
	 * PRE : -
	 * POST: Devuelve el numero de columnas
	 */
	int getNumeroDeColumnas();

	/*
	 * PRE : -
	 * POST: Devuelve la profundidad del tablero
	 */
	int getNumeroDeProfundidad();

	/*
	 * PRE : La celda debe existir
	 * POST: Cambia el valor de una celda existente
	 */
	void setCelda(std::string dato, int x, int y, int z);

	/*
	 * PRE : La celda debe existir
	 * POST: Devuelve el valor de un celda dando sus coordenadas
	 */
	std::string getCelda(int x, int y, int z);

	/*
	 * PRE : Las columnas deben tener todas la misma dimension
	 * POST: Devuelve la cantidad de elementos que tienen las columnas
	 */
	int getDimensionColumna();

	/*
	 * PRE : -
	 * POST: Inicia el tablero creandolo y rellenandolo con ceros
	 */
	void iniciarTablero();

	/* NOTA: Solo para pruebas
	 * PRE : -
	 * POST: Imprime en pantalla el trablero
	 */
	void mostrarTablero();
};


#endif /* TABLERO_H_ */
