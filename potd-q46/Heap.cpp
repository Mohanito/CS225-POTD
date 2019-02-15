#include "Heap.h"
#include <iostream>

void Heap::_percolateDown(int hole) {
    // your code here
    if(hole * 2 < _data.size()){
      int maxchildidx;
      if(hole * 2 + 1 == _data.size()){
        maxchildidx = hole * 2;
      }
      else{
        if(_data[hole * 2] > _data[hole * 2 + 1]){
          maxchildidx = hole * 2;
        }
        else{
          maxchildidx = hole * 2 + 1;
        }
      }

      if(_data[hole] < _data[maxchildidx]){
        std::swap(_data[hole], _data[maxchildidx]);
        _percolateDown(maxchildidx);
      }
    }
}

int Heap::size() const {
    return _data.size();
}

void Heap::enQueue(const int &x){
    _data.push_back(x);
    int hole = _data.size() - 1;
    for(; hole > 1 && x > _data[hole/2]; hole /= 2){
        _data[hole] = _data[hole/2];
    }
    _data[hole] = x;
}

int Heap::deQueue(){
    int minItem = _data[1];
    _data[1] = _data[_data.size() - 1];
    _data.pop_back();
    _percolateDown(1);
    return minItem;
}

void Heap::printQueue(){
    std::cout << "Current Priority Queue is: ";
    for(auto i = _data.begin() + 1; i != _data.end(); ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

std::vector<int> & Heap::getData() {
    return _data;
}
