#include "gradecalc.h"
#include "ui_gradecalc.h"

gradeCalc::gradeCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gradeCalc), value1(0)
{
    ui->setupUi(this);

    QObject::connect(ui->spinbox1, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->slider1, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
}

gradeCalc::~gradeCalc()
{
    delete ui;
}

void gradeCalc::updatelabel() {
    int x1 = static_cast<int>(ui->spinbox1->value());
    QString text( QString::number(x1));
    ui->label->setText(text);
}
