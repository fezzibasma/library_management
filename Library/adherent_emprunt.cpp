#include "adherent_emprunt.h"

Adherent_emprunt::Adherent_emprunt(QWidget *parent) :
    QWidget(parent)
{


    this->setFixedSize(900,610);


  //tableview
  _tableView=new QTableView;
  _tableView->setFixedSize(700,200);
  _tableViewEmprunt=new QTableView;
  _tableViewEmprunt->setFixedSize(700,200);


  //label
  _labelWelcome=new QLabel("Welcome");
  _labelTitleEmprunt=new QLabel("Mes emprunts");
  _labelTitle=new QLabel("Liste des articles");
  _labelTitle->setAlignment(Qt::AlignHCenter);

  //button

  _btnEmprunt=new QPushButton("Emprunter");
  _btnAnnuler=new QPushButton("Annuler");
  _btnRefreshArticle=new QPushButton("Actualiser");
  _btnRefreshEmprunt=new QPushButton("Actualiser");
  _btnEmprunt->setFixedWidth(90);
  _btnAnnuler->setFixedWidth(90);





   //model Articles
    ArticleDatabase *article_db=new ArticleDatabase;
    std::vector<Article>articles_list = article_db->select_all_articles();

      _model=new QStandardItemModel(articles_list.size(),7,this);

      //add into model from database

      for(int i=0;i<articles_list.size();i++)
      {
         _model->setData(_model->index(i,0),articles_list[i].get_id());
         _model->setData(_model->index(i,1),QString::fromStdString(articles_list[i].get_titre()));

         if(articles_list[i].get_empruntable()){
              _model->setData(_model->index(i,2),"Oui");
         }else{
             _model->setData(_model->index(i,2),"Non");
         }

         _model->setData(_model->index(i,3),articles_list[i].get_exemplaire());
         _model->setData(_model->index(i,4),articles_list[i].get_duree_max());
         _model->setData(_model->index(i,5),QString::fromStdString(articles_list[i].get_genre()));
         _model->setData(_model->index(i,6),QString::fromStdString(articles_list[i].get_type()));


      }






   _listHeaderTable <<"Id"<<"Titre"<<"Empruntable"<<"Exemplaire"<<"Durée max"<<"Genre"<<"Type";
   _model->setHorizontalHeaderLabels(_listHeaderTable);
   _tableView->verticalHeader()->setMinimumWidth(30);
   _tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
//       _tableView->setSelectionMode(QAbstractItemView::SingleSelection);





   //model emprunt

    EmpruntDatabase *emprunt_db=new EmpruntDatabase;
    std::vector<Emprunt>emprunts_list = emprunt_db->select_all_emprunts();



   _modelEmprunt=new QStandardItemModel(emprunts_list.size(),5,this);

   _listHeaderTableEmprunt<<"Id article"<<"Id adhérent"<<"Titre article"<<"Username"<<"Date emprunt";
   _modelEmprunt->setHorizontalHeaderLabels(_listHeaderTableEmprunt);





   //layout button top

   _layoutButtonTop=new QHBoxLayout;
   _layoutButtonTop->addWidget(_btnRefreshArticle,1,Qt::AlignLeft);
   _layoutButtonTop->addWidget(_btnEmprunt);

   //layout button bottom

   _layoutButtonBottom=new QHBoxLayout;
   _layoutButtonBottom->addWidget(_btnRefreshEmprunt,1,Qt::AlignLeft);
   _layoutButtonBottom->addWidget(_btnAnnuler);



//      //add to vertical layout

   _layoutV=new QVBoxLayout(this);
   _layoutV->addWidget(_labelWelcome,1,Qt::AlignRight);
   _layoutV->addSpacing(20);
   _layoutV->addWidget(_labelTitle);
   _layoutV->addWidget(_tableView,1,Qt::AlignHCenter);
   _layoutButtonTop->setContentsMargins(90,0,90,0);
   _layoutV->addLayout(_layoutButtonTop);

   _layoutV->addWidget(_labelTitleEmprunt,1,Qt::AlignHCenter);
   _layoutV->addWidget(_tableViewEmprunt,1,Qt::AlignCenter);
   _layoutButtonBottom->setContentsMargins(90,0,90,0);
   _layoutV->addLayout(_layoutButtonBottom);
   _layoutV->addSpacing(10);



//      //set model into tableview

  _tableView->setModel(_model);
  _tableView->horizontalHeader()->setStretchLastSection(true);
  _tableView->setColumnHidden(0,true);

  _tableViewEmprunt->setModel(_modelEmprunt);
  _tableViewEmprunt->horizontalHeader()->setStretchLastSection(true);
  _tableViewEmprunt->setColumnHidden(0,true);
  _tableViewEmprunt->setColumnHidden(1,true);
   _tableView->setColumnHidden(3,true);



  //connect

  connect(_btnEmprunt,SIGNAL(clicked()),this,SLOT(add_emprunt()));
  connect(_btnAnnuler,SIGNAL(clicked()),this,SLOT(annuler_emprunt()));
  connect(_btnRefreshArticle,SIGNAL(clicked()),this,SLOT(refresh_articles()));
  connect(_btnRefreshEmprunt,SIGNAL(clicked()),this,SLOT(refresh_emprunt()));



}


