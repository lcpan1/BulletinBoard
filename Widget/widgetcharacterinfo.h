#ifndef WIDGETCHARACTERINFO_H
#define WIDGETCHARACTERINFO_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>

class WidgetCharacterInfo : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetCharacterInfo(QWidget *parent = 0);

    void setCharacterPic(QString strPath);
    void setCharacterInfo(QString info1,QString info2,QString info3);



signals:


private slots:

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    void UpdateText();

    void FitPicToLabel();

    void GetPictureSize();

private:

    QLabel *m_pLabelPictre;

    QLabel *m_pLabelInfo1;
    QLabel *m_pLabelInfo2;
    QLabel *m_pLabelInfo3;

    QHBoxLayout *m_pLayoutMain;
    QVBoxLayout *m_pLayoutInfo;

};

#endif // WIDGETCHARACTERINFO_H
