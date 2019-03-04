#include "gradecalc.h"
#include "ui_gradecalc.h"

gradeCalc::gradeCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gradeCalc), value1(0)
{
    ui->setupUi(this);

    QObject::connect(ui->spinbox1, SIGNAL(valueChanged(int)),
                     this, SLOT(changeval1(int)));
    QObject::connect(ui->slider1, SIGNAL(valueChanged(int)),
                     this, SLOT(changeval1(int)));

}

gradeCalc::~gradeCalc()
{
    delete ui;
}

void gradeCalc::changeval1(int val) {
    value1 = val;
    updatelabel();
    return;
}

void gradeCalc::updatelabel() {
    double x1 = static_cast<double>(value1);
    QString text( QString::number(x1));
    ui->label->setText(text);
}
