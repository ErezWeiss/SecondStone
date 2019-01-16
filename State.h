//
// Created by user on 1/11/2019.
//

#ifndef SECONDSTONE_STATE_H
#define SECONDSTONE_STATE_H

#include <vector>
#include "string"
#include "Point.h"

template <class T>
class State {
private:
    bool elianosVisited =false;
    // the state represented by a string
    T* state;
    // cost to reach this state (set by a setter)
    double cost;
    // the state we came from to this state (setter)
    State<T> *cameFrom;
    double sumOfVertex;
    std::string cameFromDir="";
public:
    State (T* stet, double cost){
        this->state = stet;
        this->cost = cost;
        this->cameFrom = nullptr;
        this->sumOfVertex =0;
    }

    T *getState() const {
        return state;
    }

    void setState(T *state) {
        State::state = state;
    }

    double getCost() const {
        return cost;
    }

    void setCost(double cost) {
        State::cost = cost;
    }

    State<T> *getCameFrom() const {
        return cameFrom;
    }
    double getSumOfVertex() const {
        return sumOfVertex;
    }

    void setSumOfVertex(double sumOfVertex) {
        State::sumOfVertex = sumOfVertex;
    }

    // we overload Object's Equals method
    bool ifIsEquals(State <T>* s) {
        return (this->state == s->state);
    }

    std::string pathFromStart() {
        std::string toRet = "";
        State<Point>* curr = this->cameFrom;
        unsigned int i = 0;
        std::vector<std::string> path;
        //case no path or method called before running a search algorithm
        if (curr == nullptr)
        {
            return toRet;
        }
        path.push_back(this->cameFromDir);
        //reaching nullptr means we backtraced all the way to the start Node
        while (curr != nullptr)
        {
            path.push_back(curr->getCameFromDir());
            curr = curr->getCameFrom();
        }
        //constructing a string representation of the path
        i = path.size() - 1;
        for (; i >= 0; --i)
        {
            toRet += path[i];
            if (!i)
            {
                break;
            }
            if (i == path.size() - 1)
            {
                continue;
            }
            toRet+= ",";
        }
        return toRet;
    }
//    bool equals(State<Point>* n)
//    {
//        if (n != nullptr)
//        {
//            Point* nPos = n->getState();
//            if ((this->pos).i == nPos->getX() && (this->pos).j == nPos->getY())
//            {	//same Position <-> same Node
//                return true;
//            }
//        }
//
//        return false;
//    }
//return toString identifier
    std::string toString()
    {
        return "(" + std::to_string((this->state).getX()) + "," + std::to_string((this->state).getY) + ")";
    }
    void setCameFrom(State<Point>* n)
    {
        this->cameFrom = n;
        Point* pos = n->getState();
        unsigned int nI = pos->getX(), nJ = pos->getY(), thisI = (this->state)->getX(), thisJ = (this->state)->getY();
        //right
        if (nI < thisI)
        {
            this->cameFromDir = "Down";
        }
        //left
        if (nI > thisI)
        {
            this->cameFromDir = "Up";
        }
        //down
        if (nJ < thisJ)
        {
            this->cameFromDir = "Right";
        }
        //up
        if (nJ > thisJ)
        {
            this->cameFromDir = "Left";
        }
    }
    State<Point>*  getCameFrom()
    {
        return this->cameFrom;
    }
    std::string getCameFromDir()
    {
        return this->cameFromDir;
    }

};
#endif //SECONDSTONE_STATE_H
