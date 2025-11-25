#include "employee.h"

Employee::Employee(QObject *parent)
    : QObject(parent)
{
}

Employee::Employee(const QString &id, const QString &name,const QString &role, const QString &email,QObject *parent)
    : QObject(parent), m_id(id), m_name(name), m_role(role), m_email(email)
{
}

QString Employee::id() const { return m_id; }
QString Employee::name() const { return m_name; }
QString Employee::role() const { return m_role; }
QString Employee::email() const { return m_email; }

void Employee::setId(const QString &id)
{
    if (m_id != id) {
        m_id = id;
        emit idChanged();
    }
}

void Employee::setName(const QString &name)
{
    if (m_name != name) {
        m_name = name;
        emit nameChanged();
    }
}

void Employee::setRole(const QString &role)
{
    if (m_role != role) {
        m_role = role;
        emit roleChanged();
    }
}

void Employee::setEmail(const QString &email)
{
    if (m_email != email) {
        m_email = email;
        emit emailChanged();
    }
}
