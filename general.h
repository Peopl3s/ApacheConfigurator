#ifndef GENERAL
#define GENERAL
#include <QtWidgets>
#include <QtCore>

class General final:public QWidget
{
    Q_OBJECT

private:
    QLabel *namepage,*discfilename,*name,*ap,*labelhttpd,*httpd,*note;

    QPushButton *dialog,*setup,*delet,*buttonhttpd,*opennote;

    QString httpdexe;

    QSettings gs;

public:
    explicit General(QWidget *p=0);

    ~General()
    {
        writeSettings();
    }

    General(const General &am)=delete;

    General& operator=(const General &am)=delete;

public slots:

    void selectFile();

    void selectExe();

    void setupApache();

    void deletApache();

    void completeInstall();

    void completeUnstall();

    void openNote();

    void createConnections();

    void createLayout();

    void setqss();

    void readSettings();

    void writeSettings();
   //  void x();


signals:

    void selectedFile(const QString &);
};

#endif // GENERAL

