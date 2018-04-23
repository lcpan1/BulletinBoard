#ifndef WIDGETBULLETIN_H
#define WIDGETBULLETIN_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "Widget/widgetcharacterinfo.h"

class WidgetBulletin : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetBulletin(QWidget *parent = 0,int row=3,int column=4);

signals:

private slots:


private:

    QLabel *m_pLabelType1;
    QLabel *m_pLabelType2;
    QLabel *m_pLabelType3;


};

#endif // WIDGETBULLETIN_H
