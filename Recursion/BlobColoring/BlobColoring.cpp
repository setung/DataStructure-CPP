#include <iostream>
using namespace std;

#define WIDTH 20
#define HEIGHT 9

void labelComponent(unsigned char img[HEIGHT][WIDTH], int x, int y, int label) {
     if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
          return;

     if (img[y][x] == 9) {
          img[y][x] = label;
          labelComponent(img, x - 1, y, label);
          labelComponent(img, x + 1, y, label);
          labelComponent(img, x, y +1, label);
          labelComponent(img, x, y-1, label);
     }
}

void blobColoring(unsigned char img[HEIGHT][WIDTH]) {
     int label = 1;

     for (int y = 0; y < HEIGHT; y++) {
          for (int x = 0; x < WIDTH; x++) {
               if (img[y][x] == 9)
                    labelComponent(img, x, y, label++);
          }
     }
}

void printImage(unsigned char img[HEIGHT][WIDTH], string msg) {
     cout << msg << endl;
     for (int y = 0; y < HEIGHT; y++) {
          for (int x = 0; x < WIDTH; x++) {
               if (img[y][x] == 0)
                    cout << '.';
               else
                    cout << img[y][x];
          }
          cout << '\n';
     }
     cout << '\n';
}


int main()
{
     unsigned char image[HEIGHT][WIDTH] = {
          0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,0,0,9,9,0,
          9,9,9,9,9,0,9,0,0,0,0,0,0,0,0,9,0,0,9,9,
          0,0,9,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
          0,9,9,9,0,0,9,9,9,0,0,9,0,0,0,0,0,0,9,9,
          9,9,0,9,9,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
          9,9,0,9,9,0,9,0,0,0,0,0,0,0,0,0,0,0,9,9,
          9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,0,0,
          9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,9,9,
          0,0,0,0,0,0,9,0,0,0,9,9,9,9,9,9,0,0,9,9
     };

     printImage(image, "original");
     blobColoring(image);
     printImage(image, "labelled");


}

