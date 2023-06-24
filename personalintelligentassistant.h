#ifndef PERSONALINTELLIGENTASSISTANT_H
#define PERSONALINTELLIGENTASSISTANT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PersonalIntelligentAssistant; }
QT_END_NAMESPACE

class PersonalIntelligentAssistant : public QMainWindow
{
    Q_OBJECT

public:
    PersonalIntelligentAssistant(QWidget *parent = nullptr);
    ~PersonalIntelligentAssistant();

private:
    Ui::PersonalIntelligentAssistant *ui;
};
#endif // PERSONALINTELLIGENTASSISTANT_H
