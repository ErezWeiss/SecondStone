//
// Created by erez on 1/9/19.
//

#ifndef SECONDSTONE_CLIENTHANDLER_H
#define SECONDSTONE_CLIENTHANDLER_H


class ClientHandler {
public:
     void virtual handClient(int InputSocket, int OutputSocket) = 0;
};


#endif //SECONDSTONE_CLIENTHANDLER_H
