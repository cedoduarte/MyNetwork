#include "myclient.h"
#include <QDebug>

MyClient::MyClient(QObject *parent)
    : QTcpSocket(parent)
{
    connect(this, &MyClient::readyRead, this, &MyClient::onReadyRead);
}

MyClient::~MyClient()
{
    // nothing to do here
}

void MyClient::turnOnOff(const QString &ip, int port)
{
    if (isTurnedOn())
        turnOff();
    else
        turnOn(ip, port);
}

void MyClient::turnOn(const QString &ip, int port)
{
    connectToHost(ip, port);
    setTurnedOn(waitForConnected());
}

void MyClient::turnOff()
{
    disconnectFromHost();
    if (state() == QAbstractSocket::UnconnectedState)
    {
        setTurnedOn(false);
        return;
    }
    if (waitForDisconnected())
    {
        setTurnedOn(false);
        return;
    }
    setTurnedOn(true);
}

void MyClient::onReadyRead()
{
    QByteArray data = read(bytesAvailable());
    QString str = QString::fromLatin1(data);
    if (str == "bye")
        turnOff();
}

void MyClient::setTurnedOn(bool turnedOn)
{
    if (m_turnedOn != turnedOn)
    {
        m_turnedOn = turnedOn;
        emit turnedOnChanged(m_turnedOn);
    }
}
