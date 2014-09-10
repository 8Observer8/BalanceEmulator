#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
#include <QMainWindow>
#include "Sender.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sendButton_clicked();
    void slotSetSettings( const Sender &sender );

    void on_actionSettings_triggered();

    void on_actionExit_triggered();

private:
    void sendData( const QString &text );

private:
    Ui::MainWindow *ui;
    Sender *m_sender;
    QTimer m_timer;
};

#endif // MAINWINDOW_H
