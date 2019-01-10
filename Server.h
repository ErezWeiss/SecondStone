//
// Created by user on 1/7/2019.
//

#ifndef SECONDSTONE_SERVER_H
#define SECONDSTONE_SERVER_H

#include <string>
#include <vector>
#include "ClientHandler.h"

using namespace std;
class Server {
protected:
    vector<string> params;
public:
    // opening the server and listening on this port
    virtual void open (int port, ClientHandler c) = 0;
    // closing the server
    virtual  void stop() = 0;
};

#endif //SECONDSTONE_SERVER_H
