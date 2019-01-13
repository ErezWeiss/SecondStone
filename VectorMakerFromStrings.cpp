//
// Created by erez on 1/12/19.
//

#include <sstream>
#include "VectorMakerFromStrings.h"

VectorMakerFromStrings::VectorMakerFromStrings(std::vector<std::string> &input){
    this->input=input;
}

std::vector<std::vector<double>> VectorMakerFromStrings::GetVector(){
    std::vector<std::vector<double>> mainVector;
    bool flag = true;
    for ( auto i = input.begin(); i != input.end()-2; i++ ) {
        if (flag && *i != "end"){
            std::vector<double> row;
            std::string line = *i;
            std::stringstream ss(line);
            double num;
            while (ss >> num) {
                row.push_back(num);

                if (ss.peek() == ',')
                    ss.ignore();
            }
            mainVector.push_back(row);
        } else {
            flag=false;
        }
    }

    return mainVector;
}

Point VectorMakerFromStrings::GetInit(){
    std::string line = input[input.end()-2];
    double x, y;
    std::stringstream ss(line);
    ss >> x;
    if (ss.peek() == ',')
        ss.ignore();
    ss >> y;
    return Point(x,y);
}

Point VectorMakerFromStrings::GetGoal(){
        std::string line = input[input.end()-2];
            double x, y;
            std::stringstream ss(line);
            ss >> x;
            if (ss.peek() == ',')
                ss.ignore();
            ss >> y;
            return Point(x,y);
    }
}