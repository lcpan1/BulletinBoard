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

    m_iWidth = screenRect.width();
    m_iHeight = screenRect.height();


    this->setMinimumSize(m_iWidth*3/4,m_iHeight*3/4);
    this->setMaximumSize(m_iWidth,m_iHeight);


    this->setAutoFillBackground(true);
    QPalette pal;
    pal.setColor(QPalette::Background,QColor(212,213,214));
    this->setPalette(pal);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);

    this->loadQSS();

    m_pTitleBar = new CustomTitle(this,true,screenRect.width(),screenRect.height());


    m_pWidgetContent = new QWidget(this);

    m_pLayoutMain = new QVBoxLayout(this);
    m_pLayoutMain->addWidget(m_pTitleBar);
    m_pLayoutMain->addWidget(m_pWidgetContent);
    m_pLayoutMain->setMargin(1);

    this->setLayout(m_pLayoutMain);

    UpdateText();

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
    CustomMessageBox *m_pMessagebox = new CustomMessageBox(this,"","",m_iWidth,m_iHeight);
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

void MainWindow::UpdateText()
{
    m_pTitleBar->setTitleName(tr("Board"));
}
