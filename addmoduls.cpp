#include <QtWidgets>
#include <QtCore>
#include "addmoduls.h"

AddModuls::AddModuls(QWidget *p):QWidget(p)
{


    moduls=new QLabel("Подключаемые модули");
    moduls->setObjectName("Plug");


    php=new QCheckBox("PHP");

    python=new QCheckBox("Python");


    phpl=new QLabel("Путь в файлу phpХapacheХ_Х.dll");

    phppath=new QLineEdit;


   // connect(addtypebut,SIGNAL(clicked()),this,SLOT(addType()));
//    connect(addhandlerbut,SIGNAL(clicked()),this,SLOT(addHandler()));
   // connect(addencodingbut,SIGNAL(clicked()),this,SLOT(addEncoding()));



    loadmodul=new QLabel("LoadModule");

    loadmodulInfo=new QLabel;
    loadmodulInfo->setPixmap(QPixmap("help.png"));
    loadmodulInfo->setToolTip("Загрузка нового модуля");

    loadmodulline=new QLineEdit;

    loadmodulbut=new QPushButton("Добавить");


    addtype=new QLabel("AddType");

    addtypeInfo=new QLabel;
    addtypeInfo->setPixmap(QPixmap("help.png"));
    addtypeInfo->setToolTip("Эта директива для добавления новых типов предоставляемых клиентам документов на основе использования MIME-типов.");

    addtypeline=new QLineEdit;

    addtypebut=new QPushButton("Добавить");

    addhandler=new QLabel("AddHandler");

    addhandlerInfo=new QLabel;
    addhandlerInfo->setPixmap(QPixmap("help.png"));
    addhandlerInfo->setToolTip("Cтавит в соответствие расширению файла определенное действие.");

    addhandlerline=new QLineEdit;

    addhandlerbut=new QPushButton("Добавить");

    addencoding=new QLabel("AddEncoding");

    addencodingInfo=new QLabel;
    addencodingInfo->setPixmap(QPixmap("help.png"));
    addencodingInfo->setToolTip("Используется несколько видов сжатия, или кодирования, что сокращает время передачи.");

    addencodingline=new QLineEdit;

    addencodingbut=new QPushButton("Добавить");


    createConnections();

    createLayout();

    setqss();

}

void AddModuls::setFileConf(const QString &filename)
{

    conf=filename;
    qDebug()<<"config: "<<conf;
}

void AddModuls::setPHP(int state)
{
    QString mod=phppath->text();

    if(QFile(mod).exists())
    {
        QFile file(conf);

        QString str{};

       readFile(file,str);

        file.open(QIODevice::WriteOnly);

        QTextStream ss(&file);

        int rew=str.indexOf("#LoadModule rewrite_module modules/mod_rewrite.so");

        str.remove(rew,1);

        if(state==2)
        {
            int m=str.indexOf(QRegExp("#LoadModule php5_module"));

            if(m!=-1)
            {
                str.remove(m,1);

                str.replace(QRegExp("LoadModule\\sphp5_module([:\"a-zA-z0-9./\_ ]+)"),"\r\n\r\nLoadModule php5_module \""+mod+"\"\r\n\r\n");

            } else if(str.indexOf(QRegExp("LoadModule php5_module"))!=-1)
            {
                str.replace(QRegExp("LoadModule\\sphp5_module([:\"a-zA-z0-9./\_ ]+)"),"\r\n\r\nLoadModule php5_module \""+mod+"\"\r\n\r\n");

            }
            else{



                int pos=str.lastIndexOf(QRegExp("#?LoadModule\\s([a-zA-z0-9./\_ ]+)"));
                int pos2=str.indexOf("\r\n",pos);

                str.insert(pos2,"\r\nLoadModule php5_module \""+mod+"\"\r\n\r\n");

            }
            int addt=str.indexOf("#AddType application/x-httpd-php .php");

            if(addt!=-1)
            {
                str.remove(addt,1);

            }else if(str.indexOf("AddType application/x-httpd-php .php")!=-1)
            {

            }else{
                int p=str.lastIndexOf(QRegExp("AddType\\s([a-zA-Z0-9./\.- ])"));
                int p2=str.indexOf("\r\n",p);

                str.insert(p2,"\r\n\r\n\r\nAddType application/x-httpd-php .php\r\n\r\n\r\n");

            }

            int addt2=str.indexOf("#AddType application/x-httpd-php-source .phps");

            if(addt2!=-1)
            {
                str.remove(addt2,1);

            } else if(str.indexOf("AddType application/x-httpd-php-source .phps")!=-1){}else
            {

                int p=str.lastIndexOf(QRegExp("AddType\\s([a-zA-Z0-9./\.- ])"));
                int p2=str.indexOf("\r\n",p);

                str.insert(p2,"\r\n\r\n\r\nAddType application/x-httpd-php-source .phps\r\n\r\n\r\n");

            }

            QRegExp e("(DirectoryIndex\\s([a-zA-Z. ]+))");

            int regpos=0;
            regpos=e.indexIn(str,regpos);

            if(regpos!=-1)
            {
                qDebug()<<e.cap(1);
                QString dirindex=e.cap(1);

                if(dirindex.indexOf(QRegExp("index.php"))==-1)
                {
                    dirindex+=" index.php";

                    str.replace(e,dirindex);

                }
            }

        }else if(state==0)
        {

            int m=str.indexOf(QRegExp("LoadModule php5_module"));

            if(m!=-1)
            {
                str.insert(m,'#');
            }

            int m2=str.indexOf(QRegExp("AddType application/x-httpd-php .php"));

            if(m2!=-1)
            {
                str.insert(m2,'#');
            }

            int m3=str.indexOf(QRegExp("AddType application/x-httpd-php-source .phps"));

            if(m3!=-1)
            {
                str.insert(m3,'#');
            }

            str.replace("index.php","");
        }
        ss<<str;
        file.close();

    } else QMessageBox::warning(0,"PHP_dll","Файл не существует");
}

