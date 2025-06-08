#include "staffdialog.h"
#include "ui_staffdialog.h"

StaffDialog::StaffDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StaffDialog)
{
    ui->setupUi(this);
}

StaffDialog::~StaffDialog()
{
    delete ui;
}

QString StaffDialog::getName() const {
    return ui->nameEdit->text();
}

QString StaffDialog::getEmail() const {
    return ui->emlEdit->text();
}

QString StaffDialog::getAffiliation() const {
    return ui->affEdit->text();
}

QString StaffDialog::getPosition() const {
    return ui->posEdit->text();
}

QString StaffDialog::getId() const {
    return ui->stfIdEdit->text();
}
