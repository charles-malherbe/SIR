#include "../include/position.hpp"

Position::Position() {
    x = 0;
    y = 0;
}

Position::Position(double xx, double yy) {
    x = xx;
    y = yy;
}

bool Position::atLocation(Position destination) const {
    return (x == destination.x && y == destination.y);
}

bool Position::move(Position* destination, double speed) {
    if (atLocation(*destination)) {
        return true;
    }
    double distance = getDistance(*destination);
    if (distance <= speed) {
        x = destination->x;
        y = destination->y;
        return true;
    }
    double xDiff = destination->x - x;
    double yDiff = destination->y - y;
    double xRatio = xDiff / distance;
    double yRatio = yDiff / distance;
    x += xRatio * speed;
    y += yRatio * speed;
    return false;
}

void Position::setX(double x) {
    Position::x = x;
}

void Position::setY(double y) {
    Position::y = y;
}

double Position::getX() const {
    return x;
}

double Position::getY() const {
    return y;
}

double Position::getDistance(Position point) const {
    double xDiff = point.x - x;
    double yDiff = point.y - y;
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}