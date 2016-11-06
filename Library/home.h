#ifndef HOME_H
#define HOME_H

#include<QtWidgets>
#include "loginadherent.h"
#include "loginadmin.h"

class home : public QWidget
{
    Q_OBJECT

private:

    //button
    QPushButton * _btnAdmin;
    QPushButton * _btnAdherent;

    //label

    QLabel * _labelTitle;


    //layout

    QVBoxLayout * _layoutV;



public:
    explicit home(QWidget *parent = 0);

signals:

public slots:

};

#endif // HOME_H
