#include "customtitle.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>

CustomTitle::CustomTitle(QWidget *parent,bool maxmin,int height) : QWidget(parent)
{
    this->setAutoFillBackground(true);
    QPalette pal;
    pal.setColor(QPalette::Background,QColor(0,0,0));
    this->setPalette(pal);


    m_bMaxmin = maxmin;
    m_isPressed = false;
    m_bMax = false;

    this->setFixedHeight(height);
    m_pLabelTitle = new QLabel(this);
    m_pLabelTitle->setObjectName("CustomLableTitle");

    m_pButtonMin = new QPushButton(this);
    m_pButtonMin->setObjectName("CustomButtonMin");
    m_pButtonMin->setFixedSize(height*2/3,height*2/3);

    m_pButtonMax = new QPushButton(this);
    m_pButtonMax->setObjectName("CustomButtonMax");
    m_pButtonMax->setFixedSize(height*2/3,height*2/3);

    m_pButtonRestore = new QPushButton(this);
    m_pButtonRestore->setObjectName("CustomButtonRestore");
    m_pButtonRestore->setFixedSize(height*2/3,height*2/3);

    m_pButtonClose = new QPushButton(this);
    m_pButtonClose->setObjectName("CustomButtonClose");
    m_pButtonClose->setFixedSize(height*2/3,height*2/3);

    if(!m_bMaxmin)
    {
        m_pButtonMax->setVisible(false);
        m_pButtonMin->setVisible(false);
        m_pButtonRestore->setVisible(false);
    }
    else
    {
        m_pButtonRestore->setVisible(m_bMax);
        m_pButtonMax->setVisible(!m_bMax);
    }





    m_pLayout = new QHBoxLayout(this);
    m_pLayout->addStretch();
    m_pLayout->addWidget(m_pLabelTitle);
    m_pLayout->addStretch();
    m_pLayout->addWidget(m_pButtonMin);
    m_pLayout->addWidget(m_pButtonMax);
    m_pLayout->addWidget(m_pButtonRestore);
    m_pLayout->addWidget(m_pButtonClose);

    m_pLayout->setContentsMargins(0,0,10,0);
    setLayout(m_pLayout);
    connect(m_pButtonClose,SIGNAL(clicked(bool)),this,SLOT(onCloseButtonclick()));
    connect(m_pButtonMax,SIGNAL(clicked(bool)),this,SLOT(onClickedButtonMaxmin()));
    connect(m_pButtonRestore,&QPushButton::clicked,this,&CustomTitle::onClickedButtonMaxmin);
    connect(m_pButtonMin,&QPushButton::clicked,this,&CustomTitle::onclickedButtonMin);
}

void CustomTitle::setTitleHight(int height)
{
    m_iHeight = height;
    this->setFixedHeight(height);
}


void CustomTitle::setTitleName(const QString &name)
{
    m_pLabelTitle->setText(name);
    m_pLabelTitle->setToolTip(name);
}

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
            m_bMax = false;
            m_pButtonRestore->setVisible(m_bMax);
            m_pButtonMax->setVisible(!m_bMax);
        }
        else
        {
            pWindow->showMaximized();

            m_bMax = true;
            m_pButtonRestore->setVisible(m_bMax);
            m_pButtonMax->setVisible(!m_bMax);
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

