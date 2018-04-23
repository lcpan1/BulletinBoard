#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "Common/customtitle.h"
#include "Common/dialog.h"
#include "loadres.h"

class MainWindow : public Dialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void deleteItem();
    void slotFullScreen();
    void slotSetting();

protected:
    void closeEvent(QCloseEvent *event);
    void changeEvent(QEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    void loadQSS();
    void UpdateText();

private:
    CustomTitle *m_pTitleBar;
    QWidget *m_pWidgetSetting;
    QPushButton *m_pButtonSetting;
    QPushButton *m_pButtonFullScreen;
    QHBoxLayout *m_pLayoutSetting;


    QWidget *m_pWidgetContent;
    QVBoxLayout *m_pLayoutMain;

private:
    int m_iWidth;
    int m_iHeight;
    bool m_bFull;

    LoadRes* m_pLoadRes;

};

#endif // MAINWINDOW_H
