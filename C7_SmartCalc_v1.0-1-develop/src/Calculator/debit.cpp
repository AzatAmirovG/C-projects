#include "debit.h"

#include "ui_debit.h"

Debit::Debit(QWidget *parent) : QWidget(parent), ui(new Ui::Debit) {
  this->setWindowTitle("Debit");
  ui->setupUi(this);
  ui->lineEdit_debit_sum->setValidator(new QDoubleValidator(0, 100, 2, this));
  ui->lineEdit_debit_percent->setValidator(
      new QDoubleValidator(0, 100, 2, this));
  ui->lineEdit_debit_term->setValidator(new QDoubleValidator(0, 100, 2, this));
  ui->lineEdit_add_sum->setValidator(new QDoubleValidator(0, 100, 2, this));
  ui->lineEdit_partial_withdraw_sum->setValidator(
      new QDoubleValidator(0, 100, 2, this));
  ui->lcdnumber_result_sum->setDigitCount(10);
  ui->lcdNumber_result_tax->setDigitCount(10);
  ui->lcdNumber_result_percent->setDigitCount(10);
  ui->comboBox_when_add->hide();
  ui->lineEdit_add_sum->hide();
  ui->comboBox_when_withdraw->hide();
  ui->lineEdit_partial_withdraw_sum->hide();
  ui->label_7->hide();
  ui->label_6->hide();
  ui->label_8->hide();
  ui->label_12->hide();
  if (ui->checkBox_addition->isChecked()) {
    ui->label_7->show();
    ui->label_6->show();
    ui->comboBox_when_add->show();
    ui->lineEdit_add_sum->show();
  }
}

Debit::~Debit() { delete ui; }
// void Debit::on_checkBox_addition_isChecked()
//{
// if (ui->checkBox_addition->isChecked()){
//     ui->label_7->show();
//     ui->label_6->show();
//     ui->comboBox_when_add->show();
//     ui->lineEdit_add_sum->show();
// }
// }
void Debit::on_pushButton_debit_calc_clicked() {
  double sum = 0;
  sum = ui->lineEdit_debit_sum->text().toDouble();
  int term = 0;
  term = ui->lineEdit_debit_term->text().toInt() * 365;
  double percent = 0;
  percent = ui->lineEdit_debit_percent->text().toDouble() / 100;
  double capitalisation = 0;
  double withdrawal_sum = 0;
  double add_sum = 0;
  int withdrawal_term = 0;
  int add_term = 0;
  int when_receive = 0;
  double resulted_sum = sum;
  double tax = 0;
  if (ui->checkBox_capitalisation->isChecked()) {
    capitalisation = 1;
  }
  if (ui->checkBox_addition->isChecked()) {
    s21_switch(ui->comboBox_when_add->currentIndex(), &add_term);
    add_sum = ui->lineEdit_add_sum->text().toDouble();
  }
  if (ui->checkBox_partial_withdrawal->isChecked()) {
    s21_switch(ui->comboBox_when_withdraw->currentIndex(), &withdrawal_term);
    withdrawal_sum = ui->lineEdit_partial_withdraw_sum->text().toDouble();
  }

  switch (ui->comboBox_when_receive->currentIndex()) {
    case 0:
      when_receive = term;
      break;
    case 1:
      when_receive = 1;
      break;
    case 2:
      when_receive = 7;
      break;
    case 3:
      when_receive = 30;
      break;
    case 4:
      when_receive = 365;
      break;
    default:
      break;
  }

  switch (ui->comboBox_tax->currentIndex()) {
    case 0:
      tax = 0.13;
      break;
    case 1:
      tax = 0.23;
      break;
    case 2:
      tax = 0;
      break;

    default:
      break;
  }
  if (when_receive != 0) {
    for (int i = 0; i <= term; i++) {
      if (i % when_receive == 0 && i > 0) {
        if (capitalisation == 1) {
          resulted_sum = resulted_sum + resulted_sum * percent;
        } else {
          resulted_sum = resulted_sum + sum * percent;
        }
      }
      if (ui->checkBox_addition->isChecked()) {
        if (i % add_term == 0 && i > 0) {
          resulted_sum += add_sum;
        }
      }
      if (ui->checkBox_partial_withdrawal->isChecked()) {
        if (i % withdrawal_term == 0 && i > 0) {
          resulted_sum -= withdrawal_sum;
        }
      }
    }
  }

  ui->lcdnumber_result_sum->display(floor(resulted_sum * 100) / 100);
  ui->lcdNumber_result_tax->display(floor(((resulted_sum - sum) * tax) * 100) /
                                    100);
  ui->lcdNumber_result_percent->display(
      floor((resulted_sum / sum * 100 - 100) * 100) / 100);
}

void Debit::s21_switch(int index, int *var) {
  switch (index) {
    case 0:
      *var = 30;
      break;
    case 1:
      *var = 60;
      break;
    case 2:
      *var = 182;
      break;
    case 3:
      *var = 365;
      break;
    default:
      break;
  }
}

void Debit::on_checkBox_addition_stateChanged(int arg1) {
  if (ui->checkBox_addition->isChecked()) {
    ui->label_7->show();
    ui->label_6->show();
    ui->comboBox_when_add->show();
    ui->lineEdit_add_sum->show();
  } else {
    ui->label_7->hide();
    ui->label_6->hide();
    ui->comboBox_when_add->hide();
    ui->lineEdit_add_sum->hide();
  }
}

void Debit::on_checkBox_partial_withdrawal_stateChanged(int arg1) {
  if (ui->checkBox_partial_withdrawal->isChecked()) {
    ui->label_8->show();
    ui->label_12->show();
    ui->comboBox_when_withdraw->show();
    ui->lineEdit_partial_withdraw_sum->show();
  } else {
    ui->label_8->hide();
    ui->label_12->hide();
    ui->comboBox_when_withdraw->hide();
    ui->lineEdit_partial_withdraw_sum->hide();
  }
}
