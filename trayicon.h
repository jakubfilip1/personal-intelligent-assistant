#ifndef TRAYICON_H
#define TRAYICON_H

#include <QSystemTrayIcon>
#include <QMenu>
#include <QApplication>

class TrayIcon : public QSystemTrayIcon
{
public:
    explicit TrayIcon(QIcon, QObject *parent = nullptr);
    ~TrayIcon();

protected:
    QMenu *contextMenu;

    void addContextMenu();
    void exit();
};

#endif // TRAYICON_H
