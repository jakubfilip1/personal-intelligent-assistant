#ifndef PERSONALINTELLIGENTASSISTANT_H
#define PERSONALINTELLIGENTASSISTANT_H

#include <QMainWindow>
#include <QScreen>
#include <QApplication>
#include <QSystemTrayIcon>

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
    QSystemTrayIcon *trayIcon;

    void setAndroid();
    QSize getScreenSize();
    int getAndroidHeight();
    QPoint getAndroidPosition(QSize);
    void addTrayIcon();
};
#endif // PERSONALINTELLIGENTASSISTANT_H
