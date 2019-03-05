#include "gradecalc.h"
#include "ui_gradecalc.h"

gradeCalc::gradeCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gradeCalc)
{
    ui->setupUi(this);

    // create vector of spinboxes and connect them to updatelabel()
    QVector<QSpinBox*> hwboxes({ui->spinboxhw1, ui->spinboxhw2, ui->spinboxhw3, ui->spinboxhw4,
                             ui->spinboxhw5, ui->spinboxhw6, ui->spinboxhw7, ui->spinboxhw8});
    hw = hwboxes;
    for (int i = 0; i < 7; i++) {
        QObject::connect(boxes[i], SIGNAL(valueChanged(int)),
                                          this, SLOT(updatelabel()));
    }

    // create vector of sliders and connect them to updatelabel()
    QVector<QSlider*> sliders({ui->sliderhw1, ui->sliderhw2, ui->sliderhw3, ui->sliderhw4,
                              ui->sliderhw5, ui->sliderhw6, ui->sliderhw7, ui->sliderhw8});

    for(int i = 0; i < 7; i++) {
        QObject::connect(ui->sliderhw1, SIGNAL(valueChanged(int)),
                         this, SLOT(updatelabel()));
    }
}

gradeCalc::~gradeCalc()
{
    delete ui;
}

void gradeCalc::updatelabel() {
    double total = 0;
    for (int i = 0; i < 7; i++) {
        total = total + hw[i]->value();
    }


    QString text( QString::number(total));
    ui->label->setText(text);
}
