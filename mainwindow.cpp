#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pinInput_clicked()
{
    QString account = ui->lineEdit->text();
    QString pin = ui->lineEdit_3->text();

    if (account == "1001" && pin == "1234") {
        ui->statusLabel->setText("Login successful!");
    } else {
        ui->statusLabel->setText("Invalid account number or PIN!");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    int amount = ui->lineEdit_2->text().toInt();
    balance += amount;
    ui->statusLabel->setText("Deposited ₹" + QString::number(amount) + ". Balance: ₹" + QString::number(balance));

}


void MainWindow::on_pushButton_3_clicked()
{
    int amount = ui->lineEdit_2->text().toInt();
    if (amount <= balance) {
        balance -= amount;
        ui->statusLabel->setText("Withdrew ₹" + QString::number(amount) + ". Balance: ₹" + QString::number(balance));
    } else {
        ui->statusLabel->setText("Insufficient balance!");
    }

}


void MainWindow::on_pushButton_4_clicked()
{
    ui->statusLabel->setText("Current balance: ₹" + QString::number(balance));

}


void MainWindow::on_pushButton_5_clicked()
{
        QApplication::quit();
}

