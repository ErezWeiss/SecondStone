//
// Created by erez on 1/9/19.
//

#ifndef SECONDSTONE_CLIENTHANDLER_H
#define SECONDSTONE_CLIENTHANDLER_H

class ClientHandler {

public:
    virtual void handleClient(int Socket) = 0;
    virtual ClientHandler* DuplicateCH()=0;
};


#endif //SECONDSTONE_CLIENTHANDLER_H
