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

public:
     BinSrchTree(void):LinkedBinaryTree() {}
     ~BinSrchTree(void) {}

#pragma region Insert
     void insert(BinaryNode* r, BinaryNode* n) {
          if (r->getData() == n->getData())
               return;
          else if (r->getData() < n->getData()) {
               if (r->getRight() == NULL)
                    r->setRight(n);
               else
                    insert(r->getRight(), n);
          }
          else {
               if (r->getLeft() == NULL)
                    r->setLeft(n);
               else
                    insert(r->getLeft(), n);
          }
     }
     void insert(BinaryNode* n) {
          if (n == NULL) return;
          if (isEmpty()) root = n;
          else insert(root, n);
     }
#pragma endregion

#pragma region Delete
     void remove(int key) {
          if (isEmpty())
               cout << "tree is empty\n";

          BinaryNode* parent = NULL;
          BinaryNode* node = root;

          while (node != NULL && node->getData() != key) {
               parent = node;
               node = (key < node->getData()) ? node->getLeft() : node->getRight();
          }

          if (node == NULL) {
               cout << "key(" << key << ") is not in the tree\n";
               return;
          }
          else
               remove(parent, node);

     }
     void remove(BinaryNode* parent, BinaryNode* node) {
          //case 1
          if (node->isLeaf()) {
               if (parent == NULL)
                    root = NULL;
               else {
                    if (parent->getLeft() == node)
                         parent->setLeft(NULL);
                    else if (parent->getRight() == node)
                         parent->setRight(NULL);
               }
          }
          //case 2
          else if (node->getLeft() == NULL || node->getRight() == NULL) {
               BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();

               if (node == root) root = child;
               else {
                    if (parent->getLeft() == node)
                         parent->setLeft(child);
                    else if (parent->getRight() == node)
                         parent->setRight(child);
               }

          }
          //case 3
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
#pragma endregion

#pragma region Search
     BinaryNode* search(BinaryNode* r, int key) {
          if (r->getData() == key)
               return r;
          else if (r->getData() < key) {
               if (r->getRight() == NULL)
                    return NULL;
               else
                    search(r->getRight(), key);
          }
          else {
               if (r->getLeft() == NULL)
                    return NULL;
               else
                    search(r->getLeft(), key);
          }
     }
     BinaryNode* search(int key) {
          if (isEmpty()) {
               cout << "Tree is empty\n";
               return NULL;
          }

          BinaryNode* n = search(root, key);
          if (n == NULL) {
               cout << "Key(" << key << ") is not in Tree\n";
          }
          else {
               cout << "Key(" << key << ") is in Tree // node : " << n << " \n";
          }

          return n;
     }


#pragma endregion

};