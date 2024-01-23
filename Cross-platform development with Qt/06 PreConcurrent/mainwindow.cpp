#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sb_initNum->setValue(200000);
    ui->rb_synchOff->setChecked(true);

    race1 = new Controller(&m);
    race2 = new Controller(&m);

    concurRace1 = new ExampleRace(&m);
    concurRace2 = new ExampleRace(&m);

    connect(race1, &Controller::sig_WorkFinish, [&]() {
        if (countFinish == 0) {
            countFinish++;
        } else {
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                 QString::number(ui->sb_initNum->value() * 2));
            ui->pb_start->setEnabled(true);
        }
    });

    connect(race2, &Controller::sig_WorkFinish, [&]() {
        if (countFinish == 0) {
            countFinish++;
        } else {
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                 QString::number(ui->sb_initNum->value() * 2));
            ui->pb_start->setEnabled(true);
        }
    });

    connect(concurRace1, &ExampleRace::sig_Finish, [&]() {
        if (countFinish == 0) {
            countFinish++;
        } else {
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                 QString::number(ui->sb_initNum->value() * 2));
            ui->pb_start->setEnabled(true);
        }
    });

    connect(concurRace2, &ExampleRace::sig_Finish, [&]() {
        if (countFinish == 0) {
            countFinish++;
        } else {
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                 QString::number(ui->sb_initNum->value() * 2));
            ui->pb_start->setEnabled(true);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartRace(void)
{
    ui->pb_start->setEnabled(false);
    countFinish = 0;
    number = 0;

    // Create a QFutureWatcher to monitor the completion of the Qt Concurrent tasks
    QFutureWatcher<void> watcher;

    // Connect the finished signal to a lambda function
    connect(&watcher, &QFutureWatcher<void>::finished, this, [&]() {
        countFinish++;
        if (countFinish == 2) {
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                 QString::number(ui->sb_initNum->value() * 2));
            ui->pb_start->setEnabled(true);
        }
    });

    // Use Qt Concurrent to run the tasks in parallel
    int numIterations = ui->sb_initNum->value();
    if (ui->rb_mutexOn->isChecked()) {
        // With mutex
        auto function1 = std::bind(&ExampleRace::DoWork, concurRace1, &number, true, numIterations);
        auto function2 = std::bind(&ExampleRace::DoWork, concurRace2, &number, true, numIterations);
        QFuture<void> future1 = QtConcurrent::run(std::move(function1));
        QFuture<void> future2 = QtConcurrent::run(std::move(function2));
        watcher.setFuture(future1);
        watcher.setFuture(future2);
    } else {
        // Without mutex
        auto function1 = std::bind(&ExampleRace::DoWork, concurRace1, &number, false, numIterations);
        auto function2 = std::bind(&ExampleRace::DoWork, concurRace2, &number, false, numIterations);
        QFuture<void> future1 = QtConcurrent::run(std::move(function1));
        QFuture<void> future2 = QtConcurrent::run(std::move(function2));
        watcher.setFuture(future1);
        watcher.setFuture(future2);
    }
}

void MainWindow::on_pb_start_clicked()
{
    StartRace();
}
