#ifndef MYCLIENTS_H
#define MYCLIENTS_H

#include <QObject>

class MyClient;
class MainWindow;

/** clients */
class MyClients : public QObject
{
    Q_OBJECT
public:
    /** constructor */
    explicit MyClients(QObject *parent = nullptr);

    /** destructor */
    virtual ~MyClients();

    /** get client */
    MyClient *get(int clientId) const;

    /** set window */
    void setMainWindow(MainWindow *w);

    /** turn on/off */
    void turnOnOff(int clientId);
private slots:
    /** client turned on */
    void onClient1TurnedOnChanged(bool turnedOn);
    void onClient2TurnedOnChanged(bool turnedOn);
    void onClient3TurnedOnChanged(bool turnedOn);
    void onClient4TurnedOnChanged(bool turnedOn);
private:
    /** connect slots */
    void connectSlots();

    /** initialize */
    void init();

    MainWindow *m_w; //!< window

    /** clients */
    MyClient *m_client1;
    MyClient *m_client2;
    MyClient *m_client3;
    MyClient *m_client4;
};

#endif // MYCLIENTS_H
