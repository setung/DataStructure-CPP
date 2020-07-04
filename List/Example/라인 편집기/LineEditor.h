#pragma once
#include "LinkedList.h"

class LineEdiotr : public LinkedList {
public :
     void Display(FILE* fp = stdout) {
          int i = 0;
          for (Node* p = getHead(); p != NULL; p = p->getLink(), i++) {
               fprintf(stderr, "%3d: ", i);
               p->print(fp);
          }
     }

     void InsertLine() {
          int position;
          char line[MAX_CHAR_PER_LINE];
          cout << "   �Է��� ��ȣ: ";
          cin >> position;
          cout << "   �Է��� ����: ";
          insert(position, new Node(line));
          fflush(stdin);
          fgets(line, MAX_CHAR_PER_LINE, stdin);
          insert(position, new Node(line));
     }

     void DeleteLine() {
          printf("   ������ ��ȣ: ");
          int position;
          cin >> position;
          delete remove(position);
     }

     void ReplaceLine() {
          int position;
          char line[MAX_CHAR_PER_LINE];
          cout <<"   ������ ��ȣ: ";
          cin >> position;
          cout <<"   ������ ����: ";
          fflush(stdin);
          fgets(line, MAX_CHAR_PER_LINE, stdin);

          replace(position, new Node(line));
     }

     void LoadFile(char* fname) {
          FILE* fp = fopen(fname, "r");
          if (fp != NULL) {
               char line[MAX_CHAR_PER_LINE];
               while (fgets(line, MAX_CHAR_PER_LINE, fp))
                    insert(size(), new Node(line));
               
               fclose(fp);
          }
     }

     void StoreFile(char* fname) {
          FILE* fp = fopen(fname, "w");
          if (fp != NULL) {
               Display(fp);
               fclose(fp);
          }
     }


};