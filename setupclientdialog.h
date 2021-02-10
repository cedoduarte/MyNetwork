#ifndef SETUPCLIENTDIALOG_H
#define SETUPCLIENTDIALOG_H

#include <QDialog>

namespace Ui
{
class SetupClientDialog;
}

/** setup client dialog */
class SetupClientDialog : public QDialog
{
    Q_OBJECT
public:
    /** execute dialog */
    static void execDialog(int clientId, QWidget *parent = nullptr);
private slots:
    /** accept dialog */
    void on_buttonBox_accepted();

    /** reject dialog */
    void on_buttonBox_rejected();
private:
    /** constructor */
    explicit SetupClientDialog(int clientId, QWidget *parent = nullptr);

    /** destructor */
    virtual ~SetupClientDialog();

    Ui::SetupClientDialog *ui; //!< gui
    int m_clientId; //!< client id
};

#endif // SETUPCLIENTDIALOG_H
