#ifndef STUDENTSMODEL_H
#define STUDENTSMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include "member.h"

class Student : public Member {
public:
    QString programme;
    QString studentId;

    Student() { category = "Student"; }

    QString print() const override;
};

class studentsmodel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit studentsmodel(QObject *parent = nullptr);

    ~studentsmodel() {
        qDeleteAll(students);
        students.clear();
    }

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section,
                       Qt::Orientation orientation,
                       const QVariant &value,
                       int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    void addStudent(const Student &s);

private:
    QVector<Student*> students;
};

#endif // STUDENTSMODEL_H
