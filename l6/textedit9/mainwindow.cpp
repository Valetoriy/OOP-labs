#include "mainwindow.h"

#include <algorithm>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_reverseL_triggered() {
    QString str{ui->EdtLeft->text()};

    std::reverse(str.begin(), str.end());
    ui->EdtLeft->setText(str);
}

void MainWindow::on_reverseR_triggered() {
    QString str{ui->EdtRight->text()};

    std::reverse(str.begin(), str.end());
    ui->EdtRight->setText(str);
}

void MainWindow::on_reverseAll_triggered() {
    on_reverseL_triggered();
    on_reverseR_triggered();
}

void MainWindow::on_swap_triggered() {
    QString strL{ui->EdtLeft->text()};
    QString strR{ui->EdtRight->text()};

    ui->EdtLeft->setText(strR);
    ui->EdtRight->setText(strL);
}

void MainWindow::on_concatLR_triggered() {
    QString strL{ui->EdtLeft->text()};
    QString strR{ui->EdtRight->text()};

    ui->EdtLeft->setText(strL + strR);
}

void MainWindow::on_concatRL_triggered() {
    QString strL{ui->EdtLeft->text()};
    QString strR{ui->EdtRight->text()};

    ui->EdtRight->setText(strR + strL);
}
