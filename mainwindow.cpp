#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    btnNums = {{Qt::Key_0,ui->btnNum0},
               {Qt::Key_1,ui->btnNum1},
               {Qt::Key_2,ui->btnNum2},
               {Qt::Key_3,ui->btnNum3},
               {Qt::Key_4,ui->btnNum4},
               {Qt::Key_5,ui->btnNum5},
               {Qt::Key_6,ui->btnNum6},
               {Qt::Key_7,ui->btnNum7},
               {Qt::Key_8,ui->btnNum8},
               {Qt::Key_9,ui->btnNum9},
               };
    foreach (QPushButton *btnNum, btnNums) {
        connect(btnNum,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    }
    connect(ui->btnPlus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMultiple,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnPercentage,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnNumClicked()
{
    QString str = qobject_cast<QPushButton *>(sender())->text();
    if (operand == "0" && str=="0") {
        return;
    }
    if (operand == "0" && str!="0") {
        operand = "";
    }
    operand += qobject_cast<QPushButton *>(sender())->text();
    ui->display->setText(operand);
}

void MainWindow::on_btnPeriod_clicked()
{
    if(operand.contains(".")||operand=="")
        return;
        ui->display->setText(operand +=".");
}


void MainWindow::on_btnDel_clicked()
{
    ui->display->setText(operand = operand.left(operand.size()-1));
}



void MainWindow::on_btnClear_clicked()
{
    operand.clear();
    ui->display->setText(operand);
}

void MainWindow::btnBinaryOperatorClicked()
{
    control = qobject_cast<QPushButton *>(sender())->text();
    temp = operand;
    operand = "";
}
void MainWindow::on_btnEqual_clicked()
{
    if(temp=="")
        return;
    if(control=="+"){
        operand = QString::number(operand.toInt() + temp.toInt());
    }else if(control=="-"){
        operand = QString::number(operand.toInt() - temp.toInt());
    }else if(control=="*"){
        operand = QString::number(operand.toInt() * temp.toInt());
    }else if(control=="/"){
        operand = QString::number(operand.toInt() / temp.toInt());
    }else if(control=="%"){
        operand = QString::number(operand.toInt() % temp.toInt());
    }
    ui->display->setText(operand);
}


void MainWindow::on_btnClearAll_clicked()
{
    temp = "";
    control = "";
    operand = "";
    ui->display->setText(operand);
}


void MainWindow::on_btnInverse_clicked()
{
    if(operand=="0"||operand==""){
        return;
    }
    if(operand.left(1)!="-"){
            operand = "-"+operand;
    }else{
        operand = operand.right(operand.size()-1);
    }
    ui->display->setText(operand);
}


void MainWindow::on_btnSign_clicked()
{
    double f = 1 / operand.toFloat();
    operand = QString::number(f,'f',10);
    ui->display->setText(operand);
}


void MainWindow::on_btnSquare_clicked()
{
    operand = QString::number(pow(operand.toDouble(),2));
    ui->display->setText(operand);
}


void MainWindow::on_btnSqrt_clicked()
{
        operand = QString::number(sqrt(operand.toDouble()));
        ui->display->setText(operand);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!btnNums.contains(event->key()))
        return;
    btnNums.value(event->key())->click();
}

