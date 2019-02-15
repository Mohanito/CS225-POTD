// your code here
#include "q5.h"
#include "Food.h"
#include <iostream>
using namespace std;
int main(){
  Food* object = new Food();
  cout<<"You have "<< object->get_quantity()<< " " << object->get_name() << " ";
  increase_quantity(object);
  cout<<"You have "<< object->get_quantity()<< " " << object->get_name()<< " ";
  delete object;
}
