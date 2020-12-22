#ifndef QIUSIPLAYLIST_H
#define QIUSIPLAYLIST_H

#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QDebug>

class QiuSiPlaylist : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiPlaylist(QWidget *parent = nullptr);

    QListWidget *musicList;

    QPushButton *btn_play, *btn_history;

    void ShowPlaylist();
    void ShowHistory();

private:
    QString SetBtnStyle();

signals:

};

#endif // QIUSIPLAYLIST_H
