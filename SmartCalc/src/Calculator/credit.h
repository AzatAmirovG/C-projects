#ifndef CREDIT_H
#define CREDIT_H

#include <QDoubleValidator>
#include <QWidget>
#include <ostream>

#include "QtGui/qevent.h"
#include "ui_credit.h"

namespace Ui {
class Credit;
}

class Credit : public QWidget {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:
  void on_pushButton_start_credit_clicked();

 private:
  Ui::Credit *ui;
};

#endif  // CREDIT_H
