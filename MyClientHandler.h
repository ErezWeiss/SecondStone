//
// Created by erez on 1/10/19.
//

#ifndef SECONDSTONE_MYCLIENTHANDLER_H
#define SECONDSTONE_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Matrix.h"
#include "Solver.h"

class MyClientHandler : public ClientHandler {
private:
    Solver<string, Matrix> *solver;
public:
//    MyClientHandler();
    virtual void handleClient(int socket);
};


#endif //SECONDSTONE_MYCLIENTHANDLER_H
