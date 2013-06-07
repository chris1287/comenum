#include "dialog.h"
#include "ui_dialog.h"
#include "qextserialenumerator.h"
#include <QtCore/QList>
#include <QtCore/QDebug>
#include <QStringList>
#include <QStringListModel>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint),
    ui(new Ui::Dialog),
    m_timeout(2000)
{
    ui->setupUi(this);

    m_timer = new QTimer{this};
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update_ports()));
    m_timer->start(m_timeout);

    m_ports_model = new QStringListModel{this};
    ui->listView->setModel(m_ports_model);

    update_ports();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::update_ports()
{
    auto        ports = QextSerialEnumerator::getPorts();
    QStringList s;

    for (auto info : ports)
    {
        if (!info.portName.isEmpty())
        {
            s << info.friendName + " on " + info.portName;
        }
    }

    m_ports_model->setStringList(s);
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_drag_position = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - m_drag_position);
        event->accept();
    }
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Escape:
        case Qt::Key_Q:
            qApp->exit(0);
        break;
    }
}
