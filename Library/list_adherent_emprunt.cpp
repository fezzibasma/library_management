#include "list_adherent_emprunt.h"

list_adherent_emprunt::list_adherent_emprunt(QWidget *parent) :
    QWidget(parent)
{



    this->setFixedSize(1260,500);


  //tableview
  _tableView=new QTableView;
  _tableView->setFixedSize(1240,350);


  //label
  _labelTitle=new QLabel("Historique d'emprunts");
  _labelTitle->setAlignment(Qt::AlignHCenter);

  //button

  _btnRefresh=new QPushButton("Actualiser");



   //model
    EmpruntDatabase *emprunt_db=new EmpruntDatabase;
    std::vector<Emprunt>emprunt_list = emprunt_db->select_all_emprunts();

      _model=new QStandardItemModel(emprunt_list.size(),14,this);

      //add into model from database

      for(int i=0;i<emprunt_list.size();i++)
      {
         _model->setData(_model->index(i,0),emprunt_list[i].get_adherent().get_id());
         _model->setData(_model->index(i,1),emprunt_list[i].get_article().get_id());
         _model->setData(_model->index(i,2),QString::fromStdString(emprunt_list[i].get_adherent().get_nom()));
         _model->setData(_model->index(i,3),QString::fromStdString(emprunt_list[i].get_adherent().get_prenom()));
         _model->setData(_model->index(i,4),QString::fromStdString(emprunt_list[i].get_adherent().get_date_naissance()));
         _model->setData(_model->index(i,5),QString::fromStdString(emprunt_list[i].get_adherent().get_status()));
         _model->setData(_model->index(i,6),QString::fromStdString(emprunt_list[i].get_adherent().get_mail()));
         _model->setData(_model->index(i,7),QString::fromStdString(emprunt_list[i].get_adherent().get_tel()));
         _model->setData(_model->index(i,8),QString::fromStdString(emprunt_list[i].get_adherent().get_rue()+" "+
           emprunt_list[i].get_adherent().get_ville()+" "+QString::number(emprunt_list[i].get_adherent().get_code_postale()).toStdString()+" "+
                 emprunt_list[i].get_adherent().get_pays()));
         _model->setData(_model->index(i,9),QString::fromStdString(emprunt_list[i].get_article().get_titre()));
         _model->setData(_model->index(i,10),QString::fromStdString(emprunt_list[i].get_article().get_genre()));
         _model->setData(_model->index(i,11),QString::fromStdString(emprunt_list[i].get_article().get_type()));
         _model->setData(_model->index(i,12),QString::fromStdString(emprunt_list[i].get_date_emprunt()));
         if(emprunt_list[i].get_article().get_empruntable())
            _model->setData(_model->index(i,13),"Oui");
         else
             _model->setData(_model->index(i,13),"Non");

      }




         _listHeaderTable <<"Id adherent"<<"Id article"<<"Nom"<<"prénom"<<"Date naissance"
                         <<"status"<<"mail"<<"tel"<<"Adresse"<<"Titre article"<<"Genre article"<<"Type article"
                           <<"Date emprunt"<<"Empruntable";

         _model->setHorizontalHeaderLabels(_listHeaderTable);
         _tableView->verticalHeader()->setMinimumWidth(30);
         _tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


               //set model into tableview

           _tableView->setModel(_model);
           _tableView->horizontalHeader()->setStretchLastSection(true);
           _tableView->setColumnHidden(0,true);
           _tableView->setColumnHidden(1,true);





   //layout button Top

     _layoutButtonTop=new QHBoxLayout;
     _layoutButtonTop->addWidget(_btnRefresh,1,Qt::AlignHCenter);








//      //add to vertical layout

   _layoutV=new QVBoxLayout(this);
    _layoutV->addSpacing(10);
   _layoutV->addWidget(_labelTitle);
   _layoutV->addSpacing(30);
   _layoutV->addWidget(_tableView,1,Qt::AlignHCenter);
   _layoutV->addLayout(_layoutButtonTop);
   _layoutV->addStretch(1);


    //connect

   connect(_btnRefresh,SIGNAL(clicked()),this,SLOT(refresh()));



}


void list_adherent_emprunt::refresh(){


    EmpruntDatabase *emprunt_db=new EmpruntDatabase;
    std::vector<Emprunt>emprunt_list = emprunt_db->select_all_emprunts();

      _model=new QStandardItemModel(emprunt_list.size(),14,this);

      //add into model from database

      for(int i=0;i<emprunt_list.size();i++)
      {
         _model->setData(_model->index(i,0),emprunt_list[i].get_adherent().get_id());
         _model->setData(_model->index(i,1),emprunt_list[i].get_article().get_id());
         _model->setData(_model->index(i,2),QString::fromStdString(emprunt_list[i].get_adherent().get_nom()));
         _model->setData(_model->index(i,3),QString::fromStdString(emprunt_list[i].get_adherent().get_prenom()));
         _model->setData(_model->index(i,4),QString::fromStdString(emprunt_list[i].get_adherent().get_date_naissance()));
         _model->setData(_model->index(i,5),QString::fromStdString(emprunt_list[i].get_adherent().get_status()));
         _model->setData(_model->index(i,6),QString::fromStdString(emprunt_list[i].get_adherent().get_mail()));
         _model->setData(_model->index(i,7),QString::fromStdString(emprunt_list[i].get_adherent().get_tel()));
         _model->setData(_model->index(i,8),QString::fromStdString(emprunt_list[i].get_adherent().get_rue()+" "+
           emprunt_list[i].get_adherent().get_ville()+" "+QString::number(emprunt_list[i].get_adherent().get_code_postale()).toStdString()+" "+
                 emprunt_list[i].get_adherent().get_pays()));
         _model->setData(_model->index(i,9),QString::fromStdString(emprunt_list[i].get_article().get_titre()));
         _model->setData(_model->index(i,10),QString::fromStdString(emprunt_list[i].get_article().get_genre()));
         _model->setData(_model->index(i,11),QString::fromStdString(emprunt_list[i].get_article().get_type()));
         _model->setData(_model->index(i,12),QString::fromStdString(emprunt_list[i].get_date_emprunt()));
         if(emprunt_list[i].get_article().get_empruntable())
            _model->setData(_model->index(i,13),"Oui");
         else
             _model->setData(_model->index(i,13),"Non");

      }




         _model->setHorizontalHeaderLabels(_listHeaderTable);
         _tableView->verticalHeader()->setMinimumWidth(30);
         _tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


               //set model into tableview

           _tableView->setModel(_model);
           _tableView->horizontalHeader()->setStretchLastSection(true);
           _tableView->setColumnHidden(0,true);
           _tableView->setColumnHidden(1,true);




}
