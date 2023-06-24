#ifndef PERSONALINTELLIGENTASSISTANT_H
#define PERSONALINTELLIGENTASSISTANT_H

#include <QMainWindow>
#include <QScreen>
#include <QApplication>
#include <QSystemTrayIcon>
#include <QMouseEvent>

#include "chat.h"
#include "trayicon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PersonalIntelligentAssistant; }
QT_END_NAMESPACE

class PersonalIntelligentAssistant : public QMainWindow
{
    Q_OBJECT

public:
    PersonalIntelligentAssistant(QWidget *parent = nullptr);
    ~PersonalIntelligentAssistant();

protected:
    TrayIcon *trayIcon;
    Chat *chat;

    void setAndroid();
    QSize getScreenSize();
    int getAndroidHeight();
    QPoint getAndroidPosition(QSize);
    void addTrayIcon();
    void openChat();
    void mousePressEvent(QMouseEvent *) override;
    void createChat();
};
#endif // PERSONALINTELLIGENTASSISTANT_H
