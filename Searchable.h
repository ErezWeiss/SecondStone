//
// Created by user on 1/8/2019.
//

#ifndef SECONDSTONE_SEARCHABLE_H
#define SECONDSTONE_SEARCHABLE_H

#include "State.h"
#include <list>

template <class T>
class Searchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getGoalState() = 0;
    virtual std::list<State<T>*> getAllPossibleStates(State<T>* s) = 0;
    virtual std::vector<std::vector<State<T>*>> getVector()=0;
};
#endif //SECONDSTONE_SEARCHABLE_H
