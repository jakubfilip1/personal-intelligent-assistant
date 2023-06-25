#include "apiopenai.h"

APIOpenAI::APIOpenAI()
{
    this->url = "api.openai.com/v1";
}

void APIOpenAI::request(QString endpoint, void (APIOpenAI::*slot)(), QString method, QByteArray data = NULL)
{
    QUrl url("https://" + this->url + endpoint);

    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QNetworkRequest request(url);
    request.setRawHeader("Authorization", "Bearer ");
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply *response;

    if(method == "POST")
    {
        response = manager->post(request, data);
    }
    else
    {
        response = manager->get(request);
    }

    this->connect(response, &QNetworkReply::finished, this, slot);
}

void APIOpenAI::sendMessages(MessageCollection messageCollection)
{
    QJsonArray messages;

    for(MessageModel messageModel : messageCollection.getMessages())
    {
        QJsonObject message;
        message["role"] = messageModel.getRole();
        message["content"] = messageModel.getContent();

        messages.append(message);
    }

    QJsonObject data;
    data["model"] = "gpt-3.5-turbo";
    data["messages"] = messages;

    QJsonDocument document(data);

    this->request("/chat/completions", &APIOpenAI::onCompletionsRequestFinished, "POST", document.toJson());
}


void APIOpenAI::onCompletionsRequestFinished()
{
    QNetworkReply *response = qobject_cast<QNetworkReply*>(sender());

    QJsonDocument document = QJsonDocument::fromJson(response->readAll());

    QJsonArray choices = document.object().value("choices").toArray();

    MessageCollection messageCollection;

    for(QJsonValue choice : choices)
    {
        MessageModel messageModel(choice.toObject().value("message").toObject().value("role").toString(), choice.toObject().value("message").toObject().value("content").toString());
        messageCollection.add(messageModel);
    }

    emit this->messageReceived(messageCollection);
}
