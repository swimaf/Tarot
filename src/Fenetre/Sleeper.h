#ifndef SLEEPER_H
#define SLEEPER_H

#include <QVector>
#include <QPushButton>
#include <QThread>

class Sleeper : public QThread
{
public:
    Sleeper();
    void run();
    static void sleep(unsigned long secs) {
        QThread::sleep(secs);
    }
private:

};

#endif // SLEEPER_H
