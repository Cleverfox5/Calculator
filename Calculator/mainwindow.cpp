#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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


    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_divided, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(point()));
    connect(ui->pushButton_pm, SIGNAL(clicked()), this, SLOT(function_plas_minus()));
    connect(ui->pushButton_equally, SIGNAL(clicked()), this, SLOT(function_equale()));

    connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(function_c()));
    connect(ui->pushButton_CE, SIGNAL(clicked()), this, SLOT(function_ce()));
    connect(ui->pushButton_backSpace, SIGNAL(clicked()), this, SLOT(function_del()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::function_plas(){
    if (counter_clicked_equale == 0){
        second_oper = (ui->label_display->text()).toDouble();
    }
    first_oper += second_oper;
    //second_oper = 0;
    ui->label_display->setText(QString::number(first_oper, 'g', 15));

    plus_chek = false;

    is_new = true;
}

void MainWindow::function_minus(){
    if (counter_clicked_equale == 0){
        second_oper = (ui->label_display->text()).toDouble();
    }
    first_oper -= second_oper;
    //second_oper = 0;
    ui->label_display->setText(QString::number(first_oper, 'g', 15));

    minus_chek = false;

    is_new = true;
}

void MainWindow::function_multiply(){
    if (counter_clicked_equale == 0){
        second_oper = (ui->label_display->text()).toDouble();
    }
    first_oper *= second_oper;
    //second_oper = 0;
    ui->label_display->setText(QString::number(first_oper, 'g', 15));

    multiply_chek = false;

    is_new = true;
}

void MainWindow::function_divided(){
    if (counter_clicked_equale == 0){
        second_oper = (ui->label_display->text()).toDouble();
    }
    if (second_oper != 0){
        first_oper /= second_oper;
        //second_oper = 0;
        ui->label_display->setText(QString::number(first_oper, 'g', 15));
    }
    else{
        ui->label_display->setText("0");
    }

    divided_chek = false;

    is_new = true;
}

void MainWindow::doOperation(){
    if (plus_chek == true){
        function_plas();
        memory_button = ui->pushButton_plus;
    }
    else if (minus_chek == true){
        function_minus();
        memory_button = ui->pushButton_minus;
    }
    else if (multiply_chek == true){
        function_multiply();
        memory_button = ui->pushButton_multiply;
    }
    else if (divided_chek == true){
        function_divided();
        memory_button = ui->pushButton_divided;
    }
}

void MainWindow::is_this(QPushButton * button){
    if (button == ui->pushButton_plus){
        plus_chek = true;
    }
    else if (button == ui->pushButton_minus){
        minus_chek = true;
    }
    else if (button == ui->pushButton_multiply){
        multiply_chek = true;
    }
    else if (button == ui->pushButton_divided){
        divided_chek = true;
    }
}

void MainWindow::operations(){
    if ((count_operations > 0) && (is_frash_number)){
        doOperation();
    }
    QPushButton *button = (QPushButton * ) sender();

    first_oper = (ui->label_display->text()).toDouble();

    plus_chek = false;
    multiply_chek = false;
    minus_chek = false;
    divided_chek = false;

    is_frash_number = false;
    count_operations++;
    is_operation_clicked = true;

    is_this(button);
}

void MainWindow::function_equale(){
    if (counter_clicked_equale > 0){
        is_this(memory_button);
        doOperation();
        counter_clicked_equale++;
    }
    else{
        doOperation();
        counter_clicked_equale++;
    }

    counter_new = 0;
    count_operations = 0;
    is_operation_clicked = false;
}

void MainWindow::digits_numbers(){
    if(counter_new == 0){
        if (plus_chek){
            is_new = true;
            counter_new++;
        }
        else if (minus_chek){
            is_new = true;
            counter_new++;
        }
        else if (multiply_chek){
            is_new = true;
            counter_new++;
        }
        else if (divided_chek){
            is_new = true;
            counter_new++;
        }
    }

    QPushButton *button = (QPushButton * ) sender();

    long double number;
    QString str;
    if (is_new){
        number = (button->text()).toDouble();
        counter_clicked_equale = 0;
        second_oper = 0;
        is_frash_number = true;
    }
    else{
        str = ui->label_display->text();
        if (str.size() < 15){
            number = (str + button->text()).toDouble();
        }
        else{
            number = str.toDouble();
        }
    }

    is_new = false;


    QString out = QString::number(number, 'g', 15);

    ui->label_display->setText(out);
}

void MainWindow::point(){
    if (!is_point){ //можно было использовать text.containst()
        ui->label_display->setText(ui->label_display->text() + ".");
        is_point = true;
    }
}

void MainWindow::function_plas_minus(){
    long double number;

    number = (ui->label_display->text()).toDouble();
    number *= -1;

    QString out = QString::number(number, 'g', 15);
    ui->label_display->setText(out);
}

void MainWindow::function_c(){
    first_oper = 0;
    second_oper = 0;
    counter_new = 0;
    counter_clicked_equale = 0;
    is_point = false;
    is_new = false;
    is_frash_number = true;
    ui->label_display->setText("0");

    plus_chek = false;
    minus_chek = false;
    multiply_chek = false;
    divided_chek = false;

    count_operations = 0;
}

void MainWindow::function_ce(){
    second_oper = 0;
    is_point = false;
    ui->label_display->setText("0");
}

void MainWindow::function_del(){
    if (!is_operation_clicked){
        QString str = ui->label_display->text();
        if ((!str.contains('e')) && (!str.contains('i'))){
            if (str.size() > 1){
                str.remove(str.size() - 1, str.size());

                ui->label_display->setText(str);
            }
            else{
                ui->label_display->setText("0");
            }
        }
    }
}
