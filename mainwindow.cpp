#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, &QSlider::valueChanged,ui->progressBar, &QProgressBar::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
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
