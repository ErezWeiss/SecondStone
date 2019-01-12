#include<iostream>
#include<stdlib.h>
#include <w32api/wsman.h>
#include "Matrix.h"
//to be complete
//vector<int> Matrix::parseLineInput(string line) {
//    vector<int> returnStringVector;
//    int firstVal = atoi((line.substr(0, line.find(","))).c_str());
//    returnStringVector.push_back(firstVal);                                // push the first word into the vector
//    line.erase(0, line.find(',') + 1);                                      // erase the first word
//    string port = "";
//    for (unsigned int i = 0; i < line.length(); i++) {                      // if it an complicated exp. cut it and put into the vector
//        char c = line[i];
//        if (isdigit(c)) {
//            if (line[i+1]==' ' && isdigit(line[i + 2])) {
//                port = line.substr(0, i+1);
//                returnStringVector.push_back(port);
//                line.erase(0, i + 2);
//            }
//        }
//    }
//    returnStringVector.push_back(line);
//    return returnStringVector;
//}
//vector<int> Matrix::parseLineInput(string line) {
//vector<string> returnStringVector;
//string firstWord = line.substr(0, line.find(','));
//returnStringVector.push_back(firstWord);                                // push the first word into the vector
//line.erase(0, line.find(',') + 1);                                      // erase the first word
//string port = "";
//for (unsigned int i = 0; i < line.length(); i++) {                      // if it an complicated exp. cut it and put into the vector
//char c = line[i];
//if (isdigit(c)) {
//if (line[i+1]==' ' && isdigit(line[i + 2])) {
//port = line.substr(0, i+1);
//returnStringVector.push_back(port);
//line.erase(0, i + 2);
//}
//}
//}
//returnStringVector.push_back(line);
//return returnStringVector;
//}