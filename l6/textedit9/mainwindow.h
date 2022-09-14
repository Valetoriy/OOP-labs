#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   private slots:
    void on_reverseL_triggered();

    void on_reverseR_triggered();

    void on_reverseAll_triggered();

    void on_swap_triggered();

    void on_concatLR_triggered();

    void on_concatRL_triggered();

   private:
    Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
