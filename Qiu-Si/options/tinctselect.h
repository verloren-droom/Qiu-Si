#ifndef TINCTSELECT_H
#define TINCTSELECT_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QColorDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QValidator>

#include "resources/ValueStore.h"

#include <QDebug>

class TinctSelect : public QWidget
{
    Q_OBJECT
public:
    explicit TinctSelect(QWidget *parent = nullptr, QString title = "Select Color...");

    void InitUi(QString title);
    QString colorStr;
    void setColorStr(QString color);

private:
    QLineEdit *inputEdit;
    QLabel *lbl_title;
    QPushButton *btn_color;
    QHBoxLayout *lay;
signals:

};

#endif // TINCTSELECT_H
