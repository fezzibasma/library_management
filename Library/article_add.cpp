#include "article_add.h"

ArticleAdd::ArticleAdd(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(QSize(600,450));

    //label



     _labelTitre=new QLabel("Ajouter article");
      _labelTitreArticle=new QLabel("Titre");
     _labelEmpruntable=new QLabel("Empruntable");
     _labelExemplaire=new QLabel("Exemplaire");
     _labelDureeMax=new QLabel("Duree max / jr");
     _labelGenre=new QLabel("Genre");
     _labelType=new QLabel("Type");




    //editLine

     _editTitre=new QLineEdit;
     _editGenre=new QLineEdit;
     _editType=new QLineEdit;


     _editTitre->setPlaceholderText("Titre...");
     _editGenre->setPlaceholderText("Genre...");
     _editType->setPlaceholderText("Type...");



     //spinbox
     _spinExemplaire=new QSpinBox;
     _spinDureeMax=new QSpinBox;
     _spinDureeMax->setMaximum(999999999);
     _spinExemplaire->setMaximum(999999999);


     //checkbox

      _checkEmpruntable=new QCheckBox;
      _checkEmpruntable->setChecked(true);




    //button
    _btnAdd=new QPushButton("Ajouter");
    _btnClear=new QPushButton("vider");
    _btnAdd->setFixedWidth(90);
    _btnClear->setFixedWidth(90);




    //layout


    _layoutV=new QVBoxLayout(this);
    _layoutG=new QGridLayout;
    _layoutBtn=new QHBoxLayout;





    //add to grid layout inscription

    _layoutG->addWidget(_labelTitreArticle,0,0);
    _layoutG->addWidget(_editTitre,0,1);
    _layoutG->addWidget(_labelEmpruntable,1,0);
    _layoutG->addWidget(_checkEmpruntable,1,1);
    _layoutG->addWidget(_labelExemplaire,2,0);
    _layoutG->addWidget(_spinExemplaire,2,1);
    _layoutG->addWidget(_labelDureeMax,3,0);
    _layoutG->addWidget(_spinDureeMax,3,1);
    _layoutG->addWidget(_labelGenre,4,0);
    _layoutG->addWidget(_editGenre,4,1);
    _layoutG->addWidget(_labelType,5,0);
    _layoutG->addWidget(_editType,5,1);



    //lyaout btn inscription
       _layoutBtn->addWidget(_btnClear,1,Qt::AlignLeft);
       _layoutBtn->addWidget(_btnAdd,1,Qt::AlignRight);




    //add to layout v inscription

    _layoutV->addWidget(_labelTitre,0,Qt::AlignHCenter);
    _layoutV->addStretch(1);
    _layoutV->setMargin(60);
    _layoutV->addLayout(_layoutG);
    _layoutV->addStretch(1);
    _layoutV->addLayout(_layoutBtn);






    //connect

    connect(_btnAdd,SIGNAL(clicked()),this,SLOT(add_article()));
    connect(_btnClear,SIGNAL(clicked()),this,SLOT(clear_add()));


}




void ArticleAdd::clear_add(){





    _editTitre->setText("");
    _editGenre->setText("");
    _editType->setText("");
    _spinExemplaire->setValue(0);
    _spinDureeMax->setValue(0);
    _checkEmpruntable->setChecked(true);


}



void ArticleAdd::add_article(){

    QMessageBox msg;




    if( _editTitre->text() =="" || _editGenre->text()=="" || _editType->text()==""){


             msg.setText("Veuillez entrer tous les champs !");
             msg.exec();

    }else{

            Article article;
            article.set_titre(_editTitre->text().toStdString());
            article.set_genre(_editGenre->text().toStdString());
            article.set_type(_editType->text().toStdString());
            article.set_duree_max(_spinDureeMax->value());
            article.set_exemplaire(_spinExemplaire->value());
            article.set_empruntable(_checkEmpruntable->isChecked());

            ArticleDatabase * article_db=new ArticleDatabase;

           if( article_db->add_article(article))
           {
                msg.setText("Article bien enregistré !");
           }else{
                msg.setText("Non enregistrer: Veuillez verfier tous les champs !");
           }

            msg.exec();

    }
}



