#include "qiusispinbox.h"

QiusiSpinBox::QiusiSpinBox(QString title, QWidget *parent) : QWidget(parent)
{
    Init(title);
}

void QiusiSpinBox::Init(QString title)
{
    resize(320, 100);
    lbl_title = new QLabel(title + ": ", this);
    sb_number = new QSpinBox(this);
    layh = new QHBoxLayout;
    layh->addWidget(lbl_title);
    layh->addWidget(sb_number);
    setLayout(layh);

    sb_number->setValue(ValueStore::instance()->fontSize);
}

QiusiSpinBox::~QiusiSpinBox()
{

}
