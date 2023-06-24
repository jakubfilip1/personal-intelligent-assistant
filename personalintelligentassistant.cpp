#include "personalintelligentassistant.h"

PersonalIntelligentAssistant::PersonalIntelligentAssistant(QWidget *parent)
    : QMainWindow(parent)
{
    this->setAndroid();

    this->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->setWindowFlag(Qt::Tool);
    this->addTrayIcon();
    this->createChat();
}

PersonalIntelligentAssistant::~PersonalIntelligentAssistant()
{
    delete this->trayIcon;
    delete this->chat;
}

QSize PersonalIntelligentAssistant::getScreenSize()
{
    QScreen *screen = QApplication::primaryScreen();

    return screen->size();
}

int PersonalIntelligentAssistant::getAndroidHeight()
{
    QSize screenSize = this->getScreenSize();

    return screenSize.height() / 6;
}

QPoint PersonalIntelligentAssistant::getAndroidPosition(QSize androidSize)
{
    QSize screenSize = this->getScreenSize();

    int androidPositionX = screenSize.width() - androidSize.width() - (screenSize.width() / 20);
    int androidPositionY = screenSize.height() - androidSize.height() - (screenSize.height() / 10);

    return QPoint(androidPositionX, androidPositionY);
}

void PersonalIntelligentAssistant::setAndroid()
{
    QPixmap android("android.png");
    QPixmap scaledAndroid = android.scaledToHeight(this->getAndroidHeight());

    this->setFixedWidth(scaledAndroid.width());
    this->setFixedHeight(scaledAndroid.height());
    this->setMask(scaledAndroid.mask());

    QPalette background;
    background.setBrush(QPalette::Window, scaledAndroid);
    this->setPalette(background);

    QPoint androidPosition = this->getAndroidPosition(scaledAndroid.size());

    this->move(androidPosition.x(), androidPosition.y());
}

void PersonalIntelligentAssistant::addTrayIcon()
{
    QIcon android("android.png");
    this->trayIcon = new TrayIcon(android);
    this->trayIcon->show();
}

void PersonalIntelligentAssistant::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        this->openChat();
    }

    QMainWindow::mousePressEvent(event);
}

void PersonalIntelligentAssistant::openChat()
{
    if(this->chat->isVisible())
    {
        this->chat->hide();
    }
    else
    {
        this->chat->show();
    }
}

void PersonalIntelligentAssistant::createChat()
{
    this->chat = new Chat(this);
}
