#pragma once
#include <QObject>
#include <QString>

class Employee : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString role READ role WRITE setRole NOTIFY roleChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)

public:
    explicit Employee(QObject *parent = nullptr);
    Employee(const QString &id, const QString &name, const QString &role, const QString &email, QObject *parent = nullptr);

    QString id() const;
    QString name() const;
    QString role() const;
    QString email() const;

public slots:
    void setId(const QString &id);
    void setName(const QString &name);
    void setRole(const QString &role);
    void setEmail(const QString &email);

signals:
    void idChanged();
    void nameChanged();
    void roleChanged();
    void emailChanged();

private:
    QString m_id;
    QString m_name;
    QString m_role;
    QString m_email;
};
