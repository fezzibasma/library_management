//============================================================================
// Name        : Library.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include "ArticleDatabase.h"
#include "AdherentDatabase.h"
#include "AdminDatabase.h"
#include "CommandeDatabase.h"
#include "EmpruntDatabase.h"

using namespace std;

int main() {

	const bool ENABLE = false;
//
	Database *db1 = new Database();
		db1->create_connexion(ENABLE);


/******************Article***************** */
			ArticleDatabase *db=new ArticleDatabase();


//
//	/*create article*/
	Article article1;
	article1.set_id(1);
	article1.set_duree_max(20);
	article1.set_empruntable(false);
	article1.set_exemplaire(50);
	article1.set_titre("iiii");
	article1.set_genre("ppppp");
	article1.set_type("momo");

//	db = new ArticleDatabase();
//   db->add_article(article1);
//	  db->delete_all_articles();
//	db->delete_article(article1);
//	db->update_article(article1);
//	vector<Article> articles = db->select_all_articles();
//	for (int i = 0; i < articles.size(); i++) {
//
//		cout << articles[i].get_id() << " " << articles[i].get_titre() << " "
//				<< articles[i].get_empruntable() << " "
//				<< articles[i].get_exemplaire()<<" "<<articles[i].get_duree_max()<<" "<<articles[i].get_genre()<<" "<<articles[i].get_type();
//
//		cout<<endl;
//	}

//		vector<Article> articles = db->select_article_by_id(article1);
//		for (int i = 0; i < articles.size(); i++) {
//
//			cout << articles[i].get_id() << " " << articles[i].get_titre() << " "
//					<< articles[i].get_empruntable() << " "
//					<< articles[i].get_exemplaire()<<" "<<articles[i].get_duree_max()<<" "<<articles[i].get_genre()<<" "<<articles[i].get_type();
//
//			cout<<endl;
//		}

//   		vector<Article> articles = db->select_article_by_titre(article1);
//   		for (int i = 0; i < articles.size(); i++) {
//
//   			cout << articles[i].get_id() << " " << articles[i].get_titre() << " "
//   					<< articles[i].get_empruntable() << " "
//   					<< articles[i].get_exemplaire()<<" "<<articles[i].get_duree_max()<<" "<<articles[i].get_genre()<<" "<<articles[i].get_type();
//
//   			cout<<endl;
//   		}


	/******************Adherent***************** */


	AdherentDatabase *adh=new AdherentDatabase;
	Adherent adherent1;
	adherent1.set_id(1);
	adherent1.set_nom("hossam2");
	adherent1.set_prenom("benhoud");
	adherent1.set_date_naissance("16-12-1992");
	adherent1.set_status("stat");
	adherent1.set_username("toto");
	adherent1.set_password("xoxo");
	adherent1.set_mail("kk@gmail.com");
	adherent1.set_tel("7777");
	adherent1.set_ville("rabat");
	adherent1.set_code_postale(49000);
	adherent1.set_pays("France");
	adherent1.set_rue("galienni");


//	adh->add_adherent(adherent1);
//	adh->delete_all_adherents();
//	adh->delete_adherent(adherent1);
//	adh->update_adherent(adherent1);


//	   		vector<Adherent> adherents = adh->select_adherent_by_id(adherent1);
//	   		for (int i = 0; i < adherents.size(); i++) {
//
//	   			cout << adherents[i].get_id() << " " << adherents[i].get_nom() << " "
//	   					<< adherents[i].get_prenom() << " "
//	   					<< adherents[i].get_date_naissance()<<" "<<adherents[i].get_status()<<" "<<adherents[i].get_username()<<" "
//						<<adherents[i].get_password()<<" "<<adherents[i].get_mail()<<" "<<adherents[i].get_tel()<<" "
//						<<adherents[i].get_ville()<<" "<<adherents[i].get_code_postale()<<" "<<adherents[i].get_pays()<<" "
//						<<adherents[i].get_rue();
//
//	   			cout<<endl;
//	   		}


//
//		   		vector<Adherent> adherents = adh->select_adherent_by_nom(adherent1);
//		   		for (int i = 0; i < adherents.size(); i++) {
//
//		   			cout << adherents[i].get_id() << " " << adherents[i].get_nom() << " "
//		   					<< adherents[i].get_prenom() << " "
//		   					<< adherents[i].get_date_naissance()<<" "<<adherents[i].get_status()<<" "<<adherents[i].get_username()<<" "
//							<<adherents[i].get_password()<<" "<<adherents[i].get_mail()<<" "<<adherents[i].get_tel()<<" "
//							<<adherents[i].get_ville()<<" "<<adherents[i].get_code_postale()<<" "<<adherents[i].get_pays()<<" "
//							<<adherents[i].get_rue();
//
//		   			cout<<endl;
//		   		}



//
//			   		vector<Adherent> adherents = adh->select_all_adherents();
//			   		for (int i = 0; i < adherents.size(); i++) {
//
//			   			cout << adherents[i].get_id() << " " << adherents[i].get_nom() << " "
//			   					<< adherents[i].get_prenom() << " "
//			   					<< adherents[i].get_date_naissance()<<" "<<adherents[i].get_status()<<" "<<adherents[i].get_username()<<" "
//								<<adherents[i].get_password()<<" "<<adherents[i].get_mail()<<" "<<adherents[i].get_tel()<<" "
//								<<adherents[i].get_ville()<<" "<<adherents[i].get_code_postale()<<" "<<adherents[i].get_pays()<<" "
//								<<adherents[i].get_rue();
//
//			   			cout<<endl;
//			   		}


/******************************* Admin ****************/

	Admin admin;
	admin.set_id(5);
	admin.set_username("hoss");
	admin.set_password("1234567");

	AdminDatabase *adm=new AdminDatabase();
//	adm->add_admin(admin);
//	adm->delete_all_admins();
//	adm->delete_admin(admin);
//	adm->update_admin(admin);


//				   		vector<Admin> admins =adm->select_admin_by_id(admin);
//				   		for (int i = 0; i < admins.size(); i++) {
//
//				   			cout << admins[i].get_id() << " " << admins[i].get_username()<< " "
//				   					<< admins[i].get_password() ;
//
//				   			cout<<endl;
//				   		}


//		vector<Admin> admins =adm->select_admin_by_username(admin);
//				   		for (int i = 0; i < admins.size(); i++) {
//
//				   			cout << admins[i].get_id() << " " << admins[i].get_username()<< " "
//				   					<< admins[i].get_password() ;
//
//				   			cout<<endl;
//				   		}

//			vector<Admin> admins =adm->select_all_admins();
//					   		for (int i = 0; i < admins.size(); i++) {
//
//					   			cout << admins[i].get_id() << " " << admins[i].get_username()<< " "
//					   					<< admins[i].get_password() ;
//
//					   			cout<<endl;
//					   		}


	/********************** Commande ******************/

	/*
	 * "CREATE TABLE commande("
				"id  INTEGER PRIMARY KEY  AUTOINCREMENT,"
				"type  CHAR(100) NULL,"
				"genre CHAR(100) NULL,"
				"titre CHAR(100) NULL,"
				"description TEXT,"
				"id_adherent    INTEGER ,"
				"FOREIGN KEY(id_adherent) REFERENCES adherent(id));";*/
	Commande commande1;
	commande1.set_id(3);
	commande1.set_type("aoao");
	commande1.set_genre("ggg");
	commande1.set_titre("ttt");
	commande1.set_description("dddd");
	commande1.set_adherent(adherent1);

	CommandeDatabase *cmd=new CommandeDatabase;
//	cmd->add_commande(commande1);
//	cmd->delete_all_commandes();
//	cmd->delete_commande(commande1);
//  cmd->update_commande(commande1);

//	vector<Commande> commands =cmd->select_commande_by_id(commande1);
//				   		for (int i = 0; i < commands.size(); i++) {
//
//				   			cout << commands[i].get_id() << " " << commands[i].get_titre()<< " "
//				   					<< commands[i].get_type()<<" "<<commands[i].get_genre()<<" "
//									<<commands[i].get_description()<<" "<<commands[i].get_adherent().get_nom();
//
//				   			cout<<endl;
//				   		}

//		vector<Commande> commands =cmd->select_commande_by_titre(commande1);
//					   		for (int i = 0; i < commands.size(); i++) {
//
//					   			cout << commands[i].get_id() << " " << commands[i].get_titre()<< " "
//					   					<< commands[i].get_type()<<" "<<commands[i].get_genre()<<" "
//										<<commands[i].get_description()<<" "<<commands[i].get_adherent().get_nom();
//
//					   			cout<<endl;
//					   		}

//	vector<Commande> commands =cmd->select_all_commandes();
//					   		for (int i = 0; i < commands.size(); i++) {
//
//					   			cout << commands[i].get_id() << " " << commands[i].get_titre()<< " "
//					   					<< commands[i].get_type()<<" "<<commands[i].get_genre()<<" "
//										<<commands[i].get_description()<<" "<<commands[i].get_adherent().get_nom();
//
//					   			cout<<endl;
//					   		}

/************************Emprunt *********************/
	Emprunt emprunt1;
	emprunt1.set_adherent(adherent1);
	emprunt1.set_article(article1);
	emprunt1.set_date_emprunt("02-02-2016");
	emprunt1.set_date_retour("01-01-2017");

	EmpruntDatabase *empt=new EmpruntDatabase;
//	empt->add_emprunt(emprunt1);
//	empt->delete_all_emprunts();
//	empt->delete_emprunt(emprunt1);

//	vector<Emprunt> emprunts =empt->select_emprunt_by_id(emprunt1);
//						   		for (int i = 0; i < emprunts.size(); i++) {
//
//						   			cout << emprunts[i].get_adherent().get_nom() << " " << emprunts[i].get_article().get_titre()<< " "
//						   					<< emprunts[i].get_date_emprunt()<<" "<<emprunts[i].get_date_retour() ;
//						   			cout<<endl;
//						   		}

//
//		vector<Emprunt> emprunts =empt->select_all_emprunts();
//							   		for (int i = 0; i < emprunts.size(); i++) {
//
//							   			cout << emprunts[i].get_adherent().get_nom() << " " << emprunts[i].get_article().get_titre()<< " "
//							   					<< emprunts[i].get_date_emprunt()<<" "<<emprunts[i].get_date_retour() ;
//							   			cout<<endl;
//							   		}





	cout << "succes" << endl;
	return 0;
}
