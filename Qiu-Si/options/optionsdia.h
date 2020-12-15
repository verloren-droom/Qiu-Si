#ifndef OPTIONSDIA_H
#define OPTIONSDIA_H

#include <QDialog>
#include <QGroupBox>
#include <QCheckBox>
#include <QSpinBox>
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
#include "resources/JsonKeyword.h"
#include "resources/ValueStore.h"

#include <QDebug>

class OptionsDia : public QDialog
{
    Q_OBJECT
public:
    explicit OptionsDia(QWidget *parent = nullptr);

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

    // 配置文件关键字
//    void ConfigKeyword();

private:
    QTabWidget *optionsTab;
    // Text Group
    QGroupBox *textGroup;
    QPushButton *btn_text;
    QLabel *lbl_fontSize, *lbl_fontColor;
    QSpinBox *sb_fontSize;
    TinctSelect *fontTinctSelect;
    QCheckBox *cb_Blod, *cb_Italic;

    // Theme Group
    QGroupBox *themeGroup;
    QPushButton *btn_theme;
    TinctSelect *bgTinctSelect;
    QLabel *lbl_WindowColor;
    TinctSelect *themeTinctSelect;

    // View Group
    QGroupBox *viewGroup;

    QString path, themeColorStr, fontColorStr;
    QStringList fontConfig, themeConfig;

    QPushButton *btn_ok, *btn_cancel;
signals:

};

#endif // OPTIONSDIA_H
