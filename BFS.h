//
// Created by user on 1/8/2019.
//https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
//to be complete...

#ifndef SECONDSTONE_BFS_H
#define SECONDSTONE_BFS_H
class MyBFS : public absSearch<std::string, Node*, std::string>
{
    unsigned int visits;

    virtual void increaseNumOfVisits(){ ++(this->visits); }

public:
    MyBFS(){ this->visits = 0; };
    virtual std::string search(Searchable<std::string, state<T>* mg);
    virtual unsigned int getNumOfVisits() { return this->visits; };
    virtual ~MyBFS(){};
};
//
//public BFS : public absSearch{
//public override Solution search(Isearchablesearchable) {
//    // Searcher's abstract method
//    overriding addToOpenList(searchable.getInitialState());
//    // inherited from Searcher
//    HashSet<State> closed = newHashSet<State>();
//    while(OpenListSize> 0) {
//            Staten = popOpenList();
//            // inherited from Searcher, removes the best state
//            closed.Add(n);
//            if (n.Equals(searchable.getIGoallState()))
//                returnbackTrace();
//            // private method, back traces through the parents
//            // calling the delegated method, returns a list of states with n as a parent
//            List <State> succerssors = searchable.getAllPossibleStates(n);
//            for each(States insuccerssors){
//                if (!closed.Contains(s) && !openContaines(s)) {
//                    // s.setCameFrom(n);// already done by getSuccessors
//                    this->addToOpenList(s);
//                } else if(distance < son->getAlgCost()){
//                    son->setAlgCost(distance);
//                    this->removeFromQueue(son);
//                   //when node enters to priority queue it updates the heap
//                   this->addToQueue(son);
//                }
//            }
//        }
//}
//};


#endif //SECONDSTONE_BFS_H
//// Program to print BFS traversal from a given
//// source vertex. BFS(int s) traverses vertices
//// reachable from s.
//#include<iostream>
//#include <list>
//
//using namespace std;
//
//// This class represents a directed graph using
//// adjacency list representation
//class Graph
//{
//    int V;    // No. of vertices
//
//    // Pointer to an array containing adjacency
//    // lists
//    list<int> *adj;
//public:
//    Graph(int V);  // Constructor
//
//    // function to add an edge to graph
//    void addEdge(int v, int w);
//
//    // prints BFS traversal from a given source s
//    void BFS(int s);
//};
//
//Graph::Graph(int V)
//{
//    this->V = V;
//    adj = new list<int>[V];
//}
//
//void Graph::addEdge(int v, int w)
//{
//    adj[v].push_back(w); // Add w to v’s list.
//}
//
//void Graph::BFS(int s)
//{
//    // Mark all the vertices as not visited
//    bool *visited = new bool[V];
//    for(int i = 0; i < V; i++)
//        visited[i] = false;
//
//    // Create a queue for BFS
//    list<int> queue;
//
//    // Mark the current node as visited and enqueue it
//    visited[s] = true;
//    queue.push_back(s);
//
//    // 'i' will be used to get all adjacent
//    // vertices of a vertex
//    list<int>::iterator i;
//
//    while(!queue.empty())
//    {
//        // Dequeue a vertex from queue and print it
//        s = queue.front();
//        cout << s << " ";
//        queue.pop_front();
//
//        // Get all adjacent vertices of the dequeued
//        // vertex s. If a adjacent has not been visited,
//        // then mark it visited and enqueue it
//        for (i = adj[s].begin(); i != adj[s].end(); ++i)
//        {
//            if (!visited[*i])
//            {
//                visited[*i] = true;
//                queue.push_back(*i);
//            }
//        }
//    }
//}
//
//// Driver program to test methods of graph class
//int main()
//{
//    // Create a graph given in the above diagram
//    Graph g(4);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 2);
//    g.addEdge(2, 0);
//    g.addEdge(2, 3);
//    g.addEdge(3, 3);
//
//    cout << "Following is Breadth First Traversal "
//         << "(starting from vertex 2) \n";
//    g.BFS(2);
//
//    return 0;
//}