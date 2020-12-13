#ifndef ABOUTDIA_H
#define ABOUTDIA_H

#include <QDialog>
#include <QLabel>
#include <QIcon>
#include <QMessageBox>

class AboutDia : public QDialog
{
    Q_OBJECT
public:
    explicit AboutDia(QWidget *parent = nullptr);

    //init ui
    void InitDialog();

private:
    QLabel *lbl_about, *lbl_address, *lbl_info, *lbl_author, *lbl_email;

signals:

};

#endif // ABOUTDIA_H
