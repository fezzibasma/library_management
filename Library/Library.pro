

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Library
TEMPLATE = app
LIBS += -lsqlite3


SOURCES += main.cpp\
    group_add.cpp \
    home.cpp \
    loginadmin.cpp \
    loginadherent.cpp \
    homeadmin.cpp \
    article_add.cpp \
    article_list.cpp \
    adherent_emprunt.cpp \
    list_adherent_emprunt.cpp

HEADERS  += \
    group_add.h \
    home.h \
    loginadmin.h \
    loginadherent.h \
    src/Adherent.h \
    src/AdherentDatabase.h \
    src/Admin.h \
    src/AdminDatabase.h \
    src/Amende.h \
    src/Article.h \
    src/ArticleDatabase.h \
    src/Commande.h \
    src/CommandeDatabase.h \
    src/Database.h \
    src/Emprunt.h \
    src/EmpruntDatabase.h \
    homeadmin.h \
    article_add.h \
    article_list.h \
    adherent_emprunt.h \
    list_adherent_emprunt.h

FORMS    +=

OTHER_FILES += \
    database/library.db
