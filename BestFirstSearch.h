//
// Created by user on 1/8/2019.
//
#ifndef SECONDSTONE_BESTFIRSTSEARCH_H
#define SECONDSTONE_BESTFIRSTSEARCH_H
#include <string>

#include "MyPriorityQueue.h"
#include "absSearch.h"


class BestFirstSearch : public absSearch {

private:
//    MyPriorityQueue queue;
    unsigned int visits;



public:
    void increaseNumOfVisits(){ ++(this->visits); }
    void addToQueue(State<Point>* state);
    int OpenListSize;
    void remove(State<Point>* state);
//    virtual bool isContain(State<T>* state);
    State<Point>* extractMin();
    BestFirstSearch(){ this->visits = 0; };
    std::string search(Searchable);
    unsigned int getNumOfVisits() { return this->visits; };
    ~BestFirstSearch(){};
};

#endif //SECONDSTONE_BESTFIRSTSEARCH_H
