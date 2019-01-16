//
// Created by erez on 1/12/19.
//

#ifndef SECONDSTONE_SEARCHABLEMATRIX_H
#define SECONDSTONE_SEARCHABLEMATRIX_H


#include <vector>
#include "Searchable.h"
#include "State.h"
#include "Point.h"

template <class T>
class SearchableMatrix : public Searchable<T> {

private:
    std::vector<std::vector<State<T>*>> matrixVector;
    State<T>* initial;
    State<T>* goal;

public:
    // CONT
    SearchableMatrix(std::vector<std::vector<State<T>*>> matrixVector, State<T>* initial, State<T>* goal) {
        this->matrixVector = matrixVector;
        this->initial = initial;
        this->goal = goal;
    }


    State<T>* getInitialState(){
        return this->initial;
    }
    State<T>* getGoalState(){
        return this->goal;
    }
    std::list<State<T>*> getAllPossibleStates(State<Point> *s){
        std::list<State<Point>*> retList;
        unsigned long sizeOfMatrix = this->matrixVector.size()-1;
        double x = s->getState()->getX();
        double y = s->getState()->getY();

        // bottom right
        if ((x==y) && (y==sizeOfMatrix)){
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
        else if ((x==y) && (y==0)) {
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
    std::vector<std::vector<State<T>*>> getVector(){ return this->matrixVector;};
};



#endif //SECONDSTONE_SEARCHABLEMATRIX_H
