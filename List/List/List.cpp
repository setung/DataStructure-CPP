#include <iostream>
#include "ArrayList.h"
#include "Linked_List.h"
#include "DbLinkedList.h"

int main()
{
     ArrayList list;
     for (int i = 0; i < 10; i++)
          list.insert(i, i * i);

     list.display();
     list.remove(0);
     list.remove(2);
     list.remove(4);
     list.display();


     Linked_List linkedlist;
     linkedlist.insert(3, new Node(10));
     linkedlist.insert(0, new Node(20));
     linkedlist.insert(0, new Node(30));
     linkedlist.insert(1, new Node(40));
     linkedlist.display();
     linkedlist.remove(1);
     linkedlist.remove(2);
     linkedlist.display();
     linkedlist.clear();
     linkedlist.display();

     DblLinkedList dbLinkedlist;
     dbLinkedlist.insert(0, new Node2(10));
     dbLinkedlist.insert(0, new Node2(20));
     dbLinkedlist.insert(0, new Node2(30));
     dbLinkedlist.display();
     dbLinkedlist.remove(0);
     dbLinkedlist.display();
}

