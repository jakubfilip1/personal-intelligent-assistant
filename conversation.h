#ifndef CONVERSATION_H
#define CONVERSATION_H

#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "messagecollection.h"
#include "messagemodel.h"

class Conversation
{
public:
    Conversation();
    MessageCollection getMessages();
    void addMessage(MessageModel);
    void removeMessages();

};

#endif // CONVERSATION_H
