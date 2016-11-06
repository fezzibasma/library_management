#ifndef LOGINADHERENT_H
#define LOGINADHERENT_H

#include <QtWidgets>
#include "src/AdherentDatabase.h"
#include "adherent_emprunt.h"


class loginAdherent : public QWidget
{
    Q_OBJECT

private:

    //label

    QLabel * _labelTitleLogin;
    QLabel * _labelTitleInsciption;
    QLabel * _labelLoginUsername;
    QLabel * _labelLoginPassword;
    QLabel * _labelNom;
    QLabel * _labelPrenom;
    QLabel * _labelDateNaissance;
    QLabel * _labelStatus;
    QLabel * _labelUsername;
    QLabel * _labelPassword;
    QLabel * _labelMail;
    QLabel * _labelTel;
    QLabel * _labelVille;
    QLabel * _labelCodePostale;
    QLabel * _labelPays;
    QLabel * _labelRue;



    //adherent emprunt

    Adherent_emprunt * _adherent_emprunt;


    //editLine

    QLineEdit * _editLoginUsername;
    QLineEdit * _editLoginPassword;
    QLineEdit * _editNom;
    QLineEdit * _editPrenom;
    QLineEdit * _editDateNaissance;
    QLineEdit * _editStatus;
    QLineEdit * _editUsername;
    QLineEdit * _editPassword;
    QLineEdit * _editMail;
    QLineEdit * _editTel;
    QLineEdit * _editVille;
    QSpinBox * _editCodePostale;
    QLineEdit * _editPays;
    QLineEdit * _editRue;


    //button
    QPushButton * _btnConnect;
    QPushButton * _btnInscription;
    QPushButton * _btnClear_inscription;
    QPushButton * _btnClear_connect;


    //layout

    QVBoxLayout * _layoutV_connect;
    QVBoxLayout * _layoutV_inscription;
    QHBoxLayout * _layoutH;
    QHBoxLayout * _layoutBtn_inscription;
    QHBoxLayout * _layoutBtn_connect;
    QGridLayout * _layoutG_connect;
    QGridLayout * _layoutG_inscrption;









public:
    explicit loginAdherent(QWidget *parent = 0);


signals:

    void send_adherent(Adherent* adherent);

public slots:

    void inscriptionAdherent();
    void connexionAdherent();
    void clear_inscription();
    void clear_connect();


};

#endif // LOGINADHERENT_H


