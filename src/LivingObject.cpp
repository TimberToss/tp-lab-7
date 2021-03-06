#include "LivingObject.h"
#include "Ocean.h"
#include "Cell.h"

LivingObject::LivingObject(int x, int y,  Ocean* ocean) : Object(x, y, ocean) {}

LivingObject::LivingObject(Coordinates coordinates, Ocean* ocean) : Object(coordinates, ocean) {}

void LivingObject::move(int x, int y) {
    ocean->getCell(&location)->setObject(nullptr);
    location = { x,y };
    ocean->getCell(x,y)->setObject(this);
}

void LivingObject::motion() {
    int where = rand() % 4;
    Cell* cellTo;
    switch (where) {
        case UP:
            cellTo = ocean->getCell(location.x, location.y - 1);
            if (cellTo != nullptr && checkCell(cellTo)) {
                move(location.x, location.y - 1);
            }
            break;

        case RIGHT:
            cellTo = ocean->getCell(location.x + 1, location.y);
            if (cellTo != nullptr && checkCell(cellTo)) {
                move(location.x + 1, location.y);
            }
            break;

        case DOWN:
            cellTo = ocean->getCell(location.x, location.y + 1);
            if (cellTo != nullptr && checkCell(cellTo)) {
                move(location.x, location.y + 1);
            }
            break;

        case LEFT:
            cellTo = ocean->getCell(location.x - 1, location.y);
            if (cellTo != nullptr && checkCell(cellTo)) {
                move(location.x - 1, location.y);
            }
            break;
    }
}

void LivingObject::die() {
    ocean->deleteObject(this);
    ocean->getCell(&location)->setObject(nullptr);
    delete this;
}

void LivingObject::birth() {
    ocean->addObject(this);
    ocean->getCell(&location)->setObject(this);
}

std::vector<Cell*> LivingObject::getNeighbouredCells() {
    std::vector<Cell*> neighbours;
    for (int i = -1, j = -1; i < 2; i++) {
        Cell* cellTo = ocean->getCell(location.x + i, location.y + j);
        if (cellTo) {
            neighbours.push_back(cellTo);
        }
    }
    for (int i = -1, j = 1; i < 2; i++) {
        Cell* cellTo = ocean->getCell(location.x + i, location.y + j);
        if (cellTo) {
            neighbours.push_back(cellTo);
        }
    }
    Cell* cellTo = ocean->getCell(location.x - 1, location.y);
    if (cellTo) {
        neighbours.push_back(cellTo);
    }
    cellTo = ocean->getCell(location.x + 1, location.y);
    if (cellTo) {
        neighbours.push_back(cellTo);
    }
    return neighbours;
} 