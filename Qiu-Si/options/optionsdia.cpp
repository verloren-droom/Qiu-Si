#include "optionsdia.h"

OptionsDia::OptionsDia(QWidget *parent) : QDialog(parent)
{
    InitUi();
    setCurrentValue();
}

// Initialization interface function
void OptionsDia::InitUi()
{
    setFixedSize(400, 300);
    setWindowTitle("Option");
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    optionsTab = new QTabWidget(this);
    optionsTab->resize(width(), height());
    optionsTab->setTabPosition(QTabWidget::West);

    TextEditSetting();
    ThemeSetting();
//    ViewSetting();
//    ReadSetting();

    // Place the OK and Cancel buttons in the lower right corner
    QHBoxLayout *lay_select = new QHBoxLayout(this);
    btn_ok = new QPushButton("OK", this);
    btn_ok->resize(120, 60);
    btn_cancel = new QPushButton("Cancel", this);
    btn_cancel->resize(120, 60);
    lay_select->addWidget(btn_ok);
    lay_select->addWidget(btn_cancel);

    // Sets the cancel key to the default associated carriage Enter key
    btn_cancel->setFocus();
    btn_cancel->setDefault(true);

    lay_select->setAlignment(Qt::AlignRight | Qt::AlignBottom);

    SaveSetting();
    CancelSetting();
}

// Save the setting function
void OptionsDia::SaveSetting()
{
    connect(btn_ok, &QPushButton::clicked, this, &OptionsDia::setSaveValue);
}

// Save the Settings slot function
void OptionsDia::setSaveValue()
{
    ValueStore::instance()->changeFontSize(qs_fontSize->sb_number->value());
    ValueStore::instance()->changeFontBold(cb_Blod->isChecked());
    ValueStore::instance()->changeFontItalic(cb_Italic->isChecked());
    ValueStore::instance()->changeFontColor(fontTinctSelect->colorStr);
    emit saveValue();
    close();
}

// Font size change function
void OptionsDia::fontSizeChange()
{
    qs_fontSize->sb_number->setValue(ValueStore::instance()->fontSize);
}

// Cancel the setup function
void OptionsDia::CancelSetting()
{
    connect(btn_cancel, &QPushButton::clicked, this, &OptionsDia::setCurrentValue);
}

// Save the original slot function
void OptionsDia::setCurrentValue()
{
    qs_fontSize->sb_number->setValue(ValueStore::instance()->fontSize);
    cb_Blod->setChecked(ValueStore::instance()->fontBold);
    cb_Blod->setChecked(ValueStore::instance()->fontItalic);
    fontTinctSelect->setColorStr(ValueStore::instance()->fontColor);
    close();
}

// font the setting function
void OptionsDia::TextEditSetting()
{
    optionsTab->setTabText(0, "Text Edit");

    // 初始化字体分组，并设置大小
    textGroup = new QGroupBox("Text Edit", this);
    optionsTab->addTab(textGroup, "Text Edit");

    // 初始化字体设置大小，并设置大小
    qs_fontSize = new QiusiSpinBox("Font Size", this);

    // 初始化字体颜色设置
    fontTinctSelect = new TinctSelect(this, "Font Color");

    // 初始化字体粗体和斜体
    cb_Blod = new QCheckBox("Blod", this);
    cb_Italic = new QCheckBox("Italic", this);

    // Place all font Settings in the grid layout
    QGridLayout *lay_font = new QGridLayout;
    lay_font->addWidget(qs_fontSize, 0, 0, Qt::AlignLeft | Qt::AlignTop);
    lay_font->addWidget(fontTinctSelect, 0, 1, Qt::AlignLeft | Qt::AlignTop);
    lay_font->addWidget(cb_Blod, 1, 0, Qt::AlignLeft | Qt::AlignTop);
    lay_font->addWidget(cb_Italic, 1, 1, Qt::AlignLeft | Qt::AlignTop);

    // 设置水平，垂直以及外边距
    lay_font->setHorizontalSpacing(10);
    lay_font->setVerticalSpacing(30);
    lay_font->setContentsMargins(10, 10, 10, 10);

    // 将总体垂直布局放在字体分组中
    textGroup->setLayout(lay_font);
}

// Theme Settings function
void OptionsDia::ThemeSetting()
{
    optionsTab->setTabText(1, "Theme");
    // 初始化主题分组，并设置位置与大小
    themeGroup = new QGroupBox("Theme", this);
    themeGroup->setGeometry(0, height() / 3, width(), height() / 3);
    optionsTab->addTab(themeGroup, "Theme");

    // 初始化主题颜色设置，并设置大小
    themeTinctSelect = new TinctSelect(this, "Theme Color");

    // 将主题颜色设置放在一个水平布局
    QGridLayout *lay_theme = new QGridLayout;
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


