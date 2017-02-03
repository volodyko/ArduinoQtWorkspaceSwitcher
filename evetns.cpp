#include "evetns.h"
Display* display;

void openWorkplaceSelector(){
    unsigned int superKeyCode = XKeysymToKeycode(display, XK_Super_L);
    unsigned int sKeyCode = XKeysymToKeycode(display, XK_S);

    XTestFakeKeyEvent(display, superKeyCode, true, 0);
    XTestFakeKeyEvent(display, sKeyCode, true, 0);
    XTestFakeKeyEvent(display, superKeyCode, false, 5);
    XTestFakeKeyEvent(display, sKeyCode, false, 5);

    XFlush(display);
}

void sendEvetns(Xevent event)
{
    if(display!= nullptr){
        switch (event.type) {
        case SUPER_S:
            openWorkplaceSelector();
            break;
        case NONE:
        default:
            break;
        }

    }
}
