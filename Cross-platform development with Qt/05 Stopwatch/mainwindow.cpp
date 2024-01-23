#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUI();
    setupConnections();
}

void MainWindow::updateElapsedTime(int seconds) {
    timerLabel->setText(QString::number(seconds) + " сек");
}

void MainWindow::updateLapTime(int lapNumber, int lapTime) {
    QString lapText = QString("Круг %1, время: %2 сек").arg(lapNumber).arg(lapTime);
    lapsBrowser->append(lapText);
}

void MainWindow::clearLapTimes() {
    lapsBrowser->clear();
}

void MainWindow::toggleStartStop(bool isRunning) {
    if (isRunning) {
        startStopButton->setText("Стоп");
        lapButton->setEnabled(true);
    } else {
        startStopButton->setText("Старт");
        lapButton->setEnabled(false);
    }
}

void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    timerLabel = new QLabel("0 сек", this);
    layout->addWidget(timerLabel, 0, Qt::AlignCenter);

    startStopButton = new QPushButton("Старт", this);
    lapButton = new QPushButton("Круг", this);
    clearButton = new QPushButton("Очистить", this);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(startStopButton);
    buttonLayout->addWidget(lapButton);
    buttonLayout->addWidget(clearButton);

    lapsBrowser = new QTextBrowser(this);

    layout->addLayout(buttonLayout);
    layout->addWidget(lapsBrowser);

    stopwatch = new Stopwatch(this);
}

void MainWindow::setupConnections() {
    connect(stopwatch, SIGNAL(timeUpdated(int)), this, SLOT(updateElapsedTime(int)));
    connect(stopwatch, SIGNAL(startStopChanged(bool)), this, SLOT(toggleStartStop(bool)));
    connect(stopwatch, SIGNAL(lapTimeUpdated(int, int)), this, SLOT(updateLapTime(int, int)));
    connect(stopwatch, SIGNAL(lapTimeCleared()), this, SLOT(clearLapTimes()));

    connect(startStopButton, SIGNAL(clicked()), stopwatch, SLOT(startStop()));
    connect(lapButton, SIGNAL(clicked()), stopwatch, SLOT(lap()));
    connect(clearButton, SIGNAL(clicked()), stopwatch, SLOT(reset()));
}
