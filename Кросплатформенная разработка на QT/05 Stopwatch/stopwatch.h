// stopwatch.h

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTime>

class Stopwatch : public QObject {
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);

    void start();
    void stop();
    void reset();

    QString formattedTime() const;
    int elapsedTime() const;
    bool isRunning() const;

public slots:
    void update();

private:
    QTime startTime;
    int elapsedMilliseconds;
    bool running;
};

#endif 
