#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
    stack<char> s;

    for(unsigned long i = 0; i < input.size(); i++){
      if(input[i] == '(' || input[i] == '[' || input[i] == '{'){
        s.push(input[i]);
      }
      else if(input[i] == ')' || input[i] == ']' || input[i] == '}'){
        if(s.empty()){
          return false;
        }
        else{

          if(input[i] == ')' && s.top() == '('){
            s.pop();
          }
          else if(input[i] == ']' && s.top() == '['){
            s.pop();
          }
          else if(input[i] == '}' && s.top() == '{'){
            s.pop();
          }
          else{
            return false;
          }

        }
      }
    }


    if(s.empty()){
      return true;
    }
    return false;
}
