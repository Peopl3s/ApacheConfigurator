#include <QtWidgets>
#include <QtCore>
#include "general.h"
#include "config.h"
#include "directorys.h"
#include "addmoduls.h"
#include "apache.h"

Apache::Apache(QWidget *p):QWidget(p)
{
    lw=new QListWidget;
    lw->setFixedWidth(150);

    sw=new QStackedWidget;


    general=new General;

    config=new Config;

    dir=new Directory;

    am=new AddModuls;

    createConnections();


    map.insert("Общее",0);

    map.insert("Настройки параметров",1);

    map.insert("Директории",2);

    map.insert("Подключаемые модули",3);



    foreach(QString str, QStringList()<< "Общее"<< "Настройки параметров" <<"Директории" << "Подключаемые модули")
    {
        QListWidgetItem *pitem = new QListWidgetItem(QIcon("item.png"),str, lw);

    }



    //       sp=new QSplitter(Qt::Horizontal);


    sw->addWidget(general);
    sw->addWidget(config);
    sw->addWidget(dir);
    sw->addWidget(am);

    //connection


    QHBoxLayout *h=new QHBoxLayout;
    h->addWidget(lw);
    h->addWidget(sw);

    setLayout(h);

    setqss();
}


void Apache::changeWindow(QListWidgetItem *item)
{
    QString widgetname=item->text();

    qDebug()<<map[widgetname];

    sw->setCurrentIndex(map[widgetname]);

    if(widgetname=="Директории")
    {
        dir->setOptions(config->getOptions());
    }
}

void Apache::setFilename(const QString &s)
{
    filename=s;
    qDebug()<<"Установлен: "+filename;
}


void Apache::createConnections()
{

    connect(general,SIGNAL(selectedFile(QString)),this,SLOT(setFilename(QString)));

    connect(lw,SIGNAL(itemActivated(QListWidgetItem*)),this,SLOT(changeWindow(QListWidgetItem*)));

    connect(general,SIGNAL(selectedFile(QString)),config,SLOT(setFileConf(QString)));

    connect(general,SIGNAL(selectedFile(QString)),dir,SLOT(setFileConf(QString)));

    connect(general,SIGNAL(selectedFile(QString)),am,SLOT(setFileConf(QString)));
}

void Apache::setqss()
{
    QFile file("apache.qss");

    file.open(QFile::ReadOnly);

    QString strCSS = QLatin1String(file.readAll());

    this->setStyleSheet(strCSS);
}
