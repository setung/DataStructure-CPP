#include <iostream>
#include "ArrayCircularQueue.h"
#include "ArrayDeque.h"
#include "LinkedQueue.h"
int main()
{
     ArrayCircularQueue que;
     for (int i = 0; i < 10; i++)
          que.enqueue(i);
     que.display();
     que.dequeue();
     que.dequeue();
     que.dequeue();
     que.display();

     ArrayCircularDeque deque;
     for (int i = 0; i < 10; i++)
          deque.addFront(i);
     deque.display();
     deque.deleteFront();
     deque.deleteFront();
     deque.deleteRear();
     deque.display();


     LinkedQueue linkedQueue;
     linkedQueue.enqueue(new Node(1));
     linkedQueue.enqueue(new Node(2));
     linkedQueue.enqueue(new Node(3));
     linkedQueue.display();
     linkedQueue.dequeue();
     linkedQueue.dequeue();
     linkedQueue.display();





}

