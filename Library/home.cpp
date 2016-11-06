#include "home.h"

home::home(QWidget *parent) :
    QWidget(parent)
{

    this->setFixedSize(QSize(400,150));


    //label

    _labelTitle=new QLabel("Accueil");

    //layout

    _layoutV=new QVBoxLayout(this);

    //button

    _btnAdmin=new QPushButton("Espace admin");
    _btnAdherent=new QPushButton("Espace Adherent");




    //add to layout

    _layoutV->addStretch(1);
    _layoutV->addWidget(_labelTitle,0,Qt::AlignHCenter);
    _layoutV->addStretch(1);
    _layoutV->addWidget(_btnAdmin);
    _layoutV->addWidget(_btnAdherent);
    _layoutV->addStretch(1);

    //forms
    loginAdherent *adh=new loginAdherent;
    loginAdmin * adm=new loginAdmin;


    //connect
    connect(_btnAdmin,SIGNAL(clicked()),adm,SLOT(show()));
    connect(_btnAdherent,SIGNAL(clicked()),adh,SLOT(show()));



}
