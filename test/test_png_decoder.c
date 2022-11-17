#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "png_util.h"
#include "png_raw.h"
#include "png_parser.h"
#include "png_decoder.h"
#include "image_viewer.h"

int main(int argc, char **argv) {
  int error = 0;

  if (argc < 2) {
    printf("Usage: %s <filename.png>\n", argv[0]);
    return 0;
  }

  png_t *png = png_decoded_from_path(argv[1], &error);
  if (png == NULL || error != 0) {
    printf("Failed to decode PNG data: %d.\n", error);
    return 1;
  }

  show_decoded_png(png);

  png_free(png);
  return 0;
}

