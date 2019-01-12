//
// Created by user on 1/12/2019.
//

#include "MatrixBuilder.h"



SearchableMatrix &MatrixBuilder::create(vector<vector<double> > &matrix, Point initial, Point goal) {
    int i, j = 0;
    vector<vector<double> > initial_matrix = matrix;
    double goal_cost = initial_matrix[goal.first][goal.second];
    State<Point> *goalState = new State<Point>(&goal, goal_cost);;
    double init_cost = initial_matrix[initial.first][initial.second];
    State<Point> *innitialState = new State<Point>(&initial, init_cost);
    vector<vector<State<Point> *>> searchable;
    vector<State<Point> *> temp;
    State<Point> *s;
    Point *p;
    for (vector<double> victor:initial_matrix) {
        for (double cost:victor) {
            //create state
            p = new Point(i, j);
            s = new State<Point>(p, cost);
            temp.push_back(s);
            j++;
        }
        searchable.push_back(temp);
        temp = vector<State<Point> *>();
        j = 0;
        i++;
    }
    //TODO DELETE MEMORY
    SearchableMatrix *searchableMatrix = new SearchableMatrix(innitialState, goalState, searchable);
    return *searchableMatrix;
}
