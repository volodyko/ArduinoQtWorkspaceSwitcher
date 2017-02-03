#ifndef EVENTTYPE_H
#define EVENTTYPE_H
enum eventType{NONE, SUPER_S,LEFT,RIGHT, UP, DOWN, ENTER};
struct Xevent {
    Xevent(eventType ltype) : type(ltype){}
    void setType(eventType ltype){
        type = ltype;
    }

    eventType type;

};

#endif // EVENTTYPE_H
