#ifndef LIST_ADHERENT_EMPRUNT_H
#define LIST_ADHERENT_EMPRUNT_H

#include <QWidget>
#include "src/ArticleDatabase.h"
#include "article_add.h"
#include "src/EmpruntDatabase.h"


class list_adherent_emprunt : public QWidget
{
    Q_OBJECT

private:

    //list
        QStringList _listHeaderTable;





    //label

       QLabel * _labelTitle;



        //tableview
         QTableView * _tableView;

        //model
          QStandardItemModel* _model;



          //button
         QPushButton * _btnRefresh;



          //layout

          QVBoxLayout * _layoutV;
          QHBoxLayout * _layoutButtonTop;




public:
    explicit list_adherent_emprunt(QWidget *parent = 0);

signals:

public slots:

          void refresh();

};

#endif // LIST_ADHERENT_EMPRUNT_H
