#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject {
    Q_OBJECT

public:
    Stopwatch(QObject *parent = nullptr);

public slots:
    void startStop();
    void lap();
    void reset();

private slots:
    void onTimeout();

signals:
    void timeUpdated(int seconds);
    void startStopChanged(bool isRunning);
    void lapTimeUpdated(int lapNumber, int lapTime);
    void lapTimeCleared();

private:
    QTimer *timer;
    int elapsedTime;
    int lapCount;
    bool isRunning;
};

#endif // STOPWATCH_H
