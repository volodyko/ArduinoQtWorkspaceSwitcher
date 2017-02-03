#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include "eventtype.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setEventCallbackFunc(void (*func)(Xevent event));
    ~MainWindow();

private slots:

    void readSerial();

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 10755;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_avaliable;
    bool isPortOpened;
    QByteArray serialData;
    QByteArray serialBuffer;

    void (*callbackFunc)(Xevent event);

};

#endif // MAINWINDOW_H
