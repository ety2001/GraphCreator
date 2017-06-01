//Graph.h

#ifndef Graph_h
#define Graph_h

class Graph {
  private:
    int adjTable[20][20];
    char labels[20];
    int numVertices;
    int labelToIndex(char);
  public:
    Graph();
    bool addVertex(char);
    bool addEdge(char, char, int);
    bool removeVertex(char);
    bool removeEdge(char, char);
    void printTable();
    int findPath(char, char, char*);
};
#endif
