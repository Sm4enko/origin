#include "mainwindow.h"
#include <QVBoxLayout>
#include <QGroupBox>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QGroupBox *groupBox = new QGroupBox("Options(CHOISE)");
    QVBoxLayout *groupBoxLayout = new QVBoxLayout(groupBox);

    radioButton1 = new QRadioButton("Choise 1");
    radioButton2 = new QRadioButton("Choise2");

    groupBoxLayout->addWidget(radioButton1);
    groupBoxLayout->addWidget(radioButton2);

    groupBox->setLayout(groupBoxLayout);
    layout->addWidget(groupBox);

    comboBox = new QComboBox;
    comboBox->addItem("First");
    comboBox->addItem("Second");
    comboBox->addItem("Turbo");
    layout->addWidget(comboBox);

    toggleButton = new QPushButton("Toggle Button", this);
    toggleButton->setCheckable(true);
    connect(toggleButton, &QPushButton::clicked, this, &MainWindow::onToggleButtonClicked);
    layout->addWidget(toggleButton);

    progressBar = new QProgressBar;
    progressBar->setRange(0, 10);
    progressBar->setValue(0);
    layout->addWidget(progressBar);

    setLayout(layout);

    radioButton1->setText("Новая опция 1");
    radioButton2->setText("Новая опция 2");
}

void MainWindow::onToggleButtonClicked()
{
    int value = progressBar->value() + 1;
    if (value > progressBar->maximum())
    {
        value = 0;
    }
    progressBar->setValue(value);
}
