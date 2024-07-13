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

	Jugador(std::string ficha);

	int getNumero();

	std::string getFicha();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	int getCartasRestantes();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	int getFichasRestantes();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	bool getCartaBloquearTurno();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	bool getCartaJuegaDoble();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	bool getCartaDobleFicha();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	bool getCartaInvertirGiro();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	void usarCartaBloquearTurno();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	void usarCartaJuegaDoble();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	void usarCartaDobleFicha();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	void usarCartaInvertirGiro();

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de elementos en la columna
	 */
	void restarCarta();

};


#endif /* JUGADOR_H_ */
