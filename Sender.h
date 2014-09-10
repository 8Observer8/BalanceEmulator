#ifndef SENDER_H
#define SENDER_H

#include <QSerialPort>
#include <QString>
#include "PortError.h"

class Sender
{
public:
    Sender( const QString &portName = QString( "COM1" ),
            QSerialPort::BaudRate baudRate = QSerialPort::Baud9600,
            QSerialPort::DataBits dataBits = QSerialPort::Data8,
            QSerialPort::Parity parity = QSerialPort::NoParity,
            QSerialPort::StopBits stopBits = QSerialPort::OneStop,
            QSerialPort::FlowControl flowControl = QSerialPort::NoFlowControl );

    Sender( const Sender &sender );

    ~Sender();

    QString getPortName() const;
    QSerialPort::BaudRate getBaudRate() const;
    QSerialPort::DataBits getDataBist() const;
    QSerialPort::Parity getParity() const;
    QSerialPort::StopBits getStopBits() const;
    QSerialPort::FlowControl getFlowControl() const;

    void setPortName( const QString &portName )
    {
        m_portName = portName;
    }

    void open() throw( PortError );

    void send( const QByteArray &data ) throw( PortError );

private:
    QSerialPort m_serialPort;
    QString m_portName;
    QSerialPort::BaudRate m_baudRate;
    QSerialPort::DataBits m_dataBits;
    QSerialPort::Parity m_parity;
    QSerialPort::StopBits m_stopBits;
    QSerialPort::FlowControl m_flowControl;
};

#endif // SENDER_H
