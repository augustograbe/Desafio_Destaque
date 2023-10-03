#include "repinfo.h"

RepInfo::RepInfo(QObject *parent)
    : QObject{parent}
{

}


QString RepInfo::name() const
{
    return m_name;
}

void RepInfo::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

QString RepInfo::author() const
{
    return m_author;
}

void RepInfo::setAuthor(const QString &newAuthor)
{
    if (m_author == newAuthor)
        return;
    m_author = newAuthor;
    emit authorChanged();
}

QString RepInfo::description() const
{
    return m_description;
}

void RepInfo::setDescription(const QString &newDescription)
{
    if (m_description == newDescription)
        return;
    m_description = newDescription;
    emit descriptionChanged();
}

QString RepInfo::language() const
{
    return m_language;
}

void RepInfo::setLanguage(const QString &newLanguage)
{
    if (m_language == newLanguage)
        return;
    m_language = newLanguage;
    emit languageChanged();
}

int RepInfo::stars() const
{
    return m_stars;
}

void RepInfo::setStars(int newStars)
{
    if (m_stars == newStars)
        return;
    m_stars = newStars;
    emit starsChanged();
}

int RepInfo::forks() const
{
    return m_forks;
}

void RepInfo::setForks(int newForks)
{
    if (m_forks == newForks)
        return;
    m_forks = newForks;
    emit forksChanged();
}

QString RepInfo::date() const
{
    return m_date;
}

void RepInfo::setDate(const QString &newDate)
{
    if (m_date == newDate)
        return;
    m_date = newDate;
    emit nameChanged();
}
