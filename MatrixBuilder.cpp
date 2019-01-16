//
// Created by user on 1/12/2019.
//

#include "MatrixBuilder.h"



SearchableMatrix<Point>* MatrixBuilder::create(std::vector<std::vector<double> > &matrix, Point *initial, Point *goal) {
    int i=0, j = 0;
    std::vector<std::vector<double> > initial_matrix = matrix;
//    double goal_cost = initial_matrix[goal->getX()][goal->getY()];
//    State<Point> *goalState = new State<Point>(goal, goal_cost);;
//    double init_cost = initial_matrix[initial->getX()][initial->getY()];
//    State<Point> *innitialState = new State<Point>(initial, init_cost);
    std::vector<std::vector<State<Point> *>> searchable;
    std::vector<State<Point> *> temp;
    State<Point> *s;
    Point *p;

    State<Point> *innitialState;
    State<Point> *goalState;
    for (std::vector<double> victor:initial_matrix) {
        for (double cost:victor) {
            //create state
            p = new Point(i, j);
            s = new State<Point>(p, cost);

            if (initial->getX()==i && initial->getY()==j){
                innitialState = s;
            } else if (goal->getX()==i && goal->getY()==j){
                goalState=s;
            }

            temp.push_back(s);
            j++;
        }
        searchable.push_back(temp);
        temp = std::vector<State<Point> *>();
        j = 0;
        i++;
    }
    //TODO DELETE MEMORY
    SearchableMatrix<Point> *searchableMatrix = new SearchableMatrix<Point>(searchable, innitialState, goalState);
    return searchableMatrix;
}
