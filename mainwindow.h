#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "studentsmodel.h"
#include "staffsmodel.h"
#include "studialog.h"
#include "staffdialog.h"

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

private slots:
    void updateRemoveButtonState();

    void updateRemoveButton2State();

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_addButton2_clicked();

    void on_removeButton2_clicked();

private:
    Ui::MainWindow *ui;
    studentsmodel *stuModel;
    staffsmodel *stfModel;
};
#endif // MAINWINDOW_H
