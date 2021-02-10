#include "myenums.h"
#include "myservers.h"
#include "myclients.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydatabasemanager.h"
#include "setupserverdialog.h"
#include "setupclientdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    MyDatabaseManager::initialize();
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
    MyDatabaseManager::release();
}

void MainWindow::init()
{
    m_servers = new MyServers(this);
    m_clients = new MyClients(this);
    m_servers->setMainWindow(this);
    m_clients->setMainWindow(this);
    ui->server_tableView->setModel(MyDatabaseManager::getNewModel("server", this));
    ui->client_tableView->setModel(MyDatabaseManager::getNewModel("client", this));
}

void MainWindow::on_startServer1_button_clicked()
{
    m_servers->turnOnOff(mynet::Server1);
}

void MainWindow::on_startServer2_button_clicked()
{
    m_servers->turnOnOff(mynet::Server2);
}

void MainWindow::on_startServer3_button_clicked()
{
    m_servers->turnOnOff(mynet::Server3);
}

void MainWindow::on_startServer4_button_clicked()
{
    m_servers->turnOnOff(mynet::Server4);
}

void MainWindow::on_startClient1_button_clicked()
{
    m_clients->turnOnOff(mynet::Client1);
}

void MainWindow::on_startClient2_button_clicked()
{
    m_clients->turnOnOff(mynet::Client2);
}

void MainWindow::on_startClient3_button_clicked()
{
    m_clients->turnOnOff(mynet::Client3);
}

void MainWindow::on_startClient4_button_clicked()
{
    m_clients->turnOnOff(mynet::Client4);
}

void MainWindow::on_setupServer1_button_clicked()
{
    SetupServerDialog::execDialog(mynet::Server1, this);
}

void MainWindow::on_setupServer2_button_clicked()
{
    SetupServerDialog::execDialog(mynet::Server2, this);
}

void MainWindow::on_setupServer3_button_clicked()
{
    SetupServerDialog::execDialog(mynet::Server3, this);
}

void MainWindow::on_setupServer4_button_clicked()
{
    SetupServerDialog::execDialog(mynet::Server4, this);
}

void MainWindow::on_setupClient1_button_clicked()
{
    SetupClientDialog::execDialog(mynet::Client1, this);
}

void MainWindow::on_setupClient2_button_clicked()
{
    SetupClientDialog::execDialog(mynet::Client2, this);
}

void MainWindow::on_setupClient3_button_clicked()
{
    SetupClientDialog::execDialog(mynet::Client3, this);
}

void MainWindow::on_setupClient4_button_clicked()
{
    SetupClientDialog::execDialog(mynet::Client4, this);
}

void MainWindow::on_actionClose_triggered()
{
    close();
}
