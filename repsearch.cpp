#include "repsearch.h"
#include "repinfo.h"
#include <QJsonDocument>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonArray>

namespace {
    const QString &k_requestUrl = "https://api.github.com/search/repositories";
}


RepSearch::RepSearch(QObject *parent)
    : QAbstractListModel(parent)
{

}

int RepSearch::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_repList.size();
}

QVariant RepSearch::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() >= 0 && index.row() < m_repList.size()) {
        RepInfo *audioInfo = m_repList[index.row()];

        switch((Role)role) {
        case RepNameRole:
            return audioInfo->name();
        case RepAuthorRole:
            return audioInfo->author();
        case RepDescriptionRole:
            return audioInfo->description();
        case RepLanguageRole:
            return audioInfo->language();
        case RepStarsRole:
            return audioInfo->stars();
        case RepForksRole:
            return audioInfo->forks();
        case RepDateRole:
            return audioInfo->date();
        }
    }

    return {};
}

QHash<int, QByteArray> RepSearch::roleNames() const
{
    QHash<int, QByteArray> names;

    names[RepNameRole] = "repName";
    names[RepAuthorRole] = "repAuthor";
    names[RepDescriptionRole] = "repDescription";
    names[RepLanguageRole] = "repLanguage";
    names[RepStarsRole] = "repStars";
    names[RepForksRole] = "repForks";
    names[RepDateRole] = "repDate";

    return names;
}

void RepSearch::searchRep(const QString &name)
{
    if (!name.trimmed().isEmpty()) {
        if (m_reply) {
            m_reply->abort();
            m_reply->deleteLater();
            m_reply = nullptr;
        }

        QUrlQuery query;
        query.addQueryItem("q", name);
        query.addQueryItem("sort", "stars");
        query.addQueryItem("order", "desc");

        setIsSearching(true);
        m_reply = m_networkManager.get(QNetworkRequest(k_requestUrl + "?" + query.toString()));
        connect(m_reply, &QNetworkReply::finished, this, &RepSearch::parseData);

        qInfo() << m_reply;
    }
}

void RepSearch::parseData()
{
    if (m_reply->error() == QNetworkReply::NoError) {
        beginResetModel();

        qDeleteAll(m_repList);
        m_repList.clear();

        QByteArray data = m_reply->readAll();

        QJsonDocument jsonDocument = QJsonDocument::fromJson(data);

        QJsonArray results = jsonDocument["items"].toArray();

        //qInfo() << results;

        for (const auto &result : results) {
            QJsonObject entry = result.toObject();

            RepInfo *repInfo = new RepInfo(this);

            QJsonObject owner = entry["owner"].toObject();

            repInfo->setName(entry["name"].toString());
            repInfo->setAuthor(owner["login"].toString());
            repInfo->setDescription(entry["description"].toString());
            repInfo->setLanguage(entry["language"].toString());
            repInfo->setStars(entry["stargazers_count"].toInt());
            repInfo->setForks(entry["forks"].toInt());
            repInfo->setDate(entry["updated_at"].toString());

            //qInfo() << owner["login"].toString();
            m_repList << repInfo;

        }

        endResetModel();
    } else if (m_reply->error() != QNetworkReply::OperationCanceledError) {
        qCritical() << "Reply failed, eror:" << m_reply->errorString();
    }

    setIsSearching(false);
    m_reply->deleteLater();
    m_reply = nullptr;
}

bool RepSearch::isSearching() const
{
    return m_isSearching;
}

void RepSearch::setIsSearching(bool newIsSearching)
{
    if (m_isSearching == newIsSearching)
        return;
    m_isSearching = newIsSearching;
    emit isSearchingChanged();
}
