/*
 * AdminDatabase.h
 *
 *  Created on: 7 mai 2016
 *      Author: fbasma
 */

#ifndef ADMINDATABASE_H_
#define ADMINDATABASE_H_
#include "Database.h"

class AdminDatabase: public Database {


public:

	bool add_admin(Admin admin) {

		/*open database*/
		open_database();

		/* Create SQL statement */
		string sql_statement = "INSERT INTO admin (username,password)"
				"VALUES ('" + admin.get_username() + "','"
				+ admin.get_password() + "'); ";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;

	}

	bool delete_all_admins() {

		/*open database*/
		open_database();

		/* Create SQL statement */
		string sql_statement = "DELETE FROM admin;";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;
	}

	bool delete_admin(Admin admin) {

		/*open database*/
		open_database();

		/*convert*/
		ostringstream id;
		id << admin.get_id();

		/* Create SQL statement */
		string sql_statement = "DELETE FROM admin where id=" + id.str() + ";";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;

	}

	bool update_admin(Admin admin) {

		/*open database*/
		open_database();

		/*convert to string*/
		ostringstream id;
		id << admin.get_id();

		/* Create SQL statement */
		string sql_statement = "UPDATE admin set  username= '"
				+ admin.get_username() + "',password='" + admin.get_password()
				+ "' where id=" + id.str() + ";";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;
	}

	vector<Admin> select_admin_by_id(Admin admin) {

		/*convert*/
		ostringstream id;
		id << admin.get_id();

		vector<Admin> admins;

		string query = "select * from admin where id=" + id.str();

		vector<vector<string> > data = get_data_table(query);

		for (int i = 0; i < data.size(); i++) {




			Admin admin;
			admin.set_id(atoi(data[i][0].c_str()));
			admin.set_username(data[i][1]);
			admin.set_password(data[i][2]);


			admins.push_back(admin);

		}

		return admins;
	}

    vector<Admin> select_admin(Admin admin) {

		vector<Admin> admins;

        string query = "select * from admin where username='" + admin.get_username()+"'  and password ='"+admin.get_password()+"'";

		vector<vector<string> > data = get_data_table(query);

		for (int i = 0; i < data.size(); i++) {


			Admin admin;
			admin.set_id(atoi(data[i][0].c_str()));
			admin.set_username(data[i][1]);
			admin.set_password(data[i][2]);


			admins.push_back(admin);

		}

		return admins;
	}

	vector<Admin> select_all_admins() {

		vector<Admin> admins;

		string query = "select * from admin;";

		vector<vector<string> > data = get_data_table(query);

		for (int i = 0; i < data.size(); i++) {




			Admin admin;
			admin.set_id(atoi(data[i][0].c_str()));
			admin.set_username(data[i][1]);
			admin.set_password(data[i][2]);


			admins.push_back(admin);

		}

		return admins;
	}

};

#endif /* ADMINDATABASE_H_ */
