#include "CANTestDevStudio.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CANTestDevStudio w;
    w.show();
    return a.exec();
}
