#include <QVector>
#include "studentsmodel.h"

studentsmodel::studentsmodel(QObject *parent)
    : QAbstractTableModel(parent)
{}

QVariant studentsmodel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal) return {};

    switch (section) {
        case 0: return "Name";
        case 1: return "Affiliation";
        case 2: return "Email";
        case 3: return "Programme";
        case 4: return "Student ID";
    }
    return {};
}

bool studentsmodel::setHeaderData(int section,
                                  Qt::Orientation orientation,
                                  const QVariant &value,
                                  int role)
{
    return false;
}

int studentsmodel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return students.size();
}

int studentsmodel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 5;
}

QVariant studentsmodel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    const Student* student = students.at(index.row());
    switch (index.column()) {
        case 0: return student->name;
        case 1: return student->affiliation;
        case 2: return student->email;
        case 3: return student->programme;
        case 4: return student->studentId;
    }
    return QVariant();
}

bool studentsmodel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    Student* student = students[index.row()];
    switch (index.column()) {
        case 0: student->name = value.toString(); break;
        case 1: student->affiliation = value.toString(); break;
        case 2: student->email = value.toString(); break;
        case 3: student->programme = value.toString(); break;
        case 4: student->studentId = value.toString(); break;
        default: return false;
    }
    emit dataChanged(index, index, {role});
    return true;
}

Qt::ItemFlags studentsmodel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

bool studentsmodel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    for (int i = 0; i < count; ++i) {
        students.insert(row, new Student());
    }
    endInsertRows();
    return true;
}

bool studentsmodel::removeRows(int row, int count, const QModelIndex &parent) {
    if (row < 0 || row + count > students.size())
        return false;

    beginRemoveRows(parent, row, row + count - 1);

    for (int i = 0; i < count; ++i) {
        delete students[row];  // 메모리 해제
        students.removeAt(row);
    }

    endRemoveRows();
    return true;
}


void studentsmodel::addStudent(const Student &s) {
    int row = students.size();
    beginInsertRows(QModelIndex(), row, row);
    students.append(new Student(s));
    endInsertRows();
}

QString Student::print() const {
    return QString("%1\t%2\t%3\t%4\t%5")
    .arg(category)
        .arg(name)
        .arg(affiliation)
        .arg(email)
        .arg(programme + "\t" + studentId);
}
