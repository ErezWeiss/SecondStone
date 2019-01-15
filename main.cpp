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
    auto myClientHandler = new MyClientHandler;

    myParallelServer->open(5408, myClientHandler);

    while(1){

    }
    return 0;
}

