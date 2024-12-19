#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    COMPORT = new QSerialPort();
    COMPORT->setPortName("COM8");
    COMPORT->setBaudRate(QSerialPort::BaudRate::Baud9600);
    COMPORT->setParity(QSerialPort::Parity::NoParity);
    COMPORT->setDataBits(QSerialPort::DataBits::Data8);
    COMPORT->setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT->open(QIODevice::ReadWrite);

    if(COMPORT->isOpen())
    {
        qDebug()<<"Serial Port Connected";
        qDebug()<<COMPORT->error();
        ui->textBrowser->setText("Connected");
    }
    else
    {
        qDebug()<<"Not Connected";
        ui->textBrowser->setText("Not Connected");
        qDebug()<<COMPORT->error();
    }
    connect(COMPORT,SIGNAL(readyRead()),this,SLOT(Receive_Data()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Receive_Data()
{
    if (COMPORT->isOpen())
    {

        QByteArray data2 = COMPORT->readAll(); // Read data from the serial port
        QString receivedData2 = QString::fromLatin1(data2); // Convert the data to a QString
        ui->textBrowser_2->setText(receivedData2);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(COMPORT->isOpen())
    {
        QByteArray data= "z\r\n";
        QDataStream stream(&data, QIODevice::WriteOnly);
        COMPORT->write(data);
    }


}

