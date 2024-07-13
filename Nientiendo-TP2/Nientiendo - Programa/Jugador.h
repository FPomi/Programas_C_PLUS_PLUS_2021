#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <iostream>

class Jugador {
private:
	int id;
	std::string ficha;
	bool cartaBloquearTurno; // = t (t : usada, f: disponible)
	bool cartaJuegaDoble;    // "  "
	bool cartaDobleFicha;
	bool cartaInvertirGiro;
	int fichasRestantes;
	int cartasRestantes;

public:
	static int numero;

	/*
	 * PRE : Constructor
	 * POST: -
	 */
	Jugador(std::string ficha);

	int getNumero();

	std::string getFicha();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de cartas en la mano del jugador
	 */
	int getCartasRestantes();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad fichas restantes del jugador
	 */
	int getFichasRestantes();

	/*
	 * PRE : -
	 * POST: Devuelve si el jugador tiene la carta de Bloquear Turno disponible
	 */
	bool getCartaBloquearTurno();

	/*
	 * PRE : -
	 * POST: Devuelve si el jugador tiene la carta de Jugada Doble disponible
	 */
	bool getCartaJuegaDoble();

	/*
	 * PRE : -
	 * POST: Devuelve si el jugador tiene la carta de Doble Ficha disponible
	 */
	bool getCartaDobleFicha();

	/*
	 * PRE : -
	 * POST: Devuelve si el jugador tiene la carta de Invertir Giro disponible
	 */
	bool getCartaInvertirGiro();

	/*
	 * PRE : -
	 * POST: Indica que el jugador utilizo su carta de Bloquear Turno
	 */
	void usarCartaBloquearTurno();

	/*
	 * PRE : -
	 * POST: Indica que el jugador utilizo su carta de Juego Doble
	 */
	void usarCartaJuegaDoble();

	/*
	 * PRE : -
	 * POST: Indica que el jugador utilizo su carta de Doble Ficha
	 */
	void usarCartaDobleFicha();

	/*
	 * PRE : -
	 * POST: Indica que el jugador utilizo su carta de Invertir Giro
	 */
	void usarCartaInvertirGiro();

	/*
	 * PRE : -
	 * POST: Elimina una de las cartas del jugador
	 */
	void restarCarta();

};


#endif /* JUGADOR_H_ */
