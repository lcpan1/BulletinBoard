#include "custommessagebox.h"
#include <QBoxLayout>
#include "Common/custombottom.h"
#include "customtitle.h"
#include <QLabel>

CustomMessageBox::CustomMessageBox(QWidget *parent, QString strTitle, QString strText,LoadRes* pRes) : Dialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    this->setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background,QColor(226,226,226));
    this->setPalette(pal);


    int width = pRes->m_nScreenWidth;
    int height = pRes->m_nScreenHeight;

    this->setFixedSize(width/5,height/5);
    m_pCustomTitle = new CustomTitle(this,false,pRes);
    m_pCustomBottom = new CustomBottom(this,0,pRes);



    m_pLabelPic = new QLabel(this);
//    m_pLabelPic->setPixmap(QPixmap("./image/question.png"));
    m_pLabelPic->setObjectName("messagePic");
    m_pLabelPic->setFixedSize(height*2/3/25,height*2/3/25);

    m_pLabelTip = new QLabel(this);
    m_pLabelTip->setWordWrap(true);


    QFont font = m_pLabelTip->font();
    // 取得最开始的字体大小
    int fontsize = font.pixelSize();

    qDebug()<<"fontsize:"<<fontsize;

    if (fontsize == -1)
    {
        fontsize = font.pointSize();
        if (fontsize == -1)
        {
            qDebug()<<"fontsize:---1"<<fontsize;
        }
        else
        {
            qDebug()<<"fontsize:::::"<<fontsize;
            font.setFamily("Microsoft YaHei");
            //设置文字为粗体
            font.setBold(false);             //封装的setWeight函数
            //设置文字大小为50像素
            font.setPixelSize(20*pRes->m_nDPI/96 - 1);
            qDebug()<<"tip last pix::"<<font.pixelSize();

            m_pLabelTip->setFont(font);
        }
    }





    m_pCustomTitle->setTitleName(strTitle);
    m_pLabelTip->setText(strText);
    m_pLabelTip->setAlignment(Qt::AlignCenter);

    m_pLayoutInfo = new QHBoxLayout();
    m_pLayoutInfo->addStretch();
    m_pLayoutInfo->addWidget(m_pLabelPic,Qt::AlignRight);
    m_pLayoutInfo->addWidget(m_pLabelTip,Qt::AlignCenter);
//    m_pLayoutInfo->addSpacing(20);

    m_pLayoutInfo->setContentsMargins(width/30,height/90,width/30,height/90);


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
    Q_UNUSED(type);
//    switch (type) {
//    case 0:
//        m_pLabelPic->setPixmap(QPixmap("./image/question.png"));
//        break;
//    case 1:
//        m_pLabelPic->setPixmap(QPixmap("./image/question.png"));
//        break;
//    case 2:
//        m_pLabelPic->setPixmap(QPixmap("./image/question.png"));
//        break;
//    default:
//        break;
//    }
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
