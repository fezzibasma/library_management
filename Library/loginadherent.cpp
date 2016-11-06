#include "loginadherent.h"

loginAdherent::loginAdherent(QWidget *parent) :
    QWidget(parent)
{


    this->setFixedSize(QSize(950,550));

    //label

     _labelTitleInsciption=new QLabel("Inscription adhérent");
     _labelTitleLogin=new QLabel("Login adhérent");
     _labelLoginUsername=new QLabel("Username");
     _labelLoginPassword=new QLabel("Password");
     _labelNom=new QLabel("Nom");
     _labelPrenom=new QLabel("Prenom");
     _labelDateNaissance=new QLabel("Date de naissance");
     _labelStatus=new QLabel("Statut");
     _labelUsername=new QLabel("Username");
     _labelPassword=new QLabel("Password");
     _labelMail=new QLabel("Mail");
     _labelTel=new QLabel("Tel");
     _labelVille=new QLabel("Ville");
     _labelCodePostale=new QLabel("Code postal");
     _labelPays=new QLabel("Pays");
     _labelRue=new QLabel("Rue");




    //editLine

     _editLoginUsername=new QLineEdit;
     _editLoginPassword=new QLineEdit;
     _editNom=new QLineEdit;
     _editPrenom=new QLineEdit;
     _editDateNaissance=new QLineEdit;
     _editStatus=new QLineEdit;
     _editUsername=new QLineEdit;
     _editPassword=new QLineEdit;
     _editMail=new QLineEdit;
     _editTel=new QLineEdit;
     _editVille=new QLineEdit;
     _editPays=new QLineEdit;
     _editRue=new QLineEdit;

     //spinbox
     _editCodePostale=new QSpinBox;
     _editCodePostale->setMaximum(9999999999);





    _editDateNaissance->setInputMask("00/00/0000");
    _editDateNaissance->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy"));
    _editLoginPassword->setEchoMode(QLineEdit::Password);


     _editLoginUsername->setPlaceholderText("username...");
     _editLoginPassword->setPlaceholderText("password...");
     _editNom->setPlaceholderText("nom...");
     _editPrenom->setPlaceholderText("prenom...");
     _editStatus->setPlaceholderText("statut...");
     _editUsername->setPlaceholderText("username...");
     _editPassword->setPlaceholderText("password...");
     _editMail->setPlaceholderText("mail...");
     _editTel->setPlaceholderText("tel...");
     _editVille->setPlaceholderText("ville...");
     _editPays->setPlaceholderText("pays...");
     _editRue->setPlaceholderText("rue...");


    //button
    _btnConnect=new QPushButton("Connexion");
    _btnInscription=new QPushButton("Inscription");
    _btnClear_inscription=new QPushButton("vider");
    _btnClear_connect=new QPushButton("vider");
    _btnConnect->setFixedWidth(90);
    _btnInscription->setFixedWidth(90);
    _btnClear_inscription->setFixedWidth(90);
    _btnClear_connect->setFixedWidth(90);



    //layout

    _layoutH=new QHBoxLayout(this);
    _layoutV_connect=new QVBoxLayout;
    _layoutV_inscription=new QVBoxLayout;
    _layoutG_connect=new QGridLayout;
    _layoutG_inscrption=new QGridLayout;
    _layoutBtn_inscription=new QHBoxLayout;
    _layoutBtn_connect=new QHBoxLayout;


    //add to grid layout connect

    _layoutG_connect->addWidget(_labelLoginUsername,0,0);
    _layoutG_connect->addWidget(_editLoginUsername,0,1);
    _layoutG_connect->addWidget(_labelLoginPassword,1,0);
    _layoutG_connect->addWidget(_editLoginPassword,1,1);




    //add to grid layout inscription

    _layoutG_inscrption->addWidget(_labelNom,0,0);
    _layoutG_inscrption->addWidget(_editNom,0,1);
    _layoutG_inscrption->addWidget(_labelPrenom,1,0);
    _layoutG_inscrption->addWidget(_editPrenom,1,1);
    _layoutG_inscrption->addWidget(_labelDateNaissance,2,0);
    _layoutG_inscrption->addWidget(_editDateNaissance,2,1);
    _layoutG_inscrption->addWidget(_labelStatus,3,0);
    _layoutG_inscrption->addWidget(_editStatus,3,1);
    _layoutG_inscrption->addWidget(_labelUsername,4,0);
    _layoutG_inscrption->addWidget(_editUsername,4,1);
    _layoutG_inscrption->addWidget(_labelPassword,5,0);
    _layoutG_inscrption->addWidget(_editPassword,5,1);
    _layoutG_inscrption->addWidget(_labelMail,6,0);
    _layoutG_inscrption->addWidget(_editMail,6,1);
    _layoutG_inscrption->addWidget(_labelTel,7,0);
    _layoutG_inscrption->addWidget(_editTel,7,1);
    _layoutG_inscrption->addWidget(_labelVille,8,0);
    _layoutG_inscrption->addWidget(_editVille,8,1);
    _layoutG_inscrption->addWidget(_labelCodePostale,9,0);
    _layoutG_inscrption->addWidget(_editCodePostale,9,1);
    _layoutG_inscrption->addWidget(_labelPays,10,0);
    _layoutG_inscrption->addWidget(_editPays,10,1);
    _layoutG_inscrption->addWidget(_labelRue,11,0);
    _layoutG_inscrption->addWidget(_editRue,11,1);


    //lyaout btn inscription
       _layoutBtn_inscription->addWidget(_btnClear_inscription,1,Qt::AlignLeft);
       _layoutBtn_inscription->addWidget(_btnInscription,1,Qt::AlignRight);


     //layout btn connect
       _layoutBtn_connect->addWidget(_btnClear_connect,1,Qt::AlignLeft);
       _layoutBtn_connect->addWidget(_btnConnect,1,Qt::AlignRight);


    //add to layout v inscription

    _layoutV_inscription->addStretch(1);
    _layoutV_inscription->addWidget(_labelTitleInsciption);
    _layoutV_inscription->addSpacing(30);
    _layoutV_inscription->addLayout(_layoutG_inscrption);
    _layoutV_inscription->addSpacing(10);
    _layoutV_inscription->addLayout(_layoutBtn_inscription);
    _layoutV_inscription->addStretch(1);


    // add to layout v connect
    _layoutV_connect->addStretch(1);
    _layoutV_connect->addWidget(_labelTitleLogin);
    _layoutV_connect->addSpacing(40);
    _layoutV_connect->addLayout(_layoutG_connect);
    _layoutV_connect->addSpacing(20);
    _layoutV_connect->addLayout(_layoutBtn_connect);
    _layoutV_connect->addStretch(1);
    _layoutV_connect->setAlignment(Qt::AlignVCenter);


    // add to layout h

    _layoutH->addLayout(_layoutV_connect);
    _layoutH->addSpacing(100);
    _layoutH->addLayout(_layoutV_inscription);


    //adherent emprunt

    _adherent_emprunt=new Adherent_emprunt;

    //connect

    connect(this,SIGNAL(send_adherent(Adherent*)),_adherent_emprunt,SLOT(get_adherent(Adherent*)));


    connect(_btnInscription,SIGNAL(clicked()),this,SLOT(inscriptionAdherent()));
    connect(_btnClear_inscription,SIGNAL(clicked()),this,SLOT(clear_inscription()));
    connect(_btnClear_connect,SIGNAL(clicked()),this,SLOT(clear_connect()));
    connect(_btnConnect,SIGNAL(clicked()),this,SLOT(connexionAdherent()));

}


