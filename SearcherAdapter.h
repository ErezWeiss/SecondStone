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
#include <iostream>

template <class P, class S, class G>
//P=Searchable<State<Point>*>
//S=std::string
//G=Point
class SearcherAdapter : public Solver<P, S> {
private:

    Searcher<G, S> *searcher;
    SearchableMatrix<G> *searchableMatrix = nullptr;

    SearchableMatrix<G>* FromLinesToMatrix(std::vector<S> lines){
        VectorMakerFromStrings<S> vectorMakerFromStrings(lines);
        std::vector<std::vector<double>> vector1 = vectorMakerFromStrings.GetVector();
        MatrixBuilder matrixBuilder;
        return matrixBuilder.create(        vector1,
                                            vectorMakerFromStrings.GetInit(),
                                            vectorMakerFromStrings.GetGoal());
    }

public:
    // CONT
    SearcherAdapter(Searcher<G, S> *searcher, std::vector<S> lines){
        this->searcher=searcher;
        this->searchableMatrix = FromLinesToMatrix(lines);
    }

    SearchableMatrix<G>* getSearchableMatrix()  {
        return searchableMatrix;
    }

    virtual S Solve(P *searchable){
        return searcher->search(searchable);
    }
};


#endif //SECONDSTONE_SEARCHERADAPTER_H
