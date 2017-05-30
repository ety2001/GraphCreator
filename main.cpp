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

#include<iostream>;
#include<string.h>;
#include "Node.h";

using namespace std;


void addVertex(char* labels, int* count);

int main(){
  int table[20][20];
  char input[50];
  char labels[20];
  int count = 0;
  bool run = true;

  while(run){
    cout<<"Add Vertex (AV), Add Edge (AE), Remove Vertex (RV), Remove Edge(RE), Find Path (F)"<<endl;
    cin>>input;
    if(!strcmp(input, "AV"))
      addVertex(labels, count);
    }
    else if(!strcmp(input, "AE"))
      addEdge();
    }
    else if(!strcmp(input, "RV"))
      removeVertex();
    }
    else if(!strcmp(input, "RE"))
      removeEdge();
    }
    else if(!strcmp(input, "FP"))
      findPath();
    }
    else{
      cout<<"Not a valid input."<<endl;
    }
  }
  return 0;
}

void addVertex(char* labels, int* count){
  char label;
  cout<<"Enter a 1 character label"<<end;
  cin>>label;
  for(int i = 0; i < count; i++){
    if(labels[i]!=label){
      cout<<"That label already exists";
      addVertex(labels, count);
      break;
    }
  }
  labels[count-1] = label;
  count++;
}
