#ifndef GRADECALC_H
#define GRADECALC_H

#include <QMainWindow>

namespace Ui {
class gradeCalc;
}

class gradeCalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit gradeCalc(QWidget *parent = nullptr);
    ~gradeCalc();

private:
    Ui::gradeCalc *ui;
};

#endif // GRADECALC_H
