#include "customtitle.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>

//#ifdef Q_OS_WIN
//#pragma comment(lib, "user32.lib")
//#include <qt_windows.h>
//#endif

CustomTitle::CustomTitle(QWidget *parent,bool maxmin) : QWidget(parent)
{
    m_bMaxmin = maxmin;
    m_isPressed = false;
    m_bMax = false;

    this->setFixedHeight(32);
    m_pLabelTitle = new QLabel(this);
    m_pLabelTitle->setObjectName("CustomLableTitle");

    m_pButtonMin = new QPushButton(this);
    m_pButtonMin->setObjectName("CustomButtonMin");
    m_pButtonMin->setFixedSize(24,24);

    m_pButtonMaxMin = new QPushButton(this);
    m_pButtonMaxMin->setObjectName("CustomButtonMaxmin");
    m_pButtonMaxMin->setFixedSize(24,24);

    pixmax = QPixmap("./image/max2.png");
    pixrestore = QPixmap("./image/restore.png");
    m_pButtonMaxMin->setIcon(pixmax);

    m_pButtonClose = new QPushButton(this);
    m_pButtonClose->setObjectName("CustomButtonClose");
    m_pButtonClose->setFixedSize(24,24);

    if(!m_bMaxmin)
    {
        m_pButtonMaxMin->setVisible(false);
        m_pButtonMin->setVisible(false);
    }

    m_pLayout = new QHBoxLayout(this);
    m_pLayout->addStretch();
    m_pLayout->addWidget(m_pLabelTitle);
    m_pLayout->addStretch();
    m_pLayout->addWidget(m_pButtonMin);
    m_pLayout->addWidget(m_pButtonMaxMin);
    m_pLayout->addWidget(m_pButtonClose);

    m_pLayout->setContentsMargins(0,0,10,0);
    setLayout(m_pLayout);
    connect(m_pButtonClose,SIGNAL(clicked(bool)),this,SLOT(onCloseButtonclick()));
    connect(m_pButtonMaxMin,SIGNAL(clicked(bool)),this,SLOT(onClickedButtonMaxmin()));
    connect(m_pButtonMin,&QPushButton::clicked,this,&CustomTitle::onclickedButtonMin);
}

void CustomTitle::setTitleHight(int height)
{
    this->setFixedHeight(height);
}


void CustomTitle::setTitleName(const QString &name)
{
    m_pLabelTitle->setText(name);
    m_pLabelTitle->setToolTip(name);
}

//void CustomTitle::mousePressEvent(QMouseEvent *event)
//{
//#ifdef Q_OS_WIN
//    if (ReleaseCapture() && !(this->parentWidget()->isMaximized()))
//    {
//        QWidget *pWindow = this->window();
//        if (pWindow->isTopLevel())
//        {
//            SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
//        }
//    }
//    event->ignore();
//#else
//#endif
//}

void CustomTitle::mousePressEvent(QMouseEvent *event)
{
    if (m_bMaxmin)
    {
        // 在窗口最大化时禁止拖动窗口;
        if (!m_bMax)
        {
            m_isPressed = true;
            m_startMovePos = event->globalPos();
        }
    }
    else
    {
        m_isPressed = true;
        m_startMovePos = event->globalPos();
    }

    return QWidget::mousePressEvent(event);
}

void CustomTitle::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isPressed)
    {
        QPoint movePoint = event->globalPos() - m_startMovePos;
        QPoint widgetPos = this->parentWidget()->pos();
        m_startMovePos = event->globalPos();
        this->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
    }
    return QWidget::mouseMoveEvent(event);
}

void CustomTitle::mouseReleaseEvent(QMouseEvent *event)
{
    m_isPressed = false;
    return QWidget::mouseReleaseEvent(event);
}

void CustomTitle::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    onClickedButtonMaxmin();

}

void CustomTitle::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&painter,this);
}

void CustomTitle::onCloseButtonclick()
{
    emit signalClose();
}

void CustomTitle::onClickedButtonMaxmin()
{
    if(m_bMaxmin)
    {
        QWidget *pWindow = this->parentWidget();

        if(pWindow->isMaximized())
        {
            pWindow->showNormal();
            m_pButtonMaxMin->setIcon(pixmax);
            m_bMax = false;
        }
        else
        {
            pWindow->showMaximized();
            m_pButtonMaxMin->setIcon(pixrestore);
            m_bMax = true;
        }
    }
}

void CustomTitle::onclickedButtonMin()
{
    if(m_bMaxmin)
    {

        emit signalMin();
    }
}
