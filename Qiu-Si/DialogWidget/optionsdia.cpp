#include "optionsdia.h"

OptionsDia::OptionsDia(QWidget *parent) : QDialog(parent)
{
    InitUi();
}

// 初始化界面
void OptionsDia::InitUi()
{
    setFixedSize(400, 300);
    setWindowTitle("Option");
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    TextEditSetting();
    ThemeSetting();
    ViewSetting();
//    ReadSetting();

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
//        fontSize = sb_fontSize->value();
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

// 字体设置
void OptionsDia::TextEditSetting()
{
    // 初始化字体分组，并设置大小
    textGroup = new QGroupBox("Text Edit", this);
    textGroup->resize(width() - 10, height() / 3 - 10);

    // 初始化字体设置大小，并设置大小
    lbl_fontSize = new QLabel("Font Size: ", this);
    sb_fontSize = new QSpinBox(this);

    // 初始化字体颜色设置
    lbl_fontColor = new QLabel("Font Color: ", this);
    fontTinctSelect = new TinctSelect(this, "Font Color...");

    // 将所有设置放入格子布局中
    QGridLayout *lay_font = new QGridLayout;
    lay_font->addWidget(lbl_fontSize, 0, 0, Qt::AlignLeft);
    lay_font->addWidget(sb_fontSize, 0, 1, Qt::AlignLeft);
    lay_font->addWidget(lbl_fontColor, 0, 2, Qt::AlignLeft);
    lay_font->addWidget(fontTinctSelect, 0, 3, Qt::AlignLeft);

    // 设置水平，垂直以及外边距
    lay_font->setHorizontalSpacing(10);
    lay_font->setVerticalSpacing(30);
    lay_font->setContentsMargins(10, 10, 10, 10);

    // 将总体垂直布局放在字体分组中
    textGroup->setLayout(lay_font);
}

// 主题设置
void OptionsDia::ThemeSetting()
{
    // 初始化主题分组，并设置位置与大小
    themeGroup = new QGroupBox("Theme", this);
    themeGroup->setGeometry(0, height() / 3, width(), height() / 3);

    // 初始化主题颜色设置，并设置大小
    lbl_WindowColor = new QLabel("Theme Color: ", this);
    themeTinctSelect = new TinctSelect(this, "Theme Color...");

    // 将主题颜色设置放在一个水平布局
    QGridLayout *lay_theme = new QGridLayout;
    lay_theme->addWidget(lbl_WindowColor, 0, 0, Qt::AlignLeft);
    lay_theme->addWidget(themeTinctSelect, 0, 1, Qt::AlignLeft);

    // 格子布局设置
    lay_theme->setHorizontalSpacing(10);
    lay_theme->setVerticalSpacing(30);
    lay_theme->setContentsMargins(10, 10, 10, 10);


    // 将主题颜色设置添加到主题分组中
    themeGroup->setLayout(lay_theme);
}

// 视图设置
void OptionsDia::ViewSetting()
{
    // 初始化视图分组，并设置位置
    viewGroup = new QGroupBox("View", this);
    viewGroup->move(0, 200);
}

//void OptionsDia::ConfigKeyword()
//{
//    fontConfig << "font" << "size" << "color";
//    themeConfig << "theme" << "color";
//}

// 读取配置文件
void OptionsDia::ReadSetting()
{
//    path = QFileDialog::getOpenFileName(this, "select config file...", "(*.json)");
    if (path == "")
        path = ":ResFile/config/setting.json";
    QFile configFile(path);
    configFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = configFile.readAll();

    QJsonParseError jsonError;
    QJsonDocument docu = QJsonDocument::fromJson(data.toUtf8(), &jsonError);
    if (jsonError.error != QJsonParseError::NoError)
    {
        QMessageBox::warning(this, "Prompt", "Configuration file error!");
        return;
    }
    QJsonObject jsonConfig = docu.object();
//    ConfigKeyword();

    if (jsonConfig.contains(fontConfig[0]))
    {
        QJsonValue fontValue = jsonConfig.value(fontConfig[0]);
        if (fontValue.isArray())
        {
            QJsonArray fontArray = fontValue.toArray();
            for (int arr{0}; arr < fontArray.size(); ++arr)
            {
                QJsonValue setValue = fontArray.at(arr);
                QJsonObject setKey = setValue.toObject();
                for (auto a{fontConfig.begin()}; a != fontConfig.end(); ++a)
                {
                    qDebug() << *a;
                }
            }
        }
    }

}


