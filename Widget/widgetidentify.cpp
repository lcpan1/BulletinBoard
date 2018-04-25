#include "widgetidentify.h"
#include <QDebug>

WidgetIdentify::WidgetIdentify(QWidget *parent,int width,int height) : QWidget(parent)
{
    m_pLayoutMain = new QGridLayout(this);




    m_iColumn = 5;
    m_iRow = 5;
    m_iBlackRowCount = 3;
    m_iWhiteRowCount = 1;
    m_iStrangerRowCount = 1;


    int nIndex = 0;
    for(int i=0;i<4;i++)
    {
        m_pLabelType[i] = new QLabel(this);
        m_pLabelType[i]->setText(tr("Type%1").arg(i+1));

//        m_pLabelType[i]->setFixedWidth(100);

        m_pLayoutMain->addWidget(m_pLabelType[i],i,0);


        for(int j=1;j<5;j++)
        {
            m_pArrayInfo[nIndex] = new WidgetCharacterInfo(this);
//            m_pArrayInfo[nIndex]->setVisible(false);
            m_pLayoutMain->addWidget(m_pArrayInfo[nIndex],i,j,Qt::AlignRight);

            nIndex ++;
//            qDebug()<<"index::"<<nIndex;
        }

    }

    this->setLayout(m_pLayoutMain);



}

//void WidgetIdentify::resizeEvent(QResizeEvent *event)
//{
//    Q_UNUSED(event);

//}

void WidgetIdentify::CreatePicBox()
{
//    for(int i=0;i<MAX_SHOW_NUM;i++)
//    {
//        m_pArrayInfo[i] = new WidgetCharacterInfo(this);
//    }
}

void WidgetIdentify::PictureMove()
{
    int count = 10;
    if(count >MAX_COLUMN)
    {
        //move
    }
}

void WidgetIdentify::addInfo()
{

}
