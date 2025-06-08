#include "studialog.h"
#include "ui_studialog.h"

StuDialog::StuDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StuDialog)
{
    ui->setupUi(this);
}

StuDialog::~StuDialog()
{
    delete ui;
}

QString StuDialog::getName() const {
    return ui->nameEdit->text();
}

QString StuDialog::getEmail() const {
    return ui->emlEdit->text();
}

QString StuDialog::getAffiliation() const {
    return ui->affEdit->text();
}

QString StuDialog::getProgramme() const {
    return ui->pgmBox->currentText();
}

QString StuDialog::getId() const {
    return ui->sidEdit->text();
}
