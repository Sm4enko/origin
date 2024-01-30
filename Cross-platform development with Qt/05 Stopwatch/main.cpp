#include <QApplication>
#include "stopwatch.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TimerApp timerApp;
    timerApp.setWindowTitle("Таймер с кругами");
    timerApp.resize(400, 300);
    timerApp.show();

    return app.exec();
}
