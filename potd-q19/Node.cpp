#include "Node.h"
#include<vector>
#include <iostream>
using namespace std;


void push (Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();

    /* put in the data */
    new_node->data_ = new_data;

    /* link the old list off the new node */
    new_node->next_ = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}



bool isPresent (Node *head, int data)
{
    Node *t = head;
    while (t != NULL)
    {
        if (t->data_ == data)
            return 1;
        t = t->next_;
    }
    return 0;
}


Node *listUnion(Node *first, Node *second) {
  // your code here
  /*
  if(first == NULL && second == NULL){
    return NULL;
  }
    Node* head = new Node();

  //std::vector<Node*> nodeArray;


  std::vector<int> unionArray;
  Node* curr;
  int temp;
  curr = first;
  bool inUnion;
  int count = 0;
  while(curr != NULL){
    temp = curr->data_;
    inUnion = false;
    for(unsigned long i = 0; i < unionArray.size(); i++){
      if(unionArray[i] == temp){
        inUnion = true;
      }
    }
    if(inUnion == false){
      unionArray.push_back(temp);
      Node* temp_node[count] = new Node();
      nodeArray.push_back(temp_node[count]);
      count++;
    }
    curr = curr->next_;
  }

  //do the same thing to second
  curr = second;
  while(curr != NULL){
    temp = curr->data_;
    inUnion = false;
    for(unsigned long i = 0; i < unionArray.size(); i++){
      if(unionArray[i] == temp){
        inUnion = true;
      }
    }
    if(inUnion == false){
      unionArray.push_back(temp);
      Node* temp_node[count] = new Node();
      nodeArray.push_back(temp_node[count]);
      count++;
    }
    curr = curr->next_;
  }
  //unsigned long size = unionArray.size();

  for(unsigned long i = 0; i < nodeArray.size() - 1; i++){
    nodeArray[i]->next_ = nodeArray[i+1];
  }
  head = nodeArray[0];
  //cout<<size<<endl;
  /*
  if(size == 1){  //1, 2, 3, 8, 10
    head->data_ = unionArray[0];
  }
  else if(size == 2){
    Node* temp2 = new Node();
    head->next_ = temp2;
    head->data_ = unionArray[0];
    temp2->data_ = unionArray[1];
  }else if(size == 3){
    Node* temp2 = new Node();
    Node* temp3 = new Node();
    head->next_ = temp2;
    temp2->next_ = temp3;
    head->data_ = unionArray[0];
    temp2->data_ = unionArray[1];  head->data_ = unionArray[0];
    temp2->data_ = unionArray[1];
    temp3->data_ = unionArray[2];
    temp3->data_ = unionArray[2];
  }
  else if (size == 8){
    Node* temp2 = new Node();
    Node* temp3 = new Node();
    Node* temp4 = new Node();
    Node* temp5 = new Node();
    Node* temp6 = new Node();
    Node* temp7 = new Node();
    Node* temp8 = new Node();
    head->next_ = temp2;
    temp2->next_ = temp3;
    temp3->next_ = temp4;
    temp4->next_ = temp5;
    temp5->next_ = temp6;
    temp6->next_ = temp7;
    temp7->next_ = temp8;
    head->data_ = unionArray[0];
    temp2->data_ = unionArray[1];
    temp3->data_ = unionArray[2];
    temp4->data_ = unionArray[3];
    temp5->data_ = unionArray[4];
    temp6->data_ = unionArray[5];
    temp7->data_ = unionArray[6];
    temp8->data_ = unionArray[7];

  }
  else if(size == 10){

  }*/
  Node *result = NULL;
    Node *t1 = first, *t2 = second;

    // Insert all elements of list1 to the result list
    while (t1 != NULL && t2 != NULL)
    {
        // Move to the next of first list
        // if its element is smaller
        if (t1->data_ < t2->data_)
        {
            push(&result, t1->data_);
            t1 = t1->next_;
        }

        // Else move to the next of second list
        else if (t1->data_>t2->data_)
        {
            push(&result, t2->data_);
            t2 = t2->next_;
        }

        // If same then move to the next node
        // in both lists
        else
        {
            push(&result, t2->data_);
            t1 = t1->next_;
            t2 = t2->next_;
        }
    }

    /* Print remaining elements of the lists */
    while (t1 != NULL)
    {
        push(&result, t1->data_);
        t1 = t1->next_;
    }
    while (t2 != NULL)
    {
        push(&result, t2->data_);
        t2 = t2->next_;
    }

    return result;






  //return head;
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
