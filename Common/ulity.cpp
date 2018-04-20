/////////////////////////////////////////////////
#include "ulity.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"
#include <QString>
#include <QApplication>


bool isValidUseString(QString& str)
{
    if (str.isEmpty()) return false;

    int nLen = str.length();
    if (nLen <= 0) return false;

#if 1
    for(int i = 0; i < nLen; i++)
    {
        if(str.at(i).toLatin1() == 47 || str.at(i).toLatin1() == 92 ||
           str.at(i).toLatin1() == 19 || str.at(i).toLatin1() == 16)
            return false;
    }
    return true;
#else
    if (first >= '0' && first <= '9')
        return true;
    if (first >= 'A' && first <= 'Z')
        return true;
    if (first >= 'a' && first <= 'z')
        return true;

    return false;
#endif
}

int writeQfile(QFile& file, char* buffer, int nlen)
{
    int nwritelen = 0;
    while(nwritelen < nlen)
    {
        int nRes = file.write(buffer+nwritelen, nlen-nwritelen);
        if (nRes == -1)
            return -1;
        nwritelen += nRes;
    }
    file.flush();
//    fdatasync(file.handle());
    return 0;
}

bool copyUtf8(char* szBuf, QString& str, int nbufLen)
{
    QByteArray bytetest = str.toUtf8();
    if (bytetest.isEmpty() || bytetest.isNull())
        return false;

    strncpy(szBuf, bytetest.data(), nbufLen);
    szBuf[nbufLen-1] = 0;
    return true;
}

std::string qStringToUtf8(QString& str)
{
    QByteArray bytetest = str.toUtf8();
    if (bytetest.isEmpty() || bytetest.isNull())
        return std::string("");

    return std::string(bytetest.data());
}


int g_oldfontsize = 0;
int g_nspanfontsize = 0;
int g_nnewfontsize= 0;
float g_fontscale = 0;
void jFitInitFont(int nnewsize){
    QFont font = qApp->font();
    g_oldfontsize = font.pointSize();
    if (g_oldfontsize > 10)
        g_oldfontsize = 10;
    font.setPointSize(nnewsize);
#ifdef NV_FIT_SZIE
    qApp->setFont(font);
#endif
    g_nnewfontsize = nnewsize;

    g_nspanfontsize = nnewsize- g_oldfontsize;
    g_fontscale = (float)nnewsize/(float)g_oldfontsize;
    printf("nnewsize = %d, g_oldfontsize=%d\n", nnewsize, g_oldfontsize);
}

void jFitInitX(int /*nX*/){

}

void jFitInitY(int /*nY*/){

}

#ifdef NV_FIT_SZIE

int jFitFont(int nsize){
    return g_fontscale*nsize;
}

int jFitX(int nX){
    return g_fontscale*nX;
}

int jFitY(int nY){
    return g_fontscale*nY;
}

void jfitWidget(QWidget* widget){
    QRect rcframe = widget->geometry();
    int nwidth = jFitX(rcframe.width());
    int nheight = jFitY(rcframe.height());
    int nleft = jFitX(rcframe.left());
    int ntop =jFitY(rcframe.top());
    rcframe.setLeft(nleft);
    rcframe.setTop(ntop);
    rcframe.setWidth(nwidth);
    rcframe.setHeight(nheight);
    widget->setGeometry(rcframe);
}
#endif

