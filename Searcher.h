//
// Created by user on 1/8/2019.
//

#ifndef SECONDSTONE_SEARCHER_H
#define SECONDSTONE_SEARCHER_H

#include "Searchable.h"
using namespace std;
template <class T>
class Searcher {
public:
    T search (Searchable searchable) = 0;
    int getNumberOfNodesEvaluated() = 0;

};
#endif //SECONDSTONE_SEARCHER_H
