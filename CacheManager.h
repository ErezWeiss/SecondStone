//
// Created by user on 1/7/2019.
//

#ifndef SECONDSTONE_CACHEMANAGER_H
#define SECONDSTONE_CACHEMANAGER_H

template <class P,class Solution>
class CacheManager{
public:
    virtual bool ifExist(const P& p)=0;
    virtual void saveSolution(const P& p, const Solution& s)=0;
    virtual Solution getSolution(const P& p)=0;

};

#endif //SECONDSTONE_CACHEMANAGER_H
