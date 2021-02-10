#ifndef SETUPSERVERDIALOG_H
#define SETUPSERVERDIALOG_H

#include <QDialog>

namespace Ui
{
class SetupServerDialog;
}

/** setup server dialog */
class SetupServerDialog : public QDialog
{
    Q_OBJECT
public:
    /** executes dialog */
    static void execDialog(int serverId, QWidget *parent = nullptr);
private slots:
    /** accept dialog */
    void on_buttonBox_accepted();

    /** reject dialog */
    void on_buttonBox_rejected();
private:
    /** constructor */
    explicit SetupServerDialog(int serverId, QWidget *parent = nullptr);

    /** destructor */
    virtual ~SetupServerDialog();

    Ui::SetupServerDialog *ui; //!< gui
    int m_serverId; //!< server id
};

#endif // SETUPSERVERDIALOG_H
