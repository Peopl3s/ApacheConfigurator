#include <QtWidgets>
#include <QtCore>
#include "general.h"

General::General(QWidget *p):QWidget(p),gs("BHV","General")
{
    namepage=new QLabel("Общее");
    namepage->setObjectName("Plug");

    ap=new QLabel("Действие производимое с Apache:");

    httpd=new QLabel;
    httpd->setObjectName("Httpd");

    note=new QLabel("Отрыть файл в текстовом редаторе: ");

    opennote=new QPushButton("Открыть");



    discfilename=new QLabel("Выберите файл конфигурации сервера: ");

    labelhttpd=new QLabel("Выберите файл запуска сервера (httpd.exe): ");

    buttonhttpd=new QPushButton("Выберите файл");

    name=new QLabel;
    name->setObjectName("Name");

    dialog=new QPushButton("Выбрать файл");

    setup=new QPushButton("Установить");

    delet=new QPushButton("Удалить");

    //connection
    createConnections();

    readSettings();

    createLayout();

}

void General::selectFile()
{
    QString file=QFileDialog::getOpenFileName(0,QString("Выберите conf файл"),"C:/",QString("*.conf *.txt"));

    if (!file.isEmpty())
    {
        qDebug()<<file;

        name->setText(file);

        emit selectedFile(file);

    }
}


void General::selectExe()
{
    QString file=QFileDialog::getOpenFileName(0,QString("Выберите conf файл"),"C:/",QString("*.exe"));

    if (!file.isEmpty())
    {
        qDebug()<<file;

        httpd->setText(file);

        httpdexe=file;

    }
}

void General::setupApache()
{
    QProcess *p=new QProcess(this);

    if(!httpdexe.isEmpty())
    {
        p->start(httpdexe+" -k install");

        connect(p,SIGNAL(finished(int)),this,SLOT(completeInstall()));


    }else  QMessageBox::warning(0,"Setup","Empty");

}


void General::deletApache()
{
    QProcess *p=new QProcess(this);

    if(!httpdexe.isEmpty())
    {
        p->start(httpdexe+" -k uninstall");

        connect(p,SIGNAL(finished(int)),this,SLOT(completeUnstall()));

    } else  QMessageBox::warning(0,"Uninstall","Empty");

}

void General::completeInstall()
{
   QProcess *pr=(QProcess*)sender();

   QString status{};

   status+=pr->readAllStandardError()+"\r\n";
   status+=pr->readAllStandardOutput();

   QMessageBox::information(0,"Setup",status);
}


void General::completeUnstall()
{
   QProcess *pr=(QProcess*)sender();

   QString status{};

   status+=pr->readAllStandardError()+"\r\n";
   status+=pr->readAllStandardOutput();

   QMessageBox::information(0,"Uninstall",status);
}

void General::openNote()
{
    if (!name->text().isEmpty())
    {
        QScopedPointer<QProcess> p(new QProcess);

        p->startDetached("notepad "+name->text());

    }
}

void General::createConnections()
{
    connect(dialog,SIGNAL(clicked()),this,SLOT(selectFile()));

    connect(buttonhttpd,SIGNAL(clicked()),this,SLOT(selectExe()));

    connect(setup,SIGNAL(clicked()),this,SLOT(setupApache()));

    connect(delet,SIGNAL(clicked()),this,SLOT(deletApache()));

    connect(opennote,SIGNAL(clicked()),this,SLOT(openNote()));

}

void General::createLayout()
{

    QVBoxLayout *v=new QVBoxLayout;

    QHBoxLayout *h=new QHBoxLayout;

    QHBoxLayout *h2=new QHBoxLayout;

    QHBoxLayout *h3=new QHBoxLayout;

    QHBoxLayout *h4=new QHBoxLayout;

    QVBoxLayout *v2=new QVBoxLayout;

    QVBoxLayout *v3=new QVBoxLayout;


    v->addWidget(namepage);
    v->setSpacing(10);
    v->setAlignment(namepage,Qt::AlignLeft);

    h->addWidget(discfilename);
    h->addWidget(name);
    h->addStretch(1);

    h2->addWidget(labelhttpd);
    h2->addWidget(httpd);
    h2->addStretch(1);

    v3->addLayout(h);
    v3->addLayout(h2);
    v3->addWidget(ap);
    v3->addWidget(note);

    v2->addWidget(dialog);
    v2->addWidget(buttonhttpd);

    h3->addWidget(setup);
    h3->addWidget(delet);
    h3->addStretch(1);

    v2->addLayout(h3);
    v2->addWidget(opennote);

    h4->addLayout(v3);
    h4->addLayout(v2);
    h4->addStretch(1);

    QLabel *aff=new QLabel;
    aff->setPixmap(QPixmap("g44.png"));


    v->addLayout(h4);


    v->addWidget(aff);
    v->setAlignment(aff,Qt::AlignCenter);
     v->addStretch(1);

    setLayout(v);

    setqss();
}

void General::setqss()
{
    QFile file("general.qss");

    file.open(QFile::ReadOnly);

    QString strCSS = QLatin1String(file.readAll());

    this->setStyleSheet(strCSS);

}

void General::writeSettings()
{
    gs.beginGroup("/Settings");
    gs.setValue("/httpd",name->text());
    gs.setValue("/exe",httpd->text());
    gs.endGroup();

}


void General::readSettings()
{

    gs.beginGroup("/Settings");

     QString  ht=gs.value("/httpd","").toString();

    QString exe=gs.value("/exe","").toString();

    ht=ht.mid(0,ht.length());

    exe=exe.mid(0,ht.length());

    name->setText(ht);

    httpd->setText(exe);

    httpdexe=exe;

    gs.endGroup();
    qDebug()<<ht;

   // QTimer::singleShot(1000,this,x);
    QTimer::singleShot(1000,[this,ht](){emit selectedFile(ht);});

}
/* void General::x(){
     emit selectedFile(xyi);
 }

*/

