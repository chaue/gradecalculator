#include "gradecalc.h"
#include "ui_gradecalc.h"

gradeCalc::gradeCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gradeCalc)
{
    ui->setupUi(this);
}

gradeCalc::~gradeCalc()
{
    delete ui;
}
