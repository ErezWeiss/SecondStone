//
// Created by erez on 1/9/19.
//

#ifndef SECONDSTONE_MYTESTCLIENTHANDLER_H
#define SECONDSTONE_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"

class MyTestClientHandler : public ClientHandler {
public:
    void virtual handClient(int InputSocket, int OutputSocket);

private:
    Solver solver;
    CacheManager cm;
};


#endif //SECONDSTONE_MYTESTCLIENTHANDLER_H
