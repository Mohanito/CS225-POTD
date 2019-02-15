#include "Friend.h"
#include <vector>
using namespace std;
int find(int x, std::vector<int>& parents) {
   // your code
   return 0;
}

int findCircleNum(std::vector<std::vector<int>>& M) {
    // your code
    std::vector<int> sets;
    for(size_t i = 0; i < M.size(); i++){
      sets.push_back(-1);
    }
    for(size_t i = 0; i < M.size(); i++){
      for(size_t j = 0; j < M.size(); j++){
        if(i != j && M[i][j] == 1 && sets[i] != j){
          sets[j] = i;
        }
      }
    }
    int count = 0;
    for(size_t i = 0; i < sets.size(); i++){
      if(sets[i] == -1){count++;}
    }
    return count;
}
