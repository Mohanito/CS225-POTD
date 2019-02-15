// Pet.h
#include <string>
#include "Animal.h"
using namespace std;

class Pet : public Animal{
private:
  string name_;
  string owner_name_;
public:
  void setFood(string nu_food);
  string getFood();
  void setName(string nu_name);
  string getName();
  void setType(string nu_type);
  string getType();
  void setOwnerName(string nu_owner_name);
  string getOwnerName();
  string print();


  Pet();
  Pet(string type, string food, string name, string owner_name);
};
