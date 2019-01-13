//
// Created by user on 1/8/2019.
//

#include "BestFirstSearch.h"


//helper functions for BestFirstSearch.
void BestFirstSearch::addToQueue(State<Point>* state)
{
    this->open.push(state);
}
int BestFirstSearch:: getQueueSize()
{
    return this->open.size();
}
void BestFirstSearch:: removeFromQueue(State<Point>* state)
{
    State<Point>* temp = this->open.top(state);
    this->visited[temp]=BLACK;
}
void remove(State<Point>* stateToRemove) {
//    //remove element from the queue and fix the order using heapify.
//    if (contain(stateToRemove)) {
//        this->open.delete(stateToRemove);
//    }
}
State<Point>* BestFirstSearch:: extractMin()
{ //takes out the best node from the graph, in our case the node with the best cost.
    this->increaseNumOfVisits();
    State<T>* toPop = this->open.top();
    this->open.pop();
    return toPop;
}
override string search(Isearchable searchable) {
//we use set to mark our used Nodes.
std::unordered_set <State<T>*> closedMap;
State<T>* start = mg->getInitialState();
//set the source destination.
start->setAlgCost(0);
this->addToQueue(mg->getInitialState());
while (this->getQueueSize() > 0) //continue until there is no nodes left,we will check all the nodes eventually.
{
State<T>* current = this->extractMin();
closedMap.insert(current);
if (current == mg->getGoalState())
{ //case we find our node.
return current->pathFromStart();
}
vector<Node*> adj = mg->getAdj(current); //extract neighbors.
for (Node* son : adj)
{
double distance = current->getAlgCost() + son->getCost();
//check if not in the queue and not handled.
if ((closedMap.find(son) == (closedMap.end())) && !(this->isContain(son))) {
//set the path and the previous node in this path.
son->setAlgCost(distance);
son->setCameFrom(current);
this->addToQueue(son);
}
else if(distance < son->getAlgCost()) {
if (!this->isContain(son)) { //check if the queue contains the node.
this->addToQueue(son);
} else {
son->setAlgCost(distance);
this->removeFromQueue(son);
//when node enters to priority queue it updates the heap
this->addToQueue(son);
}
}
}
}

return "-1";
}