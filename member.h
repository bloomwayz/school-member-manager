#ifndef MEMBER_H
#define MEMBER_H

#include <QString>

class Member {
public:
    QString category;
    QString name;
    QString affiliation;
    QString email;

    virtual QString print() const = 0;
    virtual ~Member() = default;
};

#endif // MEMBER_H
