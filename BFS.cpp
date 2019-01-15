//
// Created by user on 1/8/2019.
//

#include "BFS.h"
#include <string>

//helper functions for BestFirstSearch.
void BFS::addToQueue(State<Point>* state)
{
    this->open.push(state);
}
int BFS:: OpenListSize()
{
    return this->open.size();
}
void BFS:: remove(State<Point>* state)
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
State<Point>* BFS:: extractMin()
{ //takes out the best node from the graph, in our case the node with the best cost.
    this->increaseNumOfVisits();
    State<Point>* toPop = this->open.top();
    this->visited.at(toPop) = BLACK;
    this->open.pop();
    return toPop;
}
std BFS::string search(Searchable<State<Point>*>* searchable)
{

//queue and a set for the nodes.
//    std::queue<Node*> queue;
//    std::unordered_set <Node*> handled;
this->initialization(searchable);
this->opene.push(searchable->getInitialState());
this->visited.insert(searchable->getInitialState());
this->visited[state]=GRAY;
this->visits = 0;
while (!this->open.empty())
{
State<Point>* current = this->open.top();
this->increaseNumOfVisits();
this->open.pop();
if (current->equals(searchable->getGoalState()))
{ //case we find our node.
this->visits = 0;
while (this->open.size() > 0)
{
this->open.pop();
}
return current->pathFromStart();
}
vector<State<Point>*> adj = searchable->getAllPossibleStates(current) //extract neighbors.
for (State<Point>* son : adj)
{
if (this->visited.find(son) == this->visited.end() )
{
//set the node as handled and set the path.
son->setCameFrom(current);
this->visited.insert(son);
this->visited[state]=GRAY;
this->open.push(son);
}
}
}
this->visits = 0;
return ("-1"); // in case our node was not found.
}
