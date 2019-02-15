#include <unordered_map>

using namespace std;

unordered_map<string, int> common_elems(unordered_map<string, int> &mapA,
                                        unordered_map<string, int> &mapB) {

    // your code here
    unordered_map<string, int> mapC;
    unordered_map<string, int>::iterator it = mapA.begin();
    unordered_map<string, int>::iterator it2;
    while(it != mapA.end()){
      string key = it->first;
      bool incremented = false;
      for(it2 = mapB.begin(); it2 != mapB.end(); ){
        if(key == it2->first){
          mapC[key] = it->second + it2->second;
          it = mapA.erase(it);
          it2 = mapB.erase(it2);
          incremented = true;
        }
        else{
          it2++;
        }
      }



      if(!incremented){
        it++;
      }

    }
    return mapC;
}
