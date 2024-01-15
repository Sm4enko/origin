#include <QApplication>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QDialog dialog;
    dialog.setWindowTitle("Database Connection Settings");

    QLineEdit *hostLineEdit = new QLineEdit(&dialog);
    QLineEdit *databaseLineEdit = new QLineEdit(&dialog);
    QLineEdit *loginLineEdit = new QLineEdit(&dialog);
    QLineEdit *passwordLineEdit = new QLineEdit(&dialog);
    QSpinBox *portSpinBox = new QSpinBox(&dialog);

    QLabel *hostLabel = new QLabel("Server:", &dialog);
    QLabel *databaseLabel = new QLabel("Database:", &dialog);
    QLabel *loginLabel = new QLabel("Login:", &dialog);
    QLabel *passwordLabel = new QLabel("Password:", &dialog);
    QLabel *portLabel = new QLabel("Port:", &dialog);

    portSpinBox->setRange(0, 8000);

    QPushButton *yesButton = new QPushButton("Ok", &dialog);
    QPushButton *noButton = new QPushButton("No", &dialog);

    QFormLayout *layout = new QFormLayout(&dialog);
    layout->addRow(hostLabel, hostLineEdit);
    layout->addRow(databaseLabel, databaseLineEdit);
    layout->addRow(loginLabel, loginLineEdit);
    layout->addRow(passwordLabel, passwordLineEdit);
    layout->addRow(portLabel, portSpinBox);
    layout->addRow(yesButton, noButton);

    QObject::connect(yesButton, &QPushButton::clicked, [&]() {
        qDebug() << "Server:" << hostLineEdit->text();
        qDebug() << "Database:" << databaseLineEdit->text();
        qDebug() << "Login:" << loginLineEdit->text();
        qDebug() << "Password:" << passwordLineEdit->text();
        qDebug() << "Port:" << portSpinBox->value();
        dialog.accept();
    });

    QObject::connect(noButton, &QPushButton::clicked, [&]() {
        dialog.reject();
    });

    dialog.show();

    return app.exec();
}
