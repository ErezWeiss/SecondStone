//
// Created by user on 1/12/2019.
//

#ifndef SECONDSTONE_MATRIXBUILDER_H
#define SECONDSTONE_MATRIXBUILDER_H


#include "SearchableMatrix.h"
#include "Point.h"

class MatrixBuilder{
    public:
        SearchableMatrix& create(std::vector<std::vector<double>> &matrix,Point initial,Point goal);
    };



#endif //SECONDSTONE_MATRIXBUILDER_H
