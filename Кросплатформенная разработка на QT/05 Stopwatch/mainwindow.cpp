#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi();
    stopwatch = new Stopwatch(this);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    connect(startStopButton, &QPushButton::clicked, this, &MainWindow::startStopButtonClicked);
    connect(lapButton, &QPushButton::clicked, this, &MainWindow::lapButtonClicked);
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::clearButtonClicked);
    connect(stopwatch, &Stopwatch::update, this, &MainWindow::updateTimer);

    timer->start(100);  // Update the timer label every 0.1 seconds
    lapNumber = 1;
}

MainWindow::~MainWindow() {
    // Clean up resources if needed
}

void MainWindow::startStopButtonClicked() {
    if (stopwatch->isRunning()) {
        stopwatch->stop();
    } else {
        stopwatch->start();
    }
    updateButtons();
}

void MainWindow::lapButtonClicked() {
    if (stopwatch->isRunning()) {
        QString lapInfo = QString("Круг %1, время: %2 сек")
                              .arg(lapNumber++)
                              .arg(stopwatch->elapsedTime());
        lapsTextBrowser->append(lapInfo);
    }
}

void MainWindow::clearButtonClicked() {
    stopwatch->reset();
    lapsTextBrowser->clear();
    lapNumber = 1;
    updateButtons();
}

void MainWindow::updateTimer() {
    timerLabel->setText(stopwatch->formattedTime());
}

void MainWindow::updateButtons() {
    if (stopwatch->isRunning()) {
        startStopButton->setText("Стоп");
        lapButton->setEnabled(true);
    } else {
        startStopButton->setText("Старт");
        lapButton->setEnabled(false);
    }
}

void MainWindow::setupUi() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    timerLabel = new QLabel("00:00:00", this);
    timerLabel->setAlignment(Qt::AlignCenter);

    startStopButton = new QPushButton("Старт", this);
    lapButton = new QPushButton("Круг", this);
    clearButton = new QPushButton("Очистить", this);

    lapsTextBrowser = new QTextBrowser(this);
    lapsTextBrowser->setMinimumHeight(100);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(timerLabel);
    layout->addWidget(startStopButton);
    layout->addWidget(lapButton);
    layout->addWidget(clearButton);
    layout->addWidget(lapsTextBrowser);
}
