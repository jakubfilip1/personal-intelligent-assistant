#include "personalintelligentassistant.h"
#include "./ui_personalintelligentassistant.h"

PersonalIntelligentAssistant::PersonalIntelligentAssistant(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PersonalIntelligentAssistant)
{
    ui->setupUi(this);
}

PersonalIntelligentAssistant::~PersonalIntelligentAssistant()
{
    delete ui;
}

