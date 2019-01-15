//
// Created by user on 1/7/2019.
//

#ifndef SECONDSTONE_SOLVER_H
#define SECONDSTONE_SOLVER_H


#include <vector>
#include <string>

using namespace std;
template <class P, class S>

class Solver {
public:
    virtual S Solve(P *p) = 0;
};

#endif //SECONDSTONE_SOLVER_H
