#include "Object.h"
#include "Ocean.h"


Object::Object(int x, int y, Ocean* ocean) {
    location.x = x;
    location.y = y;
    this->ocean = ocean;
}

Object::Object(coord coordinates, Ocean * ocean) {
    location = coordinates;
    this->ocean = ocean;
}

char Object::getSymbol() {
    return symbol;
}
