#ifndef DIALOGSETTING_H
#define DIALOGSETTING_H

#include <QWidget>
#include "Common/dialog.h"

class DialogSetting : public Dialog
{
    Q_OBJECT
public:
    explicit DialogSetting(QWidget *parent = 0,int width=1600,int height=900);

signals:

public slots:
};

#endif // DIALOGSETTING_H
