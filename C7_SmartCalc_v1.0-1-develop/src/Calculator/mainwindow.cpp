#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)

{
  ui->setupUi(this);
  this->setWindowTitle("The Calculator");
  this->setWindowFlags(Qt::FramelessWindowHint);
  // this->setAttribute(Qt::WA_TranslucentBackground);   // Making the
  // background transparent main widget
  ui->function_graph->hide();
  ui->x_min->setRange(-1000000, 1000000);
  ui->x_max->setRange(-1000000, 1000000);
  ui->y_min->setRange(-1000000, 1000000);
  ui->y_max->setRange(-1000000, 1000000);
  ui->label_result->setAlignment(Qt::AlignCenter);
  int idFont =
      QFontDatabase::addApplicationFont(":/spaceagecyrillic_regular.ttf");
  QString spaceCyrillic = QFontDatabase::applicationFontFamilies(idFont).at(0);
  QFont SC(spaceCyrillic);
  SC.setPointSize(33);
  SC.setBold(1);
  this->setFont(SC);
  ui->label_5->setFont(SC);

  int idFont2 =
      QFontDatabase::addApplicationFont(":/spaceagecyrillic_regular.ttf");
  QString spaceCyrillic_orange =
      QFontDatabase::applicationFontFamilies(idFont2).at(0);
  QFont SCO(spaceCyrillic_orange);
  SCO.setPointSize(16);
  SCO.setBold(1);
  ui->pushButton_acos->setFont(SCO);
  ui->pushButton_asin->setFont(SCO);
  ui->pushButton_atan->setFont(SCO);
  ui->pushButton_cos->setFont(SCO);
  ui->pushButton_sin->setFont(SCO);
  ui->pushButton_tan->setFont(SCO);
  ui->pushButton_log->setFont(SCO);
  ui->pushButton_ln->setFont(SCO);
  ui->pushButton_open->setFont(SCO);
  ui->pushButton_var->setFont(SCO);
  ui->pushButton_close->setFont(SCO);
  ui->pushButton_mul->setFont(SCO);
  ui->pushButton_div->setFont(SCO);
  ui->pushButton_plus->setFont(SCO);
  ui->pushButton_minus->setFont(SCO);
  ui->pushButton_pow->setFont(SCO);
  ui->pushButton_mod->setFont(SCO);
  ui->pushButton_sqrt->setFont(SCO);
  ui->label->setFont(SCO);
  ui->label_2->setFont(SCO);
  ui->label_3->setFont(SCO);
  ui->label_4->setFont(SCO);

  int idFont3 =
      QFontDatabase::addApplicationFont(":/spaceagecyrillic_regular.ttf");
  QString spaceCyrillic_small =
      QFontDatabase::applicationFontFamilies(idFont3).at(0);
  QFont S(spaceCyrillic_small);
  S.setPointSize(12);
  S.setBold(1);
  ui->x_min->setFont(S);
  ui->x_max->setFont(S);
  ui->y_min->setFont(S);
  ui->y_max->setFont(S);
  ui->pushButton->setFont(S);
  ui->pushButton_10->setFont(S);

  int idFont4 =
      QFontDatabase::addApplicationFont(":/spaceagecyrillic_regular.ttf");
  QString spaceCyrillic_med =
      QFontDatabase::applicationFontFamilies(idFont4).at(0);
  QFont SA(spaceCyrillic_med);
  SA.setPointSize(19);
  SA.setBold(1);
  ui->pushButton_graph->setFont(SA);
  ui->pushButton_debit->setFont(SA);
  ui->pushButton_credit->setFont(SA);
  ui->pushButton_C->setFont(SA);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_open, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_var, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(calculate()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_point_clicked() {
  ui->label_result->setText(ui->label_result->text() + ".");
}

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString line;
  QString new_label;
  line = (ui->label_result->text() + button->text());
  new_label = line;
  ui->label_result->setText(new_label);
}

void MainWindow::on_pushButton_close_clicked() {
  if ((ui->label_result->text().contains('(')))
    ui->label_result->setText(ui->label_result->text() + ")");
}

void MainWindow::on_pushButton_sin_clicked() {
  ui->label_result->setText(ui->label_result->text() + "sin(");
}

void MainWindow::on_pushButton_ln_clicked() {
  ui->label_result->setText(ui->label_result->text() + "ln(");
}

void MainWindow::on_pushButton_log_clicked() {
  ui->label_result->setText(ui->label_result->text() + "log(");
}

void MainWindow::on_pushButton_sqrt_clicked() {
  ui->label_result->setText(ui->label_result->text() + "sqrt(");
}

void MainWindow::on_pushButton_atan_clicked() {
  ui->label_result->setText(ui->label_result->text() + "atan(");
}

void MainWindow::on_pushButton_acos_clicked() {
  ui->label_result->setText(ui->label_result->text() + "acos(");
}

void MainWindow::on_pushButton_asin_clicked() {
  ui->label_result->setText(ui->label_result->text() + "asin(");
}

void MainWindow::on_pushButton_tan_clicked() {
  ui->label_result->setText(ui->label_result->text() + "tan(");
}

void MainWindow::on_pushButton_cos_clicked() {
  ui->label_result->setText(ui->label_result->text() + "cos(");
}

void MainWindow::on_pushButton_C_clicked() {
  ui->label_result->setText("");
  ui->function_graph->hide();
}

void MainWindow::calculate() {
  ui->label_result->setText(ui->label_result->text() + "=");
  QByteArray input_line = ui->label_result->text().toLocal8Bit();
  if (input_line.length() <= 255) {
    int count = 0;
    int check = 0;
    int i = 0;
    Token_total line[255] = {};
    Token_total line2[255] = {};
    check = s21_inflix_to_struct(input_line.data(), line, &count);
    if (check == 1) {
      ui->label_result->setText("incorrect input");
    } else {
      i = s21_from_struct_to_post(line, line2, count);
      double res = s21_post_to_result(line2, i);
      QString result = QString::number(res, 'g', 15);
      ui->label_result->setText(result);
    }
  } else {
    ui->label_result->setText("expression exceeds 255 symbols");
  }
}

void MainWindow::on_pushButton_graph_clicked() {
  ui->function_graph->show();
  ui->label_result->setText(ui->label_result->text());
  QByteArray input_line = (ui->label_result->text() + "=").toLocal8Bit();
  if (input_line != "=") {
    int count = 0;
    int i = 0;
    Token_total line[255] = {};
    double x_min = (double)ui->x_min->value();
    double x_max = (double)ui->x_max->value();
    double y_min = (double)ui->y_min->value();
    double y_max = (double)ui->y_max->value();

    double h = 0.2;
    QVector<double> x, y;

    int check = s21_inflix_to_struct(input_line.data(), line, &count);
    if (check == 1) {
      ui->label_result->setText("Incorrect input");
    } else {
      for (double X = x_min; X <= x_max; X += h) {
        x.push_back(X);
        y.push_back(s21_calculation_graph(line, count, X));
      }
    }

    ui->function_graph->addGraph();

    ui->function_graph->graph(0)->setData(x, y);

    ui->function_graph->xAxis->setRange(x_min, x_max);
    ui->function_graph->yAxis->setRange(y_min, y_max);

    ui->function_graph->setInteraction(QCP::iRangeZoom, true);

    ui->function_graph->graph(0)->setPen(QColor(50, 50, 50, 255));
    QPen graphPen = ui->function_graph->graph(0)->pen();
    graphPen.setWidth(2);
    ui->function_graph->graph(0)->setPen(graphPen);

    ui->function_graph->replot();
  }
}

void MainWindow::on_pushButton_credit_clicked() { _credit.show(); }

void MainWindow::on_pushButton_debit_clicked() { _debit.show(); }

void MainWindow::on_pushButton_clicked() { QApplication::exit(); }

void MainWindow::on_pushButton_10_clicked() { showMinimized(); }
