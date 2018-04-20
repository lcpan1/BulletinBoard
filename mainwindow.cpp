#include "mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    //获取可用桌面大小
    QRect deskRect = QApplication::desktop()->availableGeometry();
    //获取主屏幕分辨率
    QRect screenRect = QApplication::desktop()->screenGeometry();
    //获取屏幕数量
    int nScreenCount = QApplication::desktop()->screenCount();

    qDebug()<<deskRect<<screenRect<<nScreenCount;


    this->setMinimumSize(screenRect.width()/2,screenRect.height()/2);
    this->setMaximumSize(screenRect.width(),screenRect.height());


    this->setAutoFillBackground(true);
    QPalette pal;
    pal.setColor(QPalette::Background,QColor(212,213,214));
    this->setPalette(pal);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);


    m_pTitleBar = new CustomTitle(this,true);
    m_pTitleBar->setTitleHight(screenRect.height()/20);

    m_pWidgetContent = new QWidget(this);

    m_pLayoutMain = new QVBoxLayout(this);
    m_pLayoutMain->addWidget(m_pTitleBar);
    m_pLayoutMain->addWidget(m_pWidgetContent);
    m_pLayoutMain->setMargin(1);

    this->setLayout(m_pLayoutMain);

    connect(m_pTitleBar,&CustomTitle::signalClose,this,&MainWindow::close);

    connect(m_pTitleBar,&CustomTitle::signalMin,this,&MainWindow::showMinimized);

}

MainWindow::~MainWindow()
{

}
