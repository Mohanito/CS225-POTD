#include "Memory.h"
#include <iostream>
#include <iomanip>
#include "Node.h"
#include <vector>
#include <utility>

using namespace std;

/**
Frees the given memory address. Returns if the free was successful or not
Be sure to merge adjacent free blocks when possible
*/
bool Memory::free(unsigned address) {
    Node* current = head;
    while (current != NULL) {
        if (current->address == address) {
            // Your code there

            current->inUse = false;
            if(current->previous != NULL){
              if(current->previous->inUse == false){
                Node* temp = current->previous;
                current->previous = temp->previous;
                if(current->previous != NULL){
                  current->previous->next = current;
                }
                delete temp;
              }
            }

            if(current->next != NULL){
              if(current->next->inUse == false){
                Node* temp = current->next;
                current->next = temp->next;
                if(current->next != NULL){
                  current->next->previous = current;
                }
                delete temp;
              }
            }


            return true;
        }
        current = current->next;
    }

    return false;
}


/**
Reorganizes memory structure so that all of the allocated memory is grouped at the bottom (0x0000) and there is one large
chunk of free memory above.

Note: We do not care about the order of the allocated memory chunks
*/
void Memory::defragment() {
    Node* current = head;
    while (current != NULL) {

        if (current->inUse) {
            // Do nothing
        } else {
            // TODO: Find the next chunk of allocated memory and shift it down to current's address
            // We recommend using the helper function `findNextAllocatedMemoryChunk

            // Your code here

            Node* temp = findNextAllocatedMemoryChunk(current);
            if(temp != NULL){
              temp->inUse = false;
              current->inUse = true;
              /*unsigned temp_addr = temp->address;
              temp->address = current->address;
              current->address = temp_addr;

              Node* temp_node = temp->previous;
              temp->previous = current->previous;
              current->previous = temp_node;

              temp_node = temp->next;
              temp->next = current->next;
              current->next = temp_node;*/

              //if(temp->previous != NULL){temp->previous->next = temp;}
              //if(temp->next != NULL){temp->next->previous = temp;}
              //if(current->previous != NULL){current->previous->next = current;}
              //if(current->next != NULL){current->next->previous = current;}

              //current = temp;
            }
        }

        current = current->next;
    }

    // TODO: Finally merge all of the free blocks of memory together
    current = head;
    while(current->next != NULL){
      if(current->inUse == false && current->next->inUse == false){
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
      }
      current = current->next;
    }
}
