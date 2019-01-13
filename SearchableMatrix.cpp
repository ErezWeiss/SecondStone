//
// Created by erez on 1/12/19.
//

#include "SearchableMatrix.h"

State<Point> SearchableMatrix::getInitialState(){
    return this->initial;
}

State<Point> SearchableMatrix::getGoalState(){
    return this->goal;
}
std::list<State<Point>> SearchableMatrix::getAllPossibleStates(State<Point> p){
    std::list<State<Point>> retList;
    unsigned long sizeOfMatrix = this->matrixVector.size()-1;
    double x = p.getState()->getX();
    double y = p.getState()->getY();

    // bottom right
    if (x==y==sizeOfMatrix){
        retList.push_back(this->matrixVector[x][y-1]);
        retList.push_back(this->matrixVector[x-1][y]);
    }
    // bottom left
    else if (x==sizeOfMatrix && y==0){
        retList.push_back(this->matrixVector[x][1]);
        retList.push_back(this->matrixVector[x-1][0]);
    }
    // up right
    else if (x==0 && y==sizeOfMatrix){
        retList.push_back(this->matrixVector[0][sizeOfMatrix-1]);
        retList.push_back(this->matrixVector[1][sizeOfMatrix]);
    }
    // up left
    else if (x==y==0) {
        retList.push_back(this->matrixVector[0][1]);
        retList.push_back(this->matrixVector[1][0]);
    }
    // bottom
    else if(x==sizeOfMatrix){
        retList.push_back(this->matrixVector[x][y-1]);
        retList.push_back(this->matrixVector[x][y+1]);
        retList.push_back(this->matrixVector[x-1][y]);
    }
    // left
    else if (y==0){
        retList.push_back(this->matrixVector[x-1][0]);
        retList.push_back(this->matrixVector[x+1][0]);
        retList.push_back(this->matrixVector[x][1]);
    }
    // up
    else if (x==0) {
        retList.push_back(this->matrixVector[0][y-1]);
        retList.push_back(this->matrixVector[0][y+1]);
        retList.push_back(this->matrixVector[1][y]);
    }
    // right
    else if (y==sizeOfMatrix){
        retList.push_back(this->matrixVector[x+1][y]);
        retList.push_back(this->matrixVector[x-1][y]);
        retList.push_back(this->matrixVector[x][y-1]);
    }
    else {
        retList.push_back(this->matrixVector[x-1][y]);
        retList.push_back(this->matrixVector[x+1][y]);
        retList.push_back(this->matrixVector[x][y-1]);
        retList.push_back(this->matrixVector[x][y+1]);
    }
    return retList;
}