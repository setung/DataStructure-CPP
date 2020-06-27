#include <iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;

bool checkMatching(string str) {
     int nLine = 1;
     int nChar = 0;
     ArrayStack stack;

     for (int i = 0; i < str.size(); i++) {
          if (str[i] == '\n') nLine++;
          nChar++;

          if (str[i] == '[' || str[i] == '(' || str[i] == '{')
               stack.push(str[i]);
          else if (str[i] == ']' || str[i] == '}' || str[i] == ')') {
               char peek = stack.peek();

               if ((str[i] == ']' && peek == '[') ||
                    (str[i] == ')' && peek == '(') ||
                    (str[i] == '}' && peek == '{'))
                    stack.pop();
          }
     }


     if (!stack.isEmpty()) {
          cout << "문제 발견! (라인수=" << nLine << ", 문자수=" << nChar << ')' << endl;
     }
     else
          cout << "정상! (라인수=" << nLine << ", 문자수=" << nChar << ')' << endl;

     stack.display();
     
}

int main()
{
     checkMatching("()()()(){{)()()()");
}

