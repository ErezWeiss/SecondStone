#include <iostream>
#include "MyParallelServer.h"
#include "MyClientHandler.h"
#include "SearcherAdapter.h"
#include "Solver.h"
//using namespace boot;

bool stop = false;
int main() {
    std::cout << "Main begins" << std::endl;

    Server *myParallelServer = new MyParallelServer;
    ClientHandler *myClientHandler = new MyClientHandler<string>;

    myParallelServer->open(8080, myClientHandler);

    while(1){

    }
    return 0;
}

