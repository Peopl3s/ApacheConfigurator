#ifndef CONFIG
#define CONFIG
#include <QtWidgets>
#include <QtCore>
#include <algorithm>

class Config final:public QWidget
{
    Q_OBJECT

private:

    QString conf;

    QLabel *namepage,*servername,*servernameInfo,*timeout,*timeoutInfo,*keepalive,*keepaliveInfo,*keepatime,*keepatimeinfo,*mr,
    *mrinfo,*HostnameLookups,*HostnameLookupsInfo,*DocumentRoot,*DocumentRootInfo,*ServerRoot,*ServerRootInfo,
    *ErrorLog, *ErrorLogInfo,*CustomLog,*CustomLogInfo,*Listen,*ListenInfo,*ServerAdmin,*ServerAdminInfo,*ScriptAlias,*ScriptAliasInfo,
    *LogLevel,*LogLevelInfo,*UserDir,*UserDirInfo,*PidFile,*PidFileInfo,*ServerSignature,*ServerSignatureInfo,*Options,*OptionsInfo;

    QLineEdit *sname,*timename,*keepatimeline,*mrline,*DocumentRootline,*ServerRootline,*ErrorLogline,*CustomLogline,*Listenline,*ServerAdminline,
    *ScriptAliasline,*LogLevelline,*UserDirline,*PidFileline,*ServerSignatureline,*Optionsline;

    QRadioButton *on,*off,*hostnameon,*hostnameoff;

    QSet<QString>options;

    QSettings settings;

public:

    explicit Config(QWidget *p=0,QString conf_="");

    ~Config(){}

    Config(const Config &am)=delete;

    Config& operator=(const Config &am)=delete;

public slots:

    void setFileConf(const QString &filename);

    void changeServerName();

    void changeTimeout();

    void changeKeepAlive();

    void changeKeepAliveTimeout();

    void changeMaxKeepAliveRequests();

    void changeHostnameLookups();

    void changeDocumentRoot();

    void changeServerRoot();

    void changeErrorLog();

    void changeCustomLog();

    void changeListen();

    void changeServerAdmin();

    void changeScriptAlias();

    void changeLogLevel();

    void changeUserDir();

    void changePidFile();

    void changeServerSignature();

    void changeOptions();

    QSet<QString> getOptions() const;

    void createConnections();

    void createLayout();

    void readFile(QFile &,QString &);

    void setqss();
};

#endif // CONFIG

