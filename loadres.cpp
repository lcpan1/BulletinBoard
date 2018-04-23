#include "loadres.h"
#include <QApplication>
#include <QDesktopWidget>
#include <math.h>
#include <QDebug>

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

    m_nFontSize = 10;
}

LoadRes::~LoadRes()
{

}

LoadRes *LoadRes::shareObj()
{
    return pThis;
}
