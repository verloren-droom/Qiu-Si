#ifndef QIUSI_H
#define QIUSI_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QFont>

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

    // connect function
    void ConnectFunc();

    // set unified font
    QFont UnifiedFont();

private:
    Ui::QiuSi *ui;

    // content
    QTextEdit *txt_content;

    // declaration main menubar
    QMenuBar *mainMenu;

    // declaration menu
    QMenu *fileMenu, *helpMenu;

    // declaration action
    QAction *quitAction, *aboutAction;

    // declaration dialog
    QDialog *aboutDia;
};
#endif // QIUSI_H
