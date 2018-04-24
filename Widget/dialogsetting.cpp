#include "dialogsetting.h"
#include <QDebug>
#include <QTabBar>

DialogSetting::DialogSetting(QWidget *parent,LoadRes *pRes) : Dialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    this->setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background,QColor(226,226,226));
    this->setPalette(pal);


    this->setFixedSize(800,600);

    m_iCurrentIndex = 0;



    m_pTitleBar = new CustomTitle(this,false,pRes);
    m_pBottomBar = new CustomBottom(this,0,pRes);

    m_pWidgetContent = new QWidget(this);


    m_pTabWidget = new QTabWidget(this);
    m_pTabWidget->setObjectName("myTab");
    m_pTabWidget->tabBar()->setObjectName("myTabBar");


    m_pModeBulletin = new BulletinSetting(m_pTabWidget);
    m_pTabWidget->addTab(m_pModeBulletin,tr("Mode1"));

    m_pModeIdentify = new IdentifySetting(m_pTabWidget);
    m_pTabWidget->addTab(m_pModeIdentify,tr("Mode2"));




    m_pLayoutMain = new QVBoxLayout(this);
    m_pLayoutMain->addWidget(m_pTitleBar);
    m_pLayoutMain->addWidget(m_pWidgetContent);
    m_pLayoutMain->addWidget(m_pTabWidget);
    m_pLayoutMain->addWidget(m_pBottomBar);
    m_pLayoutMain->setMargin(1);
    m_pLayoutMain->setSpacing(0);

    this->setLayout(m_pLayoutMain);

    UpdateText();

    connect(m_pTitleBar,&CustomTitle::signalClose,this,&DialogSetting::reject);
    connect(m_pBottomBar,&CustomBottom::signalReject,this,&DialogSetting::reject);
    connect(m_pBottomBar,&CustomBottom::signalAccept,this,&DialogSetting::slotAccept);

}

void DialogSetting::slotAccept()
{
    qDebug()<<"accept!!";
    accept();
}

void DialogSetting::UpdateText()
{
    m_pTitleBar->setTitleName(tr("Dialog Setting"));
}
