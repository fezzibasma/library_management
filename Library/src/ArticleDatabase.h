#ifndef ARTICLEDATABASE_H_
#define ARTICLEDATABASE_H_

#include "Database.h"

using namespace std;

class ArticleDatabase: public Database {

public:

	bool add_article(Article article) {

		/*open database*/
		open_database();

		/*convert to string*/
		ostringstream empruntable, duree_max, exemplaire;
		empruntable << article.get_empruntable();
		exemplaire << article.get_exemplaire();
		duree_max << article.get_duree_max();

		/* Create SQL statement */
		string sql_statement =
				"INSERT INTO article (titre,empruntable,exemplaire,duree_max,genre,type) "
						"VALUES ('" + article.get_titre() + "',"
						+ empruntable.str() + "," + exemplaire.str() + ","
						+ duree_max.str() + ",'" + article.get_genre() + "','"
						+ article.get_type() + "'); ";

		/*execute sql statement*/
        if(execute_statement(sql_statement))
            return true;
        else
            return false;




	}

	bool delete_all_articles() {

		/*open database*/
		open_database();

		/* Create SQL statement */
		string sql_statement = "DELETE FROM article;";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;
	}

	bool delete_article(Article article) {

		/*open database*/
		open_database();

		/*convert*/
		ostringstream id;
		id << article.get_id();

		/* Create SQL statement */
		string sql_statement = "DELETE FROM article where id=" + id.str() + ";";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;

	}

	bool update_article(Article article) {

		/*open database*/
		open_database();

		/*convert to string*/
		ostringstream empruntable, duree_max, exemplaire, id;
		empruntable << article.get_empruntable();
		exemplaire << article.get_exemplaire();
		duree_max << article.get_duree_max();
		id << article.get_id();

		/* Create SQL statement */
		string sql_statement = "UPDATE article set  titre= '"
				+ article.get_titre() + "',empruntable=" + empruntable.str()
				+ ",exemplaire=" + exemplaire.str() + ",duree_max="
				+ duree_max.str() + ",genre='" + article.get_genre()
				+ "',type='" + article.get_type() + "' where id=" + id.str()
				+ ";";

		/*execute sql statement*/
		execute_statement(sql_statement);

		return true;
	}

	vector<Article> select_article_by_id(Article article) {

		/*convert*/
		ostringstream id;
		id << article.get_id();

		vector<Article> articles;

		string
		query="select * from article where id="+id.str();

		vector<vector<string> > data = get_data_table(query);

		for (int i = 0; i < data.size(); i++) {

			Article article;
			article.set_id(atoi(data[i][0].c_str()));
			article.set_titre(data[i][1]);
			article.set_empruntable(atoi(data[i][2].c_str()));
			article.set_exemplaire(atoi(data[i][3].c_str()));
			article.set_duree_max(atoi(data[i][4].c_str()));
			article.set_genre(data[i][5]);
			article.set_type(data[i][6]);

			articles.push_back(article);

		}

		return articles;
	}

	vector<Article> select_article_by_titre(Article article) {



			vector<Article> articles;

			string
			query="select * from article where titre='"+article.get_titre()+"'";

			vector<vector<string> > data = get_data_table(query);

			for (int i = 0; i < data.size(); i++) {

				Article article;
				article.set_id(atoi(data[i][0].c_str()));
				article.set_titre(data[i][1]);
				article.set_empruntable(atoi(data[i][2].c_str()));
				article.set_exemplaire(atoi(data[i][3].c_str()));
				article.set_duree_max(atoi(data[i][4].c_str()));
				article.set_genre(data[i][5]);
				article.set_type(data[i][6]);

				articles.push_back(article);

			}

			return articles;
		}






      vector<Article> select_articles_no_emprunter() {

          vector<Article> articles;

          string query = "select * from article where id not in (select id_article from emprunt);";

          vector<vector<string> > data = get_data_table(query);

          for (int i = 0; i < data.size(); i++) {

              Article article;
              article.set_id(atoi(data[i][0].c_str()));
              article.set_titre(data[i][1]);
              article.set_empruntable(atoi(data[i][2].c_str()));
              article.set_exemplaire(atoi(data[i][3].c_str()));
              article.set_duree_max(atoi(data[i][4].c_str()));
              article.set_genre(data[i][5]);
              article.set_type(data[i][6]);

              articles.push_back(article);

          }

          return articles;
      }

	vector<Article> select_all_articles() {

		vector<Article> articles;

		string query = "select * from article;";

		vector<vector<string> > data = get_data_table(query);

		for (int i = 0; i < data.size(); i++) {

			Article article;
			article.set_id(atoi(data[i][0].c_str()));
			article.set_titre(data[i][1]);
			article.set_empruntable(atoi(data[i][2].c_str()));
			article.set_exemplaire(atoi(data[i][3].c_str()));
			article.set_duree_max(atoi(data[i][4].c_str()));
			article.set_genre(data[i][5]);
			article.set_type(data[i][6]);

			articles.push_back(article);

		}

		return articles;
	}

};

#endif /* ARTICLEDATABASE_H_ */
