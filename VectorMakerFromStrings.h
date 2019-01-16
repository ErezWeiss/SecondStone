//
// Created by erez on 1/12/19.
//

#ifndef SECONDSTONE_VECTORMAKERFROMSTRINGS_H
#define SECONDSTONE_VECTORMAKERFROMSTRINGS_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "Point.h"

template <class S>
class VectorMakerFromStrings {
private:
    std::vector<S> rows;
//    std::vector<std::string> rows;

public:
    VectorMakerFromStrings(std::vector<S> &input){
        this->rows=input;
//        this->Init();
    }

//    void Init(){
////        std::vector<std::string> rows1;
////        std::stringstream ss(input[0]);
////        std::string to;
////        while(std::getline(ss,to,'\n')){
////            rows1.push_back(to);
////            std::cout<<
////        }
//        this->rows=input;
//    }

    std::vector<std::vector<double>> GetVector(){
        std::vector<std::vector<double>> mainVector;
        double num;


        /// cannot access to secnod line and above
        for(auto t=rows.begin(); t!=rows.end()-3; ++t){
            std::vector<double> row;
            std::string line = *t;
            std::stringstream ss(line);
            while (ss >> num) {
                row.push_back(num);
                if (ss.peek() == ',')
                    ss.ignore();
            }
            mainVector.push_back(row);
        }
        return mainVector;
    }
    Point *GetInit(){
        S line = rows[rows.size()-3];
        double x, y;
        std::stringstream ss(line);
        ss >> x;
        if (ss.peek() == ',')
            ss.ignore();
        ss >> y;
        return new Point(x,y);
    }
    Point *GetGoal(){
        S line = rows[rows.size()-2];
        double x, y;
        std::stringstream ss(line);
        ss >> x;
        if (ss.peek() == ',')
            ss.ignore();
        ss >> y;
        return new Point(x,y);
    }
};


#endif //SECONDSTONE_VECTORMAKERFROMSTRINGS_H
