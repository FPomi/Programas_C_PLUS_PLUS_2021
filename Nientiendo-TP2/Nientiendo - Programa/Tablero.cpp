#include "Tablero.h"
#include "Constantes.h"

using namespace std;

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

Tablero::Tablero(int numeroDeFilas, int numeroDeColumnas, int numeroDeProfundidad) {

	this->numeroDeFilas = numeroDeFilas;
	this->numeroDeColumnas = numeroDeColumnas;
	this->numeroDeProfundidad = numeroDeProfundidad;

	espacio = new Espacio;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

Tablero::~Tablero() {
	delete espacio;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int Tablero::getNumeroDeFilas() {
	return numeroDeFilas;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int Tablero::getNumeroDeColumnas() {
	return numeroDeColumnas;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int Tablero::getNumeroDeProfundidad() {
	return numeroDeProfundidad;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Tablero::setCelda(string dato, int x, int y, int z) {
	espacio->setCelda(dato, x, y, z);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

string Tablero::getCelda(int x, int y, int z) {
	return espacio->getCelda(x, y, z);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int Tablero::getDimensionColumna() {
	return espacio->getDimensionColumna();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Tablero::iniciarTablero() {
	for(int i = 1; i <= numeroDeProfundidad; i++) {
		Plano* paux = new Plano;
		for(int j = 1; j <= numeroDeColumnas; j++) {
			Columna* caux = new Columna;
			for(int k = 1; k <= numeroDeFilas; k++) {
				caux->agregarCelda(ESPACIO_VACIO);
			}
			paux->agregarColumna(caux);
		}
		espacio->agregarPlano(paux);
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Tablero::mostrarTablero() {
	espacio->imprimirEspacio();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//
