#include "tinctselect.h"

TinctSelect::TinctSelect(QWidget *parent, QString title) : QWidget(parent)
{
    InitUi(title);
}

void TinctSelect::InitUi(QString title)
{
    // 设置整体大小
    resize(180, 100);
    // 设置窗口图标
    setWindowIcon(QIcon(":/icon/images/icon/pigment.png"));

    // 给三个控件声明空间
    inputEdit = new QLineEdit(this);
    inputEdit->resize(120, 100);
    btn_color = new QPushButton(this);
    btn_color->resize(100, 100);
    lay = new QHBoxLayout;
    lay->addWidget(inputEdit);
    lay->addWidget(btn_color);
    setLayout(lay);


    connect(btn_color, &QPushButton::clicked, [=]{
        QColor tinct = QColorDialog::getColor(Qt::white, this, title);
        colorStr = "#" + QString::number(qRgb(tinct.red(), tinct.green(), tinct.blue()), 16).mid(2, 8);
        btn_color->setStyleSheet(QString("background-color: %1").arg(colorStr));
        inputEdit->setText(colorStr);
    });
    connect(inputEdit, &QLineEdit::textEdited, btn_color, [=](QString str){
        QRegExp regx("[A-Fa-f0-9]{4}");
        inputEdit->setValidator(new QRegExpValidator(regx, btn_color));
//        inputEdit->setInputMask("HHHHHHHH");
        btn_color->setStyleSheet(QString("background-color: %1").arg(str));
    });

}
