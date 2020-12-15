#ifndef QIUSI_H
#define QIUSI_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QAction>
#include <QDialog>
#include <QFont>
#include <QLabel>
#include <QFileDialog>
#include <QShortcut>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QPixmap>
#include <QTimer>
#include <QElapsedTimer>
#include <QPointer>
#include <QProgressBar>
#include <QMetaEnum>

#include "help/aboutdia.h"
#include "options/optionsdia.h"
#include "resources/ValueStore.h"
#include "resources/dynamicprogressbar.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class QiuSi; }
QT_END_NAMESPACE

class QiuSi : public QMainWindow
{
    Q_OBJECT

public:
    QiuSi(QWidget *parent = nullptr);
    ~QiuSi();

    // initialize the UI
    void InitUi();
    void InitSet();

    // initialize the menubar
    void InitBar(bool display = true);

//    void paintEvent(QEvent *ev);

    // unified font
    QFont UnifiedFont();
    // unified icon
    QIcon UnifiedIcon();

    // file menu function
    void OpenFile();
    void GetFile();
    void OpenTxtFile(QFile *txt);
    void OpenImageFile(QString filePath);


    // Tool menu function
    void changeFontSize();
    void AddSize();
    void SubSize();
    void OptionsApp();

    // help menu function
    void QuitApp();
    void AboutApp();

private:
    Ui::QiuSi *ui;

    // content
    QTextEdit *txt_content;
    QLabel *mainContent;

    // declaration main menubar
    QMenuBar *mainMenu;

    // declaration file menu
    QMenu *fileMenu, *editMenu;
    QAction *openAction, *quitAction;
    QShortcut *sc_quit, *sc_open;
    QString path;
    QStringList suffixList;

    // declaration tool menu
    QMenu *toolsMenu;
    QAction *addSizeAction, *subSizeAction, *optionsAction;
    OptionsDia *optionDia;
    QShortcut *sc_add, *sc_sub;
//    ValueStore *valueStore;

    // declaration help menu
    QMenu *helpMenu;
    QAction *aboutAction;
    AboutDia *aboutDia;

    int totalLine;

};

#endif // QIUSI_H
