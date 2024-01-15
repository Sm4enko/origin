#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QTextBrowser>
#include "stopwatch.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startStopButtonClicked();
    void lapButtonClicked();
    void clearButtonClicked();
    void updateTimer();

private:
    QLabel *timerLabel;
    QPushButton *startStopButton;
    QPushButton *lapButton;
    QPushButton *clearButton;
    QTextBrowser *lapsTextBrowser;
    Stopwatch *stopwatch;
    QTimer *timer;
    int lapNumber;

    void setupUi();
    void updateButtons();
};

#endif // MAINWINDOW_H
