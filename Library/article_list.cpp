#include "article_list.h"

ArticleList::ArticleList(QWidget *parent) :
    QWidget(parent)
{

        this->setFixedSize(740,480);


      //tableview
      _tableView=new QTableView;
      _tableView->setFixedSize(700,300);


      //label
      _labelTitle=new QLabel("Les articles non empruntés");
      _labelTitle->setAlignment(Qt::AlignHCenter);

      //button
      _btnDelete=new QPushButton("Supprimer");
      _btnValidate=new QPushButton("Enregistrer");
      _btnAdd=new QPushButton("Ajouter");
      _btnRefresh=new QPushButton("Actualiser");






       //model
        ArticleDatabase *article_db=new ArticleDatabase;
        std::vector<Article>articles_list = article_db->select_articles_no_emprunter();

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


       //layout button bottom
          _layoutButtonBottom=new QHBoxLayout;
          _layoutButtonBottom->addWidget(_btnRefresh,1,Qt::AlignLeft);
          _layoutButtonBottom->addWidget(_btnValidate,1,Qt::AlignRight);


       //layout button Top

         _layoutButtonTop=new QHBoxLayout;
         _layoutButtonTop->addWidget(_btnDelete,1,Qt::AlignHCenter);
         _layoutButtonTop->addWidget(_btnAdd,1,Qt::AlignHCenter);




       _listHeaderTable <<"Id"<<"Titre"<<"Empruntable"<<"Exemplaire"<<"Durée max"<<"Genre"<<"Type";
       _model->setHorizontalHeaderLabels(_listHeaderTable);
       _tableView->verticalHeader()->setMinimumWidth(30);
//       _tableView->setSelectionMode(QAbstractItemView::SingleSelection);




//      //add to vertical layout

       _layoutV=new QVBoxLayout(this);
        _layoutV->addSpacing(10);
       _layoutV->addWidget(_labelTitle);
       _layoutV->addSpacing(30);
       _layoutV->addWidget(_tableView,1,Qt::AlignHCenter);
       _layoutV->addLayout(_layoutButtonTop);
       _layoutV->addStretch(1);
       _layoutV->addLayout(_layoutButtonBottom);


//      //set model into tableview

      _tableView->setModel(_model);
      _tableView->horizontalHeader()->setStretchLastSection(true);
      _tableView->setColumnHidden(0,true);

//     //article add

      _articleAdd=new ArticleAdd;



     //connect


     connect(_btnDelete,SIGNAL(clicked()),this,SLOT(delete_article()));
     connect(_btnAdd,SIGNAL(clicked()),_articleAdd,SLOT(show()));
     connect(_btnRefresh,SIGNAL(clicked()),this,SLOT(refresh_model()));
     connect(_btnValidate,SIGNAL(clicked()),this,SLOT(save()));

}









void ArticleList::delete_article(){



    int row=_tableView->currentIndex().row();
    int id=_model->data(_model->index(row,0)).toString().toInt();

    Article article;
    article.set_id(id);

    ArticleDatabase *article_db=new ArticleDatabase;
    article_db->delete_article(article);


    refresh_model();



}

void ArticleList::save(){


    if(_model->rowCount()!=0){

        ArticleDatabase *article_db=new ArticleDatabase;


        for( int i=0;i<_model->rowCount();i++){


            Article article;

            article.set_id(_model->data(_model->index(i,0)).toString().toInt());
            article.set_titre(_model->data(_model->index(i,1)).toString().toStdString());
            if(_model->data(_model->index(i,2)).toString().toUpper()==QString("Oui").toUpper()){
             article.set_empruntable(true);
            }else{
                article.set_empruntable(false);
            }
            article.set_exemplaire(_model->data(_model->index(i,3)).toString().toInt());
            article.set_duree_max(_model->data(_model->index(i,4)).toString().toInt());
            article.set_genre(_model->data(_model->index(i,5)).toString().toStdString());
            article.set_type(_model->data(_model->index(i,6)).toString().toStdString());

            article_db->update_article(article);




        }
        QMessageBox msg;
        msg.setText("Bien eregistrer !");
        msg.exec();


    }


}

void ArticleList::refresh_model(){

    ArticleDatabase *article_db=new ArticleDatabase;
    std::vector<Article>articles_list = article_db->select_articles_no_emprunter();

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
