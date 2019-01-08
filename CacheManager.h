//
// Created by user on 1/7/2019.
//

#ifndef SECONDSTONE_CACHEMANAGER_H
#define SECONDSTONE_CACHEMANAGER_H
#include <string>
#include <vector>

using namespace std;
//code for example
class CacheManager {
protected:
    vector<string> params;
public:
//    virtual int execute() = 0;
    virtual bool exist(solution,problem) = 0;
    virtual void getSolution(problem) = 0;
    void setSolution(solution,problem) = 0;
};

#endif //SECONDSTONE_CACHEMANAGER_H
