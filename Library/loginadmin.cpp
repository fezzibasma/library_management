#include "loginadmin.h"



loginAdmin::loginAdmin(QWidget *parent) :
    QWidget(parent)
{

    this->setFixedSize(QSize(600,230));

    //layout
    _layoutV=new QVBoxLayout(this);
    _layoutG=new QGridLayout;

    //label

     _labelTitle=new QLabel("Login admin");
     _labelUsername=new QLabel("Username");
     _labelPassword=new QLabel("Password");


    //lineEdit

     _editUsername=new QLineEdit;
     _editPassword=new QLineEdit;
     _editUsername->setPlaceholderText("username...");
     _editPassword->setPlaceholderText("password...");
     _editPassword->setEchoMode(QLineEdit::Password);


    //button

    _btnOk=new QPushButton("Connexion");
    _btnOk->setFixedWidth(100);

    //add to GridLayout

     _layoutG->addWidget(_labelUsername,0,0);
     _layoutG->addWidget(_editUsername,0,1);
     _layoutG->addWidget(_labelPassword,1,0);
     _layoutG->addWidget(_editPassword,1,1);

    //layout H


     // add to vertical layout


     _layoutV->addWidget(_labelTitle,1,Qt::AlignCenter);
     _layoutV->addStretch(2);
     _layoutV->setMargin(40);
     _layoutV->addLayout(_layoutG);
     _layoutV->addStretch(1);
     _layoutV->addWidget(_btnOk,1,Qt::AlignRight);
     _layoutV->addStretch(1);

     _homeAdmin=new homeAdmin;


     //connect

     connect(_btnOk,SIGNAL(clicked()),this,SLOT(connexionAdmin()));


}


void loginAdmin::connexionAdmin(){

   QMessageBox msg;
   if(_editUsername->text()=="" || _editPassword->text() =="")
    {


       msg.setText("Veuillez entrer tous les champs !");
       msg.exec();

    }else{

       AdminDatabase * admin_db=new AdminDatabase;
       Admin admin;
       admin.set_username(_editUsername->text().toStdString());
       admin.set_password(_editPassword->text().toStdString());

       if (admin_db->select_admin(admin).size()==0) {

           msg.setText("Identifiant ou mot de passe incorrect !");
           msg.exec();

       }else{
          _homeAdmin->show();
       }


    }


//    std::cout<<admin.get_username()<<"  "<<admin.set_username();



//    Admin admin;
//    admin.set_username("admin");
//    admin.set_password("123456");
//    std::cout<< admin_db->add_admin(admin);

//  std::cout<<  admin_db->select_all_admins().size();



    std::cout<<"hhhhhhhhhhhhh"<<std::endl;
}
