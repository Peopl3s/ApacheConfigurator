#include <QtWidgets>
#include <QtCore>
#include "config.h"

Config::Config(QWidget *p,QString conf_):QWidget(p),conf(conf_),settings("Fuck","Config")
{

    namepage=new QLabel("Настройки параметров");

    namepage->setObjectName("Plug");

    servername=new QLabel("ServerName");

    servernameInfo=new QLabel;
    servernameInfo->setToolTip("Основное имя домена. В этой строке должно стоять "
                               "официальное имя вашего сервера в том виде,\r\n в котором оно появляется в строке URL.\r\n"
                               " Это должно быть имя компьютера,\r\n зарегистрированное в системе имен серверов вашей организации или провайдера.");

    servernameInfo->setPixmap(QPixmap("help.png"));

    sname=new QLineEdit;

    timeout=new QLabel("Timeout");

    timeoutInfo=new QLabel;
    timeoutInfo->setToolTip("Указывает как долго сервер будет пытаться продолжить прерванную передачу или прием данных.");
    timeoutInfo->setPixmap(QPixmap("help.png"));

    timename=new QLineEdit;
    timename->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));


    keepalive=new QLabel("KeepAlive");

    keepaliveInfo=new QLabel;
    keepaliveInfo->setPixmap(QPixmap("help.png"));
    keepaliveInfo->setToolTip("Позволяет передавать несколько файлов, за одно соединение,\r\n"
                              " например, не только саму html страницу, но и картинки и css файлы");


    on=new QRadioButton("On");

    off=new QRadioButton("Off");


    keepatime=new QLabel("KeepAliveTimeout");

    keepatimeinfo=new QLabel;
    keepatimeinfo->setPixmap(QPixmap("help.png"));
    keepatimeinfo->setToolTip("Таймаут соединения");

    keepatimeline=new QLineEdit;
    keepatimeline->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));

    mr=new QLabel("MaxKeepAliveRequests");

    mrinfo=new QLabel;
    mrinfo->setPixmap(QPixmap("help.png"));
    mrinfo->setToolTip("Максимальное количество запросов за одно соединение");

    mrline=new QLineEdit;
    mrline->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));

    HostnameLookups=new QLabel("HostnameLookups");

    HostnameLookupsInfo=new QLabel;
    HostnameLookupsInfo->setPixmap(QPixmap("help.png"));
    HostnameLookupsInfo->setToolTip("HostnameLookups определяет, записывать ли имена клиентов, или только их IP-адреса");

    hostnameon=new QRadioButton("On");

    hostnameoff=new QRadioButton("Off");



    DocumentRoot=new QLabel("DocumentRoot");

    DocumentRootInfo=new QLabel;
    DocumentRootInfo->setPixmap(QPixmap("help.png"));
    DocumentRootInfo->setToolTip("Устанавливает из какой папки нужно брать документы для отображенияа пользователю");

    DocumentRootline=new QLineEdit;


    ServerRoot=new QLabel("ServerRoot");

    ServerRootInfo=new QLabel;
    ServerRootInfo->setPixmap(QPixmap("help.png"));
    ServerRootInfo->setToolTip("Вершина дерева директорий, в которых содержатся конфиг, лог и error-файлы");

    ServerRootline=new QLineEdit;

    ErrorLog=new QLabel("ErrorLog");

    ErrorLogInfo=new QLabel;
    ErrorLogInfo->setPixmap(QPixmap("help.png"));
    ErrorLogInfo->setToolTip("Расположение error-файла");

    ErrorLogline=new QLineEdit;

    CustomLog=new QLabel("CustomLog");

    CustomLogInfo=new QLabel;
    CustomLogInfo->setPixmap(QPixmap("help.png"));
    CustomLogInfo->setToolTip("Расположение и формат лог-файла доступа к серверу");

    CustomLogline=new QLineEdit;

    Listen=new QLabel("Listen");

    ListenInfo=new QLabel;
    ListenInfo->setPixmap(QPixmap("help.png"));
    ListenInfo->setToolTip("Указывает программе на каком порту нужно работать");

    Listenline=new QLineEdit;
    Listenline->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));

    ServerAdmin=new QLabel("ServerAdmin");

    ServerAdminInfo=new QLabel;
    ServerAdminInfo->setPixmap(QPixmap("help.png"));
    ServerAdminInfo->setToolTip("Адрес, по которому следует направлять сообщения о проблемах с сервером");

    ServerAdminline=new QLineEdit;

    ScriptAlias=new QLabel("ScriptAlias");

    ScriptAliasInfo=new QLabel;
    ScriptAliasInfo->setPixmap(QPixmap("help.png"));
    ScriptAliasInfo->setToolTip("Указывает директории, которые содержат серверные скрипты.");

    ScriptAliasline=new QLineEdit;



    LogLevel=new QLabel("LogLevel");

    LogLevelInfo=new QLabel;
    LogLevelInfo->setPixmap(QPixmap("help.png"));
    LogLevelInfo->setToolTip("Уровень логирования ошибок. ");

    LogLevelline=new QLineEdit;

    UserDir=new QLabel("UserDir");

    UserDirInfo=new QLabel;
    UserDirInfo->setPixmap(QPixmap("help.png"));
    UserDirInfo->setToolTip("Имя директории, которое постфиксируется к имени домашней директории пользователя при получении запроса ~user");

    UserDirline=new QLineEdit;

    PidFile=new QLabel("PidFile");

    PidFileInfo=new QLabel;
    PidFileInfo->setPixmap(QPixmap("help.png"));
    PidFileInfo->setToolTip("Файл записи идентификационного номера процесса (PID) сервера при запуске.");

    PidFileline=new QLineEdit;


    ServerSignature=new QLabel("ServerSignature");

    ServerSignatureInfo=new QLabel;
    ServerSignatureInfo->setPixmap(QPixmap("help.png"));
    ServerSignatureInfo->setToolTip("Добавить дополнительную строчку, содержащую версию сервера и имя виртуального хоста на страницах, сгенерированных сервером");

    ServerSignatureline=new QLineEdit;



    Options=new QLabel("Options");

    OptionsInfo=new QLabel;
    OptionsInfo->setPixmap(QPixmap("help.png"));
    OptionsInfo->setToolTip("Директива позволяет управлять тем, какие функции сервера доступны для использования в каталоге, указанном в секции.");

    Optionsline=new QLineEdit;



    createConnections();

    createLayout();

    setqss();

}

