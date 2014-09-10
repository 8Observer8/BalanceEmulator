
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

void MainWindow::slotSetSettings( const Sender &sender )
{
    delete m_sender;

    m_sender = new Sender( sender );

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
    connect( &dialog, SIGNAL( signalSetSettings( Sender ) ),
             this, SLOT( slotSetSettings( Sender ) ) );
    dialog.exec();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::sendData( const QString &text )
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
