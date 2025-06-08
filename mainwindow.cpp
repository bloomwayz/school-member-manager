#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stuModel(new studentsmodel(this))
    , stfModel(new staffsmodel(this))
{
    ui->setupUi(this);

    ui->tableView->setModel(stuModel);
    ui->tableView2->setModel(stfModel);

    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateRemoveButtonState);

    connect(ui->tableView2->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateRemoveButton2State);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateRemoveButtonState()
{
    QItemSelectionModel* selection = ui->tableView->selectionModel();
    bool hasSelection = selection && selection->hasSelection();
    ui->removeButton->setEnabled(hasSelection);
}

void MainWindow::updateRemoveButton2State()
{
    QItemSelectionModel* selection = ui->tableView2->selectionModel();
    bool hasSelection = selection && selection->hasSelection();
    ui->removeButton2->setEnabled(hasSelection);
}

void MainWindow::on_addButton_clicked()
{
    StuDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Student s;
        s.name = dialog.getName();
        s.email = dialog.getEmail();
        s.affiliation = dialog.getAffiliation();
        s.programme = dialog.getProgramme();
        s.studentId = dialog.getId();

        stuModel->addStudent(s);
    }
}

void MainWindow::on_removeButton_clicked() {
    QModelIndexList selection = ui->tableView->selectionModel()->selectedIndexes();

    if (!selection.isEmpty()) {
        int row = selection.first().row();
        stuModel->removeRows(row, 1);
    }
}

void MainWindow::on_addButton2_clicked()
{
    StaffDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Staff s;
        s.name = dialog.getName();
        s.email = dialog.getEmail();
        s.affiliation = dialog.getAffiliation();
        s.position = dialog.getPosition();
        s.staffId = dialog.getId();

        stfModel->addStaff(s);
    }
}

void MainWindow::on_removeButton2_clicked()
{
    QModelIndexList selection = ui->tableView2->selectionModel()->selectedIndexes();

    if (!selection.isEmpty()) {
        int row = selection.first().row();
        stfModel->removeRows(row, 1);
    }
}

