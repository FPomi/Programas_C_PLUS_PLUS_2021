#ifndef PLANO_H_
#define PLANO_H_

#include <iostream>
#include "Lista.h"
#include "Columna.h"

class Plano {
private:
	Lista<Columna*>* columnas;
public:

	/*
	 * PRE : -
	 * POST: Crea un nuevo plano
	 *       Un plano es un conjunto de columnas
	 */
	Plano();

	/*
	 * PRE : -
	 * POST: Destructor
	 */
	~Plano();

	/*
	 * PRE : -
	 * POST: Agrega una columna al plano
	 */
	void agregarColumna(Columna *columna);

	/*
	 * PRE : -
	 * POST: Devuelva la cantidad de columnas dentro del plano
	 */
	int getTamanio();

	/*
	 * PRE : Todas las columnas deben tener la misma dimension
	 * POST: Devuelve la cantidad de elementos que tienen las columnas
	 */
	int getDimensionColumna();

	/*
	 * PRE : -
	 * POST: Devuelve una columna en particular
	 */
	Columna *getColumna(int posicion);

	/*
	 * PRE : -
	 * POST: Devuelve el valor de una celda dentro del plano
	 */
	std::string getCelda( int x,  int y);

	/*
	 * PRE : La celda debe existir
	 * POST: Cambia el valor de una celda en particular
	 */
	void setCelda( std::string dato, int x,  int y);

	/* Para pruebas, buscar otra alternativa quizas sea mejor..
	 * PRE : -
	 * POST: Imprime en pantalla el plano completo
	 */
	void imprimirPlano();
};


#endif /* PLANO_H_ */
