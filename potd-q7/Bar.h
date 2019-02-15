// your code here
#include <string>
#include "Foo.h"

using namespace std;

namespace potd {
  class Bar{
  public:
    Bar(string name);
    Bar(const Bar & other);
    ~Bar();
    string get_name();
    Bar & operator=(const Bar & other);
  private:
    Foo * f_;
  };
}
