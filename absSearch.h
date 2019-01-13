//
// Created by user on 1/12/2019.
//

#ifndef SECONDSTONE_ABSSEARCH_H
#define SECONDSTONE_ABSSEARCH_H

#include <string>
#include "Searcher.h"
#include "State.h"
#include "MatrixBuilder.h"

class absSearch : public Searcher
{
private:
    MyPriorityQueue<State> openList;
    int evaluated Nodes;



protected:
State popOpenList(){
    evaluatedNodes++;
    return openList.poll();
}
// a property of openList
public:
    absSearch(){
        openList=newMyPriorityQueue<State>();
        evaluatedNodes=0;
    }
    int OpenListSize{
        // it is a read-only property :)
        get{ returnopenList.Count; }
}
// ISearcher’smethods:
public int getNumberOfNodesEvaluated(){
    return evaluatedNodes;
}
public Solution search(ISearchable searchable);

};
#endif //SECONDSTONE_ABSSEARCH_H

//get the vector from user. add a VectorMakerFromString and add a Matrixbuilder!
