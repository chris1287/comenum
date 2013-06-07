#ifndef DIALOG_H
#define DIALOG_H

#include "qextserialenumerator.h"
#include <QStringListModel>
#include <QDialog>
#include <QTimer>
#include <QPoint>
#include <QMouseEvent>
#include <QKeyEvent>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private:
    Ui::Dialog       *ui;
    QStringListModel *m_ports_model;
    QTimer           *m_timer;
    const int         m_timeout;
    QPoint            m_drag_position;

private slots:
    void update_ports();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // DIALOG_H
