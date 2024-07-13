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

    /*
	 * PRE : Constructor
	 * POST: -
	 */
	Jugadores();

    /*
	 * PRE : -
	 * POST: Destructor
	 */
	~Jugadores();

	/*
	 * PRE : Tiene que existir la ficha del jugador en cuestion
	 * POST: Agrega un nuevo jugador a la lista de jugadores
	 */
	void agregarJugador(std::string ficha);

	Jugador* getJugadorActual();

	/*
	 * PRE : Deben existir una direccion de paso de turnos valida
	 * POST: Cambia al turno del siguiente jugador
	 */
	void pasarJugador(int);

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de jugadores
	 */
	int getCantidadJugadores();

	/*
	 * PRE : -
	 * POST: Devuelve el numero del jugador actual
	 */
	int getIdJugadorSiguiente();
};


#endif /* JUGADORES_H_ */
