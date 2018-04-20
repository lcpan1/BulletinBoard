#ifndef CUSTOMTITLE_H
#define CUSTOMTITLE_H

#include <QWidget>

class QLabel;
class QPushButton;
class QHBoxLayout;

class CustomTitle : public QWidget
{
    Q_OBJECT
public:
    explicit CustomTitle(QWidget *parent = 0,bool maxmin = false,int width=1600,int height = 900);
    void setTitleHight(int height);
    void setTitleName(const QString & name);


signals:
    void signalClose();
    void signalMin();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

    void resizeEvent(QResizeEvent *event);
private slots:
    void onCloseButtonclick();
    void onClickedButtonMaxmin();
    void onclickedButtonMin();

private:
    QLabel *m_pLabelTitle;
    QPushButton *m_pButtonMin;
    QPushButton *m_pButtonClose;
    QPushButton *m_pButtonMax;
    QPushButton *m_pButtonRestore;
    QHBoxLayout *m_pLayout;
private:

    bool m_bMaxmin; //是否支持最大化最小化
    bool m_bMax;
    bool m_isPressed;
    QPoint m_startMovePos;

    int m_iHeight;
};

#endif // CUSTOMTITLE_H
