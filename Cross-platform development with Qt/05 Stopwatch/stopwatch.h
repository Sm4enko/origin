#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>

class TimerApp : public QWidget {
    Q_OBJECT

public:
    TimerApp(QWidget *parent = nullptr);

private slots:
    void startStopTimer();
    void updateTime();
    void lapTime();
    void clearTime();

private:
    void resetValues();
    void updateLabel();
    void updateTextBrowser();

    QTimer *timer;
    double elapsedTime;
    QList<double> laps;
    QPushButton *startStopButton;
    QPushButton *lapButton;
    QPushButton *clearButton;
    QTextBrowser *textBrowser;
    QLabel *timeLabel;
};

#endif // STOPWATCH_H
