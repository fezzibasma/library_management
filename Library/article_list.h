#ifndef ARTICLE_LIST_H
#define ARTICLE_LIST_H

#include <QtWidgets>
#include "article_add.h"

class ArticleList : public QWidget
{
    Q_OBJECT

private:

    //list
        QStringList _listHeaderTable;


    //article Add

       ArticleAdd * _articleAdd;


    //label

       QLabel * _labelTitle;



        //tableview
         QTableView * _tableView;

        //model
          QStandardItemModel* _model;



          //button
          QPushButton *   _btnDelete;
          QPushButton *  _btnClose;
         QPushButton*  _btnValidate;
         QPushButton * _btnAdd;
         QPushButton * _btnRefresh;


          //layout

          QVBoxLayout * _layoutV;
          QHBoxLayout * _layoutButtonTop;
          QHBoxLayout * _layoutButtonBottom;




public:
    explicit ArticleList(QWidget *parent = 0);

signals:

public slots:

          void delete_article();
          void refresh_model();
          void save();



};

#endif // ARTICLE_LIST_H