void loginAdherent::clear_connect(){

    _editLoginUsername->setText("");
    _editLoginPassword->setText("");
}

void loginAdherent::clear_inscription(){

    _editNom->setText("");
    _editPrenom->setText("");
    _editDateNaissance->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy"));
    _editStatus->setText("");
    _editUsername->setText("");
    _editPassword->setText("");
    _editMail->setText("");
    _editTel->setText("");
    _editVille->setText("");
    _editCodePostale->setValue(0);
    _editPays->setText("");
    _editRue->setText("");
}



void loginAdherent::inscriptionAdherent(){

    QMessageBox msg;




    if( _editNom->text() =="" || _editPrenom->text()=="" || _editDateNaissance->text()=="//" || _editStatus->text()==""
            || _editUsername->text()=="" || _editPassword->text()=="" || _editMail->text()=="" || _editTel->text()==""
            || _editVille->text()=="" || _editCodePostale->text()=="" || _editPays->text()=="" || _editRue->text()==""){


             msg.setText("Veuillez entrer tous les champs !");
             msg.exec();

    }else{

            Adherent adherent;
            adherent.set_nom(_editNom->text().toStdString());
            adherent.set_prenom(_editPrenom->text().toStdString());
            adherent.set_date_naissance(_editDateNaissance->text().toStdString());
            adherent.set_status(_editStatus->text().toStdString());
            adherent.set_username(_editUsername->text().toStdString());
            adherent.set_password(_editPassword->text().toStdString());
            adherent.set_mail(_editMail->text().toStdString());
            adherent.set_tel(_editMail->text().toStdString());
            adherent.set_ville(_editVille->text().toStdString());
            adherent.set_code_postale(_editCodePostale->value());
            adherent.set_pays(_editPays->text().toStdString());
            adherent.set_rue(_editRue->text().toStdString());

            AdherentDatabase * adh_db=new AdherentDatabase;

           if( adh_db->add_adherent(adherent))
           {
                msg.setText("Adherent bien enregister !");
           }else{
                msg.setText("Non enregistrer: username doit étre unique !");
           }

            msg.exec();

    }
}


void loginAdherent::connexionAdherent(){


    QMessageBox msg;
    if(_editLoginUsername->text()=="" || _editLoginPassword->text() =="")
     {


        msg.setText("Veuillez entrer tous les champs !");
        msg.exec();

     }else{

        AdherentDatabase * adherent_db=new AdherentDatabase;
        Adherent adherent;
        adherent.set_username(_editLoginUsername->text().toStdString());
        adherent.set_password(_editLoginPassword->text().toStdString());

        if (adherent_db->select_adherent(adherent).size()==0) {

            msg.setText("Identifiant ou mot de passe incorrect !\nVeuillez vous inscrire");
            msg.exec();

        }else{


            int id=adherent_db->select_adherent(adherent)[0].get_id();
            adherent.set_id(id);

            _adherent_emprunt->show();
            emit send_adherent(&adherent);
             clear_connect();

        }

    }


}
