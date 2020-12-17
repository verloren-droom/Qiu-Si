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
#include <QScrollArea>
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
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QIcon>

#include "help/aboutdia.h"
#include "options/optionsdia.h"
#include "resources/ValueStore.h"
#include "resources/dynamicprogressbar.h"
#include "options/qiusivideomode.h"

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

//    void paintEvent(QEvent *ev);

    // QiuSi font
    QFont QiusiFont();
    // QiusSi icon
    QIcon QiusiIcon();
    // QiuSi Color
    QPalette QiusPalette();

    // file menu function
    void OpenFile();
    void OpenNewWindow();
    void NewWindow();
    bool GetFile();
    void OpenTxtFile(QFile *txt);
    void OpenImageFile(const QString &filePath = nullptr);
    void OpenMusicFile(const QString &filePath = nullptr);

    // Tool menu function
    void changeFontSize();
    void AddSize();
    void SubSize();
    void DisplaySizePrompt();
    void HiddenSizePrompt();
    void VideoMode();
    void OptionsApp();

    // help menu function
    void QuitApp();
    void AboutApp();

    // event
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

private:
    Ui::QiuSi *ui;

    // Initialize function
    void InitUi();
    void InitSet();
    void InitBar(bool display = true);

    // content
    QLabel *mainContent;
    QScrollArea *sa_content;

    // declaration main menubar
    QMenuBar *mainMenu;

    // declaration file menu
    QMenu *fileMenu, *editMenu;
    QAction *openAction, *openNewAction, *quitAction;
    QIcon *icon_open, *icon_openNew, *icon_quit;
    QiuSi *newQiusi;
    QShortcut *sc_open, *sc_openNew, *sc_quit;
    QString path;
    QStringList suffixList;

    // music play mode
    QMediaPlayer *musicPlay;
    QMediaPlaylist *musicPlayList;
    QiuSiVideoMode *videoMode;

    // declaration tool menu
    QMenu *toolsMenu;
    QAction *addSizeAction, *subSizeAction, *videoModeAction, *optionsAction;
    QIcon *icon_add, *icon_sub, *icon_video, *icon_option;
    OptionsDia *optionDia;
    QLabel *lbl_displaySize;
    QShortcut *sc_add, *sc_sub, *sc_music, *sc_option;
//    ValueStore *valueStore;

    // declaration help menu
    QMenu *helpMenu;
    QAction *aboutAction;
    AboutDia *aboutDia;

    int totalLine;
    QPoint dPos;

};

#endif // QIUSI_H
