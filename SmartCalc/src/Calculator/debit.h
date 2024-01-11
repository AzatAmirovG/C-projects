#ifndef DEBIT_H
#define DEBIT_H

#include <QWidget>

namespace Ui {
class Debit;
}

class Debit : public QWidget {
  Q_OBJECT

 public:
  explicit Debit(QWidget *parent = nullptr);
  ~Debit();

 private slots:
  void on_pushButton_debit_calc_clicked();
  void s21_switch(int index, int *var);
  // void on_checkBox_addition_clicked();

  void on_checkBox_addition_stateChanged(int arg1);

  void on_checkBox_partial_withdrawal_stateChanged(int arg1);

 private:
  Ui::Debit *ui;
};

#endif  // DEBIT_H