void Config::setFileConf(const QString &filename)
{

    conf=filename;
    qDebug()<<"config: "<<conf;
}

void Config::changeServerName()
{
    QString server=sname->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bServerName\\s([0-9a-z :]+)\\s{3,}"))!=-1)
    {
        if(!server.isEmpty())
        {
            str.replace(QRegExp("\\bServerName\\s([0-9a-z :]+)\\s{3,}"),"\r\nServerName "+server+"   \r\n");
        }

    }else{

        int pos=str.indexOf(QRegExp("\\bListen\\s[0-9: ]+\\s{3,}"));
        int pos2=str.indexOf("\r\n",pos);

        qDebug()<<pos2;

        str.insert(pos2,"\r\n\r\n\r\nServerName "+server+"   \r\n");

    }
    ss<<str;
    file.close();

}

void Config::changeTimeout()
{
    QString timeout=timename->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bTimeout\\s([0-9]+)"))!=-1)
    {
        if(!timeout.isEmpty())
        {
            str.replace(QRegExp("\\bTimeout\\s([0-9a-z :]+)"),"Timeout "+timeout);
        }

    }else{

        int pos=str.lastIndexOf(QRegExp("\\bServerAdmin\\s([a-zA-Z0-9@.-_]+)"));
        int pos2=str.indexOf("\r\n",pos);

        qDebug()<<pos2;

        str.insert(pos2,"\r\n\r\n\r\nTimeout "+timeout+"\r\n");

    }
    ss<<str;
    file.close();
}

