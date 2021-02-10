#include "myenums.h"
#include "myclient.h"
#include "myclients.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydatabasemanager.h"

MyClients::MyClients(QObject *parent)
    : QObject(parent)
{
    init();
}

MyClients::~MyClients()
{
    // nothing to do here
}

void MyClients::init()
{
    m_w = nullptr;
    m_client1 = new MyClient(this);
    m_client2 = new MyClient(this);
    m_client3 = new MyClient(this);
    m_client4 = new MyClient(this);
}

MyClient *MyClients::get(int clientId) const
{
    switch (clientId)
    {
        case mynet::Client1:
        {
            return m_client1;
        }
        case mynet::Client2:
        {
            return m_client2;
        }
        case mynet::Client3:
        {
            return m_client3;
        }
        case mynet::Client4:
        {
            return m_client4;
        }
    }
    return nullptr;
}

void MyClients::setMainWindow(MainWindow *w)
{
    m_w = w;
    connectSlots();
}

void MyClients::turnOnOff(int clientId)
{
    get(clientId)->turnOnOff(MyDatabaseManager::getWhichServerIsClientConnected(clientId),
                             MyDatabaseManager::getClientPort(clientId));
}

void MyClients::onClient1TurnedOnChanged(bool turnedOn)
{
    if (turnedOn)
    {
        m_w->ui->startClient1_button->setText("Turn Off");
        m_w->ui->startClient1_button->setIcon(QIcon(":/img/stop.png"));
    }
    else
    {
        m_w->ui->startClient1_button->setText("Turn On");
        m_w->ui->startClient1_button->setIcon(QIcon(":/img/run.png"));
    }
}

void MyClients::onClient2TurnedOnChanged(bool turnedOn)
{
    if (turnedOn)
    {
        m_w->ui->startClient2_button->setText("Turn Off");
        m_w->ui->startClient2_button->setIcon(QIcon(":/img/stop.png"));
    }
    else
    {
        m_w->ui->startClient2_button->setText("Turn On");
        m_w->ui->startClient2_button->setIcon(QIcon(":/img/run.png"));
    }
}

void MyClients::onClient3TurnedOnChanged(bool turnedOn)
{
    if (turnedOn)
    {
        m_w->ui->startClient3_button->setText("Turn Off");
        m_w->ui->startClient3_button->setIcon(QIcon(":/img/stop.png"));
    }
    else
    {
        m_w->ui->startClient3_button->setText("Turn On");
        m_w->ui->startClient3_button->setIcon(QIcon(":/img/run.png"));
    }
}

void MyClients::onClient4TurnedOnChanged(bool turnedOn)
{
    if (turnedOn)
    {
        m_w->ui->startClient4_button->setText("Turn Off");
        m_w->ui->startClient4_button->setIcon(QIcon(":/img/stop.png"));
    }
    else
    {
        m_w->ui->startClient4_button->setText("Turn On");
        m_w->ui->startClient4_button->setIcon(QIcon(":/img/run.png"));
    }
}

void MyClients::connectSlots()
{
    connect(m_client1, &MyClient::turnedOnChanged, this, &MyClients::onClient1TurnedOnChanged);
    connect(m_client2, &MyClient::turnedOnChanged, this, &MyClients::onClient2TurnedOnChanged);
    connect(m_client3, &MyClient::turnedOnChanged, this, &MyClients::onClient3TurnedOnChanged);
    connect(m_client4, &MyClient::turnedOnChanged, this, &MyClients::onClient4TurnedOnChanged);
}
