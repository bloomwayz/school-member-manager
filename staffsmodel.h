#ifndef STAFFSMODEL_H
#define STAFFSMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include "member.h"

class Staff : public Member {
public:
    QString position;
    QString staffId;

    Staff() { category = "Staff"; }

    QString print() const override;
};

class staffsmodel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit staffsmodel(QObject *parent = nullptr);

    ~staffsmodel() {
        qDeleteAll(staffs);
        staffs.clear();
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

    void addStaff(const Staff &s);

private:
    QVector<Staff*> staffs;
};

#endif // STAFFSMODEL_H
