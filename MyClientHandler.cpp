//
// Created by erez on 1/10/19.
//

#include <zconf.h>
#include <cstdio>
#include <vector>
#include <string>
#include <strings.h>
#include <iostream>
#include <mutex>
#include <cstring>
#include <sys/socket.h>
#include "MyClientHandler.h"
#include "SearcherAdapter.h"
#include "BestFirstSearch.h"
#include "Astar.h"
#include "DFS.h"
#include "BFS.h"

MyClientHandler::MyClientHandler(CacheManager<string, string> *cacheManager){
    this->cacheManager=cacheManager;
}

void MyClientHandler::handleClient(int new_socket) {
    std::vector<std::string> lines;

    char buffer[5000];
    ssize_t check = 0;
    std::string str;
    while (str.find("end")==string::npos) {
//        pthread_mutex_lock(&lock);
        bzero(buffer, 5000);
        check = read(new_socket, buffer, 5000);
        if (check < 0) {
            perror("cannot read from client");
        }
        str = buffer;
        lines.push_back(buffer);
        cout<< "got input from client from socket number: "<< new_socket<< endl << str<<endl<<"----"<<endl;
    }
    auto mySearcher = new Astar<Point, string>();
//    auto mySearcher = new BestFirstSearch<Point, string>();
    auto searcherAdapter = new SearcherAdapter<Searchable<Point>, std::string, Point>(mySearcher, lines);
    this->solver = searcherAdapter;
    Searchable<Point> *searchable = searcherAdapter->getSearchableMatrix();

    std::string problemForCheck="";
    for(auto const& value: lines) {
        problemForCheck+=value;
        problemForCheck+='$';
    }
    problemForCheck.erase(std::remove(problemForCheck.begin(), problemForCheck.end(), '\n'), problemForCheck.end());

    std::string returnAnswer;
    bool ifExist=this->cacheManager->ifExist(problemForCheck);
    if(ifExist){
        cout<<"exist!#################################";
        returnAnswer=this->cacheManager->getSolution(problemForCheck);
    } else{
        returnAnswer  = solver->Solve(searchable);
        this->cacheManager->saveSolution(problemForCheck,returnAnswer);
    }
    send(new_socket, returnAnswer.c_str(), returnAnswer.size(), 0);
}


ClientHandler* MyClientHandler::DuplicateCH(){
    return new MyClientHandler(this->cacheManager);
}