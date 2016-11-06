/*
 * Commande.h
 *
 *  Created on: 7 mai 2016
 *      Author: fbasma
 */

#ifndef COMMANDE_H_
#define COMMANDE_H_
#include <string>
using namespace std;

class Commande {

private:
	int _id;
	string _type, _genre, _titre, _description;
	Adherent _adherent;

public:

	/*Getters*/

	int get_id() const {
		return _id;
	}

	const string & get_type() const {
		return _type;
	}

	const string & get_genre() const {
		return _genre;
	}

	const string & get_titre() const {
		return _titre;
	}

	const string & get_description() const {
		return _description;
	}

	const Adherent & get_adherent()const{
		return _adherent;
	}
	/*Setters*/

	void set_id(int id)  {
		 _id=id;
	}


	void set_type(const string & type)  {
		 _type=type;
	}

	void set_genre(const string & genre)  {
		 _genre=genre;
	}

	void set_titre(const string & titre)  {
		 _titre=titre;
	}

	void set_description(const string & description)  {
		 _description=description;
	}

	void set_adherent(const Adherent & adherent){
		_adherent=adherent;
	}

};


#endif /* COMMANDE_H_ */
