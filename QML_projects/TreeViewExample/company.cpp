#include "company.h"

Company::Company(QObject *parent)
    : QObject(parent)
{
}

Company::Company(const QString &id,const QString &name,const QString &year,const QString &image,QObject *parent)
    : QObject(parent), m_id(id), m_name(name), m_year(year), m_image(image)
{
}

QString Company::id() const { return m_id; }
QString Company::name() const { return m_name; }
QString Company::year() const { return m_year; }
QString Company::image() const { return m_image; }
QString Company::location() const { return m_location; }
QString Company::industry() const { return m_industry; }
QString Company::ceo() const { return m_ceo; }
QString Company::status() const { return m_status; }

void Company::addEmployee(Employee *employee)
{
    if (!m_employees.contains(employee->id())) {
        m_employees.insert(employee->id(), employee);
        emit employeesChanged();
    }
}

QList<QObject*> Company::employeesAsQObjectList() const
{
    QList<QObject*> list;
    for (auto *emp : m_employees)
        list.append(emp);
    return list;
}

void Company::clearEmployees()
{
    for (auto *emp : m_employees) {
        emp->deleteLater();
    }
    m_employees.clear();
    emit employeesChanged();
}

void Company::setId(const QString &id)
{
    if (m_id != id) {
        m_id = id;
        emit idChanged();
    }
}

void Company::setName(const QString &name)
{
    if (m_name != name) {
        m_name = name;
        emit nameChanged();
    }
}

void Company::setYear(const QString &year)
{
    if (m_year != year) {
        m_year = year;
        emit yearChanged();
    }
}

void Company::setImage(const QString &image)
{
    if (m_image != image) {
        m_image = image;
        emit imageChanged();
    }
}

void Company::setLocation(const QString &location)
{
    if (m_location != location) {
        m_location = location;
        emit locationChanged();
    }
}

void Company::setIndustry(const QString &industry)
{
    if (m_industry != industry) {
        m_industry = industry;
        emit industryChanged();
    }
}

void Company::setCeo(const QString &ceo)
{
    if (m_ceo != ceo) {
        m_ceo = ceo;
        emit ceoChanged();
    }
}

void Company::setStatus(const QString &status)
{
    if (m_status != status) {
        m_status = status;
        emit statusChanged();
    }
}

bool Company::selected() const
{
    return m_selected;
}

void Company::setSelected(bool newSelected)
{
    if (m_selected == newSelected)
        return;
    m_selected = newSelected;
    emit selectedChanged();
}
