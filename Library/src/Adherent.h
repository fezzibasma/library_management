/*
 * Adherent.h
 *
 *  Created on: 7 mai 2016
 *      Author: fbasma
 */

#ifndef ADHERENT_H_
#define ADHERENT_H_

#include <string>
using namespace std;

class Adherent {

private:
	int _id, _code_postale;
	string _nom, _prenom, _date_naissance, _status, _username, _password, _mail,
			_tel, _ville, _pays, _rue;

public:

	/*getters*/

	int get_id()const {
		return _id;
	}

	int get_code_postale()const {
		return _code_postale;
	}

	const string & get_nom() const {
		return _nom;
	}

	const string & get_prenom() const {
		return _prenom;
	}

	const string & get_date_naissance() const {
		return _date_naissance;
	}

	const string & get_status() const {
		return _status;
	}

	const string & get_username() const {
		return _username;
	}

	const string & get_mail() const {
		return _mail;
	}

	const string & get_password() const {
		return _password;
	}

	const string & get_tel() const {
		return _tel;
	}

	const string & get_ville() const {
		return _ville;
	}

	const string & get_pays() const {
		return _pays;
	}
	const string & get_rue() const {
		return _rue;
	}

	/*setters*/

	void set_id(int id) {
		 _id=id;
	}
	void set_code_postale(int code_postale) {
		 _code_postale=code_postale;
	}

	void set_nom(const string & nom)  {
		 _nom=nom;
	}

	void set_prenom(const string & prenom)  {
		 _prenom=prenom;
	}

	void set_date_naissance(const string & date_naissance)  {
		 _date_naissance=date_naissance;
	}

	void set_status(const string & status)  {
		 _status=status;
	}

	void set_username(const string & username)  {
		 _username=username;
	}

	 void set_mail(const string & mail)  {
		 _mail=mail;
	}

	void set_password(const string & password)  {
		 _password=password;
	}

	void set_tel(const string & tel)  {
		 _tel=tel;
	}

	void set_ville(const string & ville)  {
		 _ville=ville;
	}

	void  set_pays(const string & pays) {
		 _pays=pays;
	}
	 void set_rue(const string & rue)  {
		 _rue=rue;
	}

};

#endif /* ADHERENT_H_ */
