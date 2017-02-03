#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arduino_is_avaliable = false;
    arduino_port_name = "";
    serialBuffer = "";

    arduino = new QSerialPort;

    qDebug() << "Number of avaliable ports: "<<QSerialPortInfo::availablePorts().length();
    foreach (const QSerialPortInfo &serialPortInfdo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Has vendor ID: " << serialPortInfdo.hasVendorIdentifier();
        if(serialPortInfdo.hasVendorIdentifier()){
            qDebug()<< "Vendor ID: " << serialPortInfdo.vendorIdentifier();
        }
        qDebug() << "Has product ID: " << serialPortInfdo.hasProductIdentifier();
        if(serialPortInfdo.hasProductIdentifier()){
            qDebug()<< "Product ID: " << serialPortInfdo.productIdentifier();
        }
    }

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if(info.hasVendorIdentifier() && info.hasProductIdentifier()){
            if(info.vendorIdentifier() == arduino_uno_vendor_id){
                if(info.productIdentifier() == arduino_uno_product_id){
                    arduino_port_name = info.portName();
                    arduino_is_avaliable = true;
                }
            }
        }
    }
    if(arduino_is_avaliable){
        ui->lblCount->setText("Port name: " + arduino_port_name);
        arduino->setPortName(arduino_port_name);
        isPortOpened = arduino->open(QSerialPort::ReadOnly);
        if(isPortOpened){
            ui->lblHello->setText("Opened");
            arduino->setBaudRate(QSerialPort::Baud9600);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            arduino->setFlowControl(QSerialPort::NoFlowControl);
            arduino->setDataTerminalReady(true);
            QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
        }else{
            ui->lblHello->setText("Fail");
        }

    }else{
        QMessageBox::warning(this, "Port eror" , "Cloudn't find the arduino");
    }
}

MainWindow::~MainWindow()
{
    if(arduino->isOpen()){
        arduino->close();
    }
    delete ui;
}

void MainWindow::readSerial(){
    serialData = arduino->readAll();
    serialBuffer.append(serialData);
    if(serialData.contains("\n")){
        ui->lblCount->setText(serialBuffer);
        Xevent event(eventType::NONE);
        if(serialBuffer.contains("openW")){
            event.setType(eventType::SUPER_S);
        }else if(serialBuffer.contains("closeW")){
            event.setType(eventType::ENTER);
        }
        callbackFunc(event);
        serialBuffer.clear();
    }
}

void MainWindow::setEventCallbackFunc(void (*func)(Xevent event)){
    callbackFunc = func;
}

/*void MainWindow::on_btnHello_clicked()
{
    QString command = "o";
    if(arduino->isWritable()){
        arduino->write(command.toStdString().c_str());
        ui->lblHello->setText("ON");
    }else{
        ui->lblHello->setText("Failed");
    }
}

void MainWindow::on_btnStop_clicked()
{
    QString command = "f";
    if(arduino->isWritable()){
        arduino->write(command.toStdString().c_str());
        ui->lblHello->setText("OFF");
    }else{
        ui->lblHello->setText("Failed");
    }
}*/
