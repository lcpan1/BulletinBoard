#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QBoxLayout>
#include <QLabel>
#include "Common/customtitle.h"
#include "Common/dialog.h"

class MainWindow : public Dialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void deleteItem();
protected:
    void closeEvent(QCloseEvent *event);
    void changeEvent(QEvent *event);
private:
    void loadQSS();
    void UpdateText();

private:
    CustomTitle *m_pTitleBar;
    QWidget *m_pWidgetContent;
    QVBoxLayout *m_pLayoutMain;

private:
    int m_iWidth;
    int m_iHeight;

};

#endif // MAINWINDOW_H
