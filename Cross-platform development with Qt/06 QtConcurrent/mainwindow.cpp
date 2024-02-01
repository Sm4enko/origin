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
        handleRaceFinish();
    });

    connect(race2, &Controller::sig_WorkFinish, [&]() {
        handleRaceFinish();
    });

    connect(concurRace1, &ExampleRace::sig_Finish, [&]() {
        handleRaceFinish();
    });

    connect(concurRace2, &ExampleRace::sig_Finish, [&]() {
        handleRaceFinish();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleRaceFinish()
{
    countFinish++;
    if (countFinish == 2) {
        ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                             QString::number(ui->sb_initNum->value() * 2));
        ui->pb_start->setEnabled(true);
    }
}

void MainWindow::StartRace(void)
{
    ui->pb_start->setEnabled(false);
    countFinish = 0;
    number = 0;

    int numIterations = ui->sb_initNum->value();

    QFutureWatcher<void> watcher;

    auto thenFunction = [=]() {
        handleRaceFinish();
    };

    QFuture<void> future1, future2;

    if (ui->rb_mutexOn->isChecked()) {
        future1 = QtConcurrent::run([=]() { concurRace1->DoWork(&number, true, numIterations); });
        future2 = future1.then([=]() { concurRace2->DoWork(&number, true, numIterations); });
    } else {
        future1 = QtConcurrent::run([=]() { concurRace1->DoWork(&number, false, numIterations); });
        future2 = future1.then([=]() { concurRace2->DoWork(&number, false, numIterations); });
    }

    watcher.setFuture(future2);

    connect(&watcher, &QFutureWatcher<void>::finished, this, thenFunction);
}

void MainWindow::on_pb_start_clicked()
{
    StartRace();
}
