#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
  int x;
  int y;
  int z;
} Point;

void point_init(Point *self, int x, int y, int z) {
  self->x = x;
  self->y = y;
  self->z = z;
}

void point_deinit(Point *self) { free(self); }

int main() {
  printf("Hello World");
  Point **arr = (Point **)malloc(sizeof(Point *) * 4);
  static int count = 0;
  for (int i = 0; i < 4; i++) {
    arr[i] = (Point *)malloc(sizeof(Point));
    arr[i]->x = count++;
    arr[i]->y = count++;
    arr[i]->z = count++;
  }
  return EXIT_SUCCESS;
}
