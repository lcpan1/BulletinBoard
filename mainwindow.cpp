#include "mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QCloseEvent>
#include "Common/custommessagebox.h"


MainWindow::MainWindow(QWidget *parent)
    : Dialog(parent)
{
    //获取可用桌面大小
    QRect deskRect = QApplication::desktop()->availableGeometry();
    //获取主屏幕分辨率
    QRect screenRect = QApplication::desktop()->screenGeometry();
    //获取屏幕数量
    int nScreenCount = QApplication::desktop()->screenCount();

    qDebug()<<deskRect<<screenRect<<nScreenCount;


    this->setMinimumSize(screenRect.width()*3/4,screenRect.height()*3/4);
    this->setMaximumSize(screenRect.width(),screenRect.height());


    this->setAutoFillBackground(true);
    QPalette pal;
    pal.setColor(QPalette::Background,QColor(212,213,214));
    this->setPalette(pal);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);

    this->loadQSS();

    m_pTitleBar = new CustomTitle(this,true,screenRect.height()/25);


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

void MainWindow::deleteItem()
{
    qDebug()<<"close";

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    CustomMessageBox *m_pMessagebox = new CustomMessageBox(this);
    if(NULL == m_pMessagebox) return;

    m_pMessagebox->setMessageBoxTitle(tr("Warning"));
    m_pMessagebox->setMessageBoxTip(tr("Exit the remote client?"));

    if(m_pMessagebox->exec() == Accepted)
    {
        event->accept();
    }
    else
        event->ignore();

    delete m_pMessagebox;

}

void MainWindow::changeEvent(QEvent *event)
{

}

void MainWindow::loadQSS()
{
    qDebug()<<QApplication::applicationDirPath();

    QString m_strAppQss = ":/main.qss";
    QString m_strPath = QApplication::applicationDirPath();

    qDebug()<<"load qss"<<m_strPath + m_strAppQss;
    QString m_strQSS = "/main.qss";
    m_strPath = m_strPath + m_strQSS;
    qDebug()<<"true qss"<<m_strPath;
    //    QFile qssFile(m_strPath + m_strAppQss);

    QFile qssFile(m_strAppQss);

    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qDebug()<<"test";
        QString qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
    }
    else
    {
        qDebug()<<"Not find";
    }
}
