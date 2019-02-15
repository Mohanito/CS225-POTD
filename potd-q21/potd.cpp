#include "potd.h"

// Your code here!
#include <string>
#include <vector>

double sum(vector<double>::iterator start, vector<double>::iterator end){
  double sum = 0;
  for(vector<double>::iterator it = start; it != end; it++){
    sum += *it;
  }
  return sum;
}

/** Returns an iterator that points to the element with the largest value between start and end. */
vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end){
  vector<double>::iterator max, temp;
  double num = *start;
  for(temp = start; temp != end; temp++){
    if(*temp >= num){
      max = temp;
      num = *temp;
    }
  }
  return max;
}

/** Sort, in descending order, part of an array between start to end.
	Hint: use max_iter.
*/
void sort_vector(vector<double>::iterator start, vector<double>::iterator end){
  vector<double>::iterator max, temp;
  double temp2;

    for(temp = start; temp != end; temp++){
      printf("%s\n", "did once");
      max = max_iter(temp, end);

      temp2 = *temp;
      *temp = *max;
      *max = temp2;
    }

}
