//
// Created by user on 1/8/2019.
//

#include "StringReverser.h"
#include<algorithm>

StringReverser::StringReverser(String problem, String solution){
    this->problem=problem;
    this->solution=solution;
}

string StringReverser::Solve(){
    this->solution=reverse(this->problem.begin(),this->problem.end());
}

