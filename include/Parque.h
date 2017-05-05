/*
 * Parque.h
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

#ifndef PARQUE_H_
#define PARQUE_H_

class Parque {
public:
	Parque(int nPassageiros);
	virtual ~Parque();

	int getNumPassageiros();
	void setNumPassageiros(int num);

private:
	int numPassageiros;

};

#endif /* PARQUE_H_ */
