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
#include "MyClientHandler.h"

#define END "end"

//MyClientHandler::MyClientHandler(){
//    this->solver = new SearcherAdapter<string>(//searcher//);
//}

void MyClientHandler::handleClient(int new_socket) {
    Matrix *matrix = new Matrix;
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
////        string retStReverse = this->solver->solve(buffer);
////        send(new_socket, ret, retStReverse.size(), 0);
//
    }
    check = read(new_socket, buffer, 5000);
    if (check < 0) {
        perror("cannot read from client");
    }
    lines.push_back(buffer);

    check = read(new_socket, buffer, 5000);
    if (check < 0) {
        perror("cannot read from client");
    }
    lines.push_back(buffer);

    for (auto i = lines.begin(); i != lines.end(); ++i)
        std::cout << *i << ' ' << endl;

}