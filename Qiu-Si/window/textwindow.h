#ifndef TEXTWINDOW_H
#define TEXTWINDOW_H

#include <QDialog>
#include <QTextEdit>
#include <QFile>
#include <QFileInfo>

class TextWindow : public QDialog
{
    Q_OBJECT
public:
    explicit TextWindow(const QString &filePath, QWidget *parent = nullptr);
    void Init(const QString &path);
private:
    QTextEdit *mainText;
signals:

};

#endif // TEXTWINDOW_H
