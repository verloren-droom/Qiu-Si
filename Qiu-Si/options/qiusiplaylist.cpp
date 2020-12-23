#include "qiusiplaylist.h"

QiuSiPlaylist::QiuSiPlaylist(QWidget *parent) : QWidget(parent)
{
    play_history = new QTabWidget(this);
    musicList = new QListWidget(play_history);
    historyList = new QListWidget(play_history);

    QTableWidget *test = new QTableWidget(this);
    QTableWidget *test2 = new QTableWidget(this);

    play_history->setTabText(0, "Playlist");
    play_history->setTabText(1, "History");

    QVBoxLayout *lay_all = new QVBoxLayout;
    lay_all->addWidget(play_history);

    setLayout(lay_all);

//    btn_play = new QPushButton("Playlist", this);
//    btn_play->setStyleSheet(SetBtnStyle());
//    btn_play->setFixedSize(100, 40);

//    btn_history = new QPushButton("History", this);
//    btn_history->setStyleSheet(SetBtnStyle());
//    btn_history->setFixedSize(100, 40);

//    QHBoxLayout *lay_ph = new QHBoxLayout;
//    lay_ph->addStretch();
//    lay_ph->addWidget(btn_play);
//    lay_ph->addWidget(btn_history);
//    lay_ph->addStretch();
//    lay_ph->setAlignment(Qt::AlignCenter);
    QHeaderView *headerView_h = test->verticalHeader();
    headerView_h->close();
    headerView_h = test->horizontalHeader();
    headerView_h->close();
    test->setSelectionBehavior(QAbstractItemView::SelectRows);
    test->setSelectionMode(QAbstractItemView::SingleSelection);
    test->setColumnCount(4);
    test->setRowCount(20);
    test->setShowGrid(false);

    test->horizontalHeader()->resizeSection(0, 417);
    test->horizontalHeader()->resizeSection(1, 50);
    test->horizontalHeader()->resizeSection(2, 50);
    test->horizontalHeader()->resizeSection(3, 50);

    headerView_h = test2->horizontalHeader();
    headerView_h->close();
    headerView_h = test2->verticalHeader();
    headerView_h->close();

    QTableWidgetItem *item = new QTableWidgetItem("haha");
    test->setItem(0, 0, item);

//    musicList->addItem(new QListWidgetItem("fisrt"));
//    musicList->addItem(new QListWidgetItem("second"));

    setStyleSheet(QString("QWidget::item{border: 1px;}"));
    musicList->setStyleSheet(SetListStyle());
    historyList->setStyleSheet(SetListStyle());

//    QVBoxLayout *lay = new QVBoxLayout;
//    lay->addLayout(lay_ph);
//    lay->addWidget(musicList);
//    lay->addWidget(historyList);

//    setContentsMargins(0, 0, 0, 0);
//    setLayout(lay);

//    connect(btn_play, &QPushButton::clicked, this, &QiuSiPlaylist::ShowPlaylist);
//    connect(btn_history, &QPushButton::clicked, this, &QiuSiPlaylist::ShowHistory);
}

inline QString QiuSiPlaylist::SetBtnStyle()
{
    return QString("QPushButton{border: 0px;}");
}

inline QString QiuSiPlaylist::SetListStyle()
{
    return "QListWidget{color: black; background: white;border:0px solid gray;}"
           "QListWidget::Item{height:30px;border:0px solid gray;padding-left:15;}"
           "QListWidget::Item:hover{color: #c02c38;background:transparent;border:0px solid gray;}"
           "QListWidget::Item:selected{color: #c02c38;border:0px solid gray;}"
           "QListWidget::Item:selected:active{background: #c02c38; color: white;border-width:0;}";
}

void QiuSiPlaylist::ShowPlaylist(bool display)
{
    musicList->show();
    historyList->close();

    if(display)
    {
        qDebug() << "playlist show";
    }
    else
    {
        qDebug() << "playlist hidden";
    }
}

void QiuSiPlaylist::ShowHistory(bool display)
{
    musicList->close();
    historyList->show();

    if (display)
    {
        qDebug() << "history show";
    }
    else
    {
        qDebug() << "history hidden";
    }
}


QVariant QiuSiPlaylist::data(const QModelIndex &index, int role) const
{
    if(index.isValid() && role == Qt::DisplayRole)
    {
        if(index.row() >= 0 && index.row() < m_data.size() && index.column() == 0)
        {
            return  QFileInfo(m_data.at(index.row()).canonicalUrl().path()).fileName();
        }
    }
    return QVariant();
}

int QiuSiPlaylist::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.size();
}


int QiuSiPlaylist::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}

bool QiuSiPlaylist::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role);
    if(index.isValid() && value.isValid() && index.row() >= 0 &&index.row() < m_data.size() && index.column()==0){
        m_data.replace(index.row(), value.toUrl());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

QModelIndex QiuSiPlaylist::index(int row, int column, const QModelIndex &parent) const
{
//    return row >= 0 &&
//            row < m_data.size() &&
//            column == 0 &&
//            !parent.isValid()
//            ?createIndex(row, column)
//           :QModelIndex();
}

QModelIndex QiuSiPlaylist::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

bool QiuSiPlaylist::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    if(row + count <= m_data.size() && row >= 0 && count >= 0)
    {
        for(int i = 0; i<count; ++i)
        {
            m_data.removeAt(row);
        }
        return true;
    }
    return false;
}
