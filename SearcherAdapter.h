//
// Created by erez on 1/10/19.
//

#ifndef SECONDSTONE_SEARCHERADAPTER_H
#define SECONDSTONE_SEARCHERADAPTER_H


#include "Solver.h"
#include "Searcher.h"
template <class S>

class SearcherAdapter : public Solver<Searchable, S> {
private:
    Searcher<S> *searcher;

public:
    SearcherAdapter(Searcher<S> *searcher){
        this->searcher=searcher;
    }
    virtual S solve(Searchable searchable){
        return searcher->search(searchable);
    }
};


#endif //SECONDSTONE_SEARCHERADAPTER_H
