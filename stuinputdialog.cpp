#include "stuinputdialog.h"
#include "ui_stuinputdialog.h"

inputdialog::inputdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::inputdialog)
{
    ui->setupUi(this);
}

inputdialog::~inputdialog()
{
    delete ui;
}
