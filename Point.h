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
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }


    void setX(double x) {
        this->x = x;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    void setY(double y) {
        this->y = y;
    }
};


#endif //SECONDSTONE_POINT_H
