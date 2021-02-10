#include "myserver.h"
#include <QDebug>

MyServer::MyServer(QObject *parent)
    : QTcpServer(parent)
{
    m_client = nullptr;
    m_turnedOn = false;
}

MyServer::~MyServer()
{
    delete m_client;
}

void MyServer::turnOnOff(int port)
{
    if (isTurnedOn())
        turnOff();
    else
        turnOn(port);
}

void MyServer::turnOn(int port)
{
    setTurnedOn(listen(QHostAddress::Any, port));
}

void MyServer::turnOff()
{
    if (m_client)
    {
        if (m_client->state() != QAbstractSocket::UnconnectedState)
        {
            m_client->write(QString("bye").toLatin1());
            m_client->waitForBytesWritten();
            delete m_client;
            m_client = nullptr;
        }
    }
    close();
    setTurnedOn(false);
}

void MyServer::incomingConnection(qintptr handle)
{
    if (m_client)
    {
        delete m_client;
        m_client = new QTcpSocket;
        m_client->setSocketDescriptor(handle);
    }
    else
    {
        m_client = new QTcpSocket;
        m_client->setSocketDescriptor(handle);
    }
}

void MyServer::setTurnedOn(bool turnedOn)
{
    if (m_turnedOn != turnedOn)
    {
        m_turnedOn = turnedOn;
        emit turnedOnChanged(m_turnedOn);
    }
}
