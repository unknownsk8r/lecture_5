#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QSpinBox>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QDebug>

#include <QFile>
#include<QIODevice>
#include<QTextStream>
#include<QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MyDialog; }
QT_END_NAMESPACE

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    MyDialog(QWidget *parent = nullptr);

    ~MyDialog();

private:
    Ui::MyDialog *ui;
    QSpinBox *sBox = new QSpinBox;
    QTextEdit *tEdit = new QTextEdit;    
    QComboBox *cBox = new QComboBox;
    QPushButton *But = new QPushButton("Сохранить");
private slots:
    bool Wrf();
};
#endif // MYDIALOG_H
