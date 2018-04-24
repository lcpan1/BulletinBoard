#ifndef IDENTIFYSETTING_H
#define IDENTIFYSETTING_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QGridLayout>
#include <QComboBox>

class IdentifySetting : public QWidget
{
    Q_OBJECT
public:
    explicit IdentifySetting(QWidget *parent = 0);

signals:

private slots:

private:
    void UpdateText();
private:


    QWidget *m_pWidgetInfo;
    QHBoxLayout *m_pLayoutInfo;
    QLabel *m_pLabelRow;
    QLabel *m_pLabelColumn;
    QComboBox *m_pCombRow;
    QComboBox *m_pCombColumn;

    QPushButton *m_pButtonSelect;

    QVBoxLayout *m_pLayoutMain;

    QWidget *m_pWidgetContent;


};

#endif // IDENTIFYSETTING_H
