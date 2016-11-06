/*
 * CommandeDatabase.h
 *
 *  Created on: 8 mai 2016
 *      Author: fbasma
 */

#ifndef COMMANDEDATABASE_H_
#define COMMANDEDATABASE_H_

#include "Database.h"
#include "AdherentDatabase.h"


class CommandeDatabase:public Database{


public:




	bool add_commande(Commande commande) {

		/*open database*/
		open_database();

		/*convert to string*/
		ostringstream id_adherent;
		id_adherent <<  commande.get_adherent().get_id();


		/* Create SQL statement */
		string sql_statement =
				"INSERT INTO commande (type,genre,titre,description,id_adherent) "
						"VALUES ('" + commande.get_type() + "','"
						 + commande.get_genre() + "','"
						 + commande.get_titre() + "','"
						 + commande.get_description() + "',"
						 + id_adherent.str()+ "); ";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;

	}

	bool delete_all_commandes() {

		/*open database*/
		open_database();

		/* Create SQL statement */
		string sql_statement = "DELETE FROM commande;";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;
	}

	bool delete_commande(Commande commande) {

		/*open database*/
		open_database();

		/*convert*/
		ostringstream id;
		id << commande.get_id();

		/* Create SQL statement */
		string sql_statement = "DELETE FROM commande where id=" + id.str() + ";";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;

	}

	bool update_commande(Commande commande) {

		/*open database*/
		open_database();

		/*convert to string*/
		ostringstream  id_commande,id_adherent;
		id_commande<<commande.get_id();
		id_adherent<<commande.get_adherent().get_id();



		/* Create SQL statement */
		string sql_statement = "UPDATE commande set  type= '"
				+ commande.get_type()+
				"',genre='"+ commande.get_genre()+
				"',titre='"+ commande.get_titre()+
				"',description='"+ commande.get_description()+
				"',id_adherent='"+ id_adherent.str()+
				"' where id=" + id_commande.str()+ ";";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;
	}



	vector<Commande> select_commande_by_id(Commande commande) {

		/*convert*/
		ostringstream id;
		id << commande.get_id();

		vector<Commande> commandes;

		string
		query="select * from commande where id="+id.str();

		vector<vector<string> > data = get_data_table(query);

		for (int i = 0; i < data.size(); i++) {

				Commande commande;
				commande.set_id(atoi(data[i][0].c_str()));
				commande.set_type(data[i][1]);
				commande.set_genre(data[i][2]);
				commande.set_titre(data[i][3]);
				commande.set_description(data[i][4]);

				Adherent adherent;
				adherent.set_id(atoi(data[i][5].c_str()));
				AdherentDatabase *adh=new AdherentDatabase;
				adherent=adh->select_adherent_by_id(adherent)[0];
				commande.set_adherent(adherent);


				commandes.push_back(commande);


		}

		return commandes;
	}


	vector<Commande> select_commande_by_titre(Commande commande) {



		vector<Commande> commandes;

		string query="select * from commande where titre='"+commande.get_titre()+"'";

		vector<vector<string> > data = get_data_table(query);



		for (int i = 0; i < data.size(); i++) {

				Commande commande;
				commande.set_id(atoi(data[i][0].c_str()));
				commande.set_type(data[i][1]);
				commande.set_genre(data[i][2]);
				commande.set_titre(data[i][3]);
				commande.set_description(data[i][4]);

				Adherent adherent;
				adherent.set_id(atoi(data[i][5].c_str()));
				AdherentDatabase *adh=new AdherentDatabase;
				adherent=adh->select_adherent_by_id(adherent)[0];
				commande.set_adherent(adherent);


				commandes.push_back(commande);


		}

		return commandes;
	}



	vector<Commande> select_all_commandes() {


		vector<Commande> commandes;

		string query="select * from commande;";

		vector<vector<string> > data = get_data_table(query);



		for (int i = 0; i < data.size(); i++) {

				Commande commande;
				commande.set_id(atoi(data[i][0].c_str()));
				commande.set_type(data[i][1]);
				commande.set_genre(data[i][2]);
				commande.set_titre(data[i][3]);
				commande.set_description(data[i][4]);

				Adherent adherent;
				adherent.set_id(atoi(data[i][5].c_str()));
				AdherentDatabase *adh=new AdherentDatabase;
				adherent=adh->select_adherent_by_id(adherent)[0];
				commande.set_adherent(adherent);


				commandes.push_back(commande);


		}

		return commandes;
		}






};


#endif /* COMMANDEDATABASE_H_ */
