#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);

signals:

public slots:
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // DIALOG_H
