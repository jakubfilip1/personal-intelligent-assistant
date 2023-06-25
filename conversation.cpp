#include "conversation.h"

Conversation::Conversation()
{

}

MessageCollection Conversation::getMessages()
{
    QFile file("conversation.json");

    file.open(QIODevice::ReadOnly);

    QByteArray json = file.readAll();

    QJsonDocument doc = QJsonDocument::fromJson(json);

    MessageCollection messCol;

    for(QJsonValue val : doc.array())
    {
        MessageModel model(val.toObject().value("role").toString(), val.toObject().value("content").toString());

        messCol.add(model);
    }

    return messCol;
}

void Conversation::addMessage(MessageModel messageModel)
{
    MessageCollection messCol = this->getMessages();

    QJsonArray arr;

    for(MessageModel model : messCol.getMessages())
    {
        QJsonObject obj;
        obj["role"] = model.getRole();
        obj["content"] = model.getContent();
        arr.append(obj);
    }

    QJsonObject newMessage;
    newMessage["role"] = messageModel.getRole();
    newMessage["content"] = messageModel.getContent();

    arr.append(newMessage);

    QJsonDocument doc(arr);

    QFile file("conversation.json");

    file.open(QIODevice::WriteOnly);

    file.write(doc.toJson());

    file.close();
}