void AddModuls::setPython(int state)
{

        QFile file(conf);

        QString str{};

         readFile(file,str);

        file.open(QIODevice::WriteOnly);

        QTextStream ss(&file);

        if(state==2)
        {
            int m=str.indexOf("#AddHandler cgi-script .cgi .py");

            if(m!=-1)
            {
                str.remove(m,1);


            } else if(str.indexOf("AddHandler cgi-script .cgi .py")!=-1)
            {


            } else {
                int pos=str.lastIndexOf(QRegExp("#?LoadModule\\s([a-zA-z0-9./\_ ]+)"));
                int pos2=str.indexOf("\r\n",pos);

                str.insert(pos2,"\r\n\r\n\r\nAddHandler cgi-script .cgi .py\r\n\r\n\r\n");

            }

            int m2=str.indexOf("#AddHandler cgi-script .py");

            if(m2!=-1)
            {
                str.remove(m2,1);


            } else if(str.indexOf("AddHandler cgi-script .py")!=-1){

            } else {
                int pos=str.lastIndexOf(QRegExp("#?LoadModule\\s([a-zA-z0-9./\_ ]+)"));
                int pos2=str.indexOf("\r\n",pos);

                str.insert(pos2,"\r\n\r\n\r\nAddHandler cgi-script .py\r\n\r\n\r\n");

            }

            QRegExp e("(DirectoryIndex\\s([a-zA-Z. ]+))");

            int regpos=0;

            regpos=e.indexIn(str,regpos);

            if(regpos!=-1)
            {
                qDebug()<<e.cap(1);
                QString dirindex=e.cap(1);

                if(dirindex.indexOf(QRegExp("index.py"))==-1)
                {
                    dirindex+=" index.py";
                    str.replace(e,dirindex);
                }
            }
            int maindir=str.indexOf(QRegExp("\\<Directory\\s([\"a-zA-z0-9_/\:]{2,})\\>"));

                  int pos2=str.indexOf(QRegExp("Options\\s([a-zA-Z ]{2,})\\s{3,}"),maindir);
                  int pos3=str.indexOf("\r\n",pos2)-1;

                  str.insert(pos3," ExecCGI");

        }

         else if (state==0)
        {

            str.replace("index.py","");
            str.replace("ExecCGI","");

            int m=str.indexOf(QRegExp("AddHandler cgi-script .py"));

            if(m!=-1)
            {
                str.insert(m,'#');
            }
            int m2=str.indexOf(QRegExp("AddHandler cgi-script .cgi .py"));

            if(m2!=-1)
            {
                str.insert(m2,'#');
            }



        }
        ss<<str;
        file.close();
}

