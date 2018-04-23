#include "widgetcharacterinfo.h"

WidgetCharacterInfo::WidgetCharacterInfo(QWidget *parent) : QWidget(parent)
{
    m_pLabelPictre = new QLabel(this);
    m_pLabelInfo1 = new QLabel(this);
    m_pLabelInfo2 = new QLabel(this);
    m_pLabelInfo3 = new QLabel(this);

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



void WidgetCharacterInfo::UpdateText()
{

}
