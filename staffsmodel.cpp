#include <QVector>
#include "staffsmodel.h"

staffsmodel::staffsmodel(QObject *parent)
    : QAbstractTableModel(parent)
{}

QVariant staffsmodel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal) return {};

    switch (section) {
    case 0: return "Name";
    case 1: return "Affiliation";
    case 2: return "Email";
    case 3: return "Position";
    case 4: return "Staff ID";
    }
    return {};
}

bool staffsmodel::setHeaderData(int section,
                                  Qt::Orientation orientation,
                                  const QVariant &value,
                                  int role)
{
    return false;
}

int staffsmodel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return staffs.size();
}

int staffsmodel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 5;
}

QVariant staffsmodel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    const Staff* staff = staffs.at(index.row());
    switch (index.column()) {
    case 0: return staff->name;
    case 1: return staff->affiliation;
    case 2: return staff->email;
    case 3: return staff->position;
    case 4: return staff->staffId;
    }
    return QVariant();
}

bool staffsmodel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    Staff* staff = staffs[index.row()];
    switch (index.column()) {
    case 0: staff->name = value.toString(); break;
    case 1: staff->affiliation = value.toString(); break;
    case 2: staff->email = value.toString(); break;
    case 3: staff->position = value.toString(); break;
    case 4: staff->staffId = value.toString(); break;
    default: return false;
    }
    emit dataChanged(index, index, {role});
    return true;
}

Qt::ItemFlags staffsmodel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

bool staffsmodel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    for (int i = 0; i < count; ++i) {
        staffs.insert(row, new Staff());
    }
    endInsertRows();
    return true;
}

bool staffsmodel::removeRows(int row, int count, const QModelIndex &parent) {
    if (row < 0 || row + count > staffs.size())
        return false;

    beginRemoveRows(parent, row, row + count - 1);

    for (int i = 0; i < count; ++i) {
        delete staffs[row];
        staffs.removeAt(row);
    }

    endRemoveRows();
    return true;
}


void staffsmodel::addStaff(const Staff &s) {
    int row = staffs.size();
    beginInsertRows(QModelIndex(), row, row);
    staffs.append(new Staff(s));
    endInsertRows();
}

QString Staff::print() const {
    return QString("%1\t%2\t%3\t%4\t%5")
    .arg(category)
        .arg(name)
        .arg(affiliation)
        .arg(email)
        .arg(position + "\t" + staffId);
}
