#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QtWidgets>
#include <iostream>
#include "src/AdminDatabase.h"
#include "homeadmin.h"

class loginAdmin : public QWidget
{
    Q_OBJECT

private:


    //home admin

    homeAdmin * _homeAdmin;

    //label
    QLabel * _labelTitle;
    QLabel * _labelUsername;
    QLabel * _labelPassword;

    //lineEdit


    QLineEdit * _editUsername;
    QLineEdit * _editPassword;

    //button

    QPushButton * _btnOk;

    //layout

    QVBoxLayout * _layoutV;
    QGridLayout * _layoutG;






public:
    explicit loginAdmin(QWidget *parent = 0);

signals:


public slots:

    void connexionAdmin();

};

#endif // LOGINADMIN_H
