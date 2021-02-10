#include "myenums.h"
#include "mydatabasemanager.h"
#include "setupclientdialog.h"
#include "ui_setupclientdialog.h"

SetupClientDialog::SetupClientDialog(int clientId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SetupClientDialog)
{
    ui->setupUi(this);
    m_clientId = clientId;
    ui->port_lineEdit->setText(QString::number(MyDatabaseManager::getClientPort(m_clientId)));
    ui->serverIp_lineEdit->setText(MyDatabaseManager::getWhichServerIsClientConnected(m_clientId));
}

SetupClientDialog::~SetupClientDialog()
{
    delete ui;
}

void SetupClientDialog::execDialog(int clientId, QWidget *parent)
{
    SetupClientDialog d(clientId, parent);
    d.exec();
}

void SetupClientDialog::on_buttonBox_accepted()
{
    MyDatabaseManager::setClientPort(m_clientId, ui->port_lineEdit->text());
    MyDatabaseManager::setWhichServerIsClientConnected(m_clientId, ui->serverIp_lineEdit->text());
    MyDatabaseManager::updateModel(mynet::Client);
    accept();
}

void SetupClientDialog::on_buttonBox_rejected()
{
    reject();
}
