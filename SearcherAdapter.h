//
// Created by erez on 1/10/19.
//

#ifndef SECONDSTONE_SEARCHERADAPTER_H
#define SECONDSTONE_SEARCHERADAPTER_H


#include "Solver.h"
#include <vector>
#include "Searcher.h"
#include "SearchableMatrix.h"
#include "VectorMakerFromStrings.h"
#include "MatrixBuilder.h"

template <class S>

class SearcherAdapter : public Solver<Searchable, S> {
private:
    Searcher<S> *searcher;
    SearchableMatrix searchableMatrix;

private:
    SearchableMatrix FromLinesToMatrix(std::vector<std::string> lines){
        VectorMakerFromStrings vectorMakerFromStrings(lines);
        std::vector<std::vector<double>> vector1 = vectorMakerFromStrings.GetVector();
        MatrixBuilder matrixBuilder;
        return matrixBuilder.create(        vector1,
                                            vectorMakerFromStrings.GetInit(),
                                            vectorMakerFromStrings.GetGoal());
    }

public:
    // CONT
    SearcherAdapter(Searcher<S> *searcher, std::vector<std::string> &lines){
        this->searcher=searcher;
        this->searchableMatrix = FromLinesToMatrix(lines);
    }

    const SearchableMatrix &getSearchableMatrix() const {
        return searchableMatrix;
    }

    virtual S solve(Searchable searchable){
        return searcher->search(searchable);
    }
};


#endif //SECONDSTONE_SEARCHERADAPTER_H
