#ifndef OPTIONSDIA_H
#define OPTIONSDIA_H

#include <QDialog>
#include <QGroupBox>
#include <QCheckBox>
#include <QLabel>
#include <QColorDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QFile>
#include <QJsonObject>
#include <QJsonParseError>
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonArray>
#include <QString>
#include <QTabWidget>

#include "tinctselect.h"
#include "qiusispinbox.h"
#include "resources/JsonKeyword.h"
#include "resources/ValueStore.h"

#include <QDebug>

class OptionsDia : public QDialog
{
    Q_OBJECT
public:
    explicit OptionsDia(QWidget *parent = nullptr);

    // 配置文件关键字
//    void ConfigKeyword();

private: 
    void InitUi();

    // textedit setting
    void TextEditSetting();
//    int GetFontSize();

    // theme setting
    void ThemeSetting();

    // view setting
    void ViewSetting();

    void SaveSetting();
    void CancelSetting();

    // 读取配置文件
    void ReadSetting();


    QTabWidget *optionsTab;
    // Text Group
    QGroupBox *textGroup;
    QPushButton *btn_text;
    QiusiSpinBox *qs_fontSize;
    TinctSelect *fontTinctSelect;
    QCheckBox *cb_Blod, *cb_Italic;

    // Theme Group
    QGroupBox *themeGroup;
    QPushButton *btn_theme;
    TinctSelect *bgTinctSelect;
    TinctSelect *themeTinctSelect;

    // View Group
    QGroupBox *viewGroup;

    QString path, themeColorStr, fontColorStr;
    QStringList fontConfig, themeConfig;

    QPushButton *btn_ok, *btn_cancel;

public slots:
    void setCurrentValue();
    void setSaveValue();
    void fontSizeChange();

signals:
    void saveValue();
};

#endif // OPTIONSDIA_H
