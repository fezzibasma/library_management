#include "group_add.h"




groupAdd::groupAdd(QWidget *parent) :
    QWidget(parent,Qt::FramelessWindowHint),_flagForMessageBox(true),_flagButtonLeft(false)
{

    //center the window
    this->move(QApplication::desktop()->availableGeometry().center()-this->rect().center());
    this->setFixedSize(420,200);

    //layout
    _layoutV=new QVBoxLayout(this);
    _gridLayout=new QGridLayout(this);

    //label
    _labelName=new QLabel(tr("Name"));
    _labelTitle=new QLabel(tr("group"));
    _labelStudentNbr=new QLabel(tr("Student number :"));

    //spin

    _spinStudentNbr=new QSpinBox;

    //editLine
    _editName=new QLineEdit;
    _editName->setPlaceholderText("Group name...");

    //button
    _btnAdd=new QPushButton(QIcon("ICON/ok.png"),tr("&Ok"));
    _btnClose=new QPushButton(QIcon("ICON/cancel.png"),tr("&Cancel"));
    _btnClearName=new QPushButton(QIcon("IMG/clear.png"),"");
    _btnClearNumber=new QPushButton(QIcon("IMG/clear.png"),"");
    _btnAdd->setFixedSize(70,30);
    _btnClose->setFixedSize(80,30);

    //add widget to grid layout
    _gridLayout->addWidget(_labelName,0,0);
    _gridLayout->addWidget(_editName,0,1);
    _gridLayout->addWidget(_btnClearName,0,2);
    _gridLayout->addWidget(_labelStudentNbr,1,0);
    _gridLayout->addWidget(_spinStudentNbr,1,1);
    _gridLayout->addWidget(_btnClearNumber,1,2);

    //stylesheet
    _labelName->setStyleSheet("font-weight:bold;color:#000000;");
    _labelStudentNbr->setStyleSheet("font-weight:bold;color:#000000;");
    _labelTitle->setStyleSheet("font-size:30px;font-weight:bold;color:#000000;");

    _spinStudentNbr->setStyleSheet("border-style: solid;border-width:2px;");
    _editName->setStyleSheet("border-style: solid;border-width:2px;");
    _btnAdd->setStyleSheet("border-radius: 7px;color:#000000 ;  border-style: solid;border-width: 2px;width:100px");
    _btnClose->setStyleSheet("border-radius: 7px;color:#000000 ;  border-style: solid;border-width: 2px;width:100px");
    _btnClearName->setStyleSheet("border-style: solid;border-width: 2px; ");
    _btnClearNumber->setStyleSheet("border-style: solid;border-width: 2px; ");

//backgroud mainwindow
     QPalette Pal(palette());
     Pal.setColor(QPalette::Background, Qt::white);
     this->setAutoFillBackground(true);
     this->setPalette(Pal);

     //add to Hboxlayout
     _layoutH=new QHBoxLayout;
     _layoutH->addWidget(_btnClose,3,Qt::AlignRight);
     _layoutH->addWidget(_btnAdd,0,Qt::AlignRight);






    //add to vLayout
    _layoutV->addStretch(1);
    _layoutV->addWidget(_labelTitle,1,Qt::AlignCenter);
    _layoutV->addStretch(1);
    _layoutV->addSpacing(25);
    _layoutV->addLayout(_gridLayout);
    _layoutV->addStretch(1);
    _layoutV->addSpacing(25);
    _layoutV->addLayout(_layoutH);
    _layoutV->addStretch(1);


    //connect
}


QSize	groupAdd::sizeHint () const{
    return QSize(400,180);

}



groupAdd::~groupAdd()
{
    delete _layoutV;
}
