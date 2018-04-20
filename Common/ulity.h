#ifndef ULITY_H
#define ULITY_H

#include <stddef.h>
#include <qwidget.h>
#include <qstring.h>
#include <QFile>
#include <string>
#include <QApplication>
#include <QDebug>

#define TREE_DIR_FILE_NAME "treedir.dat"

#define SAFE_DELETE(x) \
    if (x != NULL) { delete x; x = NULL;}

enum Button
{
    emOK = 0,
    emModify,
    emAdd,
    emSave
};
enum RadioMode
{
    emAddDevice,
    emModifyDevice,
    emAddtoClient
};

enum AddHeader
{
    emAdd_Name = 0,
    emAdd_Ip,
    emAdd_Port,
    emAdd_Type,
    emAdd_Channel_Num,
    emAdd_ConnectState,
    emAdd_StreamType,
    emAdd_UseDns,
    emAdd_Regist,
    emAdd_Count
};

enum SearchHeader
{
    emSearch_Name = 0,
    emSearch_Ip,
    emSearch_Port,
    emSearch_Mac,
    emSearch_Add, //already add in server ?
    emSearch_Type,
    emSearch_Count
};

class CAutoWaitCursor
{
public:
    CAutoWaitCursor(QWidget* widget)
    {
        m_widget = widget;
        if (m_widget != NULL)
            m_widget->setCursor(Qt::WaitCursor);
    }

    virtual ~CAutoWaitCursor()
    {
        if (m_widget != NULL)
            m_widget->setCursor(Qt::ArrowCursor);
    }

private:
    QWidget* m_widget;
};

static QString g_apppath;

inline QString getAppPath()
{
    if(g_apppath.isEmpty() || g_apppath.isNull())
    {
        g_apppath = QApplication::applicationDirPath();
    }

    return g_apppath;
}

bool isValidUseString(QString& str);

int writeQfile(QFile& file, char* buffer, int nlen);
bool copyUtf8(char* szBuf, QString& str, int nbufLen);
std::string qStringToUtf8(QString& str);
#endif // ULITY_H
