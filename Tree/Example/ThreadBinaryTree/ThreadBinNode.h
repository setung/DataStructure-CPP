#pragma once
class ThreadBinNode {
     int data;
     ThreadBinNode* left;
     ThreadBinNode* right;

public:
     bool bThread;
     ThreadBinNode(int val, ThreadBinNode* l, ThreadBinNode* r, bool th)
          :data(val), left(l), right(r), bThread(th) {}
     int getData() { return data; }
     void setRight(ThreadBinNode* r) { right = r; }
     ThreadBinNode* getLeft() { return left; }
     ThreadBinNode* getRight() { return right; }

};