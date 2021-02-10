#ifndef MYSERVERS_H
#define MYSERVERS_H

#include <QObject>

class MyServer;
class MainWindow;

/** servers */
class MyServers : public QObject
{
    Q_OBJECT
public:
    /** constructor */
    explicit MyServers(QObject *parent = nullptr);

    /** destructor */
    virtual ~MyServers();

    /** get server */
    MyServer *get(int serverId) const;

    /** set window */
    void setMainWindow(MainWindow *w);

    /** turn on/off */
    void turnOnOff(int serverId);
private slots:
    /** server turned on */
    void onServer1TurnedOnChanged(bool turnedOn);
    void onServer2TurnedOnChanged(bool turnedOn);
    void onServer3TurnedOnChanged(bool turnedOn);
    void onServer4TurnedOnChanged(bool turnedOn);
private:
    /** connect slots */
    void connectSlots();

    /** initialize */
    void init();

    MainWindow *m_w; //!< window

    /** servers */
    MyServer *m_server1;
    MyServer *m_server2;
    MyServer *m_server3;
    MyServer *m_server4;
};

#endif // MYSERVERS_H
