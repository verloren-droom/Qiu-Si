#include "optionsdia.h"

OptionsDia::OptionsDia(QWidget *parent) : QDialog(parent)
{
    InitUi();
}

void OptionsDia::InitUi()
{
    setFixedSize(400, 300);
    setWindowTitle("Option");
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    TextEditSetting();
    ThemeSetting();
    ViewSetting();

    // 将确定和取消按钮放在右下角
    QHBoxLayout *lay_select = new QHBoxLayout(this);
    btn_ok = new QPushButton("OK", this);
    btn_ok->resize(120, 60);
    btn_cancel = new QPushButton("Cancel", this);
    btn_cancel->resize(120, 60);
    lay_select->addWidget(btn_ok);
    lay_select->addWidget(btn_cancel);

    // 设置取消键为默认关联回车键
    btn_cancel->setFocus();
    btn_cancel->setDefault(true);

    lay_select->setAlignment(Qt::AlignRight | Qt::AlignBottom);

    SaveSetting();
    CancelSetting();
}

// 保存设置
void OptionsDia::SaveSetting()
{
    connect(btn_ok, &QPushButton::clicked, [=]{
        fontSize = sb_fontSize->value();
        qDebug() << fontSize;
        close();
    });
}

// 取消设置
void OptionsDia::CancelSetting()
{
    connect(btn_cancel, &QPushButton::clicked, [=]{
        close();
    });
}

void OptionsDia::TextEditSetting()
{
    textGroup = new QGroupBox("Text Edit", this);
    textGroup->resize(width(), height() / 3);

    // 字体大小设置
    lbl_fontSize = new QLabel("Font Size: ");
    sb_fontSize = new QSpinBox(this);
    QVBoxLayout *lay_font = new QVBoxLayout(this);
    QHBoxLayout *lay_fontSize = new QHBoxLayout(this);
    lay_fontSize->addWidget(lbl_fontSize);
    lay_fontSize->addWidget(sb_fontSize);

    lay_font->addLayout(lay_fontSize);
    textGroup->setLayout(lay_font);
}

void OptionsDia::ThemeSetting()
{
    themeGroup = new QGroupBox("Theme", this);
    themeGroup->setGeometry(0, height() / 3, width(), height() / 3);

    lbl_WindowColor = new QLabel("Window Color: ", this);
    QHBoxLayout *lay_windowColor = new QHBoxLayout(this);
    lay_windowColor->addWidget(lbl_WindowColor);


    themeGroup->setLayout(lay_windowColor);
}

void OptionsDia::ViewSetting()
{
    viewGroup = new QGroupBox("View", this);
    viewGroup->move(0, 200);
}
