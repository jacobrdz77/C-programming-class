#include <stdbool.h>
#include <stdio.h>

const char *findQuadrant(float x_coord, float y_coord) {
  if (x_coord == 0 && y_coord == 0) {
    return "located on the origin";
  } else if (x_coord == 0) {
    return "located on the y-axis";
  } else if (y_coord == 0) {
    return "located on the x-axis";
  } else if (x_coord > 0) {
    if (y_coord > 0) {
      return "located in Quadrant I";
    } else if (y_coord < 0) {
      return "located in Quadrant IV";
    }
  } else if (x_coord < 0) {
    if (y_coord > 0) {
      return "located in Quadrant II";
    } else if (y_coord < 0) {
      return "located in Quadrant III";
    }
  }

  return "Invalid coordinate";
}

int main() {

  float coordinates[2];
  printf("Enter x and y coordinates:");
  scanf("%f %f", &coordinates[0], &coordinates[1]);
  const char *quadrant = findQuadrant(coordinates[0], coordinates[1]);

  printf("Point (%f, %f) is located on the %s", coordinates[0], coordinates[1],
         quadrant);
  return 0;
}
