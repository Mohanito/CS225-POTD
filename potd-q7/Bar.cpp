// your code here
#include "Bar.h"
#include "Foo.h"
#include <string>

using namespace potd;
using namespace std;
Bar::Bar(string name){
  this->f_ = new Foo(name);
}
Bar::Bar(const Bar & other){
  this->f_ = new Foo(*(other.f_));
}
Bar::~Bar(){
  //this->f_->~Foo();
  delete f_;
  //delete this;
}
string Bar::get_name(){
  return this->f_->get_name();
}
Bar & Bar:: operator=(const potd::Bar & other){
  this->f_->~Foo();
  Foo *ff_ = new Foo(other.f_->get_name());
  this->f_ = ff_;
  return *this;
}
