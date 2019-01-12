//
// Created by erez on 1/12/19.
//

#ifndef SECONDSTONE_POINT_H
#define SECONDSTONE_POINT_H


class Point {
private:
    double x;
    double y;

public:
    // CONT
    Point(double x, double y){
        this->x = x;
        this-> y = y;
    }

    void setX(double x);

    void setY(double y);

    double getX() const;

    double getY() const;
};

void Point::setX(double x) {
    Point::x = x;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setY(double y) {
    Point::y = y;
}


#endif //SECONDSTONE_POINT_H
