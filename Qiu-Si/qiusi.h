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
#include <QTextStream>

#include "DialogWidget/aboutdia.h"
#include "DialogWidget/optionsdia.h"

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

    // initialize the menubar
    void InitBar(bool display = true);

    // initialize the number bar
    void InitNumBar();

    // unified font
    QFont UnifiedFont();
    // unified icon
    QIcon UnifiedIcon();

    // file menu function
    void OpenFile();
    void GetFile();


    // Tool menu function
    void AddFontSize();
    void AddSize();
    void SubFontSize();
    void SubSize();
    void OptionsApp();

    // help menu function
    void QuitApp();
    void AboutApp();

private:
    Ui::QiuSi *ui;

    // content
    QTextEdit *txt_content;

    // declaration main menubar
    QMenuBar *mainMenu;

    QToolBar *numBar;

    // declaration file menu
    QMenu *fileMenu, *editMenu;
    QAction *openAction, *quitAction;
    QShortcut *sc_quit, *sc_open;

    // declaration tool menu
    QMenu *toolsMenu;
    QAction *addSizeAction, *subSizeAction, *optionsAction;
    OptionsDia *optionDia;
    QShortcut *sc_add, *sc_sub;

    // declaration help menu
    QMenu *helpMenu;
    QAction *aboutAction;
    AboutDia *aboutDia;


    // file path
    QString path;

    int totalLine;

};
#endif // QIUSI_H