void Adherent_emprunt::refresh_articles(){



    ArticleDatabase *article_db=new ArticleDatabase;
    std::vector<Article>articles_list = article_db->select_all_articles();

      _model=new QStandardItemModel(articles_list.size(),7,this);

      //add into model from database

      for(int i=0;i<articles_list.size();i++)
      {
         _model->setData(_model->index(i,0),articles_list[i].get_id());
         _model->setData(_model->index(i,1),QString::fromStdString(articles_list[i].get_titre()));

         if(articles_list[i].get_empruntable()){
              _model->setData(_model->index(i,2),"Oui");
         }else{
             _model->setData(_model->index(i,2),"Non");
         }

         _model->setData(_model->index(i,3),articles_list[i].get_exemplaire());
         _model->setData(_model->index(i,4),articles_list[i].get_duree_max());
         _model->setData(_model->index(i,5),QString::fromStdString(articles_list[i].get_genre()));
         _model->setData(_model->index(i,6),QString::fromStdString(articles_list[i].get_type()));


      }


      _model->setHorizontalHeaderLabels(_listHeaderTable);
      _tableView->verticalHeader()->setMinimumWidth(30);

      _tableView->setModel(_model);
      _tableView->horizontalHeader()->setStretchLastSection(true);


}


void Adherent_emprunt::refresh_emprunt(){

    Adherent adherent;
    adherent.set_id(_idAdherent);


    EmpruntDatabase *emprunt_db=new EmpruntDatabase;
    std::vector<Emprunt>emprunts_list = emprunt_db->select_emprunt_by_adherent(adherent);



      _modelEmprunt->setHorizontalHeaderLabels(_listHeaderTableEmprunt);
      _modelEmprunt=new QStandardItemModel(emprunts_list.size(),5,this);

      //add into model from database

      for(int i=0;i<emprunts_list.size();i++)
      {


          _modelEmprunt->setData(_modelEmprunt->index(i,0),emprunts_list[i].get_article().get_id());
          _modelEmprunt->setData(_modelEmprunt->index(i,1),  emprunts_list[i].get_adherent().get_id());
          _modelEmprunt->setData(_modelEmprunt->index(i,2),  QString::fromStdString(emprunts_list[i].get_article().get_titre()));
          _modelEmprunt->setData(_modelEmprunt->index(i,3),  QString::fromStdString(emprunts_list[i].get_adherent().get_username()));
          _modelEmprunt->setData(_modelEmprunt->index(i,4),  QString::fromStdString(emprunts_list[i].get_date_emprunt()));



      }


      _modelEmprunt->setHorizontalHeaderLabels(_listHeaderTableEmprunt);
      _tableViewEmprunt->verticalHeader()->setMinimumWidth(30);

      _tableViewEmprunt->setModel(_modelEmprunt);
      _tableViewEmprunt->horizontalHeader()->setStretchLastSection(true);
      _tableViewEmprunt->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Adherent_emprunt::add_emprunt(){


    ArticleDatabase *article_db=new ArticleDatabase;

    int row=_tableView->currentIndex().row();
    int id_article=_model->data(_model->index(row,0)).toString().toInt();


    Adherent adherent;
    adherent.set_id(_idAdherent);

    Article article;
    article.set_id(id_article);


    if(_model->data(_model->index(row,2)).toString().toUpper()==QString("oui").toUpper()){

    Emprunt emprunt;
    emprunt.set_adherent(adherent);
    emprunt.set_article(article);
    emprunt.set_date_emprunt(QDateTime::currentDateTime().toString("dd/MM/yyyy").toStdString());

    EmpruntDatabase *emprunt_db=new EmpruntDatabase;
    emprunt_db->add_emprunt(emprunt);


    refresh_emprunt();
    }else{


        QMessageBox msgBox;
        msgBox.setText("Oups, article non empruntable !");
        msgBox.exec();
    }

}


void Adherent_emprunt::annuler_emprunt(){




    int row=_tableViewEmprunt->currentIndex().row();
    int id_article=_modelEmprunt->data(_modelEmprunt->index(row,0)).toString().toInt();
    int id_adherent=_modelEmprunt->data(_modelEmprunt->index(row,1)).toString().toInt();


    Adherent adherent;
    adherent.set_id(id_adherent);

    Article article;
    article.set_id(id_article);

    Emprunt emprunt;
    emprunt.set_adherent(adherent);
    emprunt.set_article(article);


    EmpruntDatabase *emprunt_db=new EmpruntDatabase;
    emprunt_db->delete_emprunt(emprunt);


    refresh_emprunt();


}





void Adherent_emprunt::get_adherent(Adherent * adherent){



    _idAdherent=adherent->get_id();

    QString msg=QString::fromStdString(adherent->get_username());
    _labelWelcome->setText("Bienvenue "+msg);


    refresh_emprunt();


}
