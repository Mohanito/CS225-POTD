#pragma once
#include "Base.h"
#include <string>
using namespace std;
class Derived : public Base{
public:
  string foo();
  string bar();
  virtual ~Derived();
};
