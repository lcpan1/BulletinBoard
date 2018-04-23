#ifndef LOADRES_H
#define LOADRES_H

#include <QWidget>

class LoadRes
{
public:
    LoadRes();
    ~LoadRes();

    static LoadRes* shareObj();

public:
    int m_nFontSize;
    int m_nScreenWidth;
    int m_nScreenHeight;
    int m_nDPI;


};

#endif // LOADRES_H
