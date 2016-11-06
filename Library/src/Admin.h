/*
 * Admin.h
 *
 *  Created on: 7 mai 2016
 *      Author: fbasma
 */

#ifndef ADMIN_H_
#define ADMIN_H_
#include <string>

using namespace std;

class Admin {

private:
	int _id;
	string _username, _password;

public:
	/*getters*/

	int get_id() const {
		return _id;
	}
	const string & get_username() const {
        return _username;
	}
	const string & get_password() const {
		return _password;
	}

	/* setters*/

	void set_id(int id){
		_id=id;
	}


	void set_username(const string & username) {
		_username = username;
	}
	void set_password(const string & password) {
		_password = password;
	}

};

#endif /* ADMIN_H_ */
