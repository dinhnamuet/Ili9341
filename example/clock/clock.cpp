#include "clock.h"

Clock::Clock(QObject *parent)
    : QObject(parent), myTimer(new QTimer()), myThread(new QThread(this)), h(0), m(0), s(0)
{
    connect(myTimer, &QTimer::timeout, this, &Clock::update_time);
    myTimer->start(1000);
    myTimer->moveToThread(myThread);
    myThread->start();
}

void Clock::set_time(int hour, int min, int sec)
{
    if(h == hour && m == min && s == sec)
        return;
    h = hour;
    m = min;
    s = sec;
    emit timeChanged(h, m, s);
}

void Clock::update_time()
{
    time_t tim;
    struct tm *myTm;
    time(&tim);
    myTm = localtime(&tim);
    set_time(myTm->tm_hour, myTm->tm_min, myTm->tm_sec);
}
