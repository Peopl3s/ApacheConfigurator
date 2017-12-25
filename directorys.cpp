#include <QtWidgets>
#include <QtCore>
#include "directorys.h"

Directory::Directory(QWidget *p):QWidget(p)
{
    directorys=new QLabel("Директории");
    directorys->setObjectName("Plug");


    mainDir=new QLabel("Main Directory");

    mainDirInfo=new QLabel;
    mainDirInfo->setPixmap(QPixmap("help.png"));
    mainDirInfo->setToolTip("Здесь должна быть указана главная директория, которую вы установили как DocumentRoot.\n"
                            "Конфигрурация Options добавляется из раздела Настроек.");
    mainDirline=new QLineEdit;

    addons=new QLabel("Дополнительные директории");
    addons->setObjectName("APlug");

    adddir=new QPushButton("Добавить директорию");

    d=new QTextEdit;
    d->setText("<Directory />\nOptions FollowSymLinks\nAllowOverride None\nOrder deny,allow\nDeny from all\n</Directory>");


    connect(mainDirline,SIGNAL(editingFinished()),this,SLOT(changeMainDirectory()));

    connect(adddir,SIGNAL(clicked()),this,SLOT(addDirectory()));


   createLayout();

   setqss();

}


void Directory::changeMainDirectory()
{
    QString di=mainDirline->text();

    QFile file(conf);


    QString str{};

   readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\<Directory\\s([\"a-zA-z0-9_/\:]{2,})\\>"))!=-1)
    {

        if(!di.isEmpty())
        {
            qDebug()<<"Di"<<di;

            di.replace("\\","/");

            if(QFile(di).exists())
            {
                str.replace(QRegExp("\\<Directory\\s([\"a-zA-z0-9_/\:]{2,})\\>"),"<Directory \""+di+"\">");

            }else QMessageBox::warning(0,"Directory","Некорректный путь");

            if (!op.isEmpty())
            {
                qDebug()<<"Not empty";

                int pos=str.indexOf(QRegExp("\\<Directory\\s([\"a-zA-z0-9_/\:]{2,})\\>"));
                int pos2=str.indexOf(QRegExp("Options\\s([a-zA-Z ]{2,})\\s{3,}"),pos);

                QString opp{"Options "};

                foreach(const auto &o,op)
                {
                    opp+=o+" ";
                }

                qDebug()<<opp;

                int le=str.indexOf("\n",pos2)-pos2;

                str.replace(pos2,le,opp);
            }

        }

    }else{

        qDebug()<<"fuck u";

    }
    ss<<str;
    file.close();
}

void Directory::setOptions(const QSet<QString>&s)
{
    op=s;
}


void Directory::setFileConf(const QString &filename)
{

    conf=filename;
    qDebug()<<"config: "<<conf;
}

void Directory::addDirectory()
{
    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    QString direct=d->toPlainText();

    int pos=str.lastIndexOf(QRegExp("\\</Directory\\>"))+13;

    if(pos!=-1)
    {
    str.insert(pos,"\n"+direct+"\n");
    }

    ss<<str;

    file.close();
}

void Directory::createLayout()
{

    QVBoxLayout *vmain=new QVBoxLayout;

    vmain->addWidget(directorys);
    vmain->setAlignment(directorys,Qt::AlignLeft);

    QVBoxLayout *v1=new QVBoxLayout;

    QVBoxLayout *v2=new QVBoxLayout;

    QVBoxLayout *v3=new QVBoxLayout;

    QHBoxLayout *h=new QHBoxLayout;

    v1->addWidget(mainDir);

    v2->addWidget(mainDirInfo);

    v3->addWidget(mainDirline);

    h->addLayout(v1);
    h->addLayout(v2);
    h->addLayout(v3);
    h->addStretch(1);


    vmain->addLayout(h);

    vmain->addWidget(addons);
    vmain->setAlignment(addons,Qt::AlignLeft);
    vmain->setSpacing(10);


    QHBoxLayout *hh=new QHBoxLayout;

    QHBoxLayout *hh2=new QHBoxLayout;

    hh->addWidget(d);
    hh->addStretch(1);

    hh2->addWidget(adddir);

    hh2->addStretch(1);

    vmain->addLayout(hh);
    vmain->addLayout(hh2);


    QLabel *aff=new QLabel;
    aff->setPixmap(QPixmap("apachef.png"));

    QHBoxLayout *xb=new QHBoxLayout;

    vmain->addSpacing(10);
    vmain->addStretch(1);

    xb->addLayout(vmain);
    xb->addStretch(1);

    xb->addWidget(aff);

    setLayout(xb);
}

void Directory::readFile(QFile &file, QString &str)
{
    if(file.open(QIODevice::ReadWrite))
    {

        str= file.readAll();

        //     qDebug()<<str;
    }
    else
    {
        qDebug()<< "don't open file";
        QMessageBox::warning(0,"Error","Файл не существует");
    }
    file.close();
}

void Directory::setqss()
{
    QFile file("dir.qss");

    file.open(QFile::ReadOnly);

    QString strCSS = QLatin1String(file.readAll());

    this->setStyleSheet(strCSS);
}
