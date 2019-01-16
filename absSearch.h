//
// Created by user on 1/12/2019.
//
#ifndef SECONDSTONE_ABSSEARCH_H
#define SECONDSTONE_ABSSEARCH_H
#include "Searcher.h"
#include "State.h"
#include "MatrixBuilder.h"
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include "Searcher.h"
#include "Point.h"

enum color {WHITE ,GRAY , BLACK };

template <class T>
class myComparator
{
public:
    int operator() (const State<T> *p1, const State<T> *p2)
    {
        return p1->getSumOfVertex() > p2->getSumOfVertex();
    }
};

template <class T, class P>
// T Point, P String

class absSearch : public Searcher<T, P>{
protected:
    std::unordered_map<State<T>*, color> visited;
    std::priority_queue< State<T>*,std::vector<State<T>*>,myComparator<T> >  open;

public:
    void initialization (std::vector< vector<State<T>*>> vvi){
        for(auto& row:vvi){
            for(auto& col:row){
                this->visited[col] = WHITE;
            }
        }
    }

    bool contain(State<T> *state) {
        if(this->visited[state]==GRAY){
            return true;
        }
        else{
            return false;
        }

    }

    virtual State<T>* extractMin()=0;

    virtual void remove(State<T> *stateToRemove)=0;

    // a property of openList
    virtual int OpenListSize()=0;
    // ISearcher’smethods:
    virtual int getNumberOfNodesEvaluated()=0;
    virtual P search(Searchable<T>* searchable) = 0;
};

#endif //SECONDSTONE_ABSSEARCH_H