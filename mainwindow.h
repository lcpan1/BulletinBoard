#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QBoxLayout>
#include <QLabel>
#include "Common/customtitle.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    CustomTitle *m_pTitleBar;
    QWidget *m_pWidgetContent;
    QVBoxLayout *m_pLayoutMain;



};

#endif // MAINWINDOW_H
