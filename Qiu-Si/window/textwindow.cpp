#include "textwindow.h"

TextWindow::TextWindow(const QString &filePath, QWidget *parent) : QDialog(parent)
{
    Init(filePath);
}

void TextWindow::Init(const QString &path)
{
    // 去掉对话框的问号
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    mainText = new QTextEdit(this);
    mainText->setReadOnly(true);
    mainText->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    uchar* fPtr = file.map(0, file.size());
    QString txtStr;
    if (fPtr)
    {
//        DynamicProgressBar *progressBar = new DynamicProgressBar(txt->fileName());
//        QCoreApplication::processEvents();
        file.unmap(fPtr);
        while (!file.atEnd())
        {
            txtStr += file.readLine();
        }
        repaint();
    }
    mainText->setText(txtStr);
}
