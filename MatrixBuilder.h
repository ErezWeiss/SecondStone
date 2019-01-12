//
// Created by user on 1/12/2019.
//

#ifndef SECONDSTONE_MATRIXBUILDER_H
#define SECONDSTONE_MATRIXBUILDER_H


class MatrixBuilder {

#include "SearchableMatrix.h"

    class MatrixBuilder{
    public:
        SearchableMatrix& create(vector<vector<double > >&matrix,Point initial,Point goal);
    };
};


#endif //SECONDSTONE_MATRIXBUILDER_H
