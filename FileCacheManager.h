//
// Created by user on 1/7/2019.
//

#ifndef SECONDSTONE_FILECACHEMANAGER_H
#define SECONDSTONE_FILECACHEMANAGER_H

#include <bits/pthreadtypes.h>
#include "CacheManager.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <iostream>

template <class P, class S>
class FileCacheManager: public CacheManager<P, S> {
    //file format:
    //each line- string of P:string of S
    std::unordered_map<P, S> map;
    std::string fileName;
    bool isLoaded = false;
    pthread_mutex_t tex;

    void loadMap(){
        if(isLoaded) {
            return;
        }
        std::ifstream readFile;
        readFile.open(this->fileName);
        if(readFile.is_open()) {
            std::string line;
            while (getline(readFile, line)) {
                std::string Problem, Solution;
                Problem = line.substr(0, line.find(':'));
                line.erase(0, line.find(':')+1);
                Solution = line;
                std::stringstream ssp(Problem);
                std::stringstream sss(Solution);
                P prob;
                S sol;
                ssp>>prob;
                sss>>sol;

                map[prob] = sol;
            }
        }
        isLoaded = true;
    }

    void saveMap(){
        pthread_mutex_lock(&this->tex);
        if(!isLoaded) {
            loadMap();
        }
        std::ofstream writeToFile;
        writeToFile.open(this->fileName, std::ios::trunc);
        if(!writeToFile.is_open()) {
            throw "can't open FileCacheManager file";
        }
        for(const auto& keyVal: this->map) {
            writeToFile << keyVal.first << ":" << keyVal.second << std::endl;
        }
        pthread_mutex_unlock(&this->tex);

    }


public:
    explicit FileCacheManager<P,S>(const std::string& file_name) {
        this->fileName = file_name;
        pthread_mutex_init(&this->tex, nullptr);
    }


    ~FileCacheManager(){
        saveMap();
        pthread_mutex_destroy(&this->tex);
    }


    bool ifExist(const P& p) override {
        pthread_mutex_lock(&this->tex);
        if(!isLoaded) {
            loadMap();
        }
        bool res;
        res =(map.find(p) != map.end())? true:false;
        pthread_mutex_unlock(&this->tex);
        return res;
    }


    void saveSolution(const P& p,const S& s) override {
        pthread_mutex_lock(&this->tex);
        map[p] = s;
        pthread_mutex_unlock(&this->tex);

    }

    S getSolution(const P& p) override {
        std::cout<<"solution loaded from file"<<endl;
        pthread_mutex_lock(&this->tex);
        if(!isLoaded) {
            loadMap();
        }
        S s = map[p];
        pthread_mutex_unlock(&this->tex);
        return s;
    }

};


#endif //SECONDSTONE_FILECACHEMANAGER_H
