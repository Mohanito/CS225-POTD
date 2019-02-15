#include <vector>
#include "BTreeNode.h"


BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
    BTreeNode* result = NULL;
    for(unsigned long i = 0; i < root->elements_.size(); i++){
      if(root->elements_[i] == key){
        return root;
      }
    }
    for(unsigned long j = 0; j < root->children_.size(); j++){
      result = find(root->children_[j], key);
      if(result != NULL){return result;}
    }
  return result;
}
