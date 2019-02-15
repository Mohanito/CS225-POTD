#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *insert) {
  Node * curr;
  if(*head == NULL){
    *head = insert;
  }
  curr = *head;
  cout<<"reached here"<<endl;

    while(curr->next_ != NULL){
      if(curr->data_ <= insert->data_ && insert->data_ <= curr->next_->data_){
        insert->next_ = curr -> next_;
        curr->next_ = insert;
        *curr = *insert;
      }
    }

        curr->next_ = insert;

        return;


}
