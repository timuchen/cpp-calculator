#pragma once

#include "enums.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

    void SetInputText(const std::string& text);
    void SetErrorText(const std::string& text);
    void SetFormulaText(const std::string& text);
    void SetMemText(const std::string& text);
    void SetExtraKey(const std::optional<std::string>& key);

    // колбэк-функцию нужно вызывать при нажатии кнопки с цифрами от 0 до 9;
    void SetDigitKeyCallback(std::function<void(int key)> cb);
    // колбэк-функцию нужно вызывать при нажатии кнопки операции (сложение, вычитание, умножение, деление, возведение в степень);
    void SetProcessOperationKeyCallback(std::function<void(Operation key)> cb);
    // колбэк-функцию нужно вызывать при нажатии других кнопок;
    void SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb);
    // колбэк-функцию нужно вызывать при изменении типа чисел;
    void SetControllerCallback(std::function<void(ControllerType controller)> cb);

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
    void on_tb_extra_clicked();
    void on_pb_back_space_clicked();
    void on_pb_sign_clicked();
    void on_pb_division_clicked();
    void on_pb_multiplication_clicked();
    void on_pb_subtraction_clicked();
    void on_pb_addition_clicked();
    void on_pb_equally_clicked();
    void on_pb_power_clicked();
    void on_cmb_controller_currentIndexChanged(int index);

private:
    Ui::MainWindow* ui;
    QStringList controller_params_ = {"double", "uint8_t", "int", "int64_t", "size_t", "float", "Rational"};
    std::function<void(int key)> digit_cb_;
    std::function<void(Operation key)> operation_cb_;
    std::function<void(ControlKey key)> control_cb_;
    std::function<void(ControllerType controller)> controller_cb_;
};

