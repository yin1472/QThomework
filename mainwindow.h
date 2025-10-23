#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString operand;
    QString temp;
    QString control;
    QMap<int,QPushButton*> btnNums;


private slots:
    void btnNumClicked();

    void on_btnPeriod_clicked();

    void on_btnDel_clicked();

    void on_btnClear_clicked();

    void btnBinaryOperatorClicked();

    void on_btnEqual_clicked();

    void on_btnClearAll_clicked();

    void on_btnInverse_clicked();

    void on_btnSign_clicked();

    void on_btnSquare_clicked();

    void on_btnSqrt_clicked();

    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
