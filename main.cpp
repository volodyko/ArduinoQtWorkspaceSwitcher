#include "mainwindow.h"
#include <QApplication>
#include <QX11Info>
#include "evetns.h"
#include "eventtype.h"

extern Display* display;

static void sendEventCallback(Xevent event){
    if(display!= nullptr){
        sendEvetns(event);
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    display = QX11Info::display();
    MainWindow w;
    w.setEventCallbackFunc(sendEventCallback);
    w.show();

    return a.exec();
}



