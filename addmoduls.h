#ifndef ADDMODULS
#define ADDMODULS
#include <QtWidgets>
#include <QtCore>

class AddModuls final:public QWidget
{
    Q_OBJECT
private:

    QLabel *moduls,*loadmodul,*loadmodulInfo,*addtype,*addtypeInfo,*addhandler,*addhandlerInfo,*addencoding,*addencodingInfo,*phpl;

    QCheckBox *php,*python;

    QString conf;

    QLineEdit *loadmodulline,*addtypeline,*addhandlerline,*addencodingline,*phppath;

    QPushButton *loadmodulbut,*addtypebut,*addhandlerbut,*addencodingbut;

public:

    explicit AddModuls(QWidget *p=0);

    ~AddModuls(){}

    AddModuls(const AddModuls &am)=delete;

    AddModuls& operator=(const AddModuls &am)=delete;

public slots:

    void setFileConf(const QString &filename);

    void setPHP(int state);

    void setPython(int state);

    void addLoadModul();

    void addType();

     void addHandler();

     void addEncoding();

     void createConnections();

     void createLayout();

     void readFile(QFile& , QString&);

     void setqss();
};

#endif // ADDMODULS

