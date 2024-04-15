#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool is_point = false, is_new = false, is_frash_number = true, is_operation_clicked = false;
    bool plus_chek = false, minus_chek = false, multiply_chek = false, divided_chek = false;
    int counter_new = 0, count_operations = 0, counter_clicked_equale = 0;
    long double first_oper, second_oper;
    QPushButton * memory_button;

private slots:
    void digits_numbers();
    void point(); //Доделка - нет ограничения на ввод строки (ввёл слишком много - обнулился экран)
    void function_plas_minus(); //Доделка - адаптивность к размеру окна
    void operations(); //Но лучше - setFixedSize() - просто не изменяется размер
    void function_equale();
    void function_plas();
    void function_minus();
    void function_multiply();
    void function_divided();
    void function_c();
    void function_ce();
    void function_del();
    void doOperation();
    void is_this(QPushButton *);
};
#endif // MAINWINDOW_H
