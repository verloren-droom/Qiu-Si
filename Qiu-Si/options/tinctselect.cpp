#include "tinctselect.h"

TinctSelect::TinctSelect(QWidget *parent, QString title) : QWidget(parent)
{
    InitUi(title);
}

void TinctSelect::InitUi(QString title)
{
    // 设置整体大小
    resize(360, 100);
    // 设置窗口图标
    setWindowIcon(QIcon(":/icon/images/icon/pigment.png"));

    // 给三个控件声明空间
    lbl_title = new QLabel(title + ": ", this);
    inputEdit = new QLineEdit(this);
    btn_color = new QPushButton(this);
    btn_color->setStyleSheet(QString("QPushButton{background-color: %1;border-style: outset;border: 1px groove gray;}"
                                     "QPushButton:pressed{border-style: inset;}").arg(ValueStore::instance()->fontColor)
                             );
    lay = new QHBoxLayout;
    lay->addWidget(lbl_title);
    lay->addWidget(inputEdit);
    lay->addWidget(btn_color);
    setLayout(lay);

    connect(btn_color, &QPushButton::clicked, [=]{
        QColor tinct = QColorDialog::getColor(Qt::white, this, title + "...");
        colorStr = "#" + QString::number(qRgb(tinct.red(), tinct.green(), tinct.blue()), 16).mid(2, 8);
        btn_color->setStyleSheet(QString("background-color: %1").arg(colorStr));
        inputEdit->setText(colorStr);
    });

    connect(inputEdit, &QLineEdit::textEdited, btn_color, [=](QString str){
        QRegExp regx("[A-Fa-f0-9]{4}");
        inputEdit->setValidator(new QRegExpValidator(regx, btn_color));
//        inputEdit->setInputMask("HHHHHHHH");
        btn_color->setStyleSheet(QString("QPushButton{background-color: %1; order-style: outset;border: 1px groove gray;}"
                                         "QPushButton:pressed{border-style: inset;}").arg(str));
    });

}

void TinctSelect::setColorStr(QString color)
{
    inputEdit->setText(color);
}
