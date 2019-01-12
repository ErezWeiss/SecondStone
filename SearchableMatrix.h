//
// Created by erez on 1/12/19.
//

#ifndef SECONDSTONE_SEARCHABLEMATRIX_H
#define SECONDSTONE_SEARCHABLEMATRIX_H


#include <vector>
#include "Searchable.h"
#include "State.h"

class SearchableMatrix : Searchable {
private:
    vector<vector<State<Point>>> matrixVector;
    State<Point> initial;
    State<Point> goal;

public:
    // CONT
    SearchableMatrix(vector<vector<State<Point>>> matrixVector, State<Point> initial, State<Point> goal){
        this->matrixVector = matrixVector;
        this-> initial = initial;
        this-> goal =goal;
    }
}


#endif //SECONDSTONE_SEARCHABLEMATRIX_H
