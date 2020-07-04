#include <iostream>
#include "ArrayStack.h"
#include "LinkedStack.h"

int main()
{
     LinkedStack stack;
     stack.push(new Node(10));
     stack.push(new Node(20));
     stack.push(new Node(30));
     stack.push(new Node(40));
     stack.display();
     stack.pop();
     stack.pop();
     stack.display();


}

