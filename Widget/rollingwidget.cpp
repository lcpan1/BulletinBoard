#include "rollingwidget.h"
#include <QDebug>

RollingWidget::RollingWidget(QWidget *parent,int mode,int column) : QWidget(parent)
{
    this->setAutoFillBackground(true);
    QPalette pal;
    pal.setColor(QPalette::Background,QColor(0,0,0));
    this->setPalette(pal);





}

void RollingWidget::RoollingPic()
{

}
