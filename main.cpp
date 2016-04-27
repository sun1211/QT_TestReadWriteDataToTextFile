#include "readwritetextdata.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReadWriteTextData w;
    w.show();

    return a.exec();
}
