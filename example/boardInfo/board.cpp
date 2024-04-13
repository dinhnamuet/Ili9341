#include "board.h"

Board::Board(QObject *parent) :
    QObject(parent), myTimer(new QTimer()), myThread(new QThread(this)), h(0), m(0), s(0), totalMemory(0), freeMemory(0), cpuUsed(0), hr(0), min(0), sec(0)
{
    connect(myTimer, &QTimer::timeout, this, &Board::update_info);
    myTimer->start(1000);
    myTimer->moveToThread(myThread);
    myThread->start();
}
void Board::update_sys_time(int uptime) {
    int hours, minutes, seconds;
    uptime /= 4;
    hours = uptime / 3600;
    minutes = (uptime % 3600) / 60;
    seconds = uptime % 60;
    set_sysup_time(hours, minutes, seconds);
}
int Board::get_sysup_time(void)
{
    int fd;
    char *foo = NULL;
    char buffer[RD_SIZE];
    memset(buffer, 0, RD_SIZE);
    fd = open("/proc/uptime", O_RDONLY);
    if(-1 == fd)
        return -1;
    read(fd, buffer, RD_SIZE);
    close(fd);
    strtok(buffer, " ");
    foo = strtok(NULL, " ");
    return atoi(foo);
}
void Board::set_time(int hour, int min, int sec)
{
    if(h == hour && m == min && s == sec)
        return;
    h = hour;
    m = min;
    s = sec;
    emit timeChanged(h, m, s);
}

void Board::set_sysup_time(int h, int m, int s)
{
    if(hr == h && min == m && sec == s)
        return;
    hr = h;
    min = m;
    sec = s;
    emit systimeChanged(hr, min, sec);
}

void Board::update_info()
{
    struct timespec systime;
    time_t tim;
    struct tm *myTm;
    struct tm *systm;
    time(&tim);
    myTm = localtime(&tim);
    set_time(myTm->tm_hour, myTm->tm_min, myTm->tm_sec);
    update_sys_time(get_sysup_time());
    get_CPU_memory();
    name = get_CPU_Name();
    emit nameChanged(name);
    version = get_kernel_version();
    emit kversionChanged(version);
}

int Board::get_CPU_memory()
{
    int fd;
    char *foo;
    char buffer[RD_SIZE];
    memset(buffer, 0, RD_SIZE);
    fd = open("/proc/meminfo", O_RDONLY);
    if(-1 == fd)
        return -1;
    read(fd, buffer, RD_SIZE);
    close(fd);
    foo = strstr(buffer, "Memfree");
    strtok(buffer, " ");
    totalMemory = atoi(strtok(NULL, " "));
    strtok(foo, " ");
    freeMemory = atoi(strtok(NULL, " "));
    cpuUsed = (totalMemory - freeMemory)*100/(totalMemory);
    emit cpuChanged(totalMemory/1000000, freeMemory/1000000, cpuUsed);
    return 0;
}

char *Board::get_CPU_Name()
{
    int fd;
    char *result = NULL;
    char *buffer = NULL;
    buffer = (char *)malloc(RD_SIZE*sizeof(char));
    if(!buffer)
        return NULL;
    memset(buffer, 0, RD_SIZE);
    fd = open("/proc/cpuinfo", O_RDONLY);
    if(-1 == fd)
        return NULL;
    read(fd, buffer, RD_SIZE);
    close(fd);
    result = strstr(buffer, "Ras");
    free(buffer);
    return result;
}

char *Board::get_kernel_version()
{
    int fd;
    char *foo = NULL;
    char buffer[RD_SIZE];
    memset(buffer, 0, RD_SIZE);
    fd = open("/proc/version", O_RDONLY);
    if(-1 == fd)
        return NULL;
    read(fd, buffer, RD_SIZE);
    close(fd);
    foo = strstr(buffer, "version");
    if(foo)
        strtok(foo, " ");
    foo = strtok(NULL, " ");
    return foo;
}
