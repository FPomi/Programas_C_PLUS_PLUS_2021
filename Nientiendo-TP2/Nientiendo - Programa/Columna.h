#ifndef COLUMNA_H_
#define COLUMNA_H_

#include "Lista.h"
#include <iostream>

class Columna {
private:
	Lista<std::string> *celdas;
public:

	/*
	 * PRE : -
	 * POST: Crea una nueva columna
	 */
	Columna();

	/*
	 * PRE : -
	 * POST: Destructor
	 */
	~Columna();

	/*
	 * PRE : El dato ingresado sea de tipo 'int'
	 * POST: Agrega una nueva celda a la columna
	 */
	void agregarCelda(std::string dato);

	/*
	 * PRE : El dato ingresado sea de tipo 'int'
	 *       La posicion debe estar entre 1 y la cantidad de elementos en la columna
	 * POST: Agrega una celda en una posicion especifica
	 */
	void agregarCelda(std::string dato, int posicion);

	/*
	 * PRE : El dato ingresado sea de tipo 'int'
	 *       La posicion debe estar entre 1 y la cantidad de elementos en la columna
	 * POST: Cambia el valor de una celda especifica
	 */
	void setCelda(std::string dato, int posicion);

	/*
	 * PRE : La posicion debe estar entre 1 y la cantidad de elementos en la columna
	 * POST: Devuelve el valor de una celda
	 */
	std::string getCelda( int posicion);

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	int getTamanio();
};


#endif /* COLUMNA_H_ */
