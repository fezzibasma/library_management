#ifndef HOMEADMIN_H
#define HOMEADMIN_H

#include <QtWidgets>
#include "article_list.h"
#include "list_adherent_emprunt.h"

class homeAdmin : public QWidget
{
    Q_OBJECT

private:


    //form

    ArticleList * _articleList;
    list_adherent_emprunt * _historiqueEmprunt;

    //button
        QPushButton * _btn_article;
        QPushButton * _btn_adherent_emprunt;


     //layout

        QVBoxLayout * _layoutV;



public:
    explicit homeAdmin(QWidget *parent = 0);

signals:

public slots:

};

#endif // HOMEADMIN_H
