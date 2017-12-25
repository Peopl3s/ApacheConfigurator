#ifndef APACHE
#define APACHE
#include <QtWidgets>
#include <QtCore>
#include "general.h"
#include "config.h"
#include "directorys.h"
#include "addmoduls.h"

typedef General *pgen;
Q_DECLARE_METATYPE(pgen)

typedef Config *pcon;
Q_DECLARE_METATYPE(pcon)

class Apache final: public QWidget
{
    Q_OBJECT

public:

   explicit Apache(QWidget *p=0);

    ~Apache(){}

    Apache(const Apache &am)=delete;

    Apache& operator=(const Apache &am)=delete;

public slots:

    void changeWindow(QListWidgetItem *item);

    void setFilename(const QString &s);

    void createConnections();

    void setqss();

private:

    QListWidget *lw;

    //  QSplitter *sp;
    General *general;

    QString filename;

    Config *config;

    QMap<QString,int>map;

    QStackedWidget *sw;

    Directory *dir;

    AddModuls *am;
};

#endif // APACHE

