// Pet.cpp
#include <string>
#include "Pet.h"
#include "Animal.h"
using namespace std;


void Pet::setFood(string nu_food) {
    food_ = nu_food;
}

string Pet::getFood() {
    return food_;
}

void Pet::setType(string nu_type) {
    Animal::setType(nu_type);
}

string Pet::getType() {
    return Animal::getType();
}

void Pet::setOwnerName(string nu_owner_name){
  owner_name_ = nu_owner_name;
}
string Pet::getOwnerName(){
  return owner_name_;
}
void Pet::setName(string nu_name){
  name_ = nu_name;
}

string Pet::getName(){
  return name_;
}
string Pet::print() {
    return "My name is " + name_;
};

Pet::Pet() : Animal(), name_("Fluffy"), owner_name_("Cinda") { }

Pet::Pet(string type, string food, string name, string owner_name)
      : Animal(type,food), name_(name), owner_name_(owner_name) { }
