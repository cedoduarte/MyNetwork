#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MyServers;
class MyClients;

namespace Ui
{
class MainWindow;
}

/** mainwindow */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    /* friend classes */
    friend class MyServers;
    friend class MyClients;
public:
    /** constructor */
    explicit MainWindow(QWidget *parent = nullptr);

    /** destructor */
    virtual ~MainWindow();
private slots:
    /** close window */
    void on_actionClose_triggered();

    /** start server */
    void on_startServer1_button_clicked();
    void on_startServer2_button_clicked();
    void on_startServer3_button_clicked();
    void on_startServer4_button_clicked();

    /** start client */
    void on_startClient1_button_clicked();
    void on_startClient2_button_clicked();
    void on_startClient3_button_clicked();
    void on_startClient4_button_clicked();

    /** setup server */
    void on_setupServer1_button_clicked();
    void on_setupServer2_button_clicked();
    void on_setupServer3_button_clicked();
    void on_setupServer4_button_clicked();

    /** setup client */
    void on_setupClient1_button_clicked();
    void on_setupClient2_button_clicked();
    void on_setupClient3_button_clicked();
    void on_setupClient4_button_clicked();
private:
    /** initialize */
    void init();

    Ui::MainWindow *ui; //!< gui
    MyServers *m_servers; //!< servers
    MyClients *m_clients; //!< clients
};

#endif // MAINWINDOW_H
