#pragma once

#include "calculator.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum ActiveOperation {
    NO_OPERATION,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    POWER
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ms_clicked();

    void on_pb_mr_clicked();

    void on_pb_mc_clicked();

    void on_pb_0_clicked();

    void on_pb_1_clicked();

    void on_pb_2_clicked();

    void on_pb_3_clicked();

    void on_pb_4_clicked();

    void on_pb_5_clicked();

    void on_pb_6_clicked();

    void on_pb_7_clicked();

    void on_pb_8_clicked();

    void on_pb_9_clicked();

    void on_pb_c_clicked();

    void on_pb_double_clicked();

    void on_pb_clear_clicked();

    void on_pb_sign_clicked();

    void on_pb_division_clicked();

    void on_pb_multiplication_clicked();

    void on_subtraction_clicked();

    void on_pb_addition_clicked();

    void on_pb_equally_clicked();

    void on_pb_xy_clicked();

private:
    Ui::MainWindow* ui;
    ActiveOperation current_operation_ = NO_OPERATION;
    QString input_number_;
    Calculator calculator_;
    double active_number_ = 0;
    double memory_cell_;
    bool memory_saved_ = false;

    void SetActiveNumber();

    void SetOperation(const ActiveOperation& operation);

    QString GetOperationSymbol(const ActiveOperation& operation);
};
