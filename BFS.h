//
// Created by user on 1/8/2019.
//
#ifndef SECONDSTONE_BFS_H
#define SECONDSTONE_BFS_H
#include <string>
#include "absSearch.h"
#include "Searchable.h"

template <class T, class P>
class BFS : public absSearch<T, P> {
    private:
        int evaluatedNodes;
    queue<State<T>*>  open1;
    public:
        BFS(){
            evaluatedNodes=0;
        };

    void increaseNumOfVisits(){ ++(this->evaluatedNodes); }

    //helper functions for BestFirstSearch.
    void addToQueue(State<T>* state) {
            this->open1.push(state);
        }

    int OpenListSize() {
        return this->open1.size();
    }

    void remove(State<T>* state) {
        //remove element from the queue and fix the order using heapify.
        if (this->visited[state]==GRAY) {
            State<T> *temp = this->open1.front();
            this->visited[temp] = BLACK;
        }
    }

    State<T>* extractMin() { //takes out the best node from the graph, in our case the node with the best cost.
        this->increaseNumOfVisits();
        State<T>* toPop = this->open1.front();
        this->visited.at(toPop) = BLACK;
        this->open1.pop();
        return toPop;
    }

    P search(Searchable<T>* searchable) {
        this->initialization(searchable->getVector());
        this->open1.push(searchable->getInitialState());
        this->visited[searchable->getInitialState()];
        this->visited[searchable->getInitialState()]=GRAY;
        while (!this->open1.empty()) {
            State<T>* current = this->open1.front();
            this->increaseNumOfVisits();
            this->open1.pop();
            if (current->ifIsEquals(searchable->getGoalState())) { //case we find our node.
                this->evaluatedNodes = 0;
                while (this->open1.size() > 0) {
                    this->open1.pop();
                }
                return current->pathFromStart();
            }
            list<State<T>*> adj = searchable->getAllPossibleStates(current); //extract neighbors.
            for (State<T>* son : adj) {
                if (this->visited[son] == WHITE ) {
                    //set the node as handled and set the path.
                    son->setCameFrom(current);
                    this->visited[son]=GRAY;
                    this->open1.push(son);
                }
            }
        }
        this->evaluatedNodes = 0;
        return ("-1"); // in case our node was not found.
    }
    int getNumberOfNodesEvaluated(){ return this->evaluatedNodes; };
};

#endif