#include "credit.h"

Credit::Credit(QWidget *parent) : QWidget(parent), ui(new Ui::Credit) {
  this->setWindowTitle("Credit");
  ui->setupUi(this);
  ui->lcdNumber_monthly_pay_2->hide();
  ui->label_7->hide();
  ui->lineEdit_sum->setValidator(new QDoubleValidator(0, 100, 2, this));
  ui->lineEdit_percent->setValidator(new QDoubleValidator(0, 100, 2, this));
  ui->lineEdit_term->setValidator(new QDoubleValidator(0, 100, 2, this));
  ui->lcdNumber_monthly_pay->setDigitCount(10);
  ui->lcdNumber_overpay->setDigitCount(10);
  ui->lcdNumber_monthly_pay_2->setDigitCount(10);
  ui->lcdNumber_totalsum->setDigitCount(10);
}

Credit::~Credit() { delete ui; }

void Credit::on_pushButton_start_credit_clicked() {
  double sum = ui->lineEdit_sum->text().toDouble();
  double percent = ui->lineEdit_percent->text().toDouble() / 12 / 100;
  double term = ui->lineEdit_term->text().toDouble() * 12;
  double monthly_pay = 0;
  ui->label_4->setText("Ежемесячный платеж");
  ui->lcdNumber_monthly_pay_2->display(0);
  ui->lcdNumber_monthly_pay_2->hide();
  ui->label_7->hide();
  if (ui->radioButton_ann->isChecked()) {
    ui->lcdNumber_monthly_pay_2->hide();
    ui->label_7->hide();
    monthly_pay = sum * (percent + percent / (pow(1 + percent, term) - 1));
    ui->lcdNumber_monthly_pay->display(monthly_pay);
    ui->lcdNumber_totalsum->display(monthly_pay * term);
    ui->lcdNumber_overpay->display(monthly_pay * term - sum);
  } else {
    ui->lcdNumber_monthly_pay_2->show();
    ui->label_7->show();
    ui->label_4->setText("Стартовый платеж");
    double monthly_pay_base = sum / term;
    double monthly_pay_start = sum / term + sum * percent;
    double remainder = sum;
    double sum_paid = 0;
    while (remainder > 0) {
      monthly_pay = monthly_pay_base + remainder * percent;
      remainder = remainder - monthly_pay;
      sum_paid += monthly_pay;
    }
    ui->lcdNumber_monthly_pay->display(floor(monthly_pay_start * 100) / 100);
    ui->lcdNumber_totalsum->display(floor(sum_paid * 100) / 100);
    ui->lcdNumber_overpay->display(floor((sum_paid - sum) * 100) / 100);
    ui->lcdNumber_monthly_pay_2->display(floor(monthly_pay * 100) / 100);
  }
}
