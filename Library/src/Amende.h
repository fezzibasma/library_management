/*
 * Amende.h
 *
 *  Created on: 7 mai 2016
 *      Author: fbasma
 */

#ifndef AMENDE_H_
#define AMENDE_H_

#include <string>
using namespace std;

class Amende {
private:
	int _id;
	double _montant;
	string _remarque;
	Admin _admin;
	Emprunt _emprunt;
public:

	/*getters*/

	int get_id() const {
		return _id;
	}

	double get_montant() const {
		return _montant;
	}

	const string & get_remarque() const {
		return _remarque;
	}

	const Admin & get_admin() const {
		return _admin;
	}

	const Emprunt & get_emprunt() const {
		return _emprunt;
	}

	/*Setters*/

	void set_montant(double montant) {
		_montant = montant;
	}

	void set_remarque(const string & remarque) {
		_remarque = remarque;
	}

	void set_admin(const Admin & admin) {
		_admin = admin;
	}

	void get_emprunt(const Emprunt & emprunt) {
		_emprunt = emprunt;
	}

};

#endif /* AMENDE_H_ */
