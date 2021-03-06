#ifndef DIALOGSETTING_H
#define DIALOGSETTING_H

#include <QWidget>
#include "Common/dialog.h"
#include "loadres.h"
#include "Common/customtitle.h"
#include "Common/custombottom.h"
#include <QBoxLayout>
#include <QTabWidget>
#include "Widget/bulletinsetting.h"
#include "Widget/identifysetting.h"

class DialogSetting : public Dialog
{
    Q_OBJECT
public:
    explicit DialogSetting(QWidget *parent = 0,LoadRes *pRes = 0);

signals:

private slots:
    void slotAccept();
private:
    void UpdateText();
private:
    CustomTitle *m_pTitleBar;
    CustomBottom *m_pBottomBar;
    QWidget *m_pWidgetContent;

    QTabWidget *m_pTabWidget;

    BulletinSetting *m_pModeBulletin;

    IdentifySetting *m_pModeIdentify;


    QVBoxLayout *m_pLayoutMain;
private:
    int m_iCurrentIndex;
};

#endif // DIALOGSETTING_H
