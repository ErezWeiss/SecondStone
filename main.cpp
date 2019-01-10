#include <iostream>
#include "MyParallelServer.h"
#include <>
#include "MyTestClientHandler.h"
//using namespace boot;


int main() {
    std::cout << "Hello, World!" << std::endl;

    Server *myParallelServer = new MyParallelServer;
    ClientHandler *yossi = new MyTestClientHandler();
    myParallelServer->open(5050, yossi);

    return 0;
}

