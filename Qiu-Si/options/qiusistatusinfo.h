#ifndef QIUSISTATUSINFO_H
#define QIUSISTATUSINFO_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QMatrix>

class QiuSiStatusInfo : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiStatusInfo(const QString &title = "Unknown Songs", const QString &image = nullptr, QWidget *parent = nullptr);

    void ShowInfo(const QString &title);

    QLabel *lbl_fileName;
private:
    QLabel *lbl_image;

signals:

};

#endif // QIUSISTATUSINFO_H
