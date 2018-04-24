#include "dialogsetting.h"
#include <QDebug>

DialogSetting::DialogSetting(QWidget *parent,LoadRes *pRes) : Dialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    this->setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background,QColor(226,226,226));
    this->setPalette(pal);


    this->setFixedSize(800,600);



    m_pTitleBar = new CustomTitle(this,false,pRes);
    m_pBottomBar = new CustomBottom(this,0,pRes);

    m_pWidgetContent = new QWidget(this);

    m_pLayoutMain = new QVBoxLayout(this);
    m_pLayoutMain->addWidget(m_pTitleBar);
    m_pLayoutMain->addWidget(m_pWidgetContent);
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
