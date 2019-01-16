#include <iostream>
#include "MyParallelServer.h"
#include "MyClientHandler.h"
#include "SearcherAdapter.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include <string>
//using namespace boot;

bool stop = false;
int main() {
    std::cout << "Main begins" << std::endl;
    auto myParallelServer = new MyParallelServer;
    auto myCacheManager = new FileCacheManager<std::string, std::string>("solution");
    auto myClientHandler = new MyClientHandler(myCacheManager);
    myParallelServer->open(5407, myClientHandler);
    myParallelServer->stop();
    delete myCacheManager;
    delete myParallelServer;
    delete myClientHandler;
    return 0;
}

