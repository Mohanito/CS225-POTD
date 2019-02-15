#include "potd.h"
#include <iostream>
#include <string>
using namespace std;

string stringList(Node *head) {
    // your code here!
    Node *curr = head;
    if(curr == NULL){
      return "Empty list";
    }
    string output = "";
    int index = 0;
    while (curr != NULL){

      output += ("Node "+ std::to_string(index) + ": " + std::to_string(curr->data_));
      index++;
      curr = curr->next_;
      if(curr!= NULL){
        output += " -> ";
      }
    }
    return output;
}
