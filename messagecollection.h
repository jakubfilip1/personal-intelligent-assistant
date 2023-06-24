#ifndef MESSAGECOLLECTION_H
#define MESSAGECOLLECTION_H

#include <QList>

#include "messagemodel.h"


class MessageCollection
{
public:
    MessageCollection();
    void add(MessageModel);
    QList<MessageModel> getMessages();

protected:
    QList<MessageModel> messages;
};

#endif // MESSAGECOLLECTION_H
