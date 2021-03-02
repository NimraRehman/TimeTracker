#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox>
#include <QIcon>

secondWindow::secondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondWindow)
{
    ui->setupUi(this);
}

secondWindow::~secondWindow()
{
    delete ui;
}

void secondWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username ->text();
    QString password = ui-> lineEdit_password ->text();

    if (username == "nimra" && password == "1234")
         QMessageBox::information (this, "Login", "Successful");
    else
        QMessageBox ::warning(this, "Login", "Failed");

}
