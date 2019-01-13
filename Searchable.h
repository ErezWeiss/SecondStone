//
// Created by user on 1/8/2019.
//

#ifndef SECONDSTONE_SEARCHABLE_H
#define SECONDSTONE_SEARCHABLE_H

#include "State.h"
#include <list>

template <class A>
class Searchable {
public:
    virtual A getInitialState() = 0;
    virtual A getGoalState() = 0;
    virtual std::list<A> getAllPossibleStates(A s) = 0;
};
#endif //SECONDSTONE_SEARCHABLE_H
