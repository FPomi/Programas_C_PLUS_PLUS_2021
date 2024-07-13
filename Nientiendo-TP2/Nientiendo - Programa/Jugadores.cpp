#include "Jugadores.h"
#include "Constantes.h"

using namespace std;

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

Jugadores::Jugadores() {
	jugadores = new Lista<Jugador*>;
	idJugadorActual = 1;
	cantidadJugadores = 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

Jugadores::~Jugadores() {
	delete jugadores;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Jugadores::agregarJugador(string ficha) {
	jugadores->agregar(new Jugador(ficha));
	cantidadJugadores++;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

Jugador* Jugadores::getJugadorActual() {
	return jugadores->obtener(idJugadorActual);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Jugadores::pasarJugador(int direccion) {
    if (direccion == ASCENDIENTE){
        idJugadorActual >= cantidadJugadores ? idJugadorActual = 1:idJugadorActual ++;
    } else {
        idJugadorActual <= 1 ? idJugadorActual = cantidadJugadores : idJugadorActual --;
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int Jugadores::getCantidadJugadores() {
	return jugadores->contarElementos();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int Jugadores::getIdJugadorSiguiente() {
	return idJugadorActual >= cantidadJugadores ? 2 : idJugadorActual;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//
