/**
 * Takes a GIF file, decodes it into animated_image_t, and displays
 * each frame. Requires a window system to work, since it creates a
 * window to show the final result.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <errors.h>
#include <gif_parsed.h>
#include <gif_decoded.h>
#include <image.h>

#include "image_viewer.h"

int main(int argc, char **argv) {
  int error = 0;

  if (argc < 2) {
    printf("Usage: %s [-b] <filepath>\n", argv[0]);
    printf("Options:\n  -b: Ignore background color\n");
    return 0;
  }

  int ignore_background = 0;
  if (argc > 2) {
    if (strcmp(argv[1], "-b") == 0) {
      ignore_background = 1;
    } else {
      printf("Unknown option: %s", argv[1]);
    }
  }

  animated_image_t *image = image_from_path(argv[argc - 1], ignore_background, &error);

  if (error != 0 || image == NULL) {
    printf("Image error: %d\n", error);
    return -1;
  }

  show_image(image);

  animated_image_free(image);
  return 0;
}
