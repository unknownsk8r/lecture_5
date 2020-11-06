#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_auth.h"
#include "auth.h"
#include <QTextCharFormat>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    connect(ui->action_2,SIGNAL(triggered()),this,SLOT(About_Lab1()));
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->calendarWidget->setFirstDayOfWeek(Qt::DayOfWeek(index+1));
    QTextCharFormat format;
    format.setForeground(qvariant_cast<QColor>("green"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(index+1), format);

}

void MainWindow::on_action_2_triggered()
{
    auth *dg = new auth();
    dg->show();
}
