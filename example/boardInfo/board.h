#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <QTimer>
#include <QThread>
#include <ctime>
#include "time.h"
#define RD_SIZE 4096
class Board : public QObject
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = nullptr);
    ~Board()
    {
        delete myTimer;
        delete myThread;
    }
    void update_sys_time(int uptime);
    void set_time(int hour, int min, int sec);
    int get_sysup_time(void);
    void set_sysup_time(int h, int m, int s);
    void update_info(void);
    int get_CPU_memory(void);
    char *get_CPU_Name(void);
    char *get_kernel_version(void);
signals:
    void timeChanged(int hour, int min, int sec);
    void systimeChanged(int h, int m, int s);
    void cpuChanged(float total, float free, float used);
    void nameChanged(QString name);
    void kversionChanged(QString version);
private:
    float totalMemory;
    float freeMemory;
    float cpuUsed;
    QString name;
    QString version;
    QTimer *myTimer;
    QThread *myThread;
    int h, m, s;
    int hr, min, sec;
};

#endif // BOARD_H
