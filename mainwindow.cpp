#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
int temp,number,result; // variables for computations
char operation='e'; // operation variable ; shows current operation
bool hexa; // mode variable ; true hexadecimal ; false decimal

// main window where we connect button signals with functions
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connects number buttons to digits function
    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digits()));

    //connects hexadecimal number buttons to digits function
    connect(ui->pushButton_a, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_b, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_c, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_d, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_e, SIGNAL(released()), this, SLOT(digits()));
    connect(ui->pushButton_f, SIGNAL(released()), this, SLOT(digits()));

    //connects mode buttons to hexdec function
    connect(ui->pushButton_hex, SIGNAL(released()), this, SLOT(hexdec()));
    connect(ui->pushButton_dec, SIGNAL(released()), this, SLOT(hexdec()));

    // sets dec and hex buttons to be checkable
    ui->pushButton_dec->setCheckable(true);
    ui->pushButton_dec->setChecked(true);
    ui->pushButton_hex->setCheckable(true);
    ui->pushButton_hex->setChecked(false);

    //connects each operation button to its function
    connect(ui->pushButton_plus, SIGNAL(released()), this, SLOT(plus()));
    connect(ui->pushButton_min, SIGNAL(released()), this, SLOT(minus()));
    connect(ui->pushButton_mult, SIGNAL(released()), this, SLOT(mult()));
    connect(ui->pushButton_div, SIGNAL(released()), this, SLOT(div()));
    connect(ui->pushButton_eq, SIGNAL(released()), this, SLOT(equal()));
    connect(ui->pushButton_clr, SIGNAL(released()), this, SLOT(clear()));

}

// when any digit button is pressed this function is called
// takes numbers from buttons till any operation comes.Then prints them on the label
void MainWindow::digits()
{
    QPushButton *button = (QPushButton *) sender(); // creates a button pointer to use button
    QString isim; // string which printed value stored
    bool ok; // to use toInt function
    if(hexa) // if hexadecimal mode is activated
    {
        isim=(ui->label->text() + button->text()); // takes the number digit by digit from button click
        number= isim.toInt(&ok,16); // converts numbers to decimal then stores as string to print
    }else
    {
        number = (ui->label->text() + button->text()).toInt(); // takes the number digit by digit from button click
                isim = QString::number(number); // stores as string to print
    }

    ui->label->setText(isim); // prints as label
    if(operation=='e') // if operation is default value or equal operation gets result
    {
        temp=number;
        result= number;
    }else if(operation=='t') // if operation is addition, adds number to current result
    {
        temp= number+result;

    }else if(operation=='c') // if operation is subtraction, subtracts number from current result
    {
        temp = result - number;
    }else if(operation=='b'){ // if operation is division, divides current result by number
        if(number==0){
            ui->label->setText("wrong operation, press clear button"); // if there is division by zero, gives an error message
        }else
            temp = result / number;
    }else if(operation=='m') // if operation is multiplication number, multiplies number with current result
    {
        temp= number *result;
    }

}

//when plus button is clicked sets operation to 't' then clears the label
void MainWindow::plus()
{
    operation='t';
    result= temp; // sets result to last finded value
    ui->label->setText("");
}

//when minus button is clicked sets operation to 'c' then clears the label
void MainWindow::minus()
{
    operation='c';
    result= temp; // sets result to last finded value
     ui->label->setText("");
}
//when multiplication button is clicked sets operation to 'm' then clears the label
void MainWindow::mult()
{
    operation='m';
    result= temp; // sets result to last finded value
     ui->label->setText("");
}
//when division button is clicked sets operation to 'b' then clears the label
void MainWindow::div()
{
    operation='b';
    result= temp; // sets result to last finded value
     ui->label->setText("");
}
//when equal button is clicked sets operation to 'e' then prints the result to label
void MainWindow::equal()
{
    QString hexadecimal;
    result= temp;
    operation='e';
    if(hexa) //if hexadecimal mode is activated, converts the result to hexadecimal and prints
    {
         hexadecimal.setNum(result,16);
         hexadecimal=hexadecimal.toUpper();
         ui->label->setText((hexadecimal));

    }else // prints the result
        ui->label->setText(QString::number(result));
}


//when clear button is clicked sets operation to 'e' . Then clears label, result and temporary value
void MainWindow::clear()
{

    ui->label->setText("");
    result=0;
    operation='e';
    temp=0;

}

//when hex or dec button is clicked sets hexa to either true or false, then clears the machine.
void MainWindow::hexdec()
{
    if(ui->pushButton_hex->isChecked())
    {hexa=true;
        ui->pushButton_hex->setChecked(false);
    }
    else if(ui->pushButton_dec->isChecked()){
        hexa=false;
        ui->pushButton_dec->setChecked(false);
    }else
        hexa=false;
    clear();
}

// deletes the allocated memory in the heap when program is finished
MainWindow::~MainWindow()
{
    delete ui;
}
