//
// Created by user on 1/8/2019.
//

#ifndef SECONDSTONE_STRINGREVERSECH_H
#define SECONDSTONE_STRINGREVERSECH_H

#include "ClientHandler.h"
#include "Solver.h"
#include "string"

using namespace std;

class StringReverseCH : public ClientHandler {
    Solver<string, string> *solver;
public:
    StringReverseCH();

    void handleClient(int socket)override;
};


#endif //SECONDSTONE_STRINGREVERSECH_H
