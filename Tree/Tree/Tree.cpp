#include <iostream>
#include "LinkedBinaryTree.h"
#include "BinSrchTree.h"
/*
     이진트리 특징
       - n개의 노드 = n-1개의 간선
       - 높이가 h인 이진트리는 h개 이상 2^h -1개 이하의 노드를 가짐
       - n개의 노드를 가지는 이진트리의 높이는 log2(n+1)개 이상 n이하.

     포화 이진트리
       - 노드가 꽉 차있는 이진트리
       - 높이 k = 2^k-1개 노드
     완전 이진트리
       - 노드가 꽉차있지 않아도 되지만 중간에 빈곳이 없는 트리.

*/


int main()
{
     /*LinkedBinaryTree tree;
     BinaryNode* d = new BinaryNode(4, NULL, NULL);
     BinaryNode* e = new BinaryNode(5, NULL, NULL);
     BinaryNode* b = new BinaryNode(2, d, e);
     BinaryNode* f = new BinaryNode(6, NULL, NULL);
     BinaryNode* c = new BinaryNode(3, f, NULL);
     BinaryNode* a = new BinaryNode(1, b, c);
     tree.setRoot(a);

     tree.inoder();
     tree.preorder();
     tree.postorder();
     tree.levelorder();

     cout << "\n노드 갯수 : " << tree.getCount() << endl;
     cout << "단말 노드 갯수 : " << tree.getLeafCount() << endl;
     cout << "트리 높이 : " << tree.getHeight() << endl;*/


     BinSrchTree binSrchTree;
     binSrchTree.insert(new BinaryNode(1));
     binSrchTree.inoder();
     binSrchTree.insert(new BinaryNode(5));
     binSrchTree.inoder();
     binSrchTree.insert(new BinaryNode(4));
     binSrchTree.inoder();
     binSrchTree.insert(new BinaryNode(7));
     binSrchTree.inoder();
     binSrchTree.insert(new BinaryNode(9));
     binSrchTree.inoder();

     binSrchTree.remove(5);
     binSrchTree.remove(1);

     binSrchTree.inoder();

}

