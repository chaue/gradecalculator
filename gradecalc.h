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

private slots:
    void updatelabel();

private:
    Ui::gradeCalc *ui;
    int hw1;
    int hw2;
    int hw3;
    int hw4;
    int hw5;
    int hw6;
    int hw7;
    int hw8;

};

#endif // GRADECALC_H
