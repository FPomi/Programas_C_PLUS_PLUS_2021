#include <iostream>

#include "Reglas.h"
#include "Constantes.h"

using namespace std;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool busquedaVertical(int tablero[MAX_FILAS][MAX_COLUMNAS], int columna, int fila, int jugador){

    //Vertical
    bool encontrado = false, ganador = false;
    int total = 0;

    for(int i = 0; i < MAX_FILAS; i++){

        if(encontrado){

            if(tablero[i][columna] == jugador){
                total++;
            }else{
                encontrado = false;
                total = 0;
            }
        }

        if(tablero[i][columna] == jugador && !encontrado){
            encontrado = true;
            total++;
        }

        if(total == PUNT_GANAR){
            cout<<"El jugador "<<jugador<<" gana!"<<endl;
            ganador = true;
            break;
        }
    }
    return ganador;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool busquedaHorizontal(int tablero[MAX_FILAS][MAX_COLUMNAS], int columna, int fila, int jugador){

    //Horizontal
    bool encontrado = false, ganador = false;
    int total = 0;

    for(int i = 0; i < MAX_COLUMNAS; i++){

        if(encontrado){

            if(tablero[fila][i] == jugador){
                total++;
            }else{
                encontrado = false;
                total = 0;
            }
        }

        if(tablero[fila][i] == jugador && !encontrado){
            encontrado = true;
            total++;
        }

        if(total == PUNT_GANAR){
            cout<<"El jugador "<<jugador<<" gana!"<<endl;
            ganador = true;
            break;
        }
    }
    return ganador;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool busquedaDiagonalDes(int tablero[MAX_FILAS][MAX_COLUMNAS], int columna, int fila, int jugador){

    //Diagonal descendiente

    bool encontrado = false, ganador = false;
    int total = 0;

    while((fila != 0 || columna != 0))
    {
        fila--;
        columna--;

        if(fila == 0 || columna == 0)
        break;
    }

    do
    {
        if(fila >= MAX_FILAS){
            break;
        }

        if(encontrado){

            if(tablero[fila][columna] == jugador){
                total++;
            }else{
                encontrado = false;
                total = 0;
            }
        }

        if(tablero[fila][columna] == jugador && !encontrado){
            encontrado = true;
            total++;
        }

        if(total == PUNT_GANAR){
            cout<<"El jugador "<<jugador<<" gana!"<<endl;
            ganador = true;
            break;
        }
        fila++;
        columna++;

    }while(fila < MAX_FILAS);

    return ganador;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool busquedaDiagonalAsc(int tablero[MAX_FILAS][MAX_COLUMNAS], int columna, int fila, int jugador){

    //Diagonal ascendiente

    bool encontrado = false, ganador = false;
    int total = 0;

    while((fila != 0 || columna != MAX_COLUMNAS)){
        fila--;
        columna++;

        if(fila == 0 || columna == MAX_COLUMNAS){
            break;
        }
    }

     do
    {
        if(fila >= MAX_FILAS){
            break;
        }

        if(encontrado){

            if(tablero[fila][columna] == jugador){
                total++;
            }else{
                encontrado = false;
                total = 0;
            }
        }

        if(tablero[fila][columna] == jugador && !encontrado){
            encontrado = true;
            total++;
        }

        //cout<<"total: "<<total<<endl;
        if(total == PUNT_GANAR){
            cout<<"El jugador "<<jugador<<" gana!"<<endl;
            ganador = true;
            break;
        }

        fila++;
        columna--;

    }while(fila < MAX_FILAS);

    return ganador;

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool empate(int tablero [MAX_FILAS][MAX_COLUMNAS]){

    int contador = 0;
    bool lleno = false;

    for (int i = 0; i < MAX_COLUMNAS; i++){
        if (tablero[0][i] != VACIO){
            contador ++;
        }
    }

    if(contador == MAX_COLUMNAS){
        lleno = true;
        cout<<"Empate"<<endl;
    }

    return lleno;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//
