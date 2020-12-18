#ifndef QIUSISPINBOX_H
#define QIUSISPINBOX_H

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QHBoxLayout>

#include "resources/ValueStore.h"

class QiusiSpinBox : public QWidget
{
    Q_OBJECT
public:
    explicit QiusiSpinBox(QString title, QWidget *parent = nullptr);
    ~QiusiSpinBox();

    QSpinBox *sb_number;
private:
    void Init(QString title);

    QLabel *lbl_title;
    QHBoxLayout *layh;

signals:

};

#endif // QIUSISPINBOX_H
