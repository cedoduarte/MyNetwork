#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QTcpSocket>

/** tcp client socket */
class MyClient : public QTcpSocket
{
    Q_OBJECT
public:
    /** constructor */
    explicit MyClient(QObject *parent = nullptr);

    /** destructor */
    virtual ~MyClient();

    /** turn on/off */
    void turnOnOff(const QString &ip, int port);

    /** turn on */
    void turnOn(const QString &ip, int port);

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
private slots:
    /** ready read */
    void onReadyRead();
private:
    /** set turned on */
    void setTurnedOn(bool turnedOn);

    bool m_turnedOn; //!< turned on
};

#endif // MYCLIENT_H
