/*
 * Parque.cpp
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

#include "include/Parque.h"


Parque::Parque(int nPassageiros) {
	this->numPassageiros = nPassageiros;
}

Parque::~Parque() {
	// TODO Auto-generated destructor stub
}

int Parque::getNumPassageiros() {
	return numPassageiros;
}

void Parque::setNumPassageiros(int num) {
	numPassageiros = num;
}
