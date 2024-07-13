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
	 * PRE : La fila y columna debe existir
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
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	void pasarJugador(int);

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	Tablero* getTablero();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	int pedirCarta();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	void seleccionarColumna(int columna, int profundidad, int cartaSeleccionada);

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

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	bool buscarGanadorX(int x, int y, int z, std::string ficha);

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
    bool buscarGanadorY(int x, int y, int z, std::string ficha);

    /*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
    bool buscarGanadorZ(int x, int y, int z, std::string ficha);

    /*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
    bool buscarGanadorDiagonalA(int x, int y, int z, std::string ficha);

    /*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
    bool buscarGanadorDiagonalB(int x, int y, int z, std::string ficha);

    /*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
    bool buscarGanadorDiagonalC(int x, int y, int z, std::string ficha);

    /*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
    bool buscarGanadorDiagonalD(int x, int y, int z, std::string ficha);

    /*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
    bool buscarGanadorDiagonalE(int x, int y, int z, std::string ficha);

    /*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
    bool buscarGanadorDiagonalF(int x, int y, int z, std::string ficha);

    /*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
    bool buscarGanadorDiagonalG(int x, int y, int z, std::string ficha);

    /*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
    bool buscarGanadorDiagonalH(int x, int y, int z, std::string ficha);

    /*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
    void pedirPosicionesFicha(int, int*);

    /*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
    void interaccionesCartas(int, int*);

    /*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	bool juegoFinalizado();

};

#endif /* JUEGO_H_ */