void AddModuls::addLoadModul()
{

        QFile file(conf);

        QString str{};

        readFile(file,str);

        file.open(QIODevice::WriteOnly);

        QTextStream ss(&file);


      int pos=str.lastIndexOf(QRegExp("#?LoadModule\\s([a-zA-z0-9./\_ ]+)"));
      int pos2=str.indexOf("\r\n",pos);

      str.insert(pos2,"\r\nLoadModule "+loadmodulline->text()+"\r\n");


      ss<<str;
      file.close();

}

void AddModuls::addType()
{
    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);


    int p=str.lastIndexOf(QRegExp("\\bAddType\\s([a-zA-Z0-9./\.- ])"));
    int p2=str.indexOf("\r\n",p);

    str.insert(p2,"\r\n\r\n\r\nAddType "+addtypeline->text()+"\r\n\r\n\r\n");

  ss<<str;
  file.close();
}

void AddModuls::addHandler()
{
    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);


  int pos=str.lastIndexOf(QRegExp("#?LoadModule\\s([a-zA-z0-9./\_ ]+)"));
  int pos2=str.indexOf("\r\n",pos);

  str.insert(pos2,"\r\nAddHandler "+addhandlerline->text()+"\r\n");


  ss<<str;
  file.close();

}

void AddModuls::addEncoding()
{
    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);


    int p=str.lastIndexOf(QRegExp("\\bAddType\\s([a-zA-Z0-9./\.- ])"));
    int p2=str.indexOf("\r\n",p);

    str.insert(p2,"\r\nAddEncoding "+addencodingline->text()+"\r\n");

  ss<<str;
  file.close();

}

void AddModuls::createConnections()
{
    connect(php,SIGNAL(stateChanged(int)),this,SLOT(setPHP(int)));

    connect(python,SIGNAL(stateChanged(int)),this,SLOT(setPython(int)));

    connect(loadmodulbut,SIGNAL(clicked()),this,SLOT(addLoadModul()));

    connect(addtypebut,SIGNAL(clicked()),this,SLOT(addType()));

    connect(addhandlerbut,SIGNAL(clicked()),this,SLOT(addHandler()));

    connect(addencodingbut,SIGNAL(clicked()),this,SLOT(addEncoding()));

}

void AddModuls::createLayout()
{
    QVBoxLayout *vmain=new QVBoxLayout;

    QVBoxLayout *v1=new QVBoxLayout;

    QVBoxLayout *v11=new QVBoxLayout;

    QVBoxLayout *v2=new QVBoxLayout;

    QVBoxLayout *v3=new QVBoxLayout;

    QVBoxLayout *v4=new QVBoxLayout;

    QHBoxLayout *h=new QHBoxLayout;

    vmain->addWidget(moduls);
    vmain->setAlignment(moduls,Qt::AlignLeft);


    QHBoxLayout *hor=new QHBoxLayout;


    hor->addWidget(php);
    hor->addWidget(phpl);
    hor->addWidget(phppath);
    hor->addStretch(1);

    v1->addLayout(hor);

    v1->addWidget(python);

    vmain->addLayout(v1);



    v11->addWidget(loadmodul);

    v2->addWidget(loadmodulInfo);

    v3->addWidget(loadmodulline);

    v4->addWidget(loadmodulbut);

    v11->addWidget(addtype);

    v2->addWidget(addtypeInfo);

    v3->addWidget(addtypeline);

    v4->addWidget(addtypebut);


    v11->addWidget(addhandler);

    v2->addWidget(addhandlerInfo);

    v3->addWidget(addhandlerline);

    v4->addWidget(addhandlerbut);

    v11->addWidget(addencoding);

    v2->addWidget(addencodingInfo);

    v3->addWidget(addencodingline);

    v4->addWidget(addencodingbut);

    h->addLayout(v11);
    h->addLayout(v2);
    h->addLayout(v3);
    h->addLayout(v4);

    QLabel *aff=new QLabel;
    aff->setPixmap(QPixmap("gg.png"));

    h->addSpacing(1);
    h->addStretch(1);

    vmain->addLayout(h);
    vmain->setSpacing(10);
    vmain->addStretch(1);

    vmain->addWidget(aff);
    vmain->setAlignment(aff,Qt::AlignLeft);
    setLayout(vmain);

}

void AddModuls::readFile(QFile &file, QString &str)
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

void AddModuls::setqss()
{
    QFile file("addmoduls.qss");

    file.open(QFile::ReadOnly);

    QString strCSS = QLatin1String(file.readAll());

    this->setStyleSheet(strCSS);
}