void Config::changeKeepAlive()
{
    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);



    if(on->isChecked())
    {

        if(str.indexOf(QRegExp("\\bKeepAlive\\s(On|Off)"))!=-1)
        {

            str.replace(QRegExp("\\bKeepAlive\\s(On|Off)"),"KeepAlive On");

        }else{

            int pos=str.lastIndexOf(QRegExp("\\bServerAdmin\\s([a-zA-Z0-9@.-_]+)"));
            int pos2=str.indexOf("\r\n",pos);

            qDebug()<<pos2;

            str.insert(pos2,"\r\n\r\n\r\nKeepAlive On\r\n");

        }

    }else if(off->isChecked())
    {

        if(str.indexOf(QRegExp("\\bKeepAlive\\s(On|Off)"))!=-1)
        {

            str.replace(QRegExp("\\bKeepAlive\\s(On|Off)"),"KeepAlive Off");

        }else{

            int pos=str.lastIndexOf(QRegExp("\\bServerAdmin\\s([a-zA-Z0-9@.-_]+)\\s{3,}"));
            int pos2=str.indexOf("\r\n",pos);

            qDebug()<<pos2;

            str.insert(pos2,"\r\n\r\n\r\nKeepAlive Off\r\n");

        }

    }

    ss<<str;
    file.close();
}

void Config::changeKeepAliveTimeout()
{
    QString keeptimeout=keepatimeline->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bKeepAliveTimeout\\s([0-9]+)"))!=-1)
    {
        if(!keeptimeout.isEmpty())
        {
            str.replace(QRegExp("\\bKeepAliveTimeout\\s([0-9a-z :]+)"),"KeepAliveTimeout "+keeptimeout);
        }

    }else{

        int pos=str.lastIndexOf(QRegExp("\\bServerAdmin\\s([a-zA-Z0-9@.-_]+)"));
        int pos2=str.indexOf("\r\n",pos);

        qDebug()<<pos2;

        str.insert(pos2,"\r\n\r\n\r\nKeepAliveTimeout "+keeptimeout+"\r\n");

    }
    ss<<str;
    file.close();
}

void Config::changeMaxKeepAliveRequests()
{
    QString mrec=mrline->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bMaxKeepAliveRequests \\s([0-9]+)"))!=-1)
    {
        if(!mrec.isEmpty())
        {
            str.replace(QRegExp("\\bMaxKeepAliveRequests \\s([0-9a-z :]+)"),"MaxKeepAliveRequests  "+mrec);
        }

    }else{

        int pos=str.lastIndexOf(QRegExp("\\bServerAdmin\\s([a-zA-Z0-9@.-_]+)\\s{3,}"));
        int pos2=str.indexOf("\r\n",pos);

        qDebug()<<pos2;

        str.insert(pos2,"\r\n\r\n\r\nMaxKeepAliveRequests  "+mrec+"\r\n");

    }
    ss<<str;
    file.close();
}

void Config::changeHostnameLookups()
{

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);



    if(hostnameon->isChecked())
    {

        if(str.indexOf(QRegExp("\\bHostnameLookups\\s(On|Off)"))!=-1)
        {

            str.replace(QRegExp("\\bHostnameLookups\\s(On|Off)"),"HostnameLookups On");

        }else{

            int pos=str.lastIndexOf(QRegExp("\\bServerAdmin\\s([a-zA-Z0-9@.-_]+)\\s{3,}"));
            int pos2=str.indexOf("\r\n",pos);

            qDebug()<<pos2;

            str.insert(pos2,QString("\r\n\r\n")+"HostnameLookups On"+QString("\r\n"));

        }

    }else if(hostnameoff->isChecked())
    {

        if(str.indexOf(QRegExp("\\bHostnameLookups\\s(On|Off)"))!=-1)
        {

            str.replace(QRegExp("\\bHostnameLookups\\s(On|Off)"),"HostnameLookups Off");

        }else{

            int pos=str.lastIndexOf(QRegExp("\\bServerAdmin\\s([a-zA-Z0-9@.-_]+)\\s{3,}"));
            int pos2=str.indexOf("\r\n",pos);

            qDebug()<<pos2;

            str.insert(pos2,"\r\n\r\n\r\nHostnameLookups Off\r\n");

        }

    }

    ss<<str;
    file.close();

}

