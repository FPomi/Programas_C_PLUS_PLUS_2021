#include <iostream>
#include <string>

#include "Juego.h"
#include "Reglas.h"
#include "Constantes.h"

using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int determinarFilas(){

    int maxFilas = VACIO;

    cout<<" Cuantas filas tendra el tablero?: ";
    cin>> maxFilas ;

    while (maxFilas <= VACIO){
        cout<<" Cantidad de filas invalida, ingrese de nuevo: " ;
        cin>> maxFilas ;
    }

    return maxFilas;

}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int determinarColumnas(){

    int maxColumnas = VACIO;

    cout<<" Cuantas Columnas tendra el tablero?: ";
    cin>> maxColumnas;

    while (maxColumnas <= VACIO){
        cout<<" Cantidad de columnas invalida, ingrese de nuevo: ";
        cin>> maxColumnas;
    }

    return maxColumnas;

}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int determinarProfundidad(){

    int maxProfundidad = VACIO;

    cout<<" Cuantos planos de profundidad tendra el tablero?: ";
    cin>> maxProfundidad;

    while (maxProfundidad <= VACIO){
        cout<<" Cantidad de planos de profundidad invalida, ingrese de nuevo: ";
        cin>> maxProfundidad;
    }

    return maxProfundidad;

}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int determinarFichasPorCoincidir(){

    int maxFichas = VACIO;

    cout<<" Cuantos fichas tienen que coincidir para ganar?: ";
    cin>> maxFichas;

    while (maxFichas <= VACIO){
        cout<<" Cantidad fichas a coincidir invalida, ingrese de nuevo: ";
        cin>> maxFichas;
    }

    return maxFichas;

}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void determinarFichas(Juego *juego){

    string ficha;

    cout << "\nIngresar fichas (caracter) para cada jugador" << endl << "[0 para terminar]" << endl;

	while(ficha != CONTINUAR) {
		cout << "Ingresar ficha para jugador " << juego->getCantidadJugadores() + 1 << ": ";
		cin >> ficha;

		if(ficha != CONTINUAR) {
			juego->agregarJugador(ficha);
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//
