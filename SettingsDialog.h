#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "Sender.h"

namespace Ui {
    class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

signals:
    void signalSetSettings( const Sender &sender );

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
