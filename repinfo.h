#ifndef REPINFO_H
#define REPINFO_H

#include <QObject>
#include <QUrl>
#include <qqml.h>

class RepInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)
    Q_PROPERTY(int stars READ stars WRITE setStars NOTIFY starsChanged)
    Q_PROPERTY(int forks READ forks WRITE setForks NOTIFY forksChanged)
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)

public:
    explicit RepInfo(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &newName);

    QString author() const;
    void setAuthor(const QString &newAuthor);

    QString description() const;
    void setDescription(const QString &newDescription);

    QString language() const;
    void setLanguage(const QString &newLanguage);

    int stars() const;
    void setStars(int newStars);

    int forks() const;
    void setForks(int newForks);

    QString date() const;
    void setDate(const QString &newDate);


signals:
    void nameChanged();
    void authorChanged();
    void descriptionChanged();
    void languageChanged();
    void starsChanged();
    void forksChanged();
    void dateChanged();



private:
    QString m_name;
    QString m_author;
    QString m_description;
    QString m_language;
    int m_stars;
    int m_forks;
    QString m_date;

};

#endif // REPINFO_H
