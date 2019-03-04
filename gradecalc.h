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
    void updatelabel();

private slots:
    void changeval1(int);

private:
    Ui::gradeCalc *ui;
    int value1;
};

#endif // GRADECALC_H
