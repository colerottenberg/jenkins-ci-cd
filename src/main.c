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

/*
 * # Point Deinit
 *
 * - Used to free the attached data
 */
void point_deinit(Point *self) { free(self); }

int main() {
  printf("Hello World\n");
  Point **arr = (Point **)malloc(sizeof(Point *) * 4);
  static int count = 0;
  for (int i = 0; i < 4; i++) {
    arr[i] = (Point *)malloc(sizeof(Point));
    arr[i]->x = count++;
    arr[i]->y = count++;
    arr[i]->z = count++;
    printf("|x:%d|y:%d|z:%d|\n", arr[i]->x, arr[i]->y, arr[i]->z);
  }
  for (size_t i = 0; i < 4; i++) {
    point_deinit(arr[i]);
  }
  return EXIT_SUCCESS;
}
