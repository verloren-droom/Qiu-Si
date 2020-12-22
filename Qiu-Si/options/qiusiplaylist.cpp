#include "qiusiplaylist.h"

QiuSiPlaylist::QiuSiPlaylist(QWidget *parent) : QWidget(parent)
{
    musicList = new QListWidget(this);

    btn_play = new QPushButton("Playlist", this);
    btn_play->setStyleSheet(SetBtnStyle());
    btn_play->setFixedSize(100, 40);

    btn_history = new QPushButton("History", this);
    btn_history->setStyleSheet(SetBtnStyle());
    btn_history->setFixedSize(100, 40);

    QHBoxLayout *lay_ph = new QHBoxLayout;
    lay_ph->addStretch();
    lay_ph->addWidget(btn_play);
    lay_ph->addWidget(btn_history);
    lay_ph->addStretch();
    lay_ph->setAlignment(Qt::AlignCenter);

    musicList->addItem(new QListWidgetItem("fisrt"));
    musicList->addItem(new QListWidgetItem("second"));

    setStyleSheet(QString("QWidget::item{border: 0px;}"));

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addLayout(lay_ph);
    lay->addWidget(musicList);

    setContentsMargins(0, 0, 0, 0);
    setLayout(lay);

    connect(btn_play, &QPushButton::clicked, [=]{
        ShowPlaylist();
    });

    connect(btn_history, &QPushButton::clicked, [=]{
        ShowHistory();
    });
}

QString QiuSiPlaylist::SetBtnStyle()
{
    return QString("QPushButton{border: 0px;}");
}

void QiuSiPlaylist::ShowPlaylist()
{

}

void QiuSiPlaylist::ShowHistory()
{

}
