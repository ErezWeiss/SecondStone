//
// Created by user on 1/8/2019.
//
#include <cmath>
#include <string>
#include "absSearch.h"
#include "Searchable.h"
//#include <math.h>
#include <iostream>
/* pow */

#ifndef SECONDSTONE_ASTAR_H
#define SECONDSTONE_ASTAR_H


template <class T, class P>
class Astar : public absSearch<T, P> {

private:
//    unsigned int visits;
    int evaluatedNodes;

public:
    Astar(){
//        this->visits = 0;dffd
        evaluatedNodes=0;
    };


    void increaseNumOfVisits(){ ++(this->evaluatedNodes); }

    void addToQueue(State<T>* state){
        this->openForAstar.push(state);
    }

    int OpenListSize(){  return this->openForAstar.size();}

    void remove(State<T>* state){    //remove element from the queue and fix the order using heapify.
        if (this->visited[state]==GRAY) {
            State<T>* temp = this->openForAstar.top();
            this->visited[temp] = BLACK;
        }
    }

//    virtual bool isContain(State<T>* state);
    State<T>* extractMin() {
        this->increaseNumOfVisits();
        State<T>* toPop = this->openForAstar.top();
        this->visited[toPop] = BLACK;
        this->openForAstar.pop();
        return toPop;
    }

    P search(Searchable<T> *searchable){
        static State<Point>* goalState = searchable->getGoalState();
        //we use set to mark our used Nodes.
        struct myComparatorAstar
        {
            double getGoalDistance(State<Point> *s, State<Point> *goal) {
                double sX = s->getState()->getX();
                double sY = s->getState()->getY();
                double goalX = goal->getState()->getX();
                double goalY = goal->getState()->getY();
                double distanceX = pow(sX - goalX, 2.0);
                double distanceY = pow(sY - goalY, 2);
                double calcDistance = sqrt(distanceX + distanceY);
                return calcDistance;
            }

            int operator() (const State<Point> *p1, State<Point> *p2)
            {
                return (p1->getSumOfVertex()+getGoalDistance(p1->getState(),goalState) > p2->getSumOfVertex()+ getGoalDistance(p2->getState(),goalState));
            }
        };
        std::priority_queue< State<T>*,std::vector<State<T>*>,myComparatorAstar >   openForAstar;
        this->initialization(searchable->getVector());
        State<T>* start = searchable->getInitialState();
        //set the source destination.
        start->setSumOfVertex(start->getCost());
        addToQueue(start);
        while (this->OpenListSize() > 0) //continue until there is no nodes left,we will check all the nodes eventually.
        {
            State<T> *current = extractMin();
            this->visited[current] = BLACK;
            this->evaluatedNodes++;
//        closedMap.insert(current);
            if (current->ifIsEquals(searchable->getGoalState())) { //case we find our goal.
                return current->pathFromStart();
            }
            list<State<T> *> adj = searchable->getAllPossibleStates(current); //extract neighbors.
            for (auto &son : adj) {
                if (son->getCost() == -1) {
                    continue;
                }

                double distance = current->getSumOfVertex() + son->getCost();
                //check if not in the queue and not handled.
                if ((this->visited[son] == WHITE)) {
                    //set the path and the previous node in this path.
                    this->visited[son] = GRAY;
                    son->setSumOfVertex(distance);
                    son->setCameFrom(current);
                    this->addToQueue(son);
                } else if (distance < (son->getSumOfVertex())) {
                    son->setCameFrom(current);
                    son->setSumOfVertex(distance);
                    if (this->visited[son] == BLACK) { //check if the queue contains the node.
                        this->visited[son] = GRAY;
                        this->addToQueue(son);
                    }
                }
            }
        }

        return ("-1");
    }

    int getNumberOfNodesEvaluated(){ return this->evaluatedNodes; };
};

#endif //SECONDSTONE_ASTAR_H
