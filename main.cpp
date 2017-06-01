//main.cpp
/* Create a program which can create graphs (we are using weighted edge, directed graphs), and it can search for a
 path in the graph using breadth-first search.  Use an adjacency table for the graph, which can be printed out.
 (You may assume that no more than 20 vertices will be in the table.)

Add Vertex: Enter a label for a vertex. Add it to the graph. (5 points)

Add Edge: Enter two node names and a weight (number). Add an edge between them, from the first node to the
second node. (You would need to create another edge to go both directions.)  (5 points)

Remove Vertex: Enter a vertex label and remove it from the graph. Remove all edges to that vertex.  (5 points)

Remove Edge: Enter two vertex labels, and remove an edge between them.  (5 points)

Find Path: Enter two vertex labels. Starting at the first label, use a breadth-first search to find a path
between the first vertex and the last vertex. Return the shortest path (and total) if it exists, or return
that no path exists.  (5 points)
*/

#include<iostream>
#include<string.h>
#include "Graph.h"

using namespace std;

int main(){
  Graph graph;
  char input[50];
  char path[20];
  char label;
  char label1;
  char label2;
  int length;
  int weight;
  bool run = true;

  while(run){
    cout<<"Add Vertex (AV), Add Edge (AE), Remove Vertex (RV), Remove Edge(RE), Print Table (PT), Find Path (FP), or Quit (Q)"<<endl;
    cin>>input;
    if(!strcmp(input, "AV")){
      cout<<"Enter the label: ";
      cin>>label;
      cin.ignore();
      graph.addVertex(label);
    }
    else if(!strcmp(input, "AE")){
      cout<<"Enter the first label: ";
      cin>>label1;
      cin.ignore();
      cout<<"Enter the second label: ";
      cin>>label2;
      cin.ignore();
      cout<<"Enter the weight: ";
      cin>>weight;
      cin.ignore();
      graph.addEdge(label1, label2, weight);
    }
    else if(!strcmp(input, "RV")){
      cout<<"Enter the label: ";
      cin>>label;
      cin.ignore();
      graph.removeVertex(label);
    }
    else if(!strcmp(input, "RE")){
      cout<<"Enter the first label: ";
      cin>>label1;
      cin.ignore();
      cout<<"Enter the second label: ";
      cin>>label2;
      cin.ignore();
      graph.removeEdge(label1, label2);
    }
    else if(!strcmp(input, "PT")){
      graph.printTable();
    }
    else if(!strcmp(input, "FP")){
      cout<<"Enter the first label: ";
      cin>>label1;
      cin.ignore();
      cout<<"Enter the second label: ";
      cin>>label2;
      cin.ignore();
      length = graph.findPath(label1, label2, path);
      if(length>=0){
        cout<<path<<": "<<length<<endl;
      }
      else{
        cout<<"No path exists."<<endl;
      }
    }
    else if(!strcmp(input, "Q")){
      run = false;
    }
    else{
      cout<<"Not a valid input."<<endl;
    }
  }
  return 0;
}
