#ifndef ADHERENT_EMPRUNT_H
#define ADHERENT_EMPRUNT_H

#include <QtWidgets>
#include "src/AdherentDatabase.h"
#include "src/ArticleDatabase.h"
#include "src/EmpruntDatabase.h"

class Adherent_emprunt : public QWidget
{

    Q_OBJECT

private:





    int _idAdherent;


    //label
    QLabel * _labelTitle;
    QLabel * _labelTitleEmprunt;
    QLabel * _labelWelcome;


    //list
     QStringList _listHeaderTable;
     QStringList _listHeaderTableEmprunt;




        //tableview
         QTableView * _tableView;

         QTableView * _tableViewEmprunt;

        //model
          QStandardItemModel* _model;
          QStandardItemModel *_modelEmprunt;





          //button

         QPushButton * _btnEmprunt;
         QPushButton * _btnAnnuler;
         QPushButton * _btnRefreshArticle;
         QPushButton * _btnRefreshEmprunt;



          //layout

          QVBoxLayout * _layoutV;
          QHBoxLayout * _layoutButtonTop;
          QHBoxLayout * _layoutButtonBottom;













public:
    explicit Adherent_emprunt(QWidget *parent = 0);


signals:

public slots:
    void get_adherent(Adherent* adherent);
    void add_emprunt();
    void refresh_emprunt();
    void annuler_emprunt();
    void refresh_articles();

};

#endif // ADHERENT_EMPRUNT_H
