#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include <QString>

class MessageModel
{
public:
    MessageModel(QString, QString);

    QString getRole();
    QString getContent();

protected:
    QString role;
    QString content;
};

#endif // MESSAGEMODEL_H
