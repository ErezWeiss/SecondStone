//
// Created by erez on 1/9/19.
//

#ifndef SECONDSTONE_MYPARALLELSERVER_H
#define SECONDSTONE_MYPARALLELSERVER_H


#include <sys/socket.h>
#include <thread>
#include "ClientHandler.h"
#include "Server.h"

using namespace std;

//bool stop = false;

struct arg_struct {
    int newSocket;
    ClientHandler *clientHandler;
};

class MyParallelServer : public Server {
public:
    virtual void open (int port, ClientHandler * c);
    virtual void stop();
};

#endif //SECONDSTONE_MYPARALLELSERVER_H
