#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow()
    : ui(new Ui::MainWindow) {
    ui->setupUi(this);

    for (auto param : controller_params_) {
        ui->cmb_controller->addItem(param);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SetInputText(const std::string& text) {
    ui->l_result->setStyleSheet("");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetErrorText(const std::string& text) {
    ui->l_result->setStyleSheet("color: red;");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetFormulaText(const std::string& text) {
    ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetMemText(const std::string& text) {
    ui->l_memory->setText(QString::fromStdString(text));
}

void MainWindow::SetExtraKey(const std::optional<std::string>& key) {
    if (key.has_value()) {
        ui->tb_extra->setVisible(true);
        ui->tb_extra->setText(QString::fromStdString(key.value()));
    }
    else {
        ui->tb_extra->setVisible(false);
    }
}

// колбэк-функцию нужно вызывать при нажатии кнопки с цифрами от 0 до 9;
void MainWindow::SetDigitKeyCallback(std::function<void(int key)> cb) {
    digit_cb_ = cb;
}

// колбэк-функцию нужно вызывать при нажатии кнопки операции (сложение, вычитание, умножение, деление, возведение в степень);
void MainWindow::SetProcessOperationKeyCallback(std::function<void(Operation key)> cb) {
    operation_cb_ = cb;
}

// колбэк-функцию нужно вызывать при нажатии других кнопок;
void MainWindow::SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb) {
    control_cb_ = cb;
}

// колбэк-функцию нужно вызывать при изменении типа чисел;
void MainWindow::SetControllerCallback(std::function<void(ControllerType controller)> cb) {
    controller_cb_ = cb;
}

void MainWindow::on_pb_ms_clicked()
{
    if (control_cb_)
    control_cb_(ControlKey::MEM_SAVE);
}

void MainWindow::on_pb_mr_clicked()
{
    if (control_cb_)
    control_cb_(ControlKey::MEM_LOAD);
}

void MainWindow::on_pb_mc_clicked()
{
    if (control_cb_)
    control_cb_(ControlKey::MEM_CLEAR);
}

void MainWindow::on_pb_0_clicked()
{
    if (digit_cb_)
    digit_cb_(0);
}

void MainWindow::on_pb_1_clicked()
{
    if (digit_cb_)
    digit_cb_(1);
}

void MainWindow::on_pb_2_clicked()
{
    if (digit_cb_)
    digit_cb_(2);
}

void MainWindow::on_pb_3_clicked()
{
    if (digit_cb_)
    digit_cb_(3);
}

void MainWindow::on_pb_4_clicked()
{
    if (digit_cb_)
    digit_cb_(4);
}

void MainWindow::on_pb_5_clicked()
{
    if (digit_cb_)
    digit_cb_(5);
}

void MainWindow::on_pb_6_clicked()
{
    if (digit_cb_)
    digit_cb_(6);
}

void MainWindow::on_pb_7_clicked()
{
    if (digit_cb_)
    digit_cb_(7);
}

void MainWindow::on_pb_8_clicked()
{
    if (digit_cb_)
    digit_cb_(8);
}

void MainWindow::on_pb_9_clicked()
{
    if (digit_cb_)
    digit_cb_(9);
}

void MainWindow::on_pb_c_clicked()
{
    if (control_cb_)
    control_cb_(ControlKey::CLEAR);
}

void MainWindow::on_tb_extra_clicked()
{
    if (control_cb_)
    control_cb_(ControlKey::EXTRA_KEY);
}

void MainWindow::on_pb_back_space_clicked()
{
    if (control_cb_)
    control_cb_(ControlKey::BACKSPACE);
}

void MainWindow::on_pb_sign_clicked()
{
    if (control_cb_)
    control_cb_(ControlKey::PLUS_MINUS);
}

void MainWindow::on_pb_division_clicked()
{
    if (operation_cb_)
    operation_cb_(Operation::DIVISION);
}

void MainWindow::on_pb_multiplication_clicked()
{
    if (operation_cb_)
    operation_cb_(Operation::MULTIPLICATION);
}

void MainWindow::on_pb_subtraction_clicked()
{
    if (operation_cb_)
    operation_cb_(Operation::SUBTRACTION);
}

void MainWindow::on_pb_addition_clicked()
{
    if (operation_cb_)
    operation_cb_(Operation::ADDITION);
}

void MainWindow::on_pb_power_clicked()
{
    if (operation_cb_)
    operation_cb_(Operation::POWER);
}

void MainWindow::on_pb_equally_clicked() {
    if (control_cb_)
    control_cb_(ControlKey::EQUALS);
}

void MainWindow::on_cmb_controller_currentIndexChanged(int index)
{
    if (controller_cb_)
    controller_cb_(static_cast<ControllerType>(index));
}
