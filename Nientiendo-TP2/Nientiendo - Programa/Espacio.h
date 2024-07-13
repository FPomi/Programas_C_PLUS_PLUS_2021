#ifndef ESPACIO_H_
#define ESPACIO_H_

#include "Plano.h"

class Espacio {
private:
	Lista<Plano*>* planos;
public:

	/*
	 * PRE : -
	 * POST: Crea un nuevo espacio.
	 *       Un espacio es un conjunto de planos
	 */
	Espacio();

	/*
	 * PRE : -
	 * POST: Destructor
	 */
	~Espacio();

	/*
	 * PRE : -
	 * POST: Agrega un plano (conjunto de columnas) al espacio
	 */
	void agregarPlano(Plano* plano);

	/*
	 * PRE : -
	 * POST: Devuelve la cantidad de planos en el espacio
	 */
	int getTamanio();

	/*
	 * PRE : Las columnas deben tener todas la misma dimension
	 * POST: Devuelve la cantidad de elementos que tienen las columnas
	 */
	int getDimensionColumna();

	/*
	 * PRE : -
	 * POST: Devuelve un plano a partir de una posicion
	 */
	Plano* getPlano(int posicion);

	/*
	 * PRE : Introducir una coordenada valida
	 * POST: Devuelve una celda en una coordenada dada (x,y,z)
	 */
	std::string getCelda( int x,  int y, int z);

	/*
	 * PRE : La celda debe existir
	 * POST: Cambia el valor de una celda dando sus coordenadas (x,y,z)
	 */
	void setCelda(std::string dato, int x, int y, int z);

	/* NOTA: Para pruebas nada mas, tratar de que la impresion sea desde otro objeto..
	 * PRE : -
	 * POST: Imprime en pantalla el espacio siendo los elemntos mas profundos
	 *       los ultimos en imprimirse (quizas sea mejor que sea al reves)
	 */
	void imprimirEspacio();
};


#endif /* ESPACIO_H_ */
