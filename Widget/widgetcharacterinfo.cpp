#include "widgetcharacterinfo.h"
#include <QDebug>
#include <QStyleOption>
#include <QPainter>

WidgetCharacterInfo::WidgetCharacterInfo(QWidget *parent) : QWidget(parent)
{

    this->setObjectName("WidgetCharacterInfo");
    m_pLabelPictre = new QLabel(this);
    m_pLabelInfo1 = new QLabel(this);
    m_pLabelInfo2 = new QLabel(this);
    m_pLabelInfo3 = new QLabel(this);

    setCharacterPic("./image/character1.png");

    m_pLayoutInfo = new QVBoxLayout();
    m_pLayoutInfo->addWidget(m_pLabelInfo1);
    m_pLayoutInfo->addWidget(m_pLabelInfo2);
    m_pLayoutInfo->addWidget(m_pLabelInfo3);

    m_pLayoutMain = new QHBoxLayout(this);
    m_pLayoutMain->addWidget(m_pLabelPictre);
    m_pLayoutMain->addLayout(m_pLayoutInfo);
    this->setLayout(m_pLayoutMain);

    UpdateText();


}

void WidgetCharacterInfo::setCharacterPic(QString strPath)
{

    m_pLabelPictre->setPixmap(QPixmap(strPath));
}

void WidgetCharacterInfo::setCharacterInfo(QString info1, QString info2, QString info3)
{
    m_pLabelInfo1->setText(info1);
    m_pLabelInfo2->setText(info2);
    m_pLabelInfo3->setText(info3);
}

void WidgetCharacterInfo::resizeEvent(QResizeEvent *event)
{
//    qDebug()<<"width::"<<this->width();
//    qDebug()<<"height:"<<this->height();

//    qDebug()<<"pic "<<m_pLabelPictre->size();

    FitPicToLabel();
}

void WidgetCharacterInfo::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}



void WidgetCharacterInfo::UpdateText()
{
    m_pLabelInfo1->setText("Name:XXX");
    m_pLabelInfo2->setText("Time:2018.04.21 09:22:10");
    m_pLabelInfo2->setWordWrap(true);
    m_pLabelInfo3->setText("Info:XXX");

}

void WidgetCharacterInfo::FitPicToLabel()
{
    QPixmap pixmap("./image/character1.png");
    QPixmap pixmap1 = pixmap.scaled(m_pLabelPictre->width(), m_pLabelPictre->height());

    m_pLabelPictre->setPixmap(pixmap1);
}

void WidgetCharacterInfo::GetPictureSize()
{

}
