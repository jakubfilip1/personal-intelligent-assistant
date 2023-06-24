#include "messagecollection.h"

MessageCollection::MessageCollection()
{

}

void MessageCollection::add(MessageModel messageModel)
{
    this->messages.append(messageModel);
}

QList<MessageModel> MessageCollection::getMessages()
{
    return this->messages;
}