void Config::changeDocumentRoot()
{

    QString root=DocumentRootline->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bDocumentRoot\\s([\"a-zA-z0-9_/\:]+)"))!=-1)
    {
        if(!root.isEmpty())
        {
            root.replace("\\","/");
            if(QFile(root).exists())
            {
                str.replace(QRegExp("\\bDocumentRoot\\s([\"a-zA-z0-9_/\:]+)"),"DocumentRoot \""+root+"\"");

            }else QMessageBox::warning(0,"DocumentRoot","Некорректный путь");
        }
    }else{

        root.replace("\\","/");

        if(QFile(root).exists())
        {
            int pos=str.indexOf(QRegExp("\\bServerAdmin\\s([a-zA-Z0-9@.-_]+)\\s{3,}"));
            int pos2=str.indexOf("\r\n",pos);

            qDebug()<<pos2;

            str.insert(pos2,"\r\n\r\n\r\nDocumentRoot \""+root+"\"\r\n");

        }else QMessageBox::warning(0,"DocumentRoot","Некорректный путь");
    }

    ss<<str;
    file.close();

}

void Config::changeServerRoot()
{
    QString serverroot=ServerRootline->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bServerRoot\\s([\"a-zA-z0-9_/\:]+)\\s{2,}"))!=-1)
    {
        if(!serverroot.isEmpty())
        {
            serverroot.replace("\\","/");

            if(QFile(serverroot).exists())
            {
                str.replace(QRegExp("\\bServerRoot\\s([\"a-zA-z0-9_/\:]+)\\s{2,}"),"ServerRoot \""+serverroot+"\"\r\n");

            }else QMessageBox::warning(0,"ServerRoot","Некорректный путь");
        }
    }else{

        serverroot.replace("\\","/");

        if(QFile(serverroot).exists())
        {
            int pos=str.indexOf(QRegExp("\\bListen\\s[0-9: ]+"));
            int pos2=str.indexOf("\r\n",pos);

            qDebug()<<pos2;

            str.insert(pos2,"\r\n\r\n\r\nServerRoot \""+serverroot+"\"\r\n");

        }else QMessageBox::warning(0,"ServerRoot","Некорректный путь");
    }
    ss<<str;
    file.close();
}

void Config::changeErrorLog()
{
    QString errorlog=ErrorLogline->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bErrorLog\\s([\"a-zA-z0-9_/\.:-]+)\\s{3,}"))!=-1)
    {
        if(!errorlog.isEmpty())
        {
            errorlog.replace("\\","/");

            QFile er(errorlog);

            if(er.open(QIODevice::ReadWrite))
            {
                str.replace(QRegExp("\\bErrorLog\\s([\"a-zA-z0-9_/\.:-]+)\\s{3,}"),"\r\nErrorLog \""+errorlog+"\"   \r\n");
                er.close();

            }else QMessageBox::warning(0,"ErrorLog","Некорректный путь");
        }
    }else{

        errorlog.replace("\\","/");

        QFile er(errorlog);

        if(er.open(QIODevice::ReadWrite))
        {
            int pos=str.indexOf(QRegExp("</FilesMatch>"));
            int pos2=str.indexOf("\r\n",pos);

            qDebug()<<pos2;

            str.insert(pos2,"\r\n\r\n\r\nErrorLog \""+errorlog+"\"   \r\n");

            er.close();

        }else QMessageBox::warning(0,"ErrorLog","Некорректный путь");
    }

    ss<<str;
    file.close();
}

void Config::changeCustomLog()
{
    QString customlog=CustomLogline->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bCustomLog\\s([\"a-zA-z0-9_/\.:-]+)\\scommon"))!=-1)
    {
        if(!customlog.isEmpty())
        {
            customlog.replace("\\","/");

            QFile er(customlog);

            if(er.open(QIODevice::ReadWrite))
            {
                str.replace(QRegExp("\\bCustomLog\\s([\"a-zA-z0-9_/\.:-]+)\\scommon"),"\r\nCustomLog \""+customlog+"\" common\r\n");

                er.close();

            }else QMessageBox::warning(0,"CustomLog","Некорректный путь");
        }
    }else{

        customlog.replace("\\","/");

        QFile er(customlog);

        if(er.open(QIODevice::ReadWrite))
        {
            int pos=str.indexOf(QRegExp("</FilesMatch>"));
            int pos2=str.indexOf("\r\n",pos);

            qDebug()<<pos2;

            str.insert(pos2,"\r\n\r\n\r\nCustomLog \""+customlog+"\" common\r\n\r\n");

            er.close();

        }else QMessageBox::warning(0,"CustomLog","Некорректный путь");
    }

    ss<<str;
    file.close();
}

