#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string.h"
#include "QFile"
QString name(20, ' ');
QString score(4, ' ');
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
void MainWindow::on_Savebutton_clicked()
{
    int numb = ui->lineEdit_2->text().toInt();
    if(numb==1)
    {
        QString fname1st = "1st.txt";
        QFile file1st(fname1st);

        if(file1st.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream stream(&file1st);
            name = ui->lineEdit->text();
            name.truncate(20);
            QString Final = name + ':';
            stream<<Final<<"\n";
        }
        file1st.close();
    }
    if(numb==2)
    {
        QString fname2nd = "2nd.txt";    // Second grade text file
        QFile file2nd(fname2nd);

        if(file2nd.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream stream(&file2nd);
            name = ui->lineEdit->text();
            name.truncate(20);
            QString Final = name + ':';
            stream<<Final<<"\n";
        }
        file2nd.close();
    }
}
