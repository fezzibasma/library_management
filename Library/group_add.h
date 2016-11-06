#ifndef GROUP_ADD_H
#define GROUP_ADD_H

#include <QtWidgets>


class groupAdd : public QWidget
{
    Q_OBJECT
private:

    //point
   QPoint _clickPos;

   //bool

   bool _flagForMessageBox;
   bool _flagButtonLeft;

  //labels

   QLabel * _labelName;
   QLabel * _labelTitle;
   QLabel * _labelStudentNbr;

   //spinbox

   QSpinBox * _spinStudentNbr;


   //LineEdit
   QLineEdit * _editName;

   //button
   QPushButton * _btnAdd;
   QPushButton * _btnClose;
   QPushButton * _btnClearName;
   QPushButton * _btnClearNumber;

   //layouts

   QVBoxLayout *_layoutV;
   QHBoxLayout * _layoutH;
   QGridLayout *_gridLayout;

public:
   explicit groupAdd(QWidget *parent = 0);
   virtual QSize	sizeHint () const;
//   void mouseMoveEvent(QMouseEvent * event);
//   void mousePressEvent(QMouseEvent *event);

   ~groupAdd();

signals:

public slots:



};

#endif // GROUP_ADD_H
