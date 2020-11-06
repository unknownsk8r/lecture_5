#include "mydialog.h"
#include "ui_mydialog.h"


MyDialog::MyDialog(QWidget *parent): QDialog(parent)
    , ui(new Ui::MyDialog)
{
    QHBoxLayout *Hlay = new QHBoxLayout;
    setWindowTitle("Анкета");

    cBox->addItem("value1", 1);
    cBox->addItem("value2", 2);
    cBox->addItem("value3", 3);

    Hlay->addWidget(sBox);
    Hlay->addWidget(tEdit);
    Hlay->addWidget(cBox);
    Hlay->addWidget(But);

    this->setLayout(Hlay);
    ui->setupUi(this);

    QObject::connect(But, SIGNAL(clicked()), this, SLOT(Wrf()));

}

bool MyDialog::Wrf() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save"),
                                                    QString(), QT_TRANSLATE_NOOP("Config", "*.txt"));
    if (fileName.isEmpty())
    {
        return false;
    }
    
    QFile outf(fileName);
    outf.open(QFile::WriteOnly);
    QTextStream ost(&outf);
    ost << tEdit->toPlainText();
}

MyDialog::~MyDialog()
{
    delete ui;
}

