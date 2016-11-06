#include "home.h"
#include "loginadmin.h"
#include "loginadherent.h"
#include "homeadmin.h"
#include "article_list.h"
#include "list_adherent_emprunt.h"


#include <QApplication>
#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include "src/AdminDatabase.h"



int main(int argc, char *argv[])
{



    const bool ENABLE= false;
    Database * db=new Database();
    db->create_connexion(ENABLE);




    QApplication a(argc, argv);
    home w;
    w.show();



    return a.exec();
}
