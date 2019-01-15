//
// Created by user on 1/8/2019.
//
#ifndef SECONDSTONE_BESTFIRSTSEARCH_H
#define SECONDSTONE_BESTFIRSTSEARCH_H
#include <string>
#include "absSearch.h"
#include "Searchable.h"

template <class T, class P>
class BestFirstSearch : public absSearch<T, P> {

private:
    unsigned int visits;
    int evaluatedNodes;

public:
    BestFirstSearch(){
        this->visits = 0;
        evaluatedNodes=0;
    };

    void increaseNumOfVisits(){ ++(this->evaluatedNodes); }

    void addToQueue(State<T>* state){
            this->open.push(state);
    }

    int OpenListSize(){  return this->open.size();}

    void remove(State<T>* state){    //remove element from the queue and fix the order using heapify.
        if (this->visited[state]==GRAY) {
            State<T>* temp = this->open.top();
            this->visited[temp] = BLACK;
        }
    }

//    virtual bool isContain(State<T>* state);
    State<T>* extractMin() {
        this->increaseNumOfVisits();
        State<T>* toPop = this->open.top();
        this->visited[toPop] = BLACK;
        this->open.pop();
        return toPop;
    }


    P search(Searchable<T> *searchable){    //we use set to mark our used Nodes.
        this->initialization(searchable->getVector());
        State<T>* start = searchable->getInitialState();
        //set the source destination.
        start->setSumOfVertex(0);
        addToQueue(searchable->getInitialState());
        while (this->OpenListSize() > 0) //continue until there is no nodes left,we will check all the nodes eventually.
        {
            State<T>* current = extractMin();
            this->visited[current] = BLACK;
//        closedMap.insert(current);
            if (current == searchable->getGoalState())
            { //case we find our goal.
                return current->pathFromStart();
            }
            list<State<T>*> adj = searchable->getAllPossibleStates(current); //extract neighbors.
            for(auto& son : adj)
            {
                double distance = current->getSumOfVertex() + son->getCost();
                //check if not in the queue and not handled.
                if ((  this->visited[son] != BLACK) && !(this->visited[son] != GRAY)) {
                    //set the path and the previous node in this path.
                    son->setSumOfVertex(distance);
                    son->setCameFrom(current);
                    this->addToQueue(son);
                    this->visited[son] = GRAY;
                }
                else if(distance < son->getSumOfVertex()) {
                    if (this->visited[son] != GRAY) { //check if the queue contains the node.
                        this->addToQueue(son);
                        this->visited[son] = GRAY;
                    } else {
                        son->setSumOfVertex(distance);
                        this->remove(son);
                        //when node enters to priority queue it updates the heap
                        this->addToQueue(son);
                    }
                }
            }
        }

        return ("-1") ;}
    int getNumberOfNodesEvaluated(){ return this->visits; };
};

#endif //SECONDSTONE_BESTFIRSTSEARCH_H
