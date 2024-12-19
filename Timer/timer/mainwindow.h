#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Counter.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void start();

    void terminate();

    void minuteScreenUpdate(int m);

    void secondScreenUpdate(int x);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int counter;
    Counter *minutes;
    Counter *seconds;
    Counter *reset;
};
#endif // MAINWINDOW_H
