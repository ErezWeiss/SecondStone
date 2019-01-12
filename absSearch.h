//
// Created by user on 1/12/2019.
//
#include "Searcher.h"
#include "State.h"
#include "MatrixBuilder.h"
#ifndef SECONDSTONE_ABSSEARCH_H
#define SECONDSTONE_ABSSEARCH_H
class absSearch : public Searcher
{
private MyPriorityQueue<State> openList;
private int evaluated Nodes;
    publicSearcher(){
        openList=newMyPriorityQueue<State>();
        evaluatedNodes=0;
    }
};
protected State popOpenList(){
    evaluatedNodes++;
    return openList.poll();
}
// a property of openList
public int OpenListSize{
        // it is a read-only property :)
        get{ returnopenList.Count; }
}
// ISearcher’smethods:
public int getNumberOfNodesEvaluated(){
    returnevaluatedNodes;
}
public Solution search(ISearchable searchable);
}
#endif //SECONDSTONE_SEARCHER_H

#endif //SECONDSTONE_ABSSEARCH_H
