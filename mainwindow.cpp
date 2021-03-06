#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDateTime>
#include <QDate>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/nimra/Cplusplus/guiApplication/welcome.png");
    ui -> label_image->setPixmap(pix);
    
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(myfunction()));
    timer -> start(1000);

    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetimetext = dateTime.toString("dd-MM-yyyy");
    ui -> label_date_time_3->setText(datetimetext);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myfunction()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss ");
    if ((time.second() % 2) ==0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui -> label_date_time_2 ->setText(time_text);
}


void MainWindow::on_pushButton_clicked()
{
   /* secondWindow secondWindow; //stack
    secondWindow.setModal(true);
    secondWindow.exec();*/
    hide();
    secondwindow = new secondWindow(this); //heap
    secondwindow -> show();
}
