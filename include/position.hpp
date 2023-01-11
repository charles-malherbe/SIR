
#ifndef SIR_POSITION_H
#define SIR_POSITION_H

#include <cmath>

class Position {

    private:
        double x;
        double y;

    public:
        Position();
        Position(double xx, double yy);
        bool atLocation(Position destination) const;
        bool move(Position *destination, double speed);
        void setX(double x);
        void setY(double y);
        double getX() const;
        double getY() const;
        double getDistance(Position point) const;
        double getAngle(Position point) const;
        void setAngle(double angle);

};

#endif
