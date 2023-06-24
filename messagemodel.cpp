#include "messagemodel.h"

MessageModel::MessageModel(QString role, QString content)
{
    this->role = role;
    this->content = content;
}

QString MessageModel::getRole()
{
    return this->role;
}

QString MessageModel::getContent()
{
    return this->content;
}
