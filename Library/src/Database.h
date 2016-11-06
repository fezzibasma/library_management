

#ifndef DATABASE_H_
#define DATABASE_H_

#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include "Article.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Adherent.h"
#include "Commande.h"
#include "Emprunt.h"
#include "Admin.h"



using namespace std;

class Database {


     const string NAME="../database/library.db";



private:
    sqlite3 * _db;


public:


	const string & get_name() const {
		return NAME;
	}


	sqlite3* get_db(){
		return _db;
	}

	bool create_connexion(bool enabled) {
     if (enabled){

		bool open;
		string statement;

		/* open database*/
		open_database();

		/* Create SQL statement */
		statement = "CREATE TABLE article("
				"id  INTEGER PRIMARY KEY  AUTOINCREMENT,"
				"titre          CHAR(100)   NULL,"
				"empruntable    BOOLEAN     NULL,"
				"exemplaire     INT         NULL ,"
				"duree_max      INT         NULL,"
				"genre          CHAR(100)   NULL,"
				"type           CHAR(100)   NULL );"

				"CREATE TABLE adherent("
				"id  INTEGER PRIMARY KEY  AUTOINCREMENT,"
				"nom          	CHAR(100)   NULL,"
				"prenom    		CHAR(100)   NULL,"
				"date_naissance  DATE        NULL,"
				"status         CHAR(100)   NULL,"
                "username       CHAR(100)   NULL UNIQUE,"
				"password       CHAR(100)   NULL,"
				"mail			CHAR(100)   NULL,"
                "tel			CHAR(100)   NULL,"
				"ville          CHAR(100)   NULL,"
				"code_postale   INT         NULL,"
				"pays           CHAR(100)   NULL,"
				"rue            CHAR(100)   NULL );"

				"CREATE TABLE emprunt("
				"id_adherent    INTEGER,"
				"id_article     INTEGER,"
				"date_emprunt    DATE    NULL,"
				"date_retour    DATE    NULL,"
				"FOREIGN KEY(id_article) REFERENCES article(id),"
				"FOREIGN KEY(id_adherent) REFERENCES adherent(id),"
				"PRIMARY KEY(id_adherent,id_article));"

				"CREATE TABLE admin("
				"id  INTEGER PRIMARY KEY  AUTOINCREMENT,"
                "username       CHAR(100)   NULL UNIQUE,"
				"password       CHAR(100)   NULL);"

				"CREATE TABLE amende("
				"id  INTEGER PRIMARY KEY  AUTOINCREMENT,"
				"id_admin       INTEGER,"
				"id_emprunt     INTEGER,"
				"montant        REAL,"
				"remarque       TEXT,"
				"FOREIGN KEY(id_emprunt) REFERENCES emprunt(id),"
				"FOREIGN KEY(id_admin) REFERENCES admin(id));"

				"CREATE TABLE commande("
				"id  INTEGER PRIMARY KEY  AUTOINCREMENT,"
				"type  CHAR(100) NULL,"
				"genre CHAR(100) NULL,"
				"titre CHAR(100) NULL,"
				"description TEXT,"
				"id_adherent    INTEGER ,"
                "FOREIGN KEY(id_adherent) REFERENCES adherent(id));"

                "insert into admin (username,password) values('admin','123456')";


		/* Execute SQL statement */
		 execute_statement(statement);
     }



		return true;
	}


	 bool open_database(){
			bool open;

				/* Open database */

				open = sqlite3_open(NAME.c_str(), &_db);
				if (open) {
					cout << "Can't open database" << sqlite3_errmsg(_db) << endl;


					return false;
				}
				return true;
	 }

	 bool execute_statement(string statement){
		/* Execute SQL statement */



		 char *error_msg = 0;
		 bool open = sqlite3_exec(_db, statement.c_str(), NULL, 0, &error_msg);

			if (open != SQLITE_OK) {
                cout << "SQL error " << error_msg << endl;

               sqlite3_free(error_msg);


				return false;
			}
			sqlite3_close(_db);
            return true;
	}



	 vector< vector<string> > get_data_table(string query)
	 {
		 vector< vector<string> > data;
		 open_database();

	     sqlite3_stmt *statement;

	     if ( sqlite3_prepare(_db, query.c_str(), -1, &statement, 0 ) == SQLITE_OK )
	     {
	         int ctotal = sqlite3_column_count(statement);

	         int res = 0;

	         while ( true )
	         {
	             res = sqlite3_step(statement);
	             vector<string> line;
	             if ( res == SQLITE_ROW )
	             {
	                 for ( int i = 0; i < ctotal; i++ )
	                 {
	                     string s = (char*)sqlite3_column_text(statement, i);
	                     line.push_back(s);
	                 }
	                 data.push_back(line);
	             }

	             if ( res == SQLITE_DONE || res==SQLITE_ERROR)
	             {
	                 break;
	             }
	         }
	     }
	     return data;
	 }



};

#endif /* DATABASE_H_ */
