#include "evetns.h"
Display* display;


void enterKey(){
    unsigned int enterKeyCode = XKeysymToKeycode(display, XK_Return);

    XTestFakeKeyEvent(display, enterKeyCode, true, 0);
    XTestFakeKeyEvent(display, enterKeyCode, false, 0);

    XFlush(display);
}

void password(){

    unsigned int mKeyCode = XKeysymToKeycode(display, XK_M);
    unsigned int oKeyCode = XKeysymToKeycode(display, XK_O);
    unsigned int sKeyCode = XKeysymToKeycode(display, XK_S);
    unsigned int kKeyCode = XKeysymToKeycode(display, XK_K);
    unsigned int aKeyCode = XKeysymToKeycode(display, XK_A);
    unsigned int lKeyCode = XKeysymToKeycode(display, XK_L);
    unsigned int yKeyCode = XKeysymToKeycode(display, XK_Y);
    unsigned int uKeyCode = XKeysymToKeycode(display, XK_U);
    unsigned int minusKeyCode = XKeysymToKeycode(display, XK_minus);
    unsigned int oneKeyCode = XKeysymToKeycode(display, XK_1);
    unsigned int shiftKeyCode = XKeysymToKeycode(display, XK_Shift_L);

    XTestFakeKeyEvent(display, shiftKeyCode, true, 0);
    XTestFakeKeyEvent(display, mKeyCode, true, 0);
    XTestFakeKeyEvent(display, shiftKeyCode, false, 1);
    XTestFakeKeyEvent(display, mKeyCode, false, 1);

    XTestFakeKeyEvent(display, oKeyCode, true, 2);
    XTestFakeKeyEvent(display, oKeyCode, false, 2);

    XTestFakeKeyEvent(display, sKeyCode, true, 2);
    XTestFakeKeyEvent(display, sKeyCode, false, 2);

    XTestFakeKeyEvent(display, kKeyCode, true, 2);
    XTestFakeKeyEvent(display, kKeyCode, false, 2);

    XTestFakeKeyEvent(display, aKeyCode, true, 2);
    XTestFakeKeyEvent(display, aKeyCode, false, 2);

    XTestFakeKeyEvent(display, lKeyCode, true, 2);
    XTestFakeKeyEvent(display, lKeyCode, false, 2);

    XTestFakeKeyEvent(display, yKeyCode, true, 2);
    XTestFakeKeyEvent(display, yKeyCode, false, 2);

    XTestFakeKeyEvent(display, uKeyCode, true, 2);
    XTestFakeKeyEvent(display, uKeyCode, false, 2);

    XTestFakeKeyEvent(display, kKeyCode, true, 2);
    XTestFakeKeyEvent(display, kKeyCode, false, 2);

    XTestFakeKeyEvent(display, minusKeyCode, true, 2);
    XTestFakeKeyEvent(display, minusKeyCode, false, 2);

    XTestFakeKeyEvent(display, oneKeyCode, true, 2);
    XTestFakeKeyEvent(display, oneKeyCode, false, 2);
}

void sendEvetns(Xevent event)
{
    if(display!= nullptr){
        switch (event.type) {
        case SUPER_S:
            password();
            break;
        case ENTER:
            enterKey();
            break;
        case NONE:
        default:
            break;
        }

    }
}
