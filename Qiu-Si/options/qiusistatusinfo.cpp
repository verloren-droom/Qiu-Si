#include "qiusistatusinfo.h"

QiuSiStatusInfo::QiuSiStatusInfo(const QString &title, const QString &image, QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(170, 85);

    QMatrix matrix;
    matrix.rotate(10);

    lbl_image = new QLabel(this);
    lbl_image->setPixmap(QPixmap(image));
    lbl_fileName = new QLabel(title, this);
    QFont font;
    font.setPointSize(10);
    lbl_fileName->setFont(font);
    lbl_fileName->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    QHBoxLayout *lay = new QHBoxLayout;

    lay->addWidget(lbl_image);
    lay->addWidget(lbl_fileName);
    lay->setAlignment(Qt::AlignLeft);

    lay->setContentsMargins(0, 0, 0, 10);

    setLayout(lay);
}

void QiuSiStatusInfo::ShowInfo(const QString &title)
{
    lbl_fileName->setText(title);
}
