#ifndef QIUSIPLAYLIST_H
#define QIUSIPLAYLIST_H

#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTabWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QTableView>
#include <QAbstractItemModel>
#include <QMediaContent>
#include <QList>
#include <QFileInfo>

#include <QDebug>

class QiuSiPlaylist : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiPlaylist(QWidget *parent = nullptr);

    QListWidget *musicList, *historyList;

    QTabWidget *play_history;

    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent=QModelIndex()) const;

    QModelIndex index(int row, int column, const QModelIndex &parent=QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child=QModelIndex()) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool removeRows(int row, int count, const QModelIndex &parent=QModelIndex());

public slots:
    void ShowPlaylist(bool display);
    void ShowHistory(bool display);

private:
    QString SetBtnStyle();
    QString SetListStyle();

    QList<QMediaContent> m_data;

signals:
    void dataChanged(const QModelIndex &index, const QVariant &value);
};

#endif // QIUSIPLAYLIST_H
