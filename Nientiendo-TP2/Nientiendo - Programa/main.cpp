#include <iostream>

#include "Juego.h"
#include "Constantes.h"
#include "Reglas.h"

using namespace std;

int main() {

    int maxFilas = determinarFilas();
    int maxColumnas = determinarColumnas();
    int maxProfundidad = determinarProfundidad();
    int maxFichasPorCoincidir = determinarFichasPorCoincidir();

	Juego juego(maxFilas, maxColumnas, maxProfundidad, maxFichasPorCoincidir);
	int input = -1;

	determinarFichas(&juego);

	while(input != VALIDO && !juego.juegoFinalizado()) {
		int cartaSeleccionada = NINGUNA;

		cartaSeleccionada = juego.pedirCarta();

		juego.pedirPosicionesFicha(cartaSeleccionada, &input);
		juego.interaccionesCartas (cartaSeleccionada, &input);

		juego.mostrarTablero();
	}

	return 0;
}
