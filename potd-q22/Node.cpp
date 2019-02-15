#include "Node.h"
#include<vector>
using namespace std;

Node *listIntersection(Node *first, Node *second) {
  // your code here
  if(first == NULL || second == NULL){
    return NULL;
  }
  Node* temp1, *temp2, *result;
  std::vector<Node*> nodeArray;
  temp1 = first;
  temp2 = second;
  bool inArray;
  while(temp1 != NULL){
    for(temp2 = second; temp2 != NULL; temp2 = temp2->next_){
      if(temp2->data_ == temp1->data_){
        inArray = false;
        for(unsigned long i = 0; i < nodeArray.size(); i++){
          if(nodeArray[i]->data_ == temp2->data_){
            inArray = true;
          }
        }
        if(inArray == false){
          Node* temp = new Node(*temp2);
          nodeArray.push_back(temp);
        }
      }
    }
    temp1 = temp1->next_;
  }
  if(nodeArray.size() == 0){
    return NULL;
  }
  else{
    result = nodeArray[0];
    for(unsigned long i = 0; i < nodeArray.size() - 1; i++){
      nodeArray[i]->next_ = nodeArray[i+1];
    }
    nodeArray[nodeArray.size() - 1]->next_ = NULL;
  }
  return result;
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
