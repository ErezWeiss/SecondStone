//
// Created by user on 1/8/2019.
//

#include "StringReverser.h"
#include<algorithm>

string StringReverser::solve(string problem) {
    string rev = problem;
    reverse(rev.begin(), rev.end());
    return rev;
}