void Config::changeListen()
{
    QString listen=Listenline->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bListen\\s([0-9]+)\\s{4,}"))!=-1)
    {
        if(!listen.isEmpty())
        {
            listen.replace("\\","/");

            if(listen.toInt() >0 && listen.toInt()< 65535)
            {
                str.replace(QRegExp("\\bListen\\s([0-9]+)\\s{4,}"),"Listen "+listen+"\r\n\r\n");

            }else QMessageBox::warning(0,"Listen","Некорректный порт");
        }
    }else{

        listen.replace("\\","/");

        if(listen.toInt()>0 && listen.toInt() < 65535)
        {
            int pos=str.indexOf(QRegExp("^\\#\\s+"));
            int pos2=str.indexOf("\r\n",pos);

            qDebug()<<pos2;

            str.insert(pos2,"\r\n\r\n\r\nListen "+listen+"\r\n\r\n");

        }else QMessageBox::warning(0,"Listen","Некорректный порт");
    }

    ss<<str;
    file.close();
}

void Config::changeServerAdmin()
{
    QString serveradmin=ServerAdminline->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bServerAdmin\\s([a-zA-Z0-9@.-_]+)"))!=-1)
    {
        if(!serveradmin.isEmpty())
        {
            str.replace(QRegExp("\\bServerAdmin\\s([a-zA-Z0-9@.-_]+)"),"ServerAdmin "+serveradmin+"\r\n");
        }

    } else QMessageBox::warning(0,"ServerAdmin","В файле отсутствует поле ServerAdmin");

    ss<<str;
    file.close();
}

void Config::changeScriptAlias()
{
    QString scriptalias=ScriptAliasline->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bScriptAlias\\s/cgi-bin/\\s([\"a-zA-z0-9_/\.:-]+)\\s{3,}"))!=-1)
    {
        if(!scriptalias.isEmpty())
        {
            scriptalias.replace("\\","/");

            if(QFile(scriptalias).exists())
            {
                str.replace(QRegExp("\\bScriptAlias\\s/cgi-bin/\\s([\"a-zA-z0-9_/\.:-]+)\\s{3,}"),"ScriptAlias /cgi-bin/ \""+scriptalias+"\"   \r\n");

            }else QMessageBox::warning(0,"ScriptAlias","Некорректный путь");
        }
    }else{

        scriptalias.replace("\\","/");

        if(QFile(scriptalias).exists())
        {
            int pos=str.indexOf(QRegExp("</FilesMatch>"));
            int pos2=str.indexOf("\r\n",pos);

            qDebug()<<pos2;

            str.insert(pos2,"\r\n\r\n\r\nScriptAlias /cgi-bin/ \""+scriptalias+"\"\r\n\r\n");

        }else QMessageBox::warning(0,"ScriptAlias","Некорректный путь");
    }

    ss<<str;
    file.close();

}

void Config::changeLogLevel()
{
    QString log=LogLevelline->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    static const QSet<QString>sa{"debug", "info", "notice", "warn", "error", "crit", "alert","emerg"};

    if(str.indexOf(QRegExp("\\bLogLevel\\s([a-zA-Z]+)"))!=-1)
    {
        if(!log.isEmpty())
        {

            if(std::find(sa.begin(),sa.end(),log.toLower())!=sa.end())
            {
                str.replace(QRegExp("\\bLogLevel\\s([a-zA-Z]+)"),"LogLevel "+log+"\r\n\r\n");

            } else QMessageBox::warning(0,"LogLevel","Возможные значения : debug,info,notice, warn, error, crit, alert, emerg");
        }
    }else{

        if(std::find(sa.begin(),sa.end(),log.toLower())!=sa.end())
        {
            int pos=str.indexOf(QRegExp("</FilesMatch>"));
            int pos2=str.indexOf("\r\n",pos);

            qDebug()<<pos2;

            str.insert(pos2,"\r\n\r\n\r\nLogLevel "+log+"\r\n\r\n");

        } else QMessageBox::warning(0,"LogLevel","Возможные значения : debug,info,notice, warn, error, crit, alert, emerg");

    }

    ss<<str;
    file.close();
}

