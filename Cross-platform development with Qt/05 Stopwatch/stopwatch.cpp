#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent), elapsedMilliseconds(0), running(false) {
    // Initialize the timer and connect its timeout signal
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stopwatch::handleTimeout);
}

void Stopwatch::start() {
    if (!running) {
        startTime = QTime::currentTime();
        running = true;
        emit update();
        // Start the timer when the stopwatch starts
        timer->start(100);
    }
}

void Stopwatch::stop() {
    if (running) {
        elapsedMilliseconds += startTime.msecsTo(QTime::currentTime());
        running = false;
        // Stop the timer when the stopwatch stops
        timer->stop();
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

void Stopwatch::handleTimeout() {
    // Handle the timeout of the QTimer
    emit update();
}
