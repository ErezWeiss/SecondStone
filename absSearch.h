//
// Created by user on 1/12/2019.
//
#ifndef SECONDSTONE_ABSSEARCH_H
#define SECONDSTONE_ABSSEARCH_H
#include "Searcher.h"
#include "State.h"
#include "MatrixBuilder.h"
#include "MyPriorityQueue.h"
#include <map>
#include <bits/unordered_map.h>
#include <queue>
#include <algorithm>
//#include <w32api/d2d1helper.h>
#include "Searcher.h"
#include "Point.h"



enum color {WHITE ,GRAY , BLACK };

class myComparator
{
public:
    int operator() (const State<Point>* p1, const State<Point>* p2)
    {
        return p1->getPathCost() > p2->getPathCost();
        //TODO getPathCost (IN STATE)
    }
};


class absSearch : public Searcher<State<Point>>{
protected:
    //std::map<State<T>,color> visited;
    std::unordered_map<State<Point>*, color> visited;
    std::priority_queue<State<Point>*,std::vector<State<Point>*>,myComparator> open ;
    int evaluatedNodes=0;
public:
    void initialization (std::vector< vector<State<Point>*>> vvi){
        for(auto& row:vvi){
            for(auto& col:row){
                this->visited[col] = WHITE;
            }
        }
//        vector<State<Point>*> >::iterator row;
//        vector<State<Point>*>::iterator col;
//        for (row = vvi.begin(); row != vvi.end(); row++) {
//            for (col = row->begin(); col != row->end(); col++) {
//                this->visited[col] = WHITE;
//            }
//        }
    }


    virtual State<Point>* extractMin()=0;
//    {
//        evaluatedNodes++;
//        State<Point>* temp=open.top();
//        this->visited.at(temp) = BLACK;
//        open.pop();
//        return temp;
//   }
    bool contain(State<Point>* state)
    {
        if(this->visited[state]==GRAY){
            return true;
        }
        else{
            return false;
        }
//        //check if element is in the queue.
//        auto it = std::find(this->open.begin(), this->open.end(), state);
//        return (it != this->open.end());
    }
    virtual void remove(State<Point>* stateToRemove)=0;

    // a property of openList
    virtual int OpenListSize;
    // ISearcher’smethods:
    virtual int getNumberOfNodesEvaluated()=0;
    virtual string search(Searchable searchable)=0;
};

#endif //SECONDSTONE_ABSSEARCH_H
