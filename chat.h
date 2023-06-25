#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QTextBlock>
#include <QTextBrowser>

#include "apiopenai.h"
#include "conversation.h"

class Chat : public QWidget
{
    Q_OBJECT
public:
    explicit Chat(QWidget *parent = nullptr);

protected:
    QLineEdit *messageText;
    QVBoxLayout *scrollWidgetLayout;

    void sendMessage();
    void messageReceived(MessageCollection);
    void textChanged(QTextEdit*);

signals:

};

#endif // CHAT_H
