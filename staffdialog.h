#ifndef STAFFDIALOG_H
#define STAFFDIALOG_H

#include <QDialog>

namespace Ui {
class StaffDialog;
}

class StaffDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StaffDialog(QWidget *parent = nullptr);
    ~StaffDialog();

    QString getName() const;
    QString getAffiliation() const;
    QString getEmail() const;
    QString getPosition() const;
    QString getId() const;

private:
    Ui::StaffDialog *ui;
};

#endif // STAFFDIALOG_H
