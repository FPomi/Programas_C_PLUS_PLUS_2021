#ifndef JUGADORES_H_
#define JUGADORES_H_

#include "Jugador.h"
#include "Lista.h"

class Jugadores {
private:
	Lista<Jugador*> *jugadores;
	int idJugadorActual;
	int cantidadJugadores;
public:

	Jugadores();

	~Jugadores();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	void agregarJugador(std::string ficha);

	Jugador* getJugadorActual();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	void pasarJugador(int);

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	int getCantidadJugadores();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	int getIdJugadorSiguiente();
};


#endif /* JUGADORES_H_ */
