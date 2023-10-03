#ifndef REPSEARCH_H
#define REPSEARCH_H

#include <QObject>
#include <QUrl>
#include <qqml.h>
#include <QAbstractListModel>
#include <QNetworkAccessManager>

class RepInfo;

class RepSearch : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool isSearching READ isSearching NOTIFY isSearchingChanged)

public:
    enum Role {
        RepNameRole,
        RepAuthorRole,
        RepDescriptionRole,
        RepLanguageRole,
        RepStarsRole,
        RepForksRole,
        RepDateRole
    };

    explicit RepSearch(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    bool isSearching() const;
    void setIsSearching(bool newIsSearching);

public slots:
    void searchRep(const QString &name);
    void parseData();

signals:
    void isSearchingChanged();

private:
    QList<RepInfo*> m_repList;
    QNetworkAccessManager m_networkManager;
    QNetworkReply *m_reply = nullptr;
    bool m_isSearching;
};

#endif // REPSEARCH_H
