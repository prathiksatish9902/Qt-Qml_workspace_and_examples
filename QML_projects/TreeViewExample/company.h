#pragma once
#include <QObject>
#include <QMap>
#include <QString>
#include "employee.h"

class Company : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString year READ year WRITE setYear NOTIFY yearChanged)
    Q_PROPERTY(QString image READ image WRITE setImage NOTIFY imageChanged)
    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY locationChanged)
    Q_PROPERTY(QString industry READ industry WRITE setIndustry NOTIFY industryChanged)
    Q_PROPERTY(QString ceo READ ceo WRITE setCeo NOTIFY ceoChanged)
    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(QList<QObject*> employees READ employeesAsQObjectList NOTIFY employeesChanged)
    Q_PROPERTY(bool selected READ selected WRITE setSelected NOTIFY selectedChanged FINAL)

public:
    explicit Company(QObject *parent = nullptr);
    Company(const QString &id, const QString &name, const QString &year, const QString &image, QObject *parent = nullptr);

    QString id() const;
    QString name() const;
    QString year() const;
    QString image() const;
    QString location() const;
    QString industry() const;
    QString ceo() const;
    QString status() const;

    void addEmployee(Employee *employee);
    QList<QObject*> employeesAsQObjectList() const;
    void clearEmployees();

    bool selected() const;
    void setSelected(bool newSelected);

public slots:
    void setId(const QString &id);
    void setName(const QString &name);
    void setYear(const QString &year);
    void setImage(const QString &image);
    void setLocation(const QString &location);
    void setIndustry(const QString &industry);
    void setCeo(const QString &ceo);
    void setStatus(const QString &status);

signals:
    void idChanged();
    void nameChanged();
    void yearChanged();
    void imageChanged();
    void locationChanged();
    void industryChanged();
    void ceoChanged();
    void statusChanged();
    void employeesChanged();

    void selectedChanged();

private:
    QString m_id;
    QString m_name;
    QString m_year;
    QString m_image;
    QString m_location;
    QString m_industry;
    QString m_ceo;
    QString m_status;
    bool m_selected = false;
    QMap<QString, Employee*> m_employees;
};
