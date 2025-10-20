#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "bankaccount.h"
#include "regularaccount.h"
#include "interestaccount.h"

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

private:
    Ui::MainWindow *ui;
    QList<BankAccount*> accounts;
    void addAccount(BankAccount*);
    void clearForm();
    void updateTable(BankAccount*);
    BankAccount* findAccountByNumber(QString);

private slots:
    void checkFormFilled();
    void checkAccountType(const QString&);
    void createAccount();
    void doOperation();
};
#endif // MAINWINDOW_H
