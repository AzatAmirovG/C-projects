#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QDoubleSpinBox>
#include <QInputDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QtMath>

#include "credit.h"
#include "debit.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

#ifdef __cplusplus

extern "C" {
#endif

#include "../s21_SmartCalc.h"

#ifdef __cplusplus
}
#endif

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Credit _credit;
  Debit _debit;

 private slots:
  void digits_numbers();
  void on_pushButton_point_clicked();
  void on_pushButton_close_clicked();
  void on_pushButton_sin_clicked();
  void on_pushButton_ln_clicked();
  void on_pushButton_log_clicked();
  void on_pushButton_sqrt_clicked();
  void on_pushButton_atan_clicked();
  void on_pushButton_acos_clicked();
  void on_pushButton_asin_clicked();
  void on_pushButton_tan_clicked();
  void on_pushButton_cos_clicked();
  void on_pushButton_C_clicked();
  void calculate();
  void on_pushButton_graph_clicked();
  void on_pushButton_credit_clicked();
  void on_pushButton_debit_clicked();
  void on_pushButton_clicked();
  void on_pushButton_10_clicked();
};
#endif  // MAINWINDOW_H
