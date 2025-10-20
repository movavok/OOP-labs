#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Банківська Система");

    ui->tw_accounts->setColumnCount(6);
    ui->tw_accounts->setHorizontalHeaderLabels({"Номер", "Власник", "Баланс", "Тип", "Мін. баланс", "Відсоток"});
    ui->tw_accounts->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->le_accNumber, &QLineEdit::textChanged, this, &MainWindow::checkFormFilled);
    connect(ui->le_accOwner, &QLineEdit::textChanged, this, &MainWindow::checkFormFilled);
    connect(ui->le_tab2_accNumber, &QLineEdit::textChanged, this, &MainWindow::checkFormFilled);
    connect(ui->cb_accType, &QComboBox::currentTextChanged, this, &MainWindow::checkAccountType);
    connect(ui->cb_operType, &QComboBox::currentTextChanged, this, &MainWindow::checkAccountType);
    connect(ui->b_createAccount, &QPushButton::clicked, this, &MainWindow::createAccount);
    connect(ui->b_doOperation, &QPushButton::clicked, this, &MainWindow::doOperation);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkFormFilled() {
    ui->b_createAccount->setEnabled(!ui->le_accNumber->text().isEmpty() && !ui->le_accOwner->text().isEmpty());
    ui->b_doOperation->setEnabled(!ui->le_tab2_accNumber->text().isEmpty());
}

void MainWindow::checkAccountType(const QString& type) {
    bool isRegular = (type == "Звичайний");
    ui->l_accMinBalance->setEnabled(isRegular);
    ui->dsb_accMinBalance->setEnabled(isRegular);
    ui->l_accInterest->setEnabled(!isRegular);
    ui->sb_accInterest->setEnabled(!isRegular);
    bool isDeleting = (type == "Видалити рахунок");
    ui->l_moneyAmount->setEnabled(!isDeleting);
    ui->dsb_moneyAmount->setEnabled(!isDeleting);
}

void MainWindow::addAccount(BankAccount* acc) {
    int row = ui->tw_accounts->rowCount();
    ui->tw_accounts->insertRow(row);

    ui->tw_accounts->setItem(row, 0, new QTableWidgetItem(acc->getAccNumber()));
    ui->tw_accounts->setItem(row, 1, new QTableWidgetItem(acc->getOwnerName()));
    ui->tw_accounts->setItem(row, 2, new QTableWidgetItem(QString::number(acc->getBalance())));
    ui->tw_accounts->setItem(row, 3, new QTableWidgetItem(acc->getType()));

    if (acc->getType() == "Звичайний рахунок") {
        ui->tw_accounts->setItem(row, 4, new QTableWidgetItem(QString::number(static_cast<RegularAccount*>(acc)->getMinBalance(), 'f', 2)));
        ui->tw_accounts->setItem(row, 5, new QTableWidgetItem("-"));
    } else {
        ui->tw_accounts->setItem(row, 4, new QTableWidgetItem("-"));
        ui->tw_accounts->setItem(row, 5, new QTableWidgetItem(QString::number(static_cast<InterestAccount*>(acc)->getInterestRate(), 'f', 2)));
    }
}

void MainWindow::clearForm() {
    ui->le_accNumber->clear();
    ui->le_accOwner->clear();
    ui->dsb_accBalance->setValue(0);
    ui->dsb_accMinBalance->setValue(0);
    ui->sb_accInterest->setValue(0);
    ui->cb_accType->setCurrentIndex(0);

    checkFormFilled();
}

void MainWindow::createAccount() {
    QString number = ui->le_accNumber->text();
    QString owner = ui->le_accOwner->text();
    double balance = ui->dsb_accBalance->value();
    QString type = ui->cb_accType->currentText();

    try {
        if (findAccountByNumber(number)) throw std::invalid_argument("Рахунок з таким номером вже існує!");

        BankAccount* newAccount = nullptr;

        if (type == "Звичайний") {
            double minBalance = ui->dsb_accMinBalance->value();
            if (minBalance > balance) throw std::invalid_argument("Мінімальний баланс не може бути більшим за початковий баланс!");
            newAccount = new RegularAccount(number, owner, balance, minBalance);
        }
        else newAccount = new InterestAccount(number, owner, balance, ui->sb_accInterest->value());

        accounts.append(newAccount);

        addAccount(newAccount);
        clearForm();
    } catch (const std::invalid_argument& e) {
        QMessageBox::warning(this, "Помилка створення рахунку", e.what());
    }
}

BankAccount* MainWindow::findAccountByNumber(QString number) {
    for (BankAccount* acc : accounts)
        if (acc->getAccNumber() == number) return acc;
    return nullptr;
}

void MainWindow::doOperation() {
    QString number = ui->le_tab2_accNumber->text();
    QString operType = ui->cb_operType->currentText();
    double amount = ui->dsb_moneyAmount->value();

    try {
        BankAccount* account = findAccountByNumber(number);

        if (!account) throw std::invalid_argument("Рахунок не знайдено!");

        if (operType == "Поповнити баланс") {
            account->deposit(amount);
            updateTable(account);
        }
        else if (operType == "Зняти кошти") {
            if (!account->withdraw(amount)) {
                throw std::invalid_argument("Недостатньо коштів або мінімальний баланс порушується!");
                return;
            }
            updateTable(account);
        }
        else if (operType == "Видалити рахунок") {
            for (int i = 0; i < accounts.size(); ++i) {
                if (accounts[i]->getAccNumber() == number) {
                    delete accounts[i];
                    accounts.removeAt(i);
                    ui->tw_accounts->removeRow(i);
                    return;
                }
            }
        }

    ui->le_tab2_accNumber->clear();
    ui->dsb_moneyAmount->setValue(0);

    } catch (const std::invalid_argument& e) {
        QMessageBox::warning(this, "Помилка операції", e.what());
    }
}

void MainWindow::updateTable(BankAccount* acc) {
    for (int row = 0; row < ui->tw_accounts->rowCount(); ++row) {
        if (ui->tw_accounts->item(row, 0)->text() == acc->getAccNumber()) {
            ui->tw_accounts->setItem(row, 2, new QTableWidgetItem(QString::number(acc->getBalance(), 'f', 2)));
            return;
        }
    }
}
