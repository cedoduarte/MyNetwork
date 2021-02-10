#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

/** tcp server */
class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    /** constructor */
    explicit MyServer(QObject *parent = nullptr);

    /** destructor */
    virtual ~MyServer();

    /** turn on/off */
    void turnOnOff(int port);

    /** turn on */
    void turnOn(int port);

    /** turn off */
    void turnOff();

    /** is turned on? */
    bool isTurnedOn() const
    {
        return m_turnedOn;
    }

    /** is turned off? */
    bool isTurnedOff() const
    {
        return !m_turnedOn;
    }
signals:
    /** turned on changed */
    void turnedOnChanged(bool turnedOn);
protected:
    /** new connection */
    void incomingConnection(qintptr handle) override;
private:
    /** set turned on */
    void setTurnedOn(bool turnedOn);

    QTcpSocket *m_client; //!< client socket
    bool m_turnedOn; //!< turned on
};

#endif // MYSERVER_H