void Config::changeUserDir()
{
    /* QString userdir=UserDirline->text();
    QFile file(conf);
    QString str;
   readFile(file,str);

    file.open(QIODevice::WriteOnly);
    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bUserDir\\s([\"a-zA-z0-9_/\.:-]+)\\s"))!=-1){

        if(!userdir.isEmpty()){
            userdir.replace("\\","/");
            if(QFile(userdir).exists()){
                str.replace(QRegExp("\\bUserDir\\s([\"a-zA-z0-9_/\.:-]+)\\s"),"UserDir \""+userdir+"\"\r\n");
            }else QMessageBox::warning(0,"UserDir","Некорректный путь");
        }
    }else{
        userdir.replace("\\","/");
        if(QFile(userdir).exists()){
            int pos=str.indexOf(QRegExp("</Directory>"));
            int pos2=str.indexOf("\r\n",pos);
            qDebug()<<pos2;
            str.insert(pos2,"\r\n\r\n\r\nUserDir \""+userdir+"\"\r\n\r\n");
        }else QMessageBox::warning(0,"UserDir","Некорректный путь");
    }
    ss<<str;
    file.close();
    */
}

void Config::changePidFile()
{
    /*   QString pid=PidFileline->text();
    QFile file(conf);
    QString str;
   readFile(file,str);

    file.open(QIODevice::WriteOnly);
    QTextStream ss(&file);

    if(str.indexOf(QRegExp("\\bPidFile\\s([\"a-zA-z0-9_/\.:-]+)\\s"))!=-1){

        if(!pid.isEmpty()){
           pid.replace("\\","/");
            if(QFile(pid).exists()){
                str.replace(QRegExp("\\bPidFile\\s([\"a-zA-z0-9_/\.:-]+)\\s"),"PidFile \""+pid+"\"\r\n");
            }else QMessageBox::warning(0,"PidFile","Некорректный путь");
        }
    }else{
        pid.replace("\\","/");
        if(QFile(pid).exists()){
            int pos=str.indexOf(QRegExp("\\bServerAdmin\\s([a-zA-Z0-9@.-_]+)\\s{3,}"));
            int pos2=str.indexOf("\r\n",pos);
            qDebug()<<pos2;
            str.insert(pos2,"\r\n\r\n\r\nPidFile \""+pid+"\"\r\n\r\n");
        }else QMessageBox::warning(0,"PidFile","Некорректный путь");
    }
    ss<<str;
    file.close();*/
}

void Config::changeServerSignature()
{
    QString sign=ServerSignatureline->text();

    QFile file(conf);

    QString str{};

    readFile(file,str);

    file.open(QIODevice::WriteOnly);

    QTextStream ss(&file);

    static const QSet<QString>so{"on", "off", "email"};

    if(str.indexOf(QRegExp("\\bServerSignature\\s(On|Off|Email)"))!=-1)
    {
        if(!sign.isEmpty())
        {

            if(std::find(so.begin(),so.end(),sign.toLower())!=so.end())
            {
                str.replace(QRegExp("\\bServerSignature\\s(On|Off|Email)"),"\r\nServerSignature "+sign+"\r\n\r\n");

            } else QMessageBox::warning(0,"ServerSignature","Возможные значения : On, Off, Email");
        }
    }else{

        if(std::find(so.begin(),so.end(),sign.toLower())!=so.end())
        {
            int pos=str.indexOf(QRegExp("\\</FilesMatch\\>"));
            int pos2=str.indexOf("\r\n",pos);

            qDebug()<<pos2;

            str.insert(pos2,"\r\n\r\n\r\nServerSignature "+sign+"\r\n\r\n");

        } else QMessageBox::warning(0,"ServerSignature","Возможные значения : On, Off, Email");

    }

    ss<<str;
    file.close();
}

