/*
 * Carro.h
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

#ifndef CARRO_H_
#define CARRO_H_

#include "Thread.h"
#include "Parque.h"

class Carro: public Thread {
public:
	Carro(Parque &p);
	virtual ~Carro();
	void esperaEncher();
	void daUmaVolta();
	void esperaEsvaziar();
	int getNVoltas();
	int getNumPassageiros();
	void entradaNoCarro();
	void saidaDoCarro();
	int getCapacidade();
	char getEstado();
	Parque &getParque();

	void run();
private:
	static int capacidade;
	int voltas;
	int nPassageiros;
	char estado; //0 = Esperando entrada; 1 = Na volta; 2 = Esperando saida
	Parque &parque;
};

#endif /* CARRO_H_ */
