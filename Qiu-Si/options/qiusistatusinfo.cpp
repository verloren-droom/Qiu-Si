#include "qiusistatusinfo.h"

QiuSiStatusInfo::QiuSiStatusInfo(const QString &title, const QString &image, QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(200, 80);

    lbl_image = new QLabel(this);
    lbl_image->setPixmap(QPixmap(image));
    lbl_fileName = new QLabel(title, this);

    QHBoxLayout *lay = new QHBoxLayout;

    lay->addWidget(lbl_image);
    lay->addWidget(lbl_fileName);
    lay->setAlignment(Qt::AlignLeft);

    setLayout(lay);
}
