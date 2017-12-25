#ifndef DIRECTORYS
#define DIRECTORYS
#include <QtWidgets>
#include <QtCore>
#include <algorithm>

class Directory final:public QWidget
{
    Q_OBJECT
private:

    QLabel *directorys,*mainDir,*mainDirInfo,*addons;

    QLineEdit *mainDirline;

    QSet<QString> op;

    QString conf;

    QPushButton *adddir;

    QTextEdit *d;

public:

    explicit Directory(QWidget *p=0);

    ~Directory(){}

    Directory(const Directory &am)=delete;

    Directory& operator=(const Directory &am)=delete;

public slots:

    void changeMainDirectory();

    void setOptions(const QSet<QString>&s);

    void setFileConf(const QString &filename);

    void addDirectory();

    void createLayout();

    void readFile(QFile &,QString &s);

    void setqss();
};
#endif // DIRECTORYS

