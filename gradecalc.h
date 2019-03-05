#ifndef GRADECALC_H
#define GRADECALC_H

#include <QMainWindow>
#include <QVector>
#include <QSpinBox>
#include <QVectorIterator>

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
    QVector<QSpinBox*> hw;
    double finalgrade;
};

#endif // GRADECALC_H
