#include "Node.h"
#include<vector>

using namespace std;

void sortList(Node **head) {
  if(*head == NULL){
    return;
  }
  std::vector<Node*> nodeArray;
  Node* temp;
  temp = (*head);
  for(int i = 0; i < (*head) -> getNumNodes(); i++){
    nodeArray.push_back(temp);
    temp = temp->next_;
  }
  for (int i = 0; i < (*head)->getNumNodes(); i++){
    int min = nodeArray[i]->data_;
    int minIndex = i;
    for(int j = i+1; j<(*head)->getNumNodes();j++){
      if(nodeArray[j]->data_ <= min){
        min = nodeArray[j] ->data_;
        minIndex = j;
      }
    }
    temp = nodeArray[i];
    nodeArray[i] = nodeArray[minIndex];
    nodeArray[minIndex] = temp;
  }
  nodeArray[(*head)->getNumNodes() - 1]->next_ = NULL;
  (*head) = nodeArray[0];
  temp = (*head);
  for(int i = 1; i<(*head)->getNumNodes();i++){
    temp->next_ = nodeArray[i];
    temp = nodeArray[i];
  }
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
