// your code here!
#include<cmath>
#include<array>
#include"potd.h"
using namespace std;

int * potd::raise(int * arr){
  //int size = sizeof(*arr) / sizeof(arr[0]);
  int *array = new int[5];
  for(int i = 0; i < 5; i++){
    if (arr[i] != NULL){
      array[i] = pow(arr[i], arr[i+1]);
    }
    if(arr[i] == -1){
      array[i] = -1;
      array[i-1] = arr[i - 1];
    }
  }
  return array;
}
