#include "homeadmin.h"

homeAdmin::homeAdmin(QWidget *parent) :
    QWidget(parent)
{

       this->setFixedWidth(480);

    //button
       _btn_article=new QPushButton("Gestion des articles");
       _btn_adherent_emprunt=new QPushButton("Historique d'emprunts");


     //layout

     _layoutV=new QVBoxLayout(this);


     //form

    _articleList=new ArticleList;
    _historiqueEmprunt=new list_adherent_emprunt;



     // add to v layout

        _layoutV->addWidget(_btn_article);
        _layoutV->addWidget(_btn_adherent_emprunt);


     //connect


    connect(_btn_article,SIGNAL(clicked()),_articleList,SLOT(show()));
    connect(_btn_adherent_emprunt,SIGNAL(clicked()),_historiqueEmprunt,SLOT(show()));


}
