#include "custommessagebox.h"
#include <QBoxLayout>
#include "Common/custombottom.h"
#include "customtitle.h"
#include <QLabel>

CustomMessageBox::CustomMessageBox(QWidget *parent, QString strTitle, QString strText) : Dialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    this->setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background,QColor(226,226,226));
    this->setPalette(pal);

    this->setFixedSize(300,200);
    m_pCustomTitle = new CustomTitle(this);
    m_pCustomBottom = new CustomBottom(this,0);

    m_pLabelPic = new QLabel(this);
    m_pLabelPic->setPixmap(QPixmap("./image/question.png"));
    m_pLabelTip = new QLabel(this);
    m_pLabelTip->setWordWrap(true);

    m_pCustomTitle->setTitleName(strTitle);
    m_pLabelTip->setText(strText);
    m_pLabelTip->setAlignment(Qt::AlignCenter);

    m_pLayoutInfo = new QHBoxLayout();
    m_pLayoutInfo->addStretch();
    m_pLayoutInfo->addWidget(m_pLabelPic,Qt::AlignRight);
    m_pLayoutInfo->addWidget(m_pLabelTip,Qt::AlignCenter);
    m_pLayoutInfo->addSpacing(20);
    m_pLayoutInfo->addStretch();
    m_pLayoutInfo->setContentsMargins(50,10,50,10);
//    m_pLayoutInfo->setSpacing(20);

    m_pLayout = new QVBoxLayout(this);
    m_pLayout->addWidget(m_pCustomTitle);
    m_pLayout->addLayout(m_pLayoutInfo);
    m_pLayout->addWidget(m_pCustomBottom);
    m_pLayout->setMargin(1);
    this->setLayout(m_pLayout);

    connect(m_pCustomTitle,SIGNAL(signalClose()),this,SLOT(close()));
    connect(m_pCustomBottom,SIGNAL(signalAccept()),this,SLOT(onAccept()));
    connect(m_pCustomBottom,SIGNAL(signalReject()),this,SLOT(close()));

}

void CustomMessageBox::setMessageBoxTitle(const QString &title)
{
    m_pCustomTitle->setTitleName(title);
}

void CustomMessageBox::setMessageBoxTip(const QString &tip)
{
    m_pLabelTip->setText(tip);    
}

void CustomMessageBox::setMessageBoxType(int type)
{
    switch (type) {
    case 0:
        m_pLabelPic->setPixmap(QPixmap("./image/question.png"));
        break;
    case 1:
        m_pLabelPic->setPixmap(QPixmap("./image/question.png"));
        break;
    case 2:
        m_pLabelPic->setPixmap(QPixmap("./image/question.png"));
        break;
    default:
        break;
    }
}

void CustomMessageBox::UpdateText()
{

}

void CustomMessageBox::onAccept()
{
    emit signalDelete();
    accept();
}



void CustomMsgBox(QString strTitle, QString strText, QWidget *parent)
{
    CustomMessageBox* pMessage = new CustomMessageBox(parent,strTitle, strText);
    if (NULL == pMessage) return;
    pMessage->exec();
    delete pMessage;
}
