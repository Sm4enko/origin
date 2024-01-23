#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent), elapsedTime(0), lapCount(0), isRunning(false) {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

void Stopwatch::startStop() {
    if (isRunning) {
        timer->stop();
        isRunning = false;
        emit timeUpdated(elapsedTime);
    } else {
        timer->start(1000);
        isRunning = true;
    }
    emit startStopChanged(isRunning);
}

void Stopwatch::lap() {
    if (isRunning) {
        lapCount++;
        emit lapTimeUpdated(lapCount, elapsedTime);
    }
}

void Stopwatch::reset() {
    timer->stop();
    elapsedTime = 0;
    lapCount = 0;
    isRunning = false;
    emit timeUpdated(elapsedTime);
    emit startStopChanged(isRunning);
    emit lapTimeCleared();
}

void Stopwatch::onTimeout() {
    elapsedTime++;
    emit timeUpdated(elapsedTime);
}
