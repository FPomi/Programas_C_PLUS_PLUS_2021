#include <iostream>
#include <fstream>

#include "Interacciones.h"
#include "Constantes.h"

using namespace std;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void limpiarTablero(int tablero[MAX_FILAS][MAX_COLUMNAS]){

    for (int a = 0; a < MAX_FILAS; a++){
        for (int i = 0; i < MAX_COLUMNAS; i++){
            tablero[a][i] = VACIO;
        }
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void mostrarTablero(int tablero[MAX_FILAS][MAX_COLUMNAS], string rutaSalida){

    /* abre un archivo de salida */

	ofstream salida;
	salida.open(rutaSalida.c_str());

	cout<<endl;

    for(int i = 0; i < MAX_FILAS; i++){

        cout<<"     ";

        for(int a = 0; a < MAX_COLUMNAS; a++){

            if(tablero[i][a] == JUG_1){
                cout<<SIG_JUG_1;
                salida<<SIG_JUG_1;

            }else{

                if(tablero[i][a] == JUG_2){
                    cout<<SIG_JUG_2;
                    salida<<SIG_JUG_2;

                }else{
                    cout<<SIG_VACIO;
                    salida<<SIG_VACIO;
                }
            }
        }
        cout<<endl;
        salida<<endl;
    }

    /* cierra el archivo, liberando el recurso */
	salida.close();
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int pedirJugada(int tablero[MAX_FILAS][MAX_COLUMNAS], int jugador){

    int columnaElegida;

    cout<<"     ==============================\n"<<endl;
    cout<<" Jugador N"<<jugador<<" elija un numero del 1 al "<<MAX_COLUMNAS<<": ";
    cin>>columnaElegida;

    columnaElegida--;

    while(columnaElegida < 0 || columnaElegida > MAX_COLUMNAS - 1 || tablero[0][columnaElegida] != VACIO){
        cout<<"No puede usarse esa columna, intente otra: ";
        cin>>columnaElegida;

        columnaElegida--;
    }

    cout<<endl;

    return columnaElegida;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int acomodarJugada(int tablero[MAX_FILAS][MAX_COLUMNAS], int columna, int jugador){

    bool casilleroVacio = false;
    int fila;

    for(int i = MAX_FILAS - 1; casilleroVacio == false; i--){
        if (tablero[i][columna] == VACIO){
                tablero[i][columna] = jugador;
                fila = i;
                casilleroVacio = true;
        }
    }

    return fila;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//
