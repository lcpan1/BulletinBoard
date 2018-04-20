#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QWidget>
#include "Common/dialog.h"

class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class CustomTitle;
class CustomBottom;


class CustomMessageBox : public Dialog
{
    Q_OBJECT
public:
    explicit CustomMessageBox(QWidget *parent = 0, QString strTitle="",
                              QString strText="",int width=1600,int height=900);

public:
    void setMessageBoxTitle(const QString &title);
    void setMessageBoxTip(const QString &tip);
    void setMessageBoxType(int type);
    void UpdateText();

signals:
    void signalDelete();
public slots:
    void onAccept();
private:
    CustomTitle *m_pCustomTitle;
    CustomBottom *m_pCustomBottom;

    QLabel *m_pLabelPic;
    QLabel *m_pLabelTip;
    QHBoxLayout *m_pLayoutInfo;

    QVBoxLayout *m_pLayout;

};

void CustomMsgBox(QString strTitle, QString strText, QWidget* parent);

#endif // MESSAGEBOX_H
