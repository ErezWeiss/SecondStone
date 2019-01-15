//
// Created by user on 1/8/2019.
//

#ifndef SECONDSTONE_SEARCHER_H
#define SECONDSTONE_SEARCHER_H

#include "Searchable.h"
#include "SearchableMatrix.h"

using namespace std;
template <class T, class P>
class Searcher {
public:
    virtual P search (Searchable<T> *searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
};

#endif //SECONDSTONE_SEARCHER_H
