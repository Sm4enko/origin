#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent), elapsedMilliseconds(0), running(false) {
}

void Stopwatch::start() {
    if (!running) {
        startTime = QTime::currentTime();
        running = true;
        emit update();  
    }
}

void Stopwatch::stop() {
    if (running) {
        elapsedMilliseconds += startTime.msecsTo(QTime::currentTime());
        running = false;
        disconnect(this, &Stopwatch::update, this, &Stopwatch::update);
    }
}

void Stopwatch::reset() {
    elapsedMilliseconds = 0;
    if (running) {
        startTime = QTime::currentTime();
    }
    emit update();
}

QString Stopwatch::formattedTime() const {
    int totalSeconds = elapsedMilliseconds / 1000;
    QTime time(0, totalSeconds / 60, totalSeconds % 60);
    return time.toString("hh:mm:ss");
}

int Stopwatch::elapsedTime() const {
    return elapsedMilliseconds / 1000;
}

bool Stopwatch::isRunning() const {
    return running;
}

void Stopwatch::update() {
    emit update();
}