void Config::changeOptions()
{
    QStringList opt=Optionsline->text().split(" ");

    for (const auto &option:opt)
    {
        options.insert(option);
    }
}

QSet<QString> Config::getOptions() const
{
    return options;
}

void Config::createConnections()
{
    connect(sname,SIGNAL(editingFinished()),this,SLOT(changeServerName()));

    connect(timename,SIGNAL(editingFinished()),this,SLOT(changeTimeout()));

    connect(on,SIGNAL(toggled(bool)),this,SLOT(changeKeepAlive()));

    connect(keepatimeline,SIGNAL(editingFinished()),this,SLOT(changeKeepAliveTimeout()));

    connect(mrline,SIGNAL(editingFinished()),this,SLOT(changeMaxKeepAliveRequests()));

    connect(hostnameon,SIGNAL(toggled(bool)),this,SLOT(changeHostnameLookups()));

    connect(hostnameoff,SIGNAL(toggled(bool)),this,SLOT(changeHostnameLookups()));

    connect(DocumentRootline,SIGNAL(editingFinished()),this,SLOT(changeDocumentRoot()));

    connect(ServerRootline,SIGNAL(editingFinished()),this,SLOT(changeServerRoot()));

    connect(ErrorLogline,SIGNAL(editingFinished()),this,SLOT(changeErrorLog()));

    connect(CustomLogline,SIGNAL(editingFinished()),this,SLOT(changeCustomLog()));

    connect(Listenline,SIGNAL(editingFinished()),this,SLOT(changeListen()));

    connect(ServerAdminline,SIGNAL(editingFinished()),this,SLOT(changeServerAdmin()));

    connect(ScriptAliasline,SIGNAL(editingFinished()),this,SLOT(changeScriptAlias()));

    connect(LogLevelline,SIGNAL(editingFinished()),this,SLOT(changeLogLevel()));

    connect(UserDirline,SIGNAL(editingFinished()),this,SLOT(changeUserDir()));

    connect(PidFileline,SIGNAL(editingFinished()),this,SLOT(changePidFile()));

    connect(ServerSignatureline,SIGNAL(editingFinished()),this,SLOT(changeServerSignature()));

    connect(Optionsline,SIGNAL(editingFinished()),this,SLOT(changeOptions()));
}

