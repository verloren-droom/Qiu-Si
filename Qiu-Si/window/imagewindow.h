#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QShortcut>
#include <QMouseEvent>
#include <QHoverEvent>
#include <QDebug>

class ImageWindow : public QDialog
{
    Q_OBJECT
public:
    explicit ImageWindow(const QString &filePath, QWidget *parent = nullptr);
    void Init();

    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void hoverEvent(QHoverEvent *);

private:
     QLabel *lbl_main, *lbl_info;
     QPixmap pix_res;
     QPoint dPos;

signals:

};

#endif // IMAGEWINDOW_H
