#include "Sender.h"

Sender::Sender( const QString &portName,
                QSerialPort::BaudRate baudRate,
                QSerialPort::DataBits dataBits,
                QSerialPort::Parity parity,
                QSerialPort::StopBits stopBits,
                QSerialPort::FlowControl flowControl ) :
    m_portName( portName ),
    m_baudRate( baudRate ),
    m_dataBits( dataBits ),
    m_parity( parity ),
    m_stopBits( stopBits ),
    m_flowControl( flowControl )
{
}

Sender::Sender(const Sender &sender)
{
    this->m_portName = sender.getPortName();
    this->m_baudRate = sender.getBaudRate();
    this->m_dataBits = sender.getDataBist();
    this->m_parity = sender.getParity();
    this->m_stopBits = sender.getStopBits();
    this->m_flowControl = sender.getFlowControl();
}

Sender::~Sender()
{
    m_serialPort.close();
}

QString Sender::getPortName() const
{
    return m_portName;
}

QSerialPort::BaudRate Sender::getBaudRate() const
{
    return m_baudRate;
}

QSerialPort::DataBits Sender::getDataBist() const
{
    return m_dataBits;
}

QSerialPort::Parity Sender::getParity() const
{
    return m_parity;
}

QSerialPort::StopBits Sender::getStopBits() const
{
    return m_stopBits;
}

QSerialPort::FlowControl Sender::getFlowControl() const
{
    return m_flowControl;
}

void Sender::open() throw( PortError )
{
    m_serialPort.setPortName( m_portName );

    // Open the port
    if ( !m_serialPort.open( QIODevice::WriteOnly ) ) {
        throw PortError( "Error: unable to open the port \"" +
                         m_serialPort.portName().toStdString() + "\"" );
    }

    m_serialPort.setBaudRate( m_baudRate );
    m_serialPort.setDataBits( m_dataBits );
    m_serialPort.setParity( m_parity );
    m_serialPort.setStopBits( m_stopBits );
    m_serialPort.setFlowControl( m_flowControl );
}

void Sender::send( const QByteArray &data ) throw( PortError )
{
    if ( !m_serialPort.isOpen() ) {
        throw PortError( "Error: unable to send to the port \"" +
                         m_serialPort.portName().toStdString() + "\""
                         " because it is not opened");
    }

    // Write data to the port
    if ( m_serialPort.write( data ) == -1 ) {
        throw PortError( "Error: unable to send to the port \"" +
                         m_serialPort.portName().toStdString() + "\"" );
    }
}
