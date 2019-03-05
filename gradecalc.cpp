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
    for (int i = 0; i < 8; i++) {
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
                                      this, SLOT(updatelabel()));
    QObject::connect(ui->formula2, SIGNAL(clicked()),
                                      this, SLOT(updatelabel()));
}

gradeCalc::~gradeCalc()
{
    delete ui;
}

void gradeCalc::updatelabel() {
    // calculate the average homework score
    double hwtotal = 0;
    for (int i = 0; i < 8; i++) {
        hwtotal = hwtotal + hw[i]->value();
    }
    double avghw = hwtotal / 8;

    // find the higher midterm score
    double highmid = 0;
    double lowmid = 0;
    if (ui->testbox1->value() > ui->testbox2->value()) {
        highmid = static_cast<double>(ui->testbox1->value());
        lowmid = static_cast<double>(ui->testbox2->value());
    }
    else {
        highmid = static_cast<double>(ui->testbox2->value());
        lowmid = static_cast<double>(ui->testbox1->value());
    }

    double final = static_cast<double>(ui->testbox3->value());

    // scheme 1
    if (ui->formula1->isChecked()) {
        finalgrade = 0.25 * avghw + 0.2 * (highmid + lowmid) +
                0.35 * final;
    }
    else {
        finalgrade = 0.25 * avghw + 0.3 * highmid +
                0.44 * final;
    }

    QString text( QString::number(finalgrade));
    ui->label->setText(text);
}

