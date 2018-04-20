#include "dialog.h"
#include <QKeyEvent>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{

}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Escape:
        break;
    default:
        QDialog::keyPressEvent(event);
    }
}
