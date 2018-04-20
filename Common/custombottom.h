#ifndef CUSTOMBOTTOM_H
#define CUSTOMBOTTOM_H

#include <QWidget>
#include "Common/ulity.h"

class QPushButton;
class QDialogButtonBox;
class QVBoxLayout;

class CustomBottom : public QWidget
{
    Q_OBJECT
public:
    explicit CustomBottom(QWidget *parent = 0,int flag = 0);
    void UpdateText();
signals:
    void signalAccept();
    void signalReject();
private slots:
    void accept();
    void reject();
protected:
    void changeEvent(QEvent *event);
private:
    QDialogButtonBox *m_pButtonBox;
    QPushButton *m_pButtonOk;
    QPushButton *m_pButtonCancel;
    QVBoxLayout *m_pLayout;
    int m_iFlag;
};

#endif // CUSTOMBOTTON_H
