//
// Created by erez on 1/10/19.
//

#ifndef SECONDSTONE_MYCLIENTHANDLER_H
#define SECONDSTONE_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "MatrixBuilder.h"
#include "CacheManager.h"

class MyClientHandler : public ClientHandler {
private:
    Solver<Searchable<Point>, std::string> *solver;
    CacheManager<string, string> *cacheManager;

public:
    MyClientHandler(CacheManager<string, string> *cacheManager);
    virtual void handleClient(int socket);
    virtual ClientHandler* DuplicateCH();
};
// TODO: close the socket


#endif //SECONDSTONE_MYCLIENTHANDLER_H
