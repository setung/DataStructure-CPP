#pragma once
#include <iostream>
#include <cstring>
#define MAX_CHAR_PER_LINE 1000

using namespace std;

class Line {
     char data[MAX_CHAR_PER_LINE];

public :
     Line(char* line = (char*)"") {
          strcpy(data, line);
     }

     void print(FILE* fp = stdout) {
          fprintf(fp, "%s", data);
     }

     bool hasData(char* str) { return strcmp(str, data) == 0; }
};
