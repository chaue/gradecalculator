#include "gradecalc.h"
#include "ui_gradecalc.h"

gradeCalc::gradeCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gradeCalc)
{
    ui->setupUi(this);
    ui->formula1->setChecked(true);


    // create vector of hw spinboxes and connect them to updatelabel()
    QVector<QSpinBox*> hwboxes({ui->spinboxhw1, ui->spinboxhw2, ui->spinboxhw3, ui->spinboxhw4,
                             ui->spinboxhw5, ui->spinboxhw6, ui->spinboxhw7, ui->spinboxhw8});
    hw = hwboxes;
    for (int i = 0; i < 7; i++) {
        QObject::connect(hw[i], SIGNAL(valueChanged(int)),
                                          this, SLOT(updatelabel()));
    }

    // create vector of hw sliders and connect them to updatelabel()
    QVector<QSlider*> hwsliders({ui->sliderhw1, ui->sliderhw2, ui->sliderhw3, ui->sliderhw4,
                              ui->sliderhw5, ui->sliderhw6, ui->sliderhw7, ui->sliderhw8});

    for(int i = 0; i < 7; i++) {
        QObject::connect(ui->sliderhw1, SIGNAL(valueChanged(int)),
                         this, SLOT(updatelabel()));
    }

    // connect midterm spinboxes
    QObject::connect(ui->testbox1, SIGNAL(valueChanged(int)),
                                      this, SLOT(updatelabel()));
    QObject::connect(ui->testbox2, SIGNAL(valueChanged(int)),
                                      this, SLOT(updatelabel()));
    // connect midterm sliders
    QObject::connect(ui->testslider1, SIGNAL(valueChanged(int)),
                                      this, SLOT(updatelabel()));
    QObject::connect(ui->testslider2, SIGNAL(valueChanged(int)),
                                      this, SLOT(updatelabel()));
    // connect final spinbox
    QObject::connect(ui->testbox3, SIGNAL(valueChanged(int)),
                                      this, SLOT(updatelabel()));
    // connect final slider
    QObject::connect(ui->testslider3, SIGNAL(valuChanged(int)),
                                      this, SLOT(updatelabel()));
    // connect radio buttons
    QObject::connect(ui->formula1, SIGNAL(clicked()),
                                      this, SLOT(changescheme()));
    QObject::connect(ui->formula2, SIGNAL(clicked()),
                                      this, SLOT(changescheme()));
}

gradeCalc::~gradeCalc()
{
    delete ui;
}

void gradeCalc::updatelabel() {
    double hwtotal = 0;
    for (int i = 0; i < 7; i++) {
        hwtotal = hwtotal + hw[i]->value();
    }


    QString text( QString::number(hwtotal));
    ui->label->setText(text);
}

void gradeCalc::changescheme() {
    scheme1 = !scheme1;
}
