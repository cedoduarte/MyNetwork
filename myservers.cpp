#include "myenums.h"
#include "myserver.h"
#include "myservers.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydatabasemanager.h"

MyServers::MyServers(QObject *parent)
    : QObject(parent)
{
    init();
}

MyServers::~MyServers()
{
    // nothing to do here
}

void MyServers::init()
{
    m_w = nullptr;
    m_server1 = new MyServer(this);
    m_server2 = new MyServer(this);
    m_server3 = new MyServer(this);
    m_server4 = new MyServer(this);
}

MyServer *MyServers::get(int serverId) const
{
    switch (serverId)
    {
        case mynet::Server1:
        {
            return m_server1;
        }
        case mynet::Server2:
        {
            return m_server2;
        }
        case mynet::Server3:
        {
            return m_server3;
        }
        case mynet::Server4:
        {
            return m_server4;
        }
    }
    return nullptr;
}

void MyServers::setMainWindow(MainWindow *w)
{
    m_w = w;
    connectSlots();
}

void MyServers::turnOnOff(int serverId)
{
    get(serverId)->turnOnOff(MyDatabaseManager::getServerPort(serverId));
}

void MyServers::onServer1TurnedOnChanged(bool turnedOn)
{
    if (turnedOn)
    {
        m_w->ui->startServer1_button->setText("Turn Off");
        m_w->ui->startServer1_button->setIcon(QIcon(":/img/stop.png"));
    }
    else
    {
        m_w->ui->startServer1_button->setText("Turn On");
        m_w->ui->startServer1_button->setIcon(QIcon(":/img/run.png"));
    }
}

void MyServers::onServer2TurnedOnChanged(bool turnedOn)
{
    if (turnedOn)
    {
        m_w->ui->startServer2_button->setText("Turn Off");
        m_w->ui->startServer2_button->setIcon(QIcon(":/img/stop.png"));
    }
    else
    {
        m_w->ui->startServer2_button->setText("Turn On");
        m_w->ui->startServer2_button->setIcon(QIcon(":/img/run.png"));
    }
}

void MyServers::onServer3TurnedOnChanged(bool turnedOn)
{
    if (turnedOn)
    {
        m_w->ui->startServer3_button->setText("Turn Off");
        m_w->ui->startServer3_button->setIcon(QIcon(":/img/stop.png"));
    }
    else
    {
        m_w->ui->startServer3_button->setText("Turn On");
        m_w->ui->startServer3_button->setIcon(QIcon(":/img/run.png"));
    }
}

void MyServers::onServer4TurnedOnChanged(bool turnedOn)
{
    if (turnedOn)
    {
        m_w->ui->startServer4_button->setText("Turn Off");
        m_w->ui->startServer4_button->setIcon(QIcon(":/img/stop.png"));
    }
    else
    {
        m_w->ui->startServer4_button->setText("Turn On");
        m_w->ui->startServer4_button->setIcon(QIcon(":/img/run.png"));
    }
}

void MyServers::connectSlots()
{
    connect(m_server1, &MyServer::turnedOnChanged, this, &MyServers::onServer1TurnedOnChanged);
    connect(m_server2, &MyServer::turnedOnChanged, this, &MyServers::onServer2TurnedOnChanged);
    connect(m_server3, &MyServer::turnedOnChanged, this, &MyServers::onServer3TurnedOnChanged);
    connect(m_server4, &MyServer::turnedOnChanged, this, &MyServers::onServer4TurnedOnChanged);
}
