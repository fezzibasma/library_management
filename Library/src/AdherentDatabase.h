/*
 * AdherentDatabase.h
 *
 *  Created on: 7 mai 2016
 *      Author: fbasma
 */

#ifndef ADHERENTDATABASE_H_
#define ADHERENTDATABASE_H_

#include "Database.h"

class AdherentDatabase:public Database{

public:




	bool add_adherent(Adherent adherent) {

		/*open database*/
		open_database();

		/*convert to string*/
		ostringstream code_postale;
		code_postale << adherent.get_code_postale();


		/* Create SQL statement */
		string sql_statement =
				"INSERT INTO adherent (nom,prenom,date_naissance,status,username,password,mail,tel,ville,code_postale,pays,rue) "
						"VALUES ('" + adherent.get_nom() + "','"
						 + adherent.get_prenom() + "','"
						 + adherent.get_date_naissance() + "','"
						 + adherent.get_status() + "','"
						 + adherent.get_username() + "','"
						 + adherent.get_password() + "','"
						 + adherent.get_mail()+ "','"
						 + adherent.get_tel()+ "','"
						 + adherent.get_ville() + "',"
						 + code_postale.str()+ ",'"
						 + adherent.get_pays() + "','"
						 + adherent.get_rue()+ "'); ";

		/*execute sql statement*/
        if(execute_statement(sql_statement))
            return true;
        else
            return false;


	}

	bool delete_all_adherents() {

		/*open database*/
		open_database();

		/* Create SQL statement */
		string sql_statement = "DELETE FROM adherent;";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;
	}

	bool delete_adherent(Adherent adherent) {

		/*open database*/
		open_database();

		/*convert*/
		ostringstream id;
		id << adherent.get_id();

		/* Create SQL statement */
		string sql_statement = "DELETE FROM adherent where id=" + id.str() + ";";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;

	}

	bool update_adherent(Adherent adherent) {

		/*open database*/
		open_database();

		/*convert to string*/
		ostringstream code_postale, id;
		code_postale<<adherent.get_code_postale();
		id << adherent.get_id();

		/* Create SQL statement */
		string sql_statement = "UPDATE adherent set  nom= '"
				+ adherent.get_nom()+
				"',prenom='"+ adherent.get_prenom()+
				"',date_naissance='"+ adherent.get_date_naissance()+
				"',status='"+ adherent.get_status()+
				"',username='"+ adherent.get_username()+
				"',password='"+ adherent.get_password()+
				"',mail='"+ adherent.get_mail()+
				"',tel='"+ adherent.get_tel()+
				"',ville='"+ adherent.get_ville()+
				"',code_postale="+ code_postale.str()+
				",pays='"+ adherent.get_pays()+
				"',rue='"+ adherent.get_rue()+
				"' where id=" + id.str()+ ";";




		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;
	}

	vector<Adherent> select_adherent_by_id(Adherent adherent) {

		/*convert*/
		ostringstream id;
		id << adherent.get_id();

		vector<Adherent> adherents;

		string
		query="select * from adherent where id="+id.str();

		vector<vector<string> > data = get_data_table(query);

		for (int i = 0; i < data.size(); i++) {

			Adherent adherent;

			adherent.set_id(atoi(data[i][0].c_str()));
			adherent.set_nom(data[i][1]);
			adherent.set_prenom(data[i][2]);
			adherent.set_date_naissance(data[i][3]);
			adherent.set_status(data[i][4]);
			adherent.set_username(data[i][5]);
			adherent.set_password(data[i][6]);
			adherent.set_mail(data[i][7]);
			adherent.set_tel(data[i][8]);
			adherent.set_ville(data[i][9]);
			adherent.set_code_postale(atoi(data[i][10].c_str()));
			adherent.set_pays(data[i][11]);
			adherent.set_rue(data[i][12]);



			adherents.push_back(adherent);

		}

		return adherents;
	}



    vector<Adherent> select_adherent(Adherent adherent) {

        vector<Adherent> adherents;


        string query = "select * from adherent where username='" + adherent.get_username()+"'  and password ='"+adherent.get_password()+"'";


        vector<vector<string> > data = get_data_table(query);

        for (int i = 0; i < data.size(); i++) {

            Adherent adherent;

            adherent.set_id(atoi(data[i][0].c_str()));
            adherent.set_nom(data[i][1]);
            adherent.set_prenom(data[i][2]);
            adherent.set_date_naissance(data[i][3]);
            adherent.set_status(data[i][4]);
            adherent.set_username(data[i][5]);
            adherent.set_password(data[i][6]);
            adherent.set_mail(data[i][7]);
            adherent.set_tel(data[i][8]);
            adherent.set_ville(data[i][9]);
            adherent.set_code_postale(atoi(data[i][10].c_str()));
            adherent.set_pays(data[i][11]);
            adherent.set_rue(data[i][12]);



            adherents.push_back(adherent);

        }

        return adherents;
    }



	vector<Adherent> select_adherent_by_nom(Adherent adherent) {



		vector<Adherent> adherents;

		string query="select * from adherent where nom='"+adherent.get_nom()+"'";

		vector<vector<string> > data = get_data_table(query);

		for (int i = 0; i < data.size(); i++) {

			Adherent adherent;

			adherent.set_id(atoi(data[i][0].c_str()));
			adherent.set_nom(data[i][1]);
			adherent.set_prenom(data[i][2]);
			adherent.set_date_naissance(data[i][3]);
			adherent.set_status(data[i][4]);
			adherent.set_username(data[i][5]);
			adherent.set_password(data[i][6]);
			adherent.set_mail(data[i][7]);
			adherent.set_tel(data[i][8]);
			adherent.set_ville(data[i][9]);
			adherent.set_code_postale(atoi(data[i][10].c_str()));
			adherent.set_pays(data[i][11]);
			adherent.set_rue(data[i][12]);



			adherents.push_back(adherent);

		}

		return adherents;
	}



	vector<Adherent> select_all_adherents() {



			vector<Adherent> adherents;

			string query="select * from adherent;";

			vector<vector<string> > data = get_data_table(query);

			for (int i = 0; i < data.size(); i++) {

				Adherent adherent;

				adherent.set_id(atoi(data[i][0].c_str()));
				adherent.set_nom(data[i][1]);
				adherent.set_prenom(data[i][2]);
				adherent.set_date_naissance(data[i][3]);
				adherent.set_status(data[i][4]);
				adherent.set_username(data[i][5]);
				adherent.set_password(data[i][6]);
				adherent.set_mail(data[i][7]);
				adherent.set_tel(data[i][8]);
				adherent.set_ville(data[i][9]);
				adherent.set_code_postale(atoi(data[i][10].c_str()));
				adherent.set_pays(data[i][11]);
				adherent.set_rue(data[i][12]);



				adherents.push_back(adherent);

			}

			return adherents;
		}







};



#endif /* ADHERENTDATABASE_H_ */
