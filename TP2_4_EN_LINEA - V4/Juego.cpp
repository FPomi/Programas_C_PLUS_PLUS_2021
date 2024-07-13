#include "Juego.h"
#include "Constantes.h"

using namespace std;

int Jugador::numero = 1;

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

Juego::Juego(int filas, int columnas, int profundidad, int fichasPorCoincidir) {
	tablero = new Tablero(filas, columnas, profundidad);
	tablero->iniciarTablero();

	jugadores = new Jugadores;

	direccion = ASCENDIENTE;

	this->fichasPorCoincidir = fichasPorCoincidir;

	finDeJuego = false;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

Juego::~Juego() {
	delete tablero;
	delete jugadores;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::colocarFicha(string ficha, int columna, int profundidad) {
	int finDeColumna = tablero->getDimensionColumna();
	bool ganadorEncontrado = false, fichaColocada = true;

	while((tablero->getCelda(columna, finDeColumna, profundidad) != ESPACIO_VACIO) && finDeColumna >= MIN_COLUMNA) {
		finDeColumna--;
	}

	if(finDeColumna < MIN_COLUMNA) {
		fichaColocada = false;
	}else{

        tablero->setCelda(ficha, columna, finDeColumna, profundidad);

        ganadorEncontrado = buscarGanadorX(columna, finDeColumna, profundidad, ficha) + buscarGanadorY(columna, finDeColumna, profundidad, ficha) +
                            buscarGanadorZ(columna, finDeColumna, profundidad, ficha) + buscarGanadorDiagonalA(columna, finDeColumna, profundidad, ficha) +
                            buscarGanadorDiagonalB(columna, finDeColumna, profundidad, ficha) + buscarGanadorDiagonalC(columna, finDeColumna, profundidad, ficha) +
                            buscarGanadorDiagonalD(columna, finDeColumna, profundidad, ficha) + buscarGanadorDiagonalE(columna, finDeColumna, profundidad, ficha) +
                            buscarGanadorDiagonalF(columna, finDeColumna, profundidad, ficha) + buscarGanadorDiagonalG(columna, finDeColumna, profundidad, ficha) +
                            buscarGanadorDiagonalH(columna, finDeColumna, profundidad, ficha);

        if(ganadorEncontrado) {
            cout << endl <<"            **** Gano el Jugador " << jugadores->getJugadorActual()->getNumero() << " ****" << endl << endl;
            finDeJuego = true;
        }
	}

	return fichaColocada;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Juego::mostrarTablero() {
	tablero->mostrarTablero();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Juego::agregarJugador(string ficha) {
	jugadores->agregarJugador(ficha);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

Jugador* Juego::getJugadorActual() {
	return jugadores->getJugadorActual();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Juego::pasarJugador(int direccion) {
	jugadores->pasarJugador(direccion);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

Tablero* Juego::getTablero() {
	return tablero;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Juego::seleccionarColumna(int columna, int profundidad, int cartaSeleccionada) {
	if(columna > VACIO && columna <= tablero->getDimensionColumna()) {

		if(this->colocarFicha(jugadores->getJugadorActual()->getFicha(), columna, profundidad)) {

			if(cartaSeleccionada == DOBLE_FICHA) {
				this->colocarFicha(jugadores->getJugadorActual()->getFicha(), columna, profundidad);
			}

			if(cartaSeleccionada != JUGAR_NUEVAMENTE) {
				jugadores->pasarJugador(direccion);
			}

		} else {
			cout << "Columna completa, selecciona otra" << endl;
		}
	} else {
		cout << "** La columna debe estar entre 1 y " << tablero->getDimensionColumna()  << " ** " << endl;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int Juego::pedirCarta() {
	int cartaSeleccionada = NINGUNA;
	bool usarCarta = false;

	cout << "________________________________________________" << endl << endl;
	cout << "Turno de jugador: " << jugadores->getJugadorActual()->getNumero() << ", ficha " << jugadores->getJugadorActual()->getFicha()<< endl;
	cout << "Cartas restantes: " << jugadores->getJugadorActual()->getCartasRestantes() << endl;

	while(!usarCarta) {
		if(jugadores->getJugadorActual()->getCartasRestantes() > VACIO) {

			cout << "   1) [Carta Bloquear Turno]";

			if(jugadores->getJugadorActual()->getCartaBloquearTurno()) {
				cout << " ------> (NO DISPONIBLE)";
			}

			cout << endl << "   2) [Carta Juega Doble]";

			if(jugadores->getJugadorActual()->getCartaJuegaDoble()) {
				cout << " -------- > (NO DISPONIBLE)";
			}

			cout << endl << "   3) [Carta Doble Ficha]";

			if(jugadores->getJugadorActual()->getCartaDobleFicha()) {
				cout << " ---------> (NO DISPONIBLE)";
			}

			cout << endl << "   4) [Carta Invertir Giro]";

			if(jugadores->getJugadorActual()->getCartaInvertirGiro()) {
				cout << " ---------> (NO DISPONIBLE)";
			}

			cout << endl << "   0) [No usar carta]";

			cout << endl << "  Ingresar carta       > ";

			cin >> cartaSeleccionada;



            //PUEDE PONERSE UN SWITCH (ABAJO)

			if(cartaSeleccionada == SALTEAR_TURNO) {
				if(!jugadores->getJugadorActual()->getCartaBloquearTurno()) {
					jugadores->getJugadorActual()->usarCartaBloquearTurno();
					jugadores->getJugadorActual()->restarCarta();
					usarCarta = true;
				} else {
					cartaSeleccionada = NINGUNA;
				}

			} else if(cartaSeleccionada == JUGAR_NUEVAMENTE) {

				if(!jugadores->getJugadorActual()->getCartaJuegaDoble()) {
					jugadores->getJugadorActual()->usarCartaJuegaDoble();
					jugadores->getJugadorActual()->restarCarta();
					usarCarta = true;
				} else {
					cartaSeleccionada = NINGUNA;
				}
			} else if(cartaSeleccionada == DOBLE_FICHA) {

				if(!jugadores->getJugadorActual()->getCartaDobleFicha()) {
					jugadores->getJugadorActual()->usarCartaDobleFicha();
					jugadores->getJugadorActual()->restarCarta();
					usarCarta = true;
				} else {
					cartaSeleccionada = NINGUNA;
				}
			} else if(cartaSeleccionada == INVERTIR_GIRO) {

				if(!jugadores->getJugadorActual()->getCartaInvertirGiro()) {
					jugadores->getJugadorActual()->usarCartaInvertirGiro();
					jugadores->getJugadorActual()->restarCarta();
					usarCarta = true;
				} else {
					cartaSeleccionada = NINGUNA;
				}
			} else if(cartaSeleccionada == SALIR) {
				usarCarta = true;
			}

		} else {
			usarCarta = true;
			cartaSeleccionada = NINGUNA;
		}
	}

	return cartaSeleccionada;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Juego::pedirPosicionesFicha(int cartaSeleccionada, int* input){

    cout << "  Ingresar columna     > ";
    cin >> *input;
    int x = *input;

    cout << "  Ingresar profundidad > ";
    cin >> *input;
    int z = *input;

    seleccionarColumna(x, z, cartaSeleccionada);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Juego::interaccionesCartas(int cartaSeleccionada, int* input){

    if(cartaSeleccionada == SALTEAR_TURNO) {
        cout << "El jugador " << getIdJugadorSiguiente() + 1 << " pierde un turno" << endl;
        pasarJugador(direccion);
    }

    if(cartaSeleccionada == JUGAR_NUEVAMENTE) {
        mostrarTablero();

        cout << "Jugador " << getJugadorActual()->getNumero() << " juega nuevamente: " << endl;

        pedirPosicionesFicha(cartaSeleccionada, &*input);

        pasarJugador(direccion);
    }

    if (cartaSeleccionada == INVERTIR_GIRO){
        direccion = (direccion == ASCENDIENTE ? DESCENDIENTE : ASCENDIENTE);
        /*
         * Como se llama 'pedirPosicionesFicha' antes que 'interaccionesCartas', se pasa un jugador, antes desde pedirPosicionesFicha
         * llamo dos veces, 1ero vuelve al jugador actual y despues retrocede
         */
        pasarJugador(direccion);
        pasarJugador(direccion);
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int Juego::getCantidadJugadores() {
	return jugadores->getCantidadJugadores();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int Juego::getIdJugadorSiguiente() {
	return jugadores->getIdJugadorSiguiente();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::buscarGanadorX(int x, int y, int z, string ficha) {
	int dimension = tablero->getNumeroDeColumnas();
	bool conexion = false;
	int contador = 0;

	for(int i = 1; i <= dimension; i++) {
		if(conexion) {
			if(tablero->getCelda(i, y, z) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(i, y, z) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}
	}

	return false;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::buscarGanadorY(int x, int y, int z, string ficha) {
	int dimension = tablero->getNumeroDeFilas();
	bool conexion = false;
	int contador = 0;

	for(int i = 1; i <= dimension; i++) {
		if(conexion) {
			if(tablero->getCelda(x, i, z) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(x, i, z) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}
	}

	return false;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::buscarGanadorZ(int x, int y, int z, string ficha) {
	int dimension = tablero->getNumeroDeProfundidad();
	bool conexion = false;
	int contador = 0;

	for(int i = 1; i <= dimension; i++) {
		if(conexion) {
			if(tablero->getCelda(x, y, i) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(x, y, i) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}
	}

	return false;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::buscarGanadorDiagonalA(int x, int y, int z, string ficha) {
	bool conexion = false;
	int contador = 0;

	int xA, yA, zA;
	int xB, yB, zB;

	xA = x;
	yA = y;
	zA = z;

	while(xA > 1 && yA < tablero->getNumeroDeFilas() && zA > 1) {
		xA--;
		yA++;
		zA--;
	}

	xB = xA;
	yB = yA;
	zB = zA;

	while(xB <= tablero->getNumeroDeColumnas() && yB >= 1 && zB <= tablero->getNumeroDeProfundidad()) {

		if(conexion) {
			if(tablero->getCelda(xB, yB, zB) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(xB, yB, zB) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}

		xB++;
		yB--;
		zB++;
	}

	return false;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::buscarGanadorDiagonalB(int x, int y, int z, string ficha) {
	bool conexion = false;
	int contador = 0;

	int xA, yA, zA;
	int xB, yB, zB;

	xA = x;
	yA = y;
	zA = z;

	while(xA < tablero->getNumeroDeColumnas() && yA < tablero->getNumeroDeFilas() && zA < tablero->getNumeroDeProfundidad()) {
		xA++;
		yA++;
		zA++;
	}

	xB = xA;
	yB = yA;
	zB = zA;

	while(xB >= 1 && yB >= 1 && zB >= 1) {

		if(conexion) {
			if(tablero->getCelda(xB, yB, zB) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(xB, yB, zB) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}

		xB--;
		yB--;
		zB--;
	}

	return false;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::buscarGanadorDiagonalC(int x, int y, int z, string ficha) {
	bool conexion = false;
	int contador = 0;

	int xA, yA, zA;
	int xB, yB, zB;

	xA = x;
	yA = y;
	zA = z;

	while(xA < tablero->getNumeroDeColumnas() && yA > 1 && zA > 1) {
		xA++;
		yA--;
		zA--;
	}

	xB = xA;
	yB = yA;
	zB = zA;

	while(xB >= 1 && yB <= tablero->getNumeroDeFilas() && zB <= tablero->getNumeroDeProfundidad()) {

		if(conexion) {
			if(tablero->getCelda(xB, yB, zB) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(xB, yB, zB) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}

		xB--;
		yB++;
		zB++;
	}

	return false;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::buscarGanadorDiagonalD(int x, int y, int z, string ficha) {
	bool conexion = false;
	int contador = 0;

	int xA, yA, zA;
	int xB, yB, zB;

	xA = x;
	yA = y;
	zA = z;

	while(xA > 1 && yA > 1 && zA < tablero->getNumeroDeProfundidad()) {
		xA--;
		yA--;
		zA++;
	}

	xB = xA;
	yB = yA;
	zB = zA;

	while(xB <= tablero->getNumeroDeColumnas() && yB <= tablero->getNumeroDeFilas() && zB >= 1) {

		if(conexion) {
			if(tablero->getCelda(xB, yB, zB) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(xB, yB, zB) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}

		xB++;
		yB++;
		zB--;
	}

	return false;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::buscarGanadorDiagonalE(int x, int y, int z, string ficha) {
	bool conexion = false;
	int contador = 0;

	int yA, zA;
	int yB, zB;

	yA = y;
	zA = z;

	while(yA > 1 && zA < tablero->getNumeroDeProfundidad()) {
		yA--;
		zA++;
	}

	yB = yA;
	zB = zA;

	while(yB <= tablero->getNumeroDeFilas() && zB >= 1) {

		if(conexion) {
			if(tablero->getCelda(x, yB, zB) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(x, yB, zB) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}

		yB++;
		zB--;
	}

	return false;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::buscarGanadorDiagonalF(int x, int y, int z, string ficha) {
	bool conexion = false;
	int contador = 0;

	int yA, zA;
	int yB, zB;

	yA = y;
	zA = z;

	while(yA < tablero->getNumeroDeFilas() && zA < tablero->getNumeroDeProfundidad()) {
		yA++;
		zA++;
	}

	yB = yA;
	zB = zA;

	while(yB >= 1 && zB >= 1) {

		if(conexion) {
			if(tablero->getCelda(x, yB, zB) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(x, yB, zB) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}

		yB--;
		zB--;
	}

	return false;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::buscarGanadorDiagonalG(int x, int y, int z, string ficha) {
	bool conexion = false;
	int contador = 0;

	int xA, yA;
	int xB, yB;

	xA = x;
	yA = y;

	while(xA < tablero->getNumeroDeColumnas() && yA > 1) {
		xA++;
		yA--;
	}

	xB = xA;
	yB = yA;

	while(xB >= 1 && yB <= tablero->getNumeroDeFilas()) {

		if(conexion) {
			if(tablero->getCelda(xB, yB, z) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(xB, yB, z) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}

		xB--;
		yB++;
	}

	return false;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::buscarGanadorDiagonalH(int x, int y, int z, string ficha) {

	bool conexion = false;
	int contador = 0;

	int xA, yA;
	int xB, yB;

	xA = x;
	yA = y;

	while(xA < tablero->getNumeroDeColumnas() && yA < tablero->getNumeroDeFilas()) {
		xA++;
		yA++;
	}

	xB = xA;
	yB = yA;

	while(xB >= 1 && yB >= 1) {

		if(conexion) {
			if(tablero->getCelda(xB, yB, z) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(xB, yB, z) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}

		xB--;
		yB--;
	}

	return false;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Juego::juegoFinalizado() {
	return finDeJuego;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

