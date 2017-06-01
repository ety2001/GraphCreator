// Graph.cpp

#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(){
  numVertices = 0;
  for (int i = 0; i < 20; i++){
    labels[i] = '\0';
    for (int j = 0; j < 20; j++){
      adjTable[i][j] = -1;
    }
  }
};

int Graph::labelToIndex(char label){
  for (int i = 0; i < 20; i++){
    if(labels[i]==label){
      return i;
    }
  }
  return -1;
};

bool Graph::addVertex(char label){
  if(numVertices == 20){
    cout<<"There are already 20 vertices."<<endl;
    return false;
  }
  else if(labelToIndex(label)!=-1){
    cout<<"That label is already taken."<<endl;
    return false;
  }
  for (int i = 0; i < 20; i++){
    if(labels[i]=='\0'){
      labels[i] = label;
      numVertices++;
      return true;
    }
  }
};

bool Graph::addEdge(char label1, char label2, int weight){
  int index1 = labelToIndex(label1);
  int index2 = labelToIndex(label2);
  if(index1 == -1 or index2 == -2){
    cout<<"One of the labels does not exist."<<endl;
    return false;
  }
  adjTable[index1][index2] = weight;
  return true;
};

bool Graph::removeVertex(char label){
  int index = labelToIndex(label);
  if(index == -1){
    cout<<"That label does not exist."<<endl;
    return false;
  }
  labels[index] = '\0';
  for(int i = 0; i < 20; i++){
    adjTable[index][i] = -1;
    adjTable[i][index] = -1;
  }
  numVertices--;
  return true;
};

bool Graph::removeEdge(char label1, char label2){
  int index1 = labelToIndex(label1);
  int index2 = labelToIndex(label2);
  if(index1 == -1 or index2 == -2){
    cout<<"One of the labels does not exist."<<endl;
    return false;
  }
  adjTable[index1][index2] = -1;
  return true;
};

void Graph::printTable(){
  for(int i = 0; i < 20; i++){
    if(labels[i]!='\0'){
      cout<<"\t"<<labels[i];
    }
  }
  cout<<endl;
  for(int i = 0; i < 20; i++){
    if(labels[i]!='\0'){
      cout<<labels[i];
      for(int j = 0; j < 20; j++){
        if(labels[j]!='\0'){
          cout<<"\t"<<adjTable[i][j];
        }
      }
      cout<<endl;
    }
  }
};

int Graph::findPath(char label1, char label2, char* path){
  path[0] = '\0';
  int q[20];
  int length;
  int head = 0;
  int tail = 0;
  int vis[20];
  char backwards[20];
  for (int i = 0; i < 20; i++) {
    vis[i] = -1;
  }
  int index1 = labelToIndex(label1);
  int index2 = labelToIndex(label2);
  if(index1 == -1 or index2 == -2){
    cout<<"One of the labels does not exist."<<endl;
    return -1;
  }
  if(index1 == index2){
    path[0] = index1;
    path[1] = '\0';
    return 0;
  }
  q[tail] = index1;
  tail++;
  vis[index1] = index1;
  while(head!=tail){
    int curr = q[head];
    head++;
    for(int next = 0; next < 20; next++){
      if(adjTable[curr][next] != -1 && vis[next] == -1){
        q[tail] = next;
        tail++;
        vis[next] = curr;
        if(next == index2){
          int count = 0;
          length = 0;
          backwards[count] = labels[next];
          while(next!=index1){
            //length += adjTable[vis[next]][next];``
            length++;
            next = vis[next];
            backwards[++count] = labels[next];
          }
          count++;
          for (int i = 0; i < count; i++) {
            path[i] = backwards[count-i-1];
          }
          path[count] = '\0';
          return length;
        }
      }
    }
  }
  return -1;
};
