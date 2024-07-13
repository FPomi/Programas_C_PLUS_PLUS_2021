#ifndef JUEGO_H_
#define JUEGO_H_

#include "Tablero.h"
#include "Jugadores.h"

class Juego {

private:
    int fichasPorCoincidir, direccion;
	bool finDeJuego;

	Tablero *tablero;
	Jugadores *jugadores;

public:

	/*
	 * PRE : -
	 * POST: Inicia un nuevo juego
	 */
	Juego(int filas, int columnas, int profundidad, int fichasPorCoincidir);

	/*
	 * PRE : -
	 * POST: Destructor
	 */
	~Juego();

	/*
	 * PRE : La fila, columna y profundidad deben existir y ser validas
	 * POST: Coloca una ficha en el tablero, devuelve false si la columna esta completa
	 */
	bool colocarFicha(std::string ficha, int columna, int profundidad);

	/*
	 * PRE : -
	 * POST: Muestra el tablero en pantalla
	 */
	void mostrarTablero();

	/*
	 * PRE : -
	 * POST: Agrega un jugador a la lista de jugadores
	 */
	void agregarJugador(std::string ficha);

	/*
	 * PRE : -
	 * POST: Devuelve el jugador en curso
	 */
	Jugador* getJugadorActual();

	/*
	 * PRE : Deben existir una direccion de paso de turnos valida
	 * POST: Pasa al turno del siguiente jugador
	 */
	void pasarJugador(int);

	/*
	 * PRE : -
	 * POST: Devuelve el estado actual del tablero
	 */
	Tablero* getTablero();

	/*
	 * PRE : -
	 * POST: Devuelve que carta quiere utilizar el jugador
	 */
	int pedirCarta();

	/*
	 * PRE : La columna, profundidad y carta seleccionada por el jugador deben ser validos
	 * POST: Corrobora si es posible usar la columna y profundidad donde colocar una ficha
	 */
	void seleccionarColumna(int columna, int profundidad, int cartaSeleccionada);

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de jugadores
	 */
	int getCantidadJugadores();

	/*
	 * PRE : -
	 * POST: Devuelve el numero del jugador siguiente al actual
	 */
	int getIdJugadorSiguiente();

	/*
	 * PRE : Introducir una coordenada y ficha valida
	 * POST: Indica si se encontro un ganador de forma horizontal en la misma profundidad
	 */
	bool buscarGanadorX(int x, int y, int z, std::string ficha);

	/*
	 * PRE : Introducir una coordenada y ficha valida
	 * POST: Indica si se encontro un ganador de forma vertical en la misma profundidad
	 */
    bool buscarGanadorY(int x, int y, int z, std::string ficha);

    /*
	 * PRE : Introducir una coordenada y ficha valida
	 * POST: Indica si se encontro un ganador de forma horizontal en varias profundidades
	 */
    bool buscarGanadorZ(int x, int y, int z, std::string ficha);

    /*
	 * PRE : Introducir una coordenada y ficha valida
	 * POST: Indica si se encontro un ganador de forma diagonal en la misma profundidad
	 */
    bool buscarGanadorDiagonalA(int x, int y, int z, std::string ficha);

    /*
	 * PRE : Introducir una coordenada y ficha valida
	 * POST: Indica si se encontro un ganador de forma diagonal en la misma profundidad
	 */
    bool buscarGanadorDiagonalB(int x, int y, int z, std::string ficha);

    /*
	 * PRE : Introducir una coordenada y ficha valida
	 * POST: Indica si se encontro un ganador de forma diagonal en profundidades diferentes
	 */
    bool buscarGanadorDiagonalC(int x, int y, int z, std::string ficha);

    /*
	 * PRE : Introducir una coordenada y ficha valida
	 * POST: Indica si se encontro un ganador de forma diagonal en profundidades diferentes
	 */
    bool buscarGanadorDiagonalD(int x, int y, int z, std::string ficha);

    /*
	 * PRE : Introducir una coordenada y ficha valida
	 * POST: Indica si se encontro un ganador de forma diagonal en profundidades diferentes
	 */
    bool buscarGanadorDiagonalE(int x, int y, int z, std::string ficha);

    /*
	 * PRE : Introducir una coordenada y ficha valida
	 * POST: Indica si se encontro un ganador de forma diagonal en profundidades diferentes
	 */
    bool buscarGanadorDiagonalF(int x, int y, int z, std::string ficha);

    /*
	 * PRE : Introducir una coordenada y ficha valida
	 * POST: Indica si se encontro un ganador de forma diagonal en profundidades diferentes
	 */
    bool buscarGanadorDiagonalG(int x, int y, int z, std::string ficha);

    /*
	 * PRE : Introducir una coordenada y ficha valida
	 * POST: Indica si se encontro un ganador de forma diagonal en profundidades diferentes
	 */
    bool buscarGanadorDiagonalH(int x, int y, int z, std::string ficha);

    /*
	 * PRE : La carta seleccionada debe ser valida
	 * POST: Pide la columna y profundidad en la cual se va a colocar la ficha del jugador
	 */
    void pedirPosicionesFicha(int, int*);

    /*
	 * PRE : La carta seleccionada debe ser valida
	 * POST: Dependiendo de la carta eleccionada se producira el efecto de la carta seleccionada
	 */
    void interaccionesCartas(int, int*);

    /*
	 * PRE : -
	 * POST: Detiene el juego
	 */
	bool juegoFinalizado();

};

#endif /* JUEGO_H_ */
