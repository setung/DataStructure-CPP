//Ž������ Ʈ��
/*
     ��� ���� ������ Ű�� ���´�
     ���� ����Ʈ���� Ű���� ��Ʈ�� Ű���� �۴�
     ������ ����Ƽ���� Ű���� ��Ʈ�� Ű���� ũ��.
     ���ʰ� ������ ����Ʈ���� ���� Ž�� Ʈ���̴�.

*/
#pragma once
#include "LinkedBinaryTree.h"

class BinSrchTree :public LinkedBinaryTree {
private:
     //��ȯ��� Ž��
     BinaryNode* searchRecur(BinaryNode* n, int key) {
          if (n == NULL) return NULL;
          if (key == n->getData())
               return n;
          else if (key < n->getData())
               return searchRecur(n->getLeft(), key);
          else
               return searchRecur(n->getRight(), key);
     }
     //�ݺ���� Ž��
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

     //���Կ���
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

     //��������
     void remove(BinaryNode* parent, BinaryNode* node) {

          // �����ϴ� ��尡 �ܸ� ����� ���
          if (node->isLeaf()) {
               if (parent == NULL)           // node�� root���� parent�� NULL �� ���
                    setRoot(NULL);
               else {
                    if (parent->getLeft() == node)
                         parent->setLeft(NULL);
                    else
                         parent->setRight(NULL);
               }
          }
          // �����ϴ� ��尡 �ϳ��� �ڽ��� ���� ���
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
          // �����ϴ� ��尡 �ΰ��� �ڽ��� ���� ���
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
               cout << "Ž�� ���� : Ű���� " << node->getData() << "�� ��� = " << node << '\n';
          else
               cout << "Ž�� ����: Ű���� " << key << "�� ��� ����\n";

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