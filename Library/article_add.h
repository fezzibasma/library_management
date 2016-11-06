#ifndef ARTICLE_ADD_H
#define ARTICLE_ADD_H

#include <QtWidgets>
#include "src/ArticleDatabase.h"

class ArticleAdd : public QWidget
{
    Q_OBJECT



private:

    //label


    QLabel * _labelTitreArticle;
    QLabel * _labelTitre;
    QLabel * _labelEmpruntable;
    QLabel * _labelExemplaire;
    QLabel * _labelDureeMax;
    QLabel * _labelGenre;
    QLabel * _labelType;





    //editLine
    QLineEdit * _editTitre;
    QLineEdit * _editGenre;
    QLineEdit * _editType;

    //checkbox
     QCheckBox * _checkEmpruntable;

    //spin box
    QSpinBox * _spinExemplaire;
    QSpinBox * _spinDureeMax;

    //button

    QPushButton * _btnAdd;
    QPushButton * _btnClear;


    //layout


    QVBoxLayout * _layoutV;
    QHBoxLayout * _layoutBtn;
    QGridLayout * _layoutG;



public:
    explicit ArticleAdd(QWidget *parent = 0);

signals:

public slots:


    void add_article();
    void clear_add();


};


#endif // ARTICLE_ADD_H
