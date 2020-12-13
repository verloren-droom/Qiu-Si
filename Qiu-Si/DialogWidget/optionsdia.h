#ifndef OPTIONSDIA_H
#define OPTIONSDIA_H

#include <QDialog>
#include <QGroupBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QColorDialog>
#include <QPushButton>
#include <QLineEdit>

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

private:
    QGroupBox *textGroup, *themeGroup, *viewGroup;

//    QCheckBox *cb_setting;
    QSpinBox *sb_fontSize;

    QLabel *lbl_fontSize, *lbl_fontColor, *lbl_WindowColor;

    QPushButton *btn_ok, *btn_cancel;

    QLineEdit *le_windowColor, *le_fontColor;

    int fontSize;

signals:

};

#endif // OPTIONSDIA_H
