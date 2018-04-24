#include "identifysetting.h"
#include <QDebug>

IdentifySetting::IdentifySetting(QWidget *parent) : QWidget(parent)
{
    m_pLabelRow = new QLabel(this);
    m_pLabelColumn = new QLabel(this);
    m_pCombRow = new QComboBox(this);
    m_pCombColumn = new QComboBox(this);

    for(int i=0;i<6;i++)
    {
        m_pCombRow->addItem(QString("%1").arg(i+1));
        m_pCombColumn->addItem(QString("%1").arg(i+1));
    }

    m_pButtonSelect = new QPushButton(this);

    m_pWidgetInfo = new QWidget(this);
    m_pLayoutInfo = new QHBoxLayout(m_pWidgetInfo);
    m_pLayoutInfo->addWidget(m_pLabelRow);
    m_pLayoutInfo->addWidget(m_pCombRow);

    m_pLayoutInfo->addWidget(m_pLabelColumn);
    m_pLayoutInfo->addWidget(m_pCombColumn);


    m_pLayoutInfo->addWidget(m_pButtonSelect);
    m_pWidgetInfo->setLayout(m_pLayoutInfo);

    m_pWidgetContent = new QWidget(this);








    m_pLayoutMain = new QVBoxLayout(this);
    m_pLayoutMain->addWidget(m_pWidgetInfo);
    m_pLayoutMain->addWidget(m_pWidgetContent);

    this->setLayout(m_pLayoutMain);
    UpdateText();

}

void IdentifySetting::UpdateText()
{
    m_pLabelRow->setText(tr("Row:"));
    m_pLabelColumn->setText(tr("Column:"));
    m_pButtonSelect->setText(tr("Select"));
}
