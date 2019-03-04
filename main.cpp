#include "gradecalc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gradeCalc w;
    w.show();

    return a.exec();
}
