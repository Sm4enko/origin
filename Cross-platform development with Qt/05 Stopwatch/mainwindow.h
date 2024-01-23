#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include "stopwatch.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void updateElapsedTime(int seconds);
    void updateLapTime(int lapNumber, int lapTime);
    void clearLapTimes();
    void toggleStartStop(bool isRunning);

private:
    void setupUI();
    void setupConnections();

    QLabel *timerLabel;
    QPushButton *startStopButton;
    QPushButton *lapButton;
    QPushButton *clearButton;
    QTextBrowser *lapsBrowser;
    Stopwatch *stopwatch;
};

#endif // MAINWINDOW_H
