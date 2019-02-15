#include "Node.h"

using namespace std;

void mergeList(Node *first, Node *second) {
  if(first == NULL && second == NULL){
    return;
  }
  Node* tempfirst;
  Node* tempsecond;
  Node* curr;
  tempfirst = first;
  curr = first;
  tempsecond = second;
  int smaller = 1;
  int count = 1;
  if(first->getNumNodes() < second->getNumNodes()){
    smaller = 2;
  }
  while((tempfirst != NULL) && (tempsecond != NULL)){
    if(count % 2 == 1){
      tempfirst = tempfirst->next_;
      curr->next_ = tempsecond;
      curr = curr->next_;
    }
    else{
      tempsecond = tempsecond->next_;
      curr->next_ = tempfirst;
      curr = curr->next_;
    }
    count++;


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
