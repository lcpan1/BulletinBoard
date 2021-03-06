#include "custombottom.h"
#include <QDialogButtonBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>


#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

CustomBottom::CustomBottom(QWidget *parent,int flag,LoadRes* pRes) : QWidget(parent)
{
    int width = pRes->m_nScreenWidth;
    int height = pRes->m_nScreenHeight;

    this->setFixedHeight(height/18);
    m_iFlag = flag;
    setAutoFillBackground(true);
    QPalette plt = palette();
    plt.setColor(QPalette::Background, QColor(205,205,205));
    setPalette(plt);
    m_pButtonBox = new QDialogButtonBox();
    m_pButtonOk = new QPushButton(this);
    m_pButtonCancel = new QPushButton(this);
    m_pButtonOk->setObjectName("ButtonOk");
    m_pButtonCancel->setObjectName("ButtonCancel");
    m_pButtonOk->setFixedSize(width/22,height/40);
    m_pButtonCancel->setFixedSize(width/22,height/40);
    m_pButtonOk->setFocusPolicy(Qt::NoFocus);
    m_pButtonCancel->setFocusPolicy(Qt::NoFocus);


//    QFont font = m_pButtonOk->font();
//    // 取得最开始的字体大小
//    int fontsize = font.pixelSize();

//    qDebug()<<"button fontsize:"<<fontsize;

//    if (fontsize == -1)//查看是否按照像素设置字体大小
//    {
//        fontsize = font.pointSize();
//        if (fontsize == -1)//查看是否按照点设置字体大小
//        {
//            qDebug()<<"button fontsize:---1"<<fontsize;
//        }
//        else
//        {
//            qDebug()<<"button fontsize:::::"<<fontsize;
//            font.setFamily("Microsoft YaHei");
//            //设置文字为粗体
//            font.setBold(false);             //封装的setWeight函数
//            //设置文字大小为50像素
//            font.setPixelSize(20*pRes->m_nDPI/96 *0.8);

//            qDebug()<<"last pix::"<<font.pixelSize();


//            m_pButtonOk->setFont(font);
//            m_pButtonCancel->setFont(font);
//        }
//    }



    m_pButtonBox->addButton(m_pButtonOk,QDialogButtonBox::AcceptRole);
    m_pButtonBox->addButton(m_pButtonCancel,QDialogButtonBox::RejectRole);
    m_pLayout = new QVBoxLayout;
    m_pLayout->addWidget(m_pButtonBox);
    setLayout(m_pLayout);
    UpdateText();

    connect(m_pButtonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(m_pButtonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void CustomBottom::UpdateText()
{
    switch (m_iFlag) {
    case emOK:
        m_pButtonOk->setText(tr("OK"));
        m_pButtonOk->setToolTip(tr("OK"));
        break;
    case emModify:
        m_pButtonOk->setText(tr("Modify"));
        m_pButtonOk->setToolTip(tr("Modify"));
        break;
    case emAdd:
        m_pButtonOk->setText(tr("Add"));
        m_pButtonOk->setToolTip(tr("Add"));
        break;
    case emSave:
        m_pButtonOk->setText(tr("Save"));
        m_pButtonOk->setToolTip(tr("Save"));
        break;
    default:
        break;
    }

    m_pButtonCancel->setText(tr("Cancel"));
    m_pButtonCancel->setToolTip(tr("Cancel"));
}

void CustomBottom::accept()
{
//    qDebug()<<"OK";
    emit signalAccept();
}

void CustomBottom::reject()
{
//    qDebug()<<"Cancel";
    emit signalReject();
}

void CustomBottom::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
        UpdateText();
    QWidget::changeEvent(event);
}
