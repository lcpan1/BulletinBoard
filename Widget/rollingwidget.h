#ifndef ROLLINGWIDGET_H
#define ROLLINGWIDGET_H

#include <QWidget>

#define MODE_VERTICAL   1
#define MODE_HORIZONTAL 0

class RollingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RollingWidget(QWidget *parent = 0,int mode = MODE_HORIZONTAL,int column = 0);

signals:

public slots:

private:
    void RoollingPic();


};

#endif // ROLLINGWIDGET_H
