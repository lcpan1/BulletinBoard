#ifndef WIDGETIDENTIFY_H
#define WIDGETIDENTIFY_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QGridLayout>
#include "Widget/widgetcharacterinfo.h"

#define MAX_SHOW_NUM 25
#define MAX_ROW 5
#define MAX_COLUMN 5

class WidgetIdentify : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetIdentify(QWidget *parent = 0,int width=1600,int height=900);

signals:

public slots:
private:
    void CreatePicBox();
    void PictureMove();

private:
    WidgetCharacterInfo *m_pArrayInfo[MAX_SHOW_NUM];
    QLabel *m_pLabelType[MAX_ROW];

    QGridLayout *m_pLayoutMain;

private:
    int m_iRow;
    int m_iColumn;


};

#endif // WIDGETIDENTIFY_H
