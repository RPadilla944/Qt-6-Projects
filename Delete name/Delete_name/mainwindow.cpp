#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
int pick;
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

void MainWindow::on_pick_clicked()
{
    pick = ui->lineEdit->text().toInt();
    if(pick==1)
    {
        QFile file1st("1st.txt");
        file1st.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file1st);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            ui->listWidget->addItem(line);
        }
    }

    else if(pick==2)
    {
        QFile file2nd("2nd.txt");
        file2nd.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in2(&file2nd);
        while(!in2.atEnd())
        {
            QString line = in2.readLine();
            ui->listWidget->addItem(line);
        }
    }
}
void MainWindow::on_deleteb_clicked()
{
    if(pick==1)
    {
        QFile file1d("1st.txt");
        file1d.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
        QTextStream in1d(&file1d);

        QString s;

        //Detele item
        foreach (QListWidgetItem *NAME, ui->listWidget->selectedItems())
        {
            delete ui->listWidget->takeItem(ui->listWidget->row(NAME));
        }

        //Read list from listWidgets
        auto numRows = ui->listWidget->count();
        for(int row = 0; row < numRows; ++row)
        {
            auto item = ui->listWidget->item(row);
            s = item->text();
            file1d.resize(0);   // Delets all data from the textfile
            in1d<<s;            //adds row to text file
            in1d<<"\n";       //adds a line break
            qDebug()<<s;
        }
        file1d.close();
    }
    if(pick==2)
    {
        QFile file2d("2nd.txt");
        file2d.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
        QTextStream in2d(&file2d);

        QString t;

        //Detele item
        foreach (QListWidgetItem *NAME, ui->listWidget->selectedItems())
        {
            delete ui->listWidget->takeItem(ui->listWidget->row(NAME));
        }

        //Read list from listWidgets
        auto numRows = ui->listWidget->count();
        for(int row = 0; row < numRows; ++row)
        {
            auto item = ui->listWidget->item(row);
            t = item->text();
            file2d.resize(0);   // Delets all data from the textfile
            in2d<<t;            //adds row to text file
            in2d<<"\n";       //adds a line break
            qDebug()<<t;
        }
        file2d.close();
    }
}

