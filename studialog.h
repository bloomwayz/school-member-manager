#ifndef STUDIALOG_H
#define STUDIALOG_H

#include <QDialog>

namespace Ui {
class StuDialog;
}

class StuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StuDialog(QWidget *parent = nullptr);
    ~StuDialog();

    QString getName() const;
    QString getAffiliation() const;
    QString getEmail() const;
    QString getProgramme() const;
    QString getId() const;

private:
    Ui::StuDialog *ui;
};

#endif // STUDIALOG_H
