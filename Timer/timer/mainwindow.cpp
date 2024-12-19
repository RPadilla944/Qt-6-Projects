#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QCoreApplication>
#include <QLCDNumber>
#include <iostream>
#include "Counter.h"
#include "QThread"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //***********************************************************Timer********************************************
    //Counter
    seconds = new Counter(this,1);
    minutes = new Counter(this,1);
    reset = new Counter(this,1);

    ui->lcdNumber->connect(seconds,SIGNAL(countChanges1(int)), this, SLOT(secondScreenUpdate(int)));
    ui->lcdNumber_2->connect(minutes,SIGNAL(countChanges2(int)), this, SLOT(minuteScreenUpdate(int)));
    ui->pushButton->connect(reset,SIGNAL(reset1(int)), this, SLOT(secondScreenUpdate(int)));

    //Buttons
    connect(ui->Start, SIGNAL (released()), this, SLOT (start()));
    connect(ui->pushButton_8, SIGNAL (released()), this, SLOT (terminate()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::start(){
    minutes->start();
    seconds->start();
}
void MainWindow::terminate(){
    minutes->terminate();
    seconds->terminate();
}
void MainWindow::minuteScreenUpdate(int m)
{ui->lcdNumber_2->display(m);}
void MainWindow::secondScreenUpdate(int x)
{ui->lcdNumber->display(x);}


void MainWindow::on_pushButton_clicked()
{
    reset=0;

    ui->lcdNumber->display("0");
    ui->lcdNumber_2->display("0");

}