void Config::createLayout()
{
    QVBoxLayout *mainV1=new QVBoxLayout;

    QVBoxLayout *v1=new QVBoxLayout;

    QVBoxLayout *v2=new QVBoxLayout;

    QVBoxLayout *v3=new QVBoxLayout;

    mainV1->addWidget(namepage);
    mainV1->setAlignment(namepage,Qt::AlignLeft);



    QHBoxLayout *labels1=new QHBoxLayout;

    QHBoxLayout *labels2=new QHBoxLayout;

    QHBoxLayout *labels3=new QHBoxLayout;

    QHBoxLayout *edit3=new QHBoxLayout;

    QHBoxLayout *labels4=new QHBoxLayout;

    QHBoxLayout *labels5=new QHBoxLayout;


    labels1->addWidget(servername);

    v3->addWidget(servernameInfo);

    v1->addLayout(labels1);

    v2->addWidget(sname);


    labels2->addWidget(timeout);

    v3->addWidget(timeoutInfo);

    v1->addLayout(labels2);

    v2->addWidget(timename);


    labels3->addWidget(keepalive);

    v3->addWidget(keepaliveInfo);

    v1->addLayout(labels3);

    edit3->addStretch(1);
    edit3->addWidget(on);
    edit3->addWidget(off);

   // QGroupBox *groupbox1=new QGroupBox;
  //  groupbox1->setLayout(edit3);

    v2->addLayout(edit3);


    labels4->addWidget(keepatime);

    v3->addWidget(keepatimeinfo);

    v1->addLayout(labels4);

    v2->addWidget(keepatimeline);


    labels5->addWidget(mr);

    v3->addWidget(mrinfo);

    v1->addLayout(labels5);

    v2->addWidget(mrline);

    QHBoxLayout *labels6=new QHBoxLayout;

    labels6->addWidget(HostnameLookups);

    v3->addWidget(HostnameLookupsInfo);

    v1->addLayout(labels6);

    QHBoxLayout *edit4=new QHBoxLayout;

    edit4->addStretch(1);
    edit4->addWidget(hostnameon);
    edit4->addWidget(hostnameoff);

    v2->addLayout(edit4);


    QHBoxLayout *labels7=new QHBoxLayout;

    labels7->addWidget(DocumentRoot);

    v3->addWidget(DocumentRootInfo);

    v1->addLayout(labels7);

    v2->addWidget(DocumentRootline);


    QHBoxLayout *labels8=new QHBoxLayout;

    labels8->addWidget(ServerRoot);

    v3->addWidget(ServerRootInfo);

    v1->addLayout(labels8);

    v2->addWidget(ServerRootline);


    QHBoxLayout *labels9=new QHBoxLayout;

    labels9->addWidget(ErrorLog);

    v3->addWidget(ErrorLogInfo);

    v1->addLayout(labels9);

    v2->addWidget(ErrorLogline);

    QHBoxLayout *labels10=new QHBoxLayout;

    labels10->addWidget(CustomLog);

    v3->addWidget(CustomLogInfo);

    v1->addLayout(labels10);

    v2->addWidget(CustomLogline);

    QHBoxLayout *labels11=new QHBoxLayout;

    labels11->addWidget(Listen);

    v3->addWidget(ListenInfo);

    v1->addLayout(labels11);

    v2->addWidget(Listenline);

    QHBoxLayout *labels12=new QHBoxLayout;

    labels12->addWidget(ServerAdmin);

    v3->addWidget(ServerAdminInfo);

    v1->addLayout(labels12);

    v2->addWidget(ServerAdminline);

    QHBoxLayout *labels13=new QHBoxLayout;

    labels13->addWidget(ScriptAlias);

    v3->addWidget(ScriptAliasInfo);

    v1->addLayout(labels13);

    v2->addWidget(ScriptAliasline);

    QHBoxLayout *labels14=new QHBoxLayout;

    labels14->addWidget(LogLevel);

    v3->addWidget(LogLevelInfo);

    v1->addLayout(labels14);

    v2->addWidget(LogLevelline);

    QHBoxLayout *labels15=new QHBoxLayout;

    labels15->addWidget(UserDir);

    v3->addWidget(UserDirInfo);

    v1->addLayout(labels15);

    v2->addWidget(UserDirline);


    QHBoxLayout *labels16=new QHBoxLayout;

    labels16->addWidget(PidFile);

    v3->addWidget(PidFileInfo);

    v1->addLayout(labels16);

    v2->addWidget(PidFileline);


    QHBoxLayout *labels17=new QHBoxLayout;

    labels17->addWidget(ServerSignature);

    v3->addWidget(ServerSignatureInfo);

    v1->addLayout(labels17);

    v2->addWidget(ServerSignatureline);


    QHBoxLayout *labels18=new QHBoxLayout;

    labels18->addWidget(Options);

    v3->addWidget(OptionsInfo);

    v1->addLayout(labels18);

    v2->addWidget(Optionsline);



    QHBoxLayout *mainH=new QHBoxLayout;

    QVBoxLayout *af=new QVBoxLayout;

    QLabel *aff=new QLabel;
    aff->setPixmap(QPixmap("apachef.png"));

    af->addWidget(aff);

    mainH->addLayout(v1);
    mainH->addLayout(v3);
    mainH->addLayout(v2);

    mainH->addStretch(1);

    mainH->addLayout(af);



    mainV1->setSpacing(5);
    mainV1->addLayout(mainH);
    mainV1->addStretch(1);

    setLayout(mainV1);

}

void Config::readFile(QFile &file, QString &str)
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




void Config::setqss()
{
    QFile file("config.qss");

    file.open(QFile::ReadOnly);

    QString strCSS = QLatin1String(file.readAll());

    this->setStyleSheet(strCSS);
}
