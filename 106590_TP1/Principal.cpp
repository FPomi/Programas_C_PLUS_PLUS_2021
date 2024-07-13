//JUEGO DE 4 EN LINEA//

//http://www.disfrutalasmatematicas.com/juegos/4-en-linea.html//

#include <iostream>

#include "Constantes.h"
#include "Interacciones.h"
#include "Reglas.h"

using namespace std;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int main(){

    int tablero[MAX_FILAS][MAX_COLUMNAS], columnaElegida, fila, jugador = JUG_1;
    bool ganador = false;

    string rutaSalida = "D:/Franco/Facultad/Algoritmos/Programas_C++_2021/106590_TP1/106590_TP1/Archivo_salida.txt";

    cout << "========================================" <<endl;
    cout << "************** 4 EN LINEA **************" <<endl;
    cout << "========================================" <<endl;

    cout<<endl;

    limpiarTablero(tablero);
    mostrarTablero(tablero, rutaSalida);

    do{

        columnaElegida = pedirJugada(tablero, jugador);
        fila = acomodarJugada(tablero, columnaElegida, jugador);

        mostrarTablero(tablero, rutaSalida);

        ganador = busquedaVertical(tablero, columnaElegida, fila, jugador)
                + busquedaHorizontal(tablero, columnaElegida, fila, jugador)
                + busquedaDiagonalDes(tablero, columnaElegida, fila, jugador)
                + busquedaDiagonalAsc(tablero, columnaElegida, fila, jugador);

        if (empate(tablero)){
            break;
        }

        if (jugador == JUG_1){
            jugador = JUG_2;
        }else{
            jugador = JUG_1;
        }

    }while(ganador == false);


    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//
