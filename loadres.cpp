#include "loadres.h"
#include <QApplication>
#include <QDesktopWidget>
#include <math.h>
#include <QDebug>
#include "Common/commdef.h"

static LoadRes* pThis = NULL;

LoadRes::LoadRes()
{
    pThis = this;
    m_nScreenWidth = qApp->desktop()->screenGeometry().width();
    m_nScreenHeight = qApp->desktop()->screenGeometry().height();

    qDebug()<<"width:"<<m_nScreenWidth<<"height:"<<m_nScreenHeight;

    int nScreenWidthmm = qApp->desktop()->widthMM();
    int nSCreenHeightmm =  qApp->desktop()->heightMM();
    qDebug()<<"Real width:"<<nScreenWidthmm<<"Real height:"<<nSCreenHeightmm;

    m_nDPI = sqrt(pow(m_nScreenWidth,2) + pow(m_nScreenHeight,2)) / sqrt(pow(nScreenWidthmm,2) + pow(nSCreenHeightmm,2)) *25.4 ;

    qDebug()<<"DPI::"<<m_nDPI;


    QFont font;
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
            font.setPixelSize(FONT_SIZE*m_nDPI/STANDARD_DPI *FONT_TIME);
            qDebug()<<"tip last pix::"<<font.pixelSize();

            qApp->setFont(font);

        }
    }



    m_nFontSize = 10;
}

LoadRes::~LoadRes()
{

}

LoadRes *LoadRes::shareObj()
{
    return pThis;
}
