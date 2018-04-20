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
    explicit CustomTitle(QWidget *parent = 0,bool maxmin = false);
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
private slots:
    void onCloseButtonclick();
    void onClickedButtonMaxmin();
    void onclickedButtonMin();
private:
    QLabel *m_pLabelTitle;
    QPushButton *m_pButtonMin;
    QPushButton *m_pButtonClose;
    QPushButton *m_pButtonMaxMin;
    QHBoxLayout *m_pLayout;
private:
    QPixmap pixrestore;
    QPixmap pixmax;
    bool m_bMaxmin; //最大化还原按钮
    bool m_bMax;
    bool m_isPressed;
    QPoint m_startMovePos;
};

#endif // CUSTOMTITLE_H
