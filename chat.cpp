#include "chat.h"

Chat::Chat(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowFlag(Qt::Tool);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::WindowStaysOnTopHint);

    QWidget *personalIntelligentAssistant = dynamic_cast<QWidget*>(this->parent());

    this->setFixedHeight(personalIntelligentAssistant->height() + 500);
    this->setFixedWidth(personalIntelligentAssistant->width() + 300);

    this->move(personalIntelligentAssistant->x() - this->width() + personalIntelligentAssistant->width(), personalIntelligentAssistant->y() - this->height());

}
