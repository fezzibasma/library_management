/*
 * EmpruntDatabase.h
 *
 *  Created on: 8 mai 2016
 *      Author: fbasma
 */

#ifndef EMPRUNTDATABASE_H_
#define EMPRUNTDATABASE_H_
#include "Database.h"
#include "EmpruntDatabase.h"
#include "AdherentDatabase.h"

class EmpruntDatabase: public Database {



public:

	bool add_emprunt(Emprunt emprunt) {

		/*open database*/
		open_database();

		/*convert to string*/
		ostringstream id_adherent, id_article;
		id_adherent << emprunt.get_adherent().get_id();
		id_article << emprunt.get_article().get_id();

		/* Create SQL statement */
		string sql_statement =
				"INSERT INTO emprunt (id_adherent,id_article,date_emprunt,date_retour) "
						"VALUES (" + id_adherent.str() + "," + id_article.str()
						+ ",'" + emprunt.get_date_emprunt() + "','"
						+ emprunt.get_date_retour() + "'); ";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;

	}

	bool delete_all_emprunts() {

		/*open database*/
		open_database();

		/* Create SQL statement */
		string sql_statement = "DELETE FROM emprunt;";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;
	}

	bool delete_emprunt(Emprunt emprunt) {

		/*open database*/
		open_database();

		/*convert*/
		ostringstream id_article, id_adherent;
		id_article << emprunt.get_article().get_id();
		id_adherent << emprunt.get_adherent().get_id();

		/* Create SQL statement */
		string sql_statement = "DELETE FROM emprunt where id_article="
				+ id_article.str() + " and id_adherent=" + id_adherent.str()
				+ ";";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;

	}




    vector<Emprunt> select_emprunt_by_adherent(Adherent adherent) {

        /*convert to string*/
        ostringstream id_adherent;
        id_adherent << adherent.get_id();


        vector<Emprunt> emprunts;

        string query = "select * from emprunt where id_adherent=" + id_adherent.str()+ ";";

        vector<vector<string> > data = get_data_table(query);

        for (int i = 0; i < data.size(); i++) {

            Emprunt emprunt;

            /*Get adherent*/
            Adherent adherent;
            adherent.set_id(atoi(data[i][0].c_str()));
            AdherentDatabase *adh = new AdherentDatabase;
            adherent = adh->select_adherent_by_id(adherent)[0];
            emprunt.set_adherent(adherent);

            /*Get article*/
            Article article;
            article.set_id(atoi(data[i][1].c_str()));
            ArticleDatabase *art = new ArticleDatabase;
            article = art->select_article_by_id(article)[0];
            emprunt.set_article(article);


            emprunt.set_date_emprunt(data[i][2]);
            emprunt.set_date_retour(data[i][3]);



            emprunts.push_back(emprunt);
        }

        return emprunts;
    }


	vector<Emprunt> select_emprunt_by_id(Emprunt emprunt) {

		/*convert to string*/
		ostringstream id_adherent, id_article;
		id_adherent << emprunt.get_adherent().get_id();
		id_article << emprunt.get_article().get_id();

		vector<Emprunt> emprunts;

		string query = "select * from emprunt where id_article="
				+ id_article.str() + " and id_adherent=" + id_adherent.str()
				+ ";";

		vector<vector<string> > data = get_data_table(query);

		for (int i = 0; i < data.size(); i++) {

			Emprunt emprunt;

			/*Get adherent*/
			Adherent adherent;
			adherent.set_id(atoi(data[i][0].c_str()));
			AdherentDatabase *adh = new AdherentDatabase;
			adherent = adh->select_adherent_by_id(adherent)[0];
			emprunt.set_adherent(adherent);

			/*Get article*/
			Article article;
			article.set_id(atoi(data[i][1].c_str()));
			ArticleDatabase *art = new ArticleDatabase;
			article = art->select_article_by_id(article)[0];
			emprunt.set_article(article);


			emprunt.set_date_emprunt(data[i][2]);
			emprunt.set_date_retour(data[i][3]);



			emprunts.push_back(emprunt);
		}

		return emprunts;
	}



	vector<Emprunt> select_all_emprunts() {

		vector<Emprunt> emprunts;

		string query = "select * from emprunt;";

		vector<vector<string> > data = get_data_table(query);

		for (int i = 0; i < data.size(); i++) {

			Emprunt emprunt;

			/*Get adherent*/
			Adherent adherent;
			adherent.set_id(atoi(data[i][0].c_str()));
			AdherentDatabase *adh = new AdherentDatabase;
			adherent = adh->select_adherent_by_id(adherent)[0];
			emprunt.set_adherent(adherent);

			/*Get article*/
			Article article;
			article.set_id(atoi(data[i][1].c_str()));
			ArticleDatabase *art = new ArticleDatabase;
			article = art->select_article_by_id(article)[0];
			emprunt.set_article(article);


			emprunt.set_date_emprunt(data[i][2]);
			emprunt.set_date_retour(data[i][3]);



			emprunts.push_back(emprunt);
		}

		return emprunts;
	}

};

#endif /* EMPRUNTDATABASE_H_ */
