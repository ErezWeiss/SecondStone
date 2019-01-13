//
// Created by erez on 1/12/19.
//

#ifndef SECONDSTONE_VECTORMAKERFROMSTRINGS_H
#define SECONDSTONE_VECTORMAKERFROMSTRINGS_H

#include <vector>
#include <string>
#include "Point.h"

class VectorMakerFromStrings {
private:
    std::vector<std::string> input;
public:
    VectorMakerFromStrings(std::vector<std::string> &input);
    std::vector<std::vector<double>> GetVector();
    Point GetInit();
    Point GetGoal();
};


#endif //SECONDSTONE_VECTORMAKERFROMSTRINGS_H
