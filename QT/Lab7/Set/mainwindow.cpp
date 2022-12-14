#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setWordWrapMode(QTextOption::NoWrap);
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_showButton_clicked()
{
    ui->textEdit->clear();
    if (countOfElemInSet == 0)
    {
        QMessageBox::information(this, "Message", "Set is empty.");
        return;
    }
    QString result;
    set<int>::iterator1 iter = m.begin();
    while (iter != m.end())
    {
        result += " (" + QString::number((*iter).first) + ") ";
        iter++;
    }
    ui->textEdit->setText(result);
}


void MainWindow::on_countButton_clicked()
{
    int line = ui->lineEditCount->text().toInt();
    if (ui->lineEditCount->text().size() == 0)
    {
        QMessageBox::information(this, "Message", "Insert in line integer key to check count.");
        return;
    }

    QMessageBox::information(this, "Message", QString::number(m.count(line)));
}


void MainWindow::on_insertButton_clicked()
{
    int line = ui->lineEditInsertKey->text().toInt();
    if (ui->lineEditInsertKey->text().size() == 0)
    {
        QMessageBox::information(this, "Message", "Insert in line integer key to insert.");
        return;
    }

    if (countOfElemInSet != 0 && m.find(line) == m.end())
    countOfElemInSet++;

    if (countOfElemInSet == 0)
    {
        countOfElemInSet++;
    }
    m.insert(std::make_pair(line, line));
}


void MainWindow::on_removeButton_clicked()
{
    int line = ui->lineEditEraseKey->text().toInt();
    if (ui->lineEditEraseKey->text().size() == 0)
    {
        QMessageBox::information(this, "Message", "Insert in line integer key to erase(remove).");
        return;
    }

    if (countOfElemInSet == 0 || m.find(line) == m.end())
    {
        QMessageBox::information(this, "Message", "No such key.");
        return;
    }
    m.erase(line);
    countOfElemInSet--;
}


void MainWindow::on_findButton_clicked()
{
    int line = ui->lineEditFindKey->text().toInt();
    if (ui->lineEditFindKey->text().size() == 0)
    {
        QMessageBox::information(this, "Message", "Insert in line integer key to find.");
        return;
    }

    set<int>::iterator1 iter = m.find(line);
    if (countOfElemInSet == 0 || iter == m.end())
    {
        QMessageBox::information(this, "Message", "No such key.");
        return;
    }

    QMessageBox::information(this, "Message", "Key: " + QString::number((*iter).first));
}


