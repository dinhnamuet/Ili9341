#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <ctime>
class Clock : public QObject
{
    Q_OBJECT
public:
    ~Clock()
    {
        delete myTimer;
        delete myThread;
    }
    explicit Clock(QObject *parent = nullptr);
    void set_time(int hour, int min, int sec);
    void update_time(void);
signals:
    void timeChanged(int hour, int min, int sec);
private:
    QTimer *myTimer;
    QThread *myThread;
    int h,m,s;
};

#endif // CLOCK_H
