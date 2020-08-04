#include <iostream>

using namespace std;

const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
     {'1','1','1','1','1','1'},
     {'e','0','1','0','0','1'},
     {'1','0','0','0','1','1'},
     {'1','0','1','0','1','1'},
     {'1','0','1','0','0','x'},
     {'1','1','1','1','1','1'}
};

struct Location2D {
     int row;
     int col;
     
     Location2D(int r = 0, int c = 0) { row = r; col = c; }

     bool isNeighbor(Location2D& p) {
          return ((row == p.row && (col == p.col - 1 || col == p.col + 1)) ||
               (col == p.col) && (row == p.row - 1 || row == p.row + 1));
     }

     bool operator==(Location2D& p) { return row == p.row && col == p.col; }
};

bool isValidLoc(int r, int c) {
     if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
          return false;
     else
          return map[r][c] == '0' || map[r][c] == 'x';
}

Location2D locEntry, locExit;
bool done = false;

void searchRecur(Location2D pt) {
     cout << pt.row << "," << pt.col<<' ';
     if (done) return;
     if (pt == locExit) {
          done = true;
          return;
     }

     int r = pt.row;
     int c = pt.col;
     map[r][c] = '5';

     if (isValidLoc(r - 1, c)) searchRecur(Location2D(r - 1, c));
     if (isValidLoc(r + 1, c)) searchRecur(Location2D(r + 1, c));
     if (isValidLoc(r, c+1)) searchRecur(Location2D(r - 1, c+1));
     if (isValidLoc(r, c-1)) searchRecur(Location2D(r - 1, c-1));

}

int main()
{

     locEntry = Location2D(1, 0);
     locExit = Location2D(4, 5);

     searchRecur(locEntry);

     if (done)
          cout << " 끝 \n";
     else
          cout << " 출구 못찾음\n";

}
