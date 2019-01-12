//
// Created by user on 1/11/2019.
//

#ifndef SECONDSTONE_STATE_H
#define SECONDSTONE_STATE_H
template <class T>
class State {
    // the state represented by a string
    T* state;
    // cost to reach this state (set by a setter)
    double cost;
    // the state we came from to this state (setter)
    State<T> *cameFrom;
    double sumOfVertex;
public:
    State (T* stet, double cost){
        this->state = stet;
        this->cost = cost;
        this->cameFrom = nullptr;
        this->sumOfVertex =0;
    }

    T *getState() const {
        return state;
    }

    void setState(T *state) {
        State::state = state;
    }

    double getCost() const {
        return cost;
    }

    void setCost(double cost) {
        State::cost = cost;
    }

    State<T> *getCameFrom() const {
        return cameFrom;
    }

    void setCameFrom(State<T> *cameFrom) {
        State::cameFrom = cameFrom;
    }

    double getSumOfVertex() const {
        return sumOfVertex;
    }

    void setSumOfVertex(double sumOfVertex) {
        State::sumOfVertex = sumOfVertex;
    }

    // we overload Object's Equals method
    bool ifIsEquals(State <T>* s) {
        return (this->state == s->state);
    }

};
#endif //SECONDSTONE_STATE_H
