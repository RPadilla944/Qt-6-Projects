#ifndef COUNTER_H
#define COUNTER_H

#include <QThread>
#include <QDebug>
class Counter : public QThread
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent,int givenCount): QThread(parent){
        count = givenCount;
    };


signals:
    void countChanges1(int value);
    void countChanges2(int value);
    void reset1(int a);

public slots:

private:
    int count;
    int m=1;
    int i;
    void run() override {
        for (i=59 ; true; i--)
        {
            if ((i==0)&&(m==0))
            {
                countChanges1(i);
                break;
            }
            if (i == 0)
            {
                i=59;
                m=m-1;
            }
            countChanges1(i);
            countChanges2(m);
            sleep(count);
        }
        reset1(i);
        if(i== 0)
        {
            i =59;
        }
    };
};

#endif // COUNTER_H
