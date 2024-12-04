#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"

#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SetActiveNumber()
{
    active_number_ = input_number_.toDouble();

    if (active_number_ == 0) {
        input_number_ = 0;
    }

    ui->l_result->setText(QString::number(active_number_));
}

void MainWindow::SetOperation(const ActiveOperation& operation)
{
    if (current_operation_ == NO_OPERATION) {
        calculator_.Set(active_number_);
    }

    current_operation_ = operation;

    QString formated = "%1 %2";
    ui->l_formula->setText(formated
                               .arg(QString::number(calculator_.GetNumber()))
                               .arg(GetOperationSymbol(operation)));

    input_number_ = 0;
}

QString MainWindow::GetOperationSymbol(const ActiveOperation& operation)
{
    QString symbol;
    switch (operation) {
        case DIVISION:
            symbol = "÷";
            break;
        case MULTIPLICATION:
            symbol = "×";
            break;
        case SUBTRACTION:
            symbol = "−";
            break;
        case ADDITION:
            symbol = "+";
            break;
        case POWER:
            symbol = "^";
            break;
        default:
            break;
    }
    return symbol;
}

void MainWindow::on_pb_ms_clicked()
{
    memory_cell_ = active_number_;
    memory_saved_ = true;
    ui->l_memory->setText("M");
}

void MainWindow::on_pb_mr_clicked()
{
    if (memory_saved_) {
        active_number_ = memory_cell_;
        ui->l_result->setText(QString::number(memory_cell_));
    }
}

void MainWindow::on_pb_mc_clicked()
{
    memory_cell_ = 0;
    memory_saved_ = false;
    ui->l_memory->setText("");
}

void MainWindow::on_pb_0_clicked()
{
    input_number_ += QString("0");
    SetActiveNumber();
}

void MainWindow::on_pb_1_clicked()
{
    input_number_ += QString("1");
    SetActiveNumber();
}

void MainWindow::on_pb_2_clicked()
{
    input_number_ += QString("2");
    SetActiveNumber();
}

void MainWindow::on_pb_3_clicked()
{
    input_number_ += QString("3");
    SetActiveNumber();
}

void MainWindow::on_pb_4_clicked()
{
    input_number_ += QString("4");
    SetActiveNumber();
}

void MainWindow::on_pb_5_clicked()
{
    input_number_ += QString("5");
    SetActiveNumber();
}

void MainWindow::on_pb_6_clicked()
{
    input_number_ += QString("6");
    SetActiveNumber();
}

void MainWindow::on_pb_7_clicked()
{
    input_number_ += QString("7");
    SetActiveNumber();
}

void MainWindow::on_pb_8_clicked()
{
    input_number_ += QString("8");
    SetActiveNumber();
}

void MainWindow::on_pb_9_clicked()
{
    input_number_ += QString("9");
    SetActiveNumber();
}

void MainWindow::on_pb_c_clicked()
{
    input_number_ = 0;
    SetActiveNumber();
    ui->l_formula->clear();
    calculator_.Set(0);
    current_operation_ = NO_OPERATION;
}

void MainWindow::on_pb_double_clicked()
{
    input_number_ += QString(".");
    SetActiveNumber();
}

void MainWindow::on_pb_clear_clicked()
{
    input_number_.chop(1);
    SetActiveNumber();
}

void MainWindow::on_pb_sign_clicked()
{
    if (input_number_.startsWith('-')) {
        input_number_ = input_number_.mid(1);
    } else {
        input_number_ = "-" + input_number_;
    }

    SetActiveNumber();
}

void MainWindow::on_pb_division_clicked()
{
    SetOperation(DIVISION);
}


void MainWindow::on_pb_multiplication_clicked()
{
    SetOperation(MULTIPLICATION);
}


void MainWindow::on_subtraction_clicked()
{
    SetOperation(SUBTRACTION);
}


void MainWindow::on_pb_addition_clicked()
{
    SetOperation(ADDITION);
}

void MainWindow::on_pb_xy_clicked()
{
    SetOperation(POWER);
}

void MainWindow::on_pb_equally_clicked()
{
    if (current_operation_ == NO_OPERATION) {
        return;
    }

    QString formated = "%1 %2 %3 =";
    ui->l_formula->setText(formated
                               .arg(QString::number(calculator_.GetNumber()))
                               .arg(GetOperationSymbol(current_operation_))
                               .arg(active_number_));

    if(current_operation_ == DIVISION) {
        calculator_.Div(active_number_);
    } else if (current_operation_ == MULTIPLICATION) {
        calculator_.Mul(active_number_);
    } else if (current_operation_ == SUBTRACTION) {
        calculator_.Sub(active_number_);
    } else if (current_operation_ == ADDITION) {
        calculator_.Add(active_number_);
    } else if (current_operation_ == POWER) {
        calculator_.Pow(active_number_);
    } else {
        assert("Error: Operator not found!");
    }

    active_number_ = calculator_.GetNumber();
    ui->l_result->setText(QString::number(active_number_));

    current_operation_ = NO_OPERATION;
    input_number_ = "";
}
