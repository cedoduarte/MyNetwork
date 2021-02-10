#include "myenums.h"
#include "mydatabasemanager.h"
#include "setupserverdialog.h"
#include "ui_setupserverdialog.h"

SetupServerDialog::SetupServerDialog(int serverId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SetupServerDialog)
{
    ui->setupUi(this);
    m_serverId = serverId;
    ui->port_lineEdit->setText(QString::number(MyDatabaseManager::getServerPort(m_serverId)));
}

SetupServerDialog::~SetupServerDialog()
{
    delete ui;
}

void SetupServerDialog::execDialog(int serverId, QWidget *parent)
{
    SetupServerDialog d(serverId, parent);
    d.exec();
}

void SetupServerDialog::on_buttonBox_accepted()
{
    MyDatabaseManager::setServerPort(m_serverId, ui->port_lineEdit->text());
    MyDatabaseManager::updateModel(mynet::Server);
    accept();
}

void SetupServerDialog::on_buttonBox_rejected()
{
    reject();
}
