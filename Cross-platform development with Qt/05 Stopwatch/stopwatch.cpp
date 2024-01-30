#include "stopwatch.h"

TimerApp::TimerApp(QWidget *parent) : QWidget(parent) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TimerApp::updateTime);

    QLabel *timeTextLabel = new QLabel("Время:", this);
    timeTextLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLabel *timerLabel = new QLabel("0.0", this);
    timerLabel->setAlignment(Qt::AlignCenter);
    timeLabel = timerLabel;

    QHBoxLayout *timeLayout = new QHBoxLayout;
    timeLayout->addWidget(timeTextLabel);
    timeLayout->addWidget(timerLabel);

    startStopButton = new QPushButton("Старт", this);
    connect(startStopButton, &QPushButton::clicked, this, &TimerApp::startStopTimer);

    lapButton = new QPushButton("Круг", this);
    lapButton->setEnabled(false);
    connect(lapButton, &QPushButton::clicked, this, &TimerApp::lapTime);

    clearButton = new QPushButton("Очистить", this);
    connect(clearButton, &QPushButton::clicked, this, &TimerApp::clearTime);

    textBrowser = new QTextBrowser(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(timeLayout);
    layout->addWidget(startStopButton);
    layout->addWidget(lapButton);
    layout->addWidget(clearButton);
    layout->addWidget(textBrowser);

    setLayout(layout);

    resetValues();
}

void TimerApp::startStopTimer() {
    if (!timer->isActive()) {
        startStopButton->setText("Стоп");
        lapButton->setEnabled(true);
        timer->start(100);
    } else {
        startStopButton->setText("Старт");
        lapButton->setEnabled(false);
        timer->stop();
    }
}

void TimerApp::updateTime() {
    elapsedTime += 0.1;
    updateLabel();
}

void TimerApp::lapTime() {
    double lap = (laps.isEmpty() ? elapsedTime : elapsedTime - laps.last());
    laps.append(elapsedTime);
    updateTextBrowser();
}

void TimerApp::clearTime() {
    resetValues();
    updateLabel();
    updateTextBrowser();
}

void TimerApp::resetValues() {
    elapsedTime = 0.0;
    laps.clear();
}

void TimerApp::updateLabel() {
    QString timeText = QString::number(elapsedTime, 'f', 1);
    timeLabel->setText(timeText);
}

void TimerApp::updateTextBrowser() {
    textBrowser->clear();
    for (int i = 0; i < laps.size(); ++i) {
        double lapDifference = (i > 0) ? (laps.at(i) - laps.at(i - 1)) : laps.at(i);
        QString lapDifferenceText = QString("Круг %1, время: %2 сек").arg(i + 1).arg(lapDifference, 0, 'f', 1);
        textBrowser->append(lapDifferenceText);
    }
}
