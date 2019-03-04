#include "gradecalc.h"
#include "ui_gradecalc.h"

gradeCalc::gradeCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gradeCalc), hw1(0), hw2(0), hw3(0), hw4(0),hw5(0), hw6(0), hw7(0), hw8(0)
{
    ui->setupUi(this);

    QObject::connect(ui->spinbox1, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->slider1, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->spinbox2, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->slider2, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->spinbox3, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->slider3, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->spinbox4, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->slider4, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->spinbox5, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->slider5, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->spinbox6, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->slider6, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->spinbox7, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->slider7, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->spinbox8, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
    QObject::connect(ui->slider8, SIGNAL(valueChanged(int)),
                     this, SLOT(updatelabel()));
}

gradeCalc::~gradeCalc()
{
    delete ui;
}

void gradeCalc::updatelabel() {
    double hw1 = static_cast<double>(ui->spinbox1->value());
    double hw2 = static_cast<double>(ui->spinbox2->value());
    double hw3 = static_cast<double>(ui->spinbox3->value());
    double hw4 = static_cast<double>(ui->spinbox4->value());
    double hw5 = static_cast<double>(ui->spinbox5->value());
    double hw6 = static_cast<double>(ui->spinbox6->value());
    double hw7 = static_cast<double>(ui->spinbox7->value());
    double hw8 = static_cast<double>(ui->spinbox8->value());
    double total = hw1 + hw2 + hw3 + hw4 + hw5 + hw6 + hw7 + hw8;

    QString text( QString::number(total));
    ui->label->setText(text);
}
