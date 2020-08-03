//탐색이진 트리
/*
     모든 노드는 유일한 키를 갖는다
     왼쪽 서브트리의 키들은 루트의 키보다 작다
     오른쪽 서브티리의 키들은 루트의 키보다 크다.
     왼쪽과 오른쪽 서브트리도 이진 탐색 트리이다.

*/
#pragma once
#include "LinkedBinaryTree.h"

class BinSrchTree :public LinkedBinaryTree {
private:
     //순환기반 탐색
     BinaryNode* searchRecur(BinaryNode* n, int key) {
          if (n == NULL) return NULL;
          if (key == n->getData())
               return n;
          else if (key < n->getData())
               return searchRecur(n->getLeft(), key);
          else
               return searchRecur(n->getRight(), key);
     }
     //반복기반 탐색
     BinaryNode* searchIter(BinaryNode* n, int key) {
          while (n != NULL) {
               if (key == n->getData())
                    return n;
               else if (key < n->getData())
                    n = n->getLeft();
               else
                    n = n->getRight();
          }

          return NULL;
     }

     //삽입연산
     void insertRecur(BinaryNode* r, BinaryNode* n) {
          if (n->getData() == r->getData())
               return;
          else if (n->getData() < r->getData()) {
               if (r->getLeft() == NULL)
                    r->setLeft(n);
               else
                    insertRecur(r->getLeft(), n);
          }
          else {
               if (r->getRight() == NULL)
                    r->setRight(n);
               else
                    insertRecur(r->getRight(), n);
          }
     }

     //삭제연산
     void remove(BinaryNode* parent, BinaryNode* node) {

          // 삭제하는 노드가 단말 노드일 경우
          if (node->isLeaf()) {
               if (parent == NULL)           // node가 root여서 parent가 NULL 인 경우
                    setRoot(NULL);
               else {
                    if (parent->getLeft() == node)
                         parent->setLeft(NULL);
                    else
                         parent->setRight(NULL);
               }
          }
          // 삭제하는 노드가 하나의 자식을 갖은 경우
          else if (node->getLeft() == NULL || node->getRight() == NULL) {
               BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();

               if (node == getRoot())
                    setRoot(child);
               else {
                    if (parent->getLeft() == node)
                         parent->setLeft(child);
                    else
                         parent->setRight(child);
               }
          }
          // 삭제하는 노드가 두개의 자식을 갖은 경우
          else {
               BinaryNode* succp = node;
               BinaryNode* succ = node->getRight();

               while (succ->getLeft() != NULL) {
                    succp = succ;
                    succ = succ->getLeft();
               }

               if (succp->getLeft() == succ)
                    succp->setLeft(succ->getRight());
               else
                    succp->setRight(succ->getRight());

               node->setData(succ->getData());
               node = succ;

          }

          delete node;
     }

public:
     BinSrchTree(void) {}
     ~BinSrchTree(void) {}



     BinaryNode* search(int key) {
          BinaryNode* node = searchRecur(getRoot(), key);
          if (node != NULL)
               cout << "탐색 성공 : 키값이 " << node->getData() << "인 노드 = " << node << '\n';
          else
               cout << "탐색 실패: 키값이 " << key << "인 노드 없음\n";

          return node;
     }

     void insert(BinaryNode* n) {
          if (n == NULL) return;
          if (isEmpty()) setRoot(n);
          else insertRecur(getRoot(), n);
     }

     void remove(int key) {
          if (isEmpty()) return;

          BinaryNode* parent = NULL;
          BinaryNode* node = getRoot();
          while (node != NULL && node->getData() != key) {
               parent = node;
               node = (key < node->getData())
                    ? node->getLeft() : node->getRight();

          }

          if (node == NULL) {
               cout << "Error: Key("<< key<<") is not in the tree!\n";
               return;
          }
          else remove(parent, node);

     }

};