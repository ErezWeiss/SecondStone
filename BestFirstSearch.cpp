//
// Created by user on 1/8/2019.
//

#include "BestFirstSearch.h"
#include <string>

//helper functions for BestFirstSearch.
void BestFirstSearch::addToQueue(State<Point>* state)
{
    this->open.push(state);
}
int BestFirstSearch:: OpenListSize()
{
    return this->open.size();
}
void BestFirstSearch:: remove(State<Point>* state)
{
    //remove element from the queue and fix the order using heapify.
    if (this->visited[state]==GRAY) {
        State<Point> *temp = this->open.top();
        this->visited[temp] = BLACK;
    }
}
//void remove(State<Point>* stateToRemove) {
//    //remove element from the queue and fix the order using heapify.
//    if (contain(stateToRemove)) {
//        this->open.delete(stateToRemove);
//    }
//}
State<Point>* BestFirstSearch:: extractMin()
{ //takes out the best node from the graph, in our case the node with the best cost.
    this->increaseNumOfVisits();
    State<Point>* toPop = this->open.top();
    this->visited.at(toPop) = BLACK;
    this->open.pop();
    return toPop;
}
std::string BestFirstSearch:: search(Searchable* searchable) {
    //we use set to mark our used Nodes.
    State<Point>* start = searchable->getInitialState();
    //set the source destination.
    start->setSumOfVertex(0);
    addToQueue(searchable->getInitialState());
    while (OpenListSize() > 0) //continue until there is no nodes left,we will check all the nodes eventually.
    {
        State<Point>* current = extractMin();
//        closedMap.insert(current);
        if (current == searchable->getGoalState())
        { //case we find our goal.
            return current->pathFromStart();
        }
        vector<State<Point>*> adj = searchable->getAllPossibleStates(current); //extract neighbors.
        for(auto& son : adj)
        {
            double distance = current->getSumOfVertex() + son->getCost();
            //check if not in the queue and not handled.
            if ((  this->visited[son] != BLACK) && !(this->visited[son] != WHITE)) {
                //set the path and the previous node in this path.
                son->setAlgCost(distance);
                son->setCameFrom(current);
                this->addToQueue(son);
            }
            else if(distance < son->getAlgCost()) {
                if (this->visited[son] != GRAY) { //check if the queue contains the node.
                    this->addToQueue(son);
                } else {
                    son->setAlgCost(distance);
                    this->remove(son);
                    //when node enters to priority queue it updates the heap
                    this->addToQueue(son);
                }
            }
        }
    }

    return -1 ;
}