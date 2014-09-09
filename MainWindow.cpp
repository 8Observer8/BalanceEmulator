
#include <QMessageBox>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SettingsDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_sender = new Sender;
}

MainWindow::~MainWindow()
{
    delete m_sender;
    delete ui;
}

void MainWindow::on_sendButton_clicked()
{
    QString text = ui->testValueLineEdit->text();
    sendData( text );
}

void MainWindow::slotSetSettings( const QString &portName,
                                  const QString &portSpeed )
{
    delete m_sender;

    QSerialPort::BaudRate convertedPortSpeed =
            static_cast<QSerialPort::BaudRate>( portSpeed.toInt() );

    m_sender = new Sender( portName, convertedPortSpeed );

    try {
        m_sender->open();
    } catch ( const PortError &e ) {
        QMessageBox::information( this, "Error", QString( e.what() ) );
    } catch ( ... ) {
        QMessageBox::information( this, "Error", "Error: unknown exception" );
    }
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog dialog;
    dialog.setModal( true );
    connect( &dialog, SIGNAL( signalSetSettings( QString, QString ) ),
             this, SLOT( slotSetSettings( QString, QString ) ) );
    dialog.exec();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::sendData(const QString &text)
{
    QByteArray data;
    data.append( text );
    try {
        m_sender->send( data );
    } catch ( const PortError &e ) {
        QMessageBox::information( this, "Error", QString( e.what() ) );
        return;
    } catch ( ... ) {
        QMessageBox::information( this, "Error", "Error: unknown exception" );
        return;
    }
}
