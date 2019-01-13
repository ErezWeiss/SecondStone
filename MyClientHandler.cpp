//
// Created by erez on 1/10/19.
//



#include <zconf.h>
#include <cstdio>
#include "Matrix.h"
#include <vector>
#include <string>
#include <strings.h>
#include <iostream>
#include <mutex>
#include <cstring>
#include <sys/socket.h>
#include "MyClientHandler.h"
#include "SearcherAdapter.h"

#define END "end"


void MyClientHandler::handleClient(int new_socket) {
    std::vector<std::string> lines;

    //TO DO : WHAT IS THE SIZE OF INPUT?
    char buffer[5000];
    int check = 0;
    int natalie = 0;
    std::string str;
    //reads from client as long as input is not stop
    while (strcmp(buffer, END)!=0) {
//        pthread_mutex_lock(&lock);
        bzero(buffer, sizeof(str));
        check = read(new_socket, buffer, 5000);
        if (check < 0) {
            perror("cannot read from client");
        }
        lines.push_back(buffer);
        str = buffer;

    }


    for (auto i = lines.begin(); i != lines.end(); ++i)
        std::cout << *i << ' ' << "myclienthandler "<< endl;

    SearcherAdapter<string> *searcherAdapter = new SearcherAdapter<string>(*searcher, lines);
    //TODO
    //add CONT args:
    // searcher and lines
    // i didnt use the solver for now. problem of pointers...
//    Solver<Searchable, string> *solver1 = searcherAdapter;
//    this->solver = solver1;
    std::string returnAnswer = searcherAdapter->solve(searcherAdapter->getSearchableMatrix());
    send(new_socket, returnAnswer.c_str(), returnAnswer.size(), 0);

}
