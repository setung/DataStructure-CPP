#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 연산자의 연산 우선순위 정보를 반환
int getOpPrec(char op) {
     switch (op)
     {
     case '*':
     case '/':
          return 5;
     case '+':
     case '-':
          return 3;
     case '(':
          return 1;

     default:
          break;
     }

     return -1;
}

// 두 연산자의 우선순위 비교 결과를 반환
int whoPrecOp(char op1, char op2) {
     int op1Prec = getOpPrec(op1);
     int op2Prec = getOpPrec(op2);

     if (op1Prec > op2Prec)
          return 1;
     else if (op1Prec < op2Prec)
          return -1;
     else
          return 0;

}

//중위 표현 -> 후위 표현
string convToRPNExp(string exp) {
     stack<char> s;
     string convExp;
     char tok, popOp;

     for (int i = 0; i < exp.size(); i++) {
          tok = exp[i];

          if (isdigit(tok)) {
               convExp.push_back(tok);
          }
          else
          {
               switch (tok)
               {
               case '(':
                    s.push(tok);
                    break;
               case ')':
                    while (1) {
                         popOp = s.top();
                         s.pop();
                         if (popOp == '(')
                              break;
                         convExp.push_back(popOp);
                    }
                    break;
               case '+': case '-':
               case '*': case '/':
                    while (!s.empty() && whoPrecOp(s.top(), tok) >= 0)
                    {
                         convExp.push_back(s.top());
                         s.pop();
                    }
                    s.push(tok);
                    break;
               default:
                    break;
               }
          }

     }

     while (!s.empty()) {
          convExp.push_back(s.top());
          s.pop();
     }

     return convExp;
}

//후위 표기법 수식 계산
int evalRPNExp(string exp) {
     stack<char> s;
     char op1, op2, tok;

     for (int i = 0; i < exp.size(); i++) {
          tok = exp[i];
          if (isdigit(tok)) {
               s.push(tok - '0');
          }
          else {
               op2 = s.top();
               s.pop();
               op1 = s.top();
               s.pop();

               switch (tok)
               {
               case '+':
                    s.push(op1 + op2);
                    break;
               case '-':
                    s.push(op1 - op2);
                    break;
               case '*':
                    s.push(op1 * op2);
                    break;
               case '/':
                    s.push(op1 / op2);
                    break;
               }
          }
     }

     return s.top();

}
int main()
{
     string exp = "3*5/(1+10)";

     cout << evalRPNExp(convToRPNExp(exp));
}


