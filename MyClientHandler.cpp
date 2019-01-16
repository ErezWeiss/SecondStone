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

    auto mySearcher = new BestFirstSearch<Point, string>();
    auto searcherAdapter = new SearcherAdapter<Searchable<Point>, std::string, Point>(mySearcher, lines);
    this->solver = searcherAdapter;
    Searchable<Point> *searchable = searcherAdapter->getSearchableMatrix();
    std::string returnAnswer = solver->Solve(searchable);
    send(new_socket, returnAnswer.c_str(), returnAnswer.size(), 0);
}


ClientHandler* MyClientHandler::DuplicateCH(){
    return new MyClientHandler;
}