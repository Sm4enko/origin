#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QRadioButton>
#include <QComboBox>
#include <QPushButton>
#include <QProgressBar>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onToggleButtonClicked();

private:
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QComboBox *comboBox;
    QPushButton *toggleButton;
    QProgressBar *progressBar;
};

#endif // MAINWINDOW_H
