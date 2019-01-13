//
// Created by erez on 1/12/19.
//

#ifndef SECONDSTONE_SEARCHABLEMATRIX_H
#define SECONDSTONE_SEARCHABLEMATRIX_H


#include <vector>
#include "Searchable.h"
#include "State.h"
#include "Point.h"

class SearchableMatrix : Searchable<State<Point>> {

private:
    std::vector<std::vector<State<Point>>> matrixVector;
    State<Point> initial;
    State<Point> goal;

public:
    // CONT
    SearchableMatrix(std::vector<std::vector<State<Point>>> matrixVector, State<Point> initial, State<Point> goal) {
        this->matrixVector = matrixVector;
        this->initial = initial;
        this->goal = goal;
    }

    virtual State<Point> getInitialState();
    virtual State<Point> getGoalState();
    virtual std::list<State<Point>> getAllPossibleStates(State<Point> s);
};



#endif //SECONDSTONE_SEARCHABLEMATRIX_H
