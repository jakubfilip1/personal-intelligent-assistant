#ifndef APIOPENAI_H
#define APIOPENAI_H

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "messagecollection.h"

class APIOpenAI : public QObject
{
    Q_OBJECT
public:
    APIOpenAI();
    void sendMessages(MessageCollection);
    void request(QString, void (APIOpenAI::*)(), QString, QByteArray);

signals:
    void messageReceived(MessageCollection &);

protected:
    QString url;
    void onCompletionsRequestFinished();

};

#endif // APIOPENAI_H
