//
// Created by user on 1/7/2019.
//

#ifndef SECONDSTONE_SOLVER_H
#define SECONDSTONE_SOLVER_H


#include <vector>

using namespace std;
class Solver {
protected:
    vector<string> params;
public:
    Solution solve(Problem problem);
};

#endif //SECONDSTONE_SOLVER_H
