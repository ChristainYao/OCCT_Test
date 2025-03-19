#include "OCCT_Test.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OCCT_Test w;
    w.show();
    return a.exec();
}
