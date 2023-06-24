#include "trayicon.h"

TrayIcon::TrayIcon(QIcon icon, QObject *parent)
    : QSystemTrayIcon{icon, parent}
{
    this->addContextMenu();
}

TrayIcon::~TrayIcon()
{
    delete contextMenu;
}

void TrayIcon::addContextMenu()
{
    this->contextMenu = new QMenu();

    QAction *exit = new QAction("Exit");
    this->contextMenu->addAction(exit);

    this->connect(exit, &QAction::triggered, this, &TrayIcon::exit);

    this->setContextMenu(this->contextMenu);
}

void TrayIcon::exit()
{
    QApplication::exit();
}
