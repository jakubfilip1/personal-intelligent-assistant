#include "chat.h"

Chat::Chat(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowFlag(Qt::Tool);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::WindowStaysOnTopHint);

    this->setChatSize();
    this->setChatPosition();

    QVBoxLayout *centralLayout = new QVBoxLayout();

    QPushButton *trash = new QPushButton();
    trash->setText("Clear conversation");
    connect(trash, &QPushButton::clicked, this, &Chat::clearConversation);
    centralLayout->addWidget(trash);


    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    QWidget *scrollWidget = new QWidget();
    this->scrollWidgetLayout = new QVBoxLayout();
    this->scrollWidgetLayout->setAlignment(Qt::AlignTop);

    scrollWidget->setLayout(this->scrollWidgetLayout);

    scrollArea->setWidget(scrollWidget);
    centralLayout->addWidget(scrollArea);

    QWidget *form = new QWidget();
    QHBoxLayout *formLayout = new QHBoxLayout();
    QPushButton *sendButton = new QPushButton();

    this->connect(sendButton, &QPushButton::clicked, this, &Chat::sendMessage);

    this->messageText = new QLineEdit();

    sendButton->setText("Send");
    formLayout->addWidget(this->messageText);
    formLayout->addWidget(sendButton);

    form->setLayout(formLayout);

    centralLayout->addWidget(form);

    this->setLayout(centralLayout);

    Conversation conv;

    for(MessageModel model : conv.getMessages().getMessages())
    {
        this->addMessage(model);
    }
}

void Chat::sendMessage()
{
    APIOpenAI *api = new APIOpenAI();

    QString newMessage = this->messageText->text();
    this->messageText->clear();

    MessageModel messageModel("user", newMessage);
    this->addMessage(messageModel);

    Conversation conv;

    api->sendMessages(conv.getMessages());

    this->connect(api, &APIOpenAI::messageReceived, this, &Chat::messageReceived);
}

void Chat::messageReceived(MessageCollection mc)
{
    this->addMessage(mc.getMessages().last());
}

void Chat::textChanged(QTextEdit *newMessageWidget)
{
    newMessageWidget->setFixedHeight(newMessageWidget->document()->documentLayout()->documentSize().height() + newMessageWidget->contentsMargins().top() + newMessageWidget->contentsMargins().bottom());
}

void Chat::setChatSize()
{
    QWidget *personalIntelligentAssistant = dynamic_cast<QWidget*>(this->parent());

    this->setFixedHeight(personalIntelligentAssistant->height() + 500);
    this->setFixedWidth(personalIntelligentAssistant->width() + 300);
}

void Chat::setChatPosition()
{
    QWidget *personalIntelligentAssistant = dynamic_cast<QWidget*>(this->parent());

    this->move(personalIntelligentAssistant->x() - this->width() + personalIntelligentAssistant->width(), personalIntelligentAssistant->y() - this->height());
}

void Chat::addMessage(MessageModel messageModel)
{
    QTextEdit * newMessageWidget = new QTextEdit();

    this->connect(newMessageWidget->document()->documentLayout(), &QAbstractTextDocumentLayout::documentSizeChanged, [this, newMessageWidget]() {this->textChanged(newMessageWidget);});
    newMessageWidget->setReadOnly(true);
    newMessageWidget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    newMessageWidget->setText(messageModel.getContent());

    Conversation conv;
    conv.addMessage(messageModel);

    this->scrollWidgetLayout->addWidget(newMessageWidget);
    this->scrollWidgetLayout->invalidate();
}

void Chat::clearConversation()
{
    QLayoutItem *item;

    while((item = this->scrollWidgetLayout->takeAt(0)) != nullptr)
    {
        QWidget *widget;

        if(widget = item->widget())
        {
            this->scrollWidgetLayout->removeWidget(widget);

            delete widget;
        }
        else
        {
            this->scrollWidgetLayout->removeItem(item);
            delete item;
        }
    }

    Conversation conv;
    conv.removeMessages();

    this->scrollWidgetLayout->invalidate();
}
