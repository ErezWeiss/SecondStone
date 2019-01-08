//
// Created by user on 1/8/2019.
//

#ifndef SECONDSTONE_STRINGREVERSER_H
#define SECONDSTONE_STRINGREVERSER_H

#include "Solver.h"

class StringReverser : public Solver{
private:
string problem;
string solution;
public:
    StringReverser(string problem, string solution);
    string StringReverser::Solve();
    ~StringReverser();
};

#endif //SECONDSTONE_STRINGREVERSER_H
